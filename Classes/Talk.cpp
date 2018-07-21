#include"Talk.h"
USING_NS_CC;
bool TalkLayer::init(){
	if (!Layer::init()){
		return false;
	}
	auto txtLabel = Label::createWithSystemFont("this is TalkLayer", "", 25);
	txtLabel->setPosition(Vec2::ZERO);
	txtLabel->retain();
	this->addChild(txtLabel);
	log("this is talkLayer");
	
	return true;
}