#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
	
	virtual bool onTouchBegan(cocos2d::Touch*t, cocos2d::Event*e);
	virtual void onTouchMoved(cocos2d::Touch*t, cocos2d::Event*e);
	virtual void onTouchEnded(cocos2d::Touch*t, cocos2d::Event*e);
private:
	cocos2d::Size visibleSize;
	cocos2d::SpriteBatchNode*batchNode;
	cocos2d::DrawNode* drawnode;
	int totalCoinFallCount=0;
};

class testLayer :public cocos2d::Layer{
public:
	CREATE_FUNC(testLayer);
	virtual bool init();

};
#endif // __HELLOWORLD_SCENE_H__
