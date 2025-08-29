#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include "TrueListDifficultyPopup.hpp"

TrueListDifficultyPopup* TrueListDifficultyPopup::create(LevelListLayer* layer) {
    TrueListDifficultyPopup* result = new TrueListDifficultyPopup();
    if (result->initAnchored(240, 300, layer)) {
        result->autorelease();
        return result;
    }
    delete result;
    return nullptr;
}

bool TrueListDifficultyPopup::setup(LevelListLayer* layer) {
    setTitle("True List Difficulty");
    setID("true-list-difficulty-popup");

    return true;
}