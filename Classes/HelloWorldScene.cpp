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
#include "AudioEngine.h"

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

	//背景
	backGround = Sprite::create("backGround2.jpg");
	backGround->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	backGround->setScaleX(1.22f);
	backGround->setScaleY(1.31f);
	this->addChild(backGround);

	//スリープカービィ生成
	kirby_sleep = Sprite::create("sleep2.png");
	kirby_sleep->setPosition(Vec2(300, 200));
	this->addChild(kirby_sleep);
	//泡の生成
	foam = Sprite::create("foam.png");
	Vec2 foamPosition = kirby_sleep->getPosition();
	foam->setPosition(foamPosition + Vec2(-50,20));
	this->addChild(foam);

	//関数生成
	//CallFunc* action = CallFunc::create(CC_CALLBACK_0(HelloWorld::foamMove, this));
	//foam->runAction(action);
	//泡のアクション
	MoveTo* foamRise = MoveTo::create(3.0f ,foamPosition + Vec2(-50, 60));
	FadeOut* foamFade = FadeOut::create(0.5f);
	ScaleTo* foamScale = ScaleTo::create(3.0f, 1.5f);
	Spawn* foamSpawn = Spawn::create(foamRise, foamScale, nullptr);
	Sequence* foamSeqence = Sequence::create(foamSpawn, foamFade, nullptr);
	/*Repeat* foamRepeat = Repeat::create(foamSeqence, 3.0f);*/
	foam->runAction(foamSeqence);

	CallFunc* foamAction = CallFunc::create(CC_CALLBACK_0(HelloWorld::foamMove, this));
	//update関数を有効にする
	this->scheduleUpdate();

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

void HelloWorld::foamMove() {
	//泡の生成
	foam = Sprite::create("foam.png");
	Vec2 foamPosition = kirby_sleep->getPosition();
	foam->setPosition(foamPosition + Vec2(-50, 20));
	this->addChild(foam);
}
