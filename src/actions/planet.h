#ifndef OCSE_ACTIONS_PLANET_H
#define OCSE_ACTIONS_PLANET_H

#include "entities/planet.h"
#include "entities/player.h"

namespace oe = ocse::entities;

namespace ocse::actions {
    void bind_planet_to_player(oe::Player& player, oe::Planet& planet);
}

#endif //OCSE_ACTIONS_PLANET_H
