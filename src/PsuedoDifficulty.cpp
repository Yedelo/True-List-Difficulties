#include "PsuedoDifficulty.hpp"

PsuedoDifficulty getPsuedoDifficulty(GJGameLevel* level) {
    if (level->m_ratings == 0) {
        return PsuedoDifficulty::NA;
    }
    if (level->m_autoLevel) {
        return PsuedoDifficulty::Auto;
    }
    if (level->m_demon) {
        switch (level->m_demonDifficulty) {
            case 3: return PsuedoDifficulty::EasyDemon;
            case 4: return PsuedoDifficulty::MediumDemon;
            case 0: return PsuedoDifficulty::HardDemon;
            case 5: return PsuedoDifficulty::InsaneDemon;
            case 6: return PsuedoDifficulty::ExtremeDemon;
        }
    }
    return static_cast<PsuedoDifficulty>((level->m_ratingsSum / level->m_ratings) + 1);
}