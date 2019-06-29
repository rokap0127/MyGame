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
	//�X�v���C�g�̐���
	Sprite* sprite = Sprite::create("owl.png");
	this->addChild(sprite);
	sprite->setScale(0.3f);
	sprite->setPosition(
		Vec2(visibleSize.width - 200.0f, 
			visibleSize.height - 200.0f));

	////�A�N�V����1�̐���
	//MoveTo* action1 = MoveTo::create(2.0f, Vec2(600.0f, 200.0f));
	////�A�N�V����2�̐���
	//JumpTo* action2 = JumpTo::create(1.0f, Vec2(200.0f, 200.0f), 300.0f, 2);
	////�A���A�N�V�����̍쐬(nullptr�ŏI���)
	//Sequence* action3 = Sequence::create(action1, action2, nullptr);
	////�����A�N�V�����쐬
	//Spawn* action4 = Spawn::create(action1, action2, nullptr);
	////�A�N�V����5�쐬(�W�����v����A�N�V����)
	//JumpBy* action5 = JumpBy::create(2.0f, Vec2(100.0f, 100.0f), 100.0f, 2);
	////�J��Ԃ��̃A�N�V�����쐬
	//Repeat* action6 = Repeat::create(action3, 3);
	////�����ɌJ��Ԃ��A�N�V�����̍쐬
	//RepeatForever* action7 = RepeatForever::create(action3);
	////DelayTime�̎g����
	//DelayTime* action8 = DelayTime::create(1.0f);
	//Sequence* action9 = Sequence::create(action8, action1, action2, nullptr);
	//Repeat* action10 = Repeat::create(action9, 10);

	////�A�N�V�����̎��s
	//sprite->runAction(action10);

	//�A�N�V�����̐���
	//�ړ�����
	//����
	MoveTo* action1 = MoveTo::create(5.0f, Vec2(200.0f, visibleSize.height - 200.0f));
	//�E��
	MoveTo* action2 = MoveTo::create(5.0f, Vec2(
		visibleSize.width - 200.0f, 
		visibleSize.height - 200.0f));
	//�t�F�[�h�C��.�A�E�g����
	FadeOut* action4 = FadeOut::create(5.0f);
	FadeIn* action5 = FadeIn::create(5.0f);
	//�����ɃA�N�V����
	Spawn* action6 = Spawn::create(action1, action4, nullptr);
	Spawn* action7 = Spawn::create(action2, action5, nullptr);
	//�ړ�����
	//����
	MoveTo* action10 = MoveTo::create(5.0f, Vec2(200.0f, 200.0f));
	//�E��
	MoveTo* action11 = MoveTo::create(5.0f, Vec2(visibleSize.width - 200.0f, 200.0f));

	//�������1����
	Sequence* action3 = Sequence::create(action1, action2, nullptr);
	
	//�������Q����
	Sequence* action8 = Sequence::create(action6, action7, nullptr);

	//�������R����
	Repeat* action9 = Repeat::create(action8, 5);

	//�������S����
	Sequence* action12 = Sequence::create(action1, action10, action11, action2, nullptr);

	//�������T����
	RepeatForever* action13 = RepeatForever::create(action12);

	//�A�N�V�������s
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
	//�����ɍX�V����������
	
}
