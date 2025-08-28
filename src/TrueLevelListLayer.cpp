#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include "PsuedoDifficulty.hpp"

struct DifficultyInfo {
    PsuedoDifficulty difficulty;
    bool rated;
};

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
        std::vector<DifficultyInfo> difficulties;
        CCObject* object;
        CCArray* levels = m_levelList->getListLevelsArray(CCArray::create());
        CCARRAY_FOREACH(levels, object) {
            if (GJGameLevel* level = geode::cast::typeinfo_cast<GJGameLevel*>(object)) {
                difficulties.push_back(DifficultyInfo {
                    .difficulty = getPsuedoDifficulty(level),
                    .rated = level->m_stars != 0
                });
            }
        } 
        std::vector<int> filteredDifficulties;
        for (int i = 0; i < difficulties.size(); i ++) {
            DifficultyInfo info = difficulties.at(i);
            PsuedoDifficulty difficulty = info.difficulty;
            bool rated = info.rated;
            if (!Mod::get()->getSettingValue<bool>("include-rated-levels") && rated) continue;
            if (!Mod::get()->getSettingValue<bool>("include-unrated-levels") && !rated) continue;
            if (!Mod::get()->getSettingValue<bool>("include-na-levels") && difficulty == PsuedoDifficulty::NA) continue;
            filteredDifficulties.push_back(static_cast<int>(difficulty));
        }
        log::info("{}", filteredDifficulties);
    }
};