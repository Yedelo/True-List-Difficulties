#pragma once

enum class PsuedoDifficulty {
    NA,
    Auto,
    Easy,
    Normal,
    Hard,
    Harder,
    Insane,
    EasyDemon,
    MediumDemon,
    HardDemon,
    InsaneDemon,
    ExtremeDemon
};

PsuedoDifficulty getPsuedoDifficulty(GJGameLevel* level);