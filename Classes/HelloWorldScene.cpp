#include "HelloWorldScene.h"
#include"ui\CocosGUI.h"
#include"Talk.h"
USING_NS_CC;
using namespace cocos2d::ui;


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
     visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//ParticleRain*pg = ParticleRain::create();
	//pg->setPosition(Vec2(300, 300));
	//pg->setColor(Color3B::GREEN);
	//this->addChild(pg);

	//ParticleExplosion*pgz = ParticleExplosion::create();
	//pgz->setPosition(Vec2(350, 300));
	//this->addChild(pgz);
	//

	auto l2 = testLayer::create();
	l2->setPosition(Vec2(visibleSize.width*0.3f, visibleSize.height*0.4f));
	this->addChild(l2);

	auto l23 = testLayer::create();
	l23->setPosition(Vec2(visibleSize.width*0.3f, visibleSize.height*0.5f));
	this->addChild(l23);

	Button*bt = Button::create("CloseNormal.png",
		"CloseSelected.png", "");
	bt->setPosition(Vec2(200, 200));
	this->addChild(bt);
	bt->addClickEventListener([](Ref*p){
		log("bt");
	});
	


	return true;
	
}
bool HelloWorld::onTouchBegan(Touch*t, Event*e){
	return true;
}
void HelloWorld::onTouchMoved(Touch*t, Event*e){
	log("this is moved");
	

}
void HelloWorld::onTouchEnded(Touch*t, Event*e){
	log("this is end");




int iRandomCount = CCRANDOM_0_1()*(10 - 20 + 1) + 20;
	//int iRandomCount = CCRANDOM_0_1()*(250 - 280 + 1) + 280;
	totalCoinFallCount += iRandomCount; 
	for (int i = 1; i != iRandomCount; i++){
		Point startPos = Vec2(CCRANDOM_0_1()*(0 - visibleSize.width + 1) + visibleSize.width, visibleSize.height );
		//CCLOG("%f,%f", startPos.x, startPos.y);
		Sprite*imgCoinIcon = Sprite::create("imgDropCoin.png");
		//Sprite*imgCoinIcon = Sprite::createWithTexture(batchNode->getTexture());
		imgCoinIcon->setScale(0.6);
		imgCoinIcon->setRotation(CCRANDOM_0_1()*(0 - 360 + 1) + 360);
		imgCoinIcon->setPosition(startPos);
		this->addChild(imgCoinIcon);
		imgCoinIcon->runAction(
			Sequence::create(MoveTo::create(
			0.3 + (CCRANDOM_0_1()*(1 - 3 + 1) + 3) / 10, Vec2(startPos.x, 0)
			), CallFunc::create([=](){
			imgCoinIcon->runAction(Sequence::create(JumpTo::create(0.8, Vec2(startPos.x, 0), CCRANDOM_0_1()*(150 - 500 + 1) + 500, 1),
				CallFunc::create([=](){
				imgCoinIcon->removeFromParent(); })
					, NULL)
					);
		}), NULL)
			);
	}
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	
	CCLOG("end button");
}


bool testLayer::init(){
	if (!Layer::init()){
		return false;
	}
	auto lab = Label::createWithSystemFont("this is test layer", "", 25);
	lab->setPosition(Vec2::ZERO);
	this->addChild(lab);
	auto listener = EventListenerTouchOneByOne::create();

	//下面的代码和CC_CALLBACK_2宏等价,不是很理解[]里需不需要加引用或者=
	listener->onTouchBegan = std::bind([](Touch*t, Event*e){
		log("%f,%f", t->getLocation().x, t->getLocation().y);
		return true;
	}, std::placeholders::_1, std::placeholders::_2);
	

	listener->setSwallowTouches(false);//不屏蔽往下传递事件
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}
