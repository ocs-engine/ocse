#include "actions/planet.h"

#include <stdexcept>

namespace ocse::actions {
    void bind_planet_to_player(oe::Player& player, oe::Planet& planet)
    {
        if (planet.player == &player) {
            throw std::logic_error{"This planet already owned this player"};
        }
        if (planet.player) {
            throw std::runtime_error{"This planet already owned another player"};
        }
        planet.player = &player;
        player.planets.push_back(&planet);
    }
}
