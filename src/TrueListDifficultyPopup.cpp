#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include "TrueListDifficultyPopup.hpp"

TrueListDifficultyPopup* TrueListDifficultyPopup::create(LevelListLayer* layer) {
    TrueListDifficultyPopup* result = new TrueListDifficultyPopup();
    if (result->initAnchored(240, 240, layer)) {
        result->autorelease();
        return result;
    }
    delete result;
    return nullptr;
}

bool TrueListDifficultyPopup::setup(LevelListLayer* layer) {
    setTitle("True List Difficulty");
    setID("true-list-difficulty-popup");

    CCMenu* generalMenu = createAndAddMenu("general-menu");
    generalMenu->ignoreAnchorPointForPosition(true);
    generalMenu->setScale(0.4);
    generalMenu->setPosition({120, 144});
    CCLabelBMFont* includedDifficultiesLabel = CCLabelBMFont::create("Included Difficulties", "bigFont.fnt");
    includedDifficultiesLabel->setID("included-difficulties-label");
    generalMenu->addChildAtPosition(includedDifficultiesLabel, Anchor::Top, {0, -20});

    CCMenu* meanMenu = createAndAddMenu("mean-menu");
    CCLabelBMFont* meanLabel = CCLabelBMFont::create("Mean", "bigFont.fnt");
    meanMenu->addChild(meanLabel);
    GJDifficultySprite* meanSprite = GJDifficultySprite::create(static_cast<int>(GJDifficulty::Easy), GJDifficultyName::Short);
    meanMenu->addChild(meanSprite);

    CCMenu* medianMenu = createAndAddMenu("median-menu");
    CCLabelBMFont* medianLabel = CCLabelBMFont::create("Median", "bigFont.fnt");
    medianMenu->addChild(medianLabel);
    GJDifficultySprite* medianSprite = GJDifficultySprite::create(static_cast<int>(GJDifficulty::Normal), GJDifficultyName::Short);
    medianMenu->addChild(medianSprite);

    CCMenu* modeMenu = createAndAddMenu("mode-menu");
    CCLabelBMFont* modeLabel = CCLabelBMFont::create("Mode", "bigFont.fnt");
    modeMenu->addChild(modeLabel);
    GJDifficultySprite* modeSprite = GJDifficultySprite::create(static_cast<int>(GJDifficulty::Hard), GJDifficultyName::Short);
    modeMenu->addChild(modeSprite);


    return true;
}

CCMenu* TrueListDifficultyPopup::createAndAddMenu(std::string id) {
    CCMenu* menu = CCMenu::create();
    menu->setID(id);
    m_mainLayer->addChild(menu);
    return menu;
}