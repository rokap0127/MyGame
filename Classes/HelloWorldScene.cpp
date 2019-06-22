/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

static cocos2d::Size smallResolution = cocos2d::Size(1280, 720);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size largeResolutionSize = cocos2d::Size(1280, 720);

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }
	
	//乱数の初期化
	srand(time(nullptr));

	//for(int i=0;i<5;i++)
	//{
	//	sprite[i] = Sprite::create("owl.png");
	//	this->addChild(sprite[i]);
	//	sprite[i]->setScale(0.2f);
	//	sprite[i]->setPosition(Vec2(300 + i*100, visibleSize.height / 2.0f));

	//	float mx, my;
	//	mx = (float)rand() / RAND_MAX * 500 - 250;
	//	my = (float)rand() / RAND_MAX * 500 - 250;
	//	MoveBy* action1 = MoveBy::create(1.0f, Vec2(mx, my));
	//	sprite[i]->runAction(action1);
	//}

	//問題１
	//sprite[0] = Sprite::create("owl.png");
	//this->addChild(sprite[0]);
	//sprite[1] = Sprite::create("owl.png");
	//this->addChild(sprite[1]);
	//sprite[0]->setScale(0.2f);
	//sprite[1]->setScale(0.2f);
	//sprite[0]->setPosition(Vec2(300, 200));
	//sprite[1]->setPosition(Vec2(550, 200));
	////アクション
	//JumpBy*action1 = JumpBy::create(2.0f, Vec2(300, 0), 100.0f, 1);
	//sprite[0]->runAction(action1);
	//sprite[1]->runAction(action1->clone());

	//問題２
	//for (int i = 0; i < 10; i++) {
	//	sprite[i] = Sprite::create("owl.png");
	//	this->addChild(sprite[i]);
	//	sprite[i]->setScale(0.2f);
	//	sprite[i]->setPosition(Vec2(150 + i * 150, 200));
	//	JumpBy*action1 = JumpBy::create(2.0f, Vec2(150, 0), 200.0f, 1);
	//	sprite[i]->runAction(action1);
	//}
	//問題３
		
		//for (int i = 0; i < 10; i++) {
		//	float vecX, vecY, mx, my;
		//	vecX = (float)rand() / RAND_MAX * 1000;
		//	vecY = (float)rand() / RAND_MAX * 500;
		//	//-250-250
		//	mx = (float)rand() / RAND_MAX * 500 - 250;
		//	my = (float)rand() / RAND_MAX * 500 - 150;
		//	sprite[i] = Sprite::create("owl.png");
		//	this->addChild(sprite[i]);
		//	sprite[i]->setScale(0.2f);
		//	sprite[i]->setPosition(Vec2(vecX, vecY));
		//	JumpBy*action1 = JumpBy::create(2.0f, Vec2(mx, my), 500.0f, 1);
		//	sprite[i]->runAction(action1);
		//}
	//問題4
		sprite[0] = Sprite::create("owl.png");
		this->addChild(sprite[0]);
		sprite[0]->setScale(0.2f);
		sprite[0]->setPosition(Vec2(visibleSize.width - 150.0f, visibleSize.height - 150.0f));
		//MoveBy* action1 = MoveBy::create(10.0f, Vec2(-visibleSize.width+300.0f, 0.0f));
		//sprite[0]->runAction(action1);
		//FadeOut* action2 = FadeOut::create(5.0f);
		//sprite[0]->runAction(action2);
		state = 0;
		switch (state)
		{
		case 0:
			MoveBy * action1 = MoveBy::create(10.0f, Vec2(-visibleSize.width + 300.0f, 0.0f));
			sprite[0]->runAction(action1);
			if (sprite[0]->getPosition <= -visibleSize.width + 300.0f) {
				state = 1;
			}
			break;
		}
    //// add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");
    //if (sprite == nullptr)
    //{
    //    problemLoading("'HelloWorld.png'");
    //}
    //else
    //{
    //    // position the sprite on the center of the screen
    //    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //    // add the sprite as a child to this layer
    //    this->addChild(sprite, 0);
    //}

	//テクスチャファイル名を指定して、スプライトを作成
	
	//sprite = Sprite::create("owl.png");
	//sprite2 = Sprite::create("animal_lion.png");
	///*シーングラフにつなぐ*/ 
	//this->addChild(sprite);
	//this->addChild(sprite2);
	////スプライト
	//sprite->setPosition(Vec2(100, 100));
	//sprite->setScale(0.2f);
	//sprite2->setPosition(Vec2(200, 150));

	////アクション作成
	//MoveBy* action1 = MoveBy::create(1.0f, Vec2(1000,500));
	//sprite->runAction(action1);
	//MoveBy* action2 = MoveBy::create(1.0f, Vec2(1000, 500));
	//sprite2->runAction(action1->clone());
	//MoveTo* action1 = MoveTo::create(1.0f, Vec2(200, 100));
	//ScaleTo* action1 = ScaleTo::create(1.0f, 1.0f);
	//EaseIn* action2 = EaseIn::create(action1, 2.0f);
	//EaseBounceOut* action2 = EaseBounceOut::create(action1);
	//sprite->runAction(action2);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta) {
	//ここに更新処理を書く
	
}
