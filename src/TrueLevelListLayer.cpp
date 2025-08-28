#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/LevelListLayer.hpp>
class $modify(LevelListLayer) {
    $override bool init(GJLevelList* list) {
        if (!LevelListLayer::init(list)) return false;
        
        log::info("Hello level list layer");

        return true;
    }
};