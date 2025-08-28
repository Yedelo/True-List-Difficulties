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
        CCObject* object;
        CCARRAY_FOREACH(m_levels, object) {
            if (GJGameLevel* level = geode::cast::typeinfo_cast<GJGameLevel*>(object)) {
                logLevelInfo(level);
            }
        }
    }
};

#define LOG(member) log::info("- {}: {}", #member, level->m_##member)

void logLevelInfo(GJGameLevel* level) {
    log::info("Logging info for level {}", level->m_levelName);
    log::info("- difficulty: {}", static_cast<int>(level->m_difficulty));
    LOG(ratings);
    LOG(ratingsSum);
    LOG(demon);
    LOG(demonDifficulty);
    LOG(stars);
    LOG(autoLevel);
    LOG(starRatings);
    LOG(starRatingsSum);
    LOG(maxStarRatings);
    LOG(minStarRatings);
    LOG(demonVotes);
    LOG(rateStars);
}
