#ifndef OCSE_ACTIONS_H
#define OCSE_ACTIONS_H

#include "entities/Planet.h"
#include "entities/Player.h"

namespace oe = ocse::entities;

namespace ocse::actions {
    void bind_planet_to_player(oe::Player& player, oe::Planet& planet);
}

#endif //OCSE_ACTIONS_H
