#include <Geode/Geode.hpp>

using namespace geode::prelude;

void logLevelInfo(GJGameLevel* level);

#include <Geode/modify/LevelListLayer.hpp>
class $modify(TrueLevelListLayer, LevelListLayer) {
    $override bool init(GJLevelList* list) {
        if (!LevelListLayer::init(list)) return false;
        
        if (Mod::get()->getSettingValue<bool>("enabled")) {
            CCMenu* rightSideMenu = static_cast<CCMenu*>(getChildByID("right-side-menu"));
            CircleButtonSprite* sprite = CircleButtonSprite::createWithSprite("logo.png"_spr);
            sprite->setScale(1 / 1.26);
            CCMenuItemSpriteExtra* button = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(TrueLevelListLayer::showTrueListDifficulty));
            button->setID("true-list-difficulty-button");
            rightSideMenu->addChild(button);
            rightSideMenu->updateLayout();
        }

        return true;
    }

    void showTrueListDifficulty(CCObject* sender) {
        
    }
};