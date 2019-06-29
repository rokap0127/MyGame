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
	//スプライトの生成
	Sprite* sprite = Sprite::create("owl.png");
	this->addChild(sprite);
	sprite->setScale(0.3f);
	sprite->setPosition(
		Vec2(visibleSize.width - 200.0f, 
			visibleSize.height - 200.0f));

	////アクション1の生成
	//MoveTo* action1 = MoveTo::create(2.0f, Vec2(600.0f, 200.0f));
	////アクション2の生成
	//JumpTo* action2 = JumpTo::create(1.0f, Vec2(200.0f, 200.0f), 300.0f, 2);
	////連続アクションの作成(nullptrで終わる)
	//Sequence* action3 = Sequence::create(action1, action2, nullptr);
	////同時アクション作成
	//Spawn* action4 = Spawn::create(action1, action2, nullptr);
	////アクション5作成(ジャンプするアクション)
	//JumpBy* action5 = JumpBy::create(2.0f, Vec2(100.0f, 100.0f), 100.0f, 2);
	////繰り返しのアクション作成
	//Repeat* action6 = Repeat::create(action3, 3);
	////無限に繰り返すアクションの作成
	//RepeatForever* action7 = RepeatForever::create(action3);
	////DelayTimeの使い方
	//DelayTime* action8 = DelayTime::create(1.0f);
	//Sequence* action9 = Sequence::create(action8, action1, action2, nullptr);
	//Repeat* action10 = Repeat::create(action9, 10);

	////アクションの実行
	//sprite->runAction(action10);

	//アクションの生成
	//移動する
	//左上
	MoveTo* action1 = MoveTo::create(5.0f, Vec2(200.0f, visibleSize.height - 200.0f));
	//右上
	MoveTo* action2 = MoveTo::create(5.0f, Vec2(
		visibleSize.width - 200.0f, 
		visibleSize.height - 200.0f));
	//フェードイン.アウトする
	FadeOut* action4 = FadeOut::create(5.0f);
	FadeIn* action5 = FadeIn::create(5.0f);
	//同時にアクション
	Spawn* action6 = Spawn::create(action1, action4, nullptr);
	Spawn* action7 = Spawn::create(action2, action5, nullptr);
	//移動する
	//左下
	MoveTo* action10 = MoveTo::create(5.0f, Vec2(200.0f, 200.0f));
	//右下
	MoveTo* action11 = MoveTo::create(5.0f, Vec2(visibleSize.width - 200.0f, 200.0f));

	//＊＊問題1＊＊
	Sequence* action3 = Sequence::create(action1, action2, nullptr);
	
	//＊＊問題２＊＊
	Sequence* action8 = Sequence::create(action6, action7, nullptr);

	//＊＊問題３＊＊
	Repeat* action9 = Repeat::create(action8, 5);

	//＊＊問題４＊＊
	Sequence* action12 = Sequence::create(action1, action10, action11, action2, nullptr);

	//＊＊問題５＊＊
	RepeatForever* action13 = RepeatForever::create(action12);

	//アクション実行
	sprite->runAction(action13);

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
