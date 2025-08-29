#pragma once

using namespace geode::prelude;

class TrueListDifficultyPopup : public geode::Popup<LevelListLayer*> {
protected:
    bool setup(LevelListLayer* layer) override;
public:
    static TrueListDifficultyPopup* create(LevelListLayer* layer);
};