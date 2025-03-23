#include "actions/planet.h"
#include "functions/planet.h"

#include <stdexcept>

namespace of = ocse::functions;

namespace ocse::actions {
    oe::Planet create_planet(
        oe::PlanetCoordinates coordinates,
        const std::string& name
    ) {
        of::FieldRange max_field_range = of::get_max_field_range_by_position(
            coordinates.position
        );
        oe::PlanetFieldCount field_count = of::get_initial_field_count(
            max_field_range
        );
        return oe::Planet{
            coordinates,
            field_count,
            150, // TODO develop getter for initial temperature
            name
        };
    }

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
