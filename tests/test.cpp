#include "actions/actions.h"
#include "entities/Planet.h"
#include "entities/Player.h"

#include "boost/ut.hpp"

#include <deque>
#include <stdexcept>

using namespace boost::ut;

namespace oa = ocse::actions;
namespace oe = ocse::entities;

int main() {
    std::deque<oe::Player> players;
    std::deque<oe::Planet> planets;

    auto& player_1 = players.emplace_back();
    auto& planet = planets.emplace_back();

    "bind new planet to player_1"_test = [=] mutable {
        oa::bind_planet_to_player(player_1, planet);
        expect(that % planet.player == &player_1);
        expect(player_1.planets.size() == 1_i);
    };

    "trying bind planet to player_1 twice"_test = [=] mutable {
        oa::bind_planet_to_player(player_1, planet);

        expect(throws<std::logic_error>([&] {
            oa::bind_planet_to_player(player_1, planet);
        })) << "throws logic_error";
        expect(player_1.planets.size() == 1_i);
    };

    "trying bind planet to player_2"_test = [=] mutable {
        auto& player_2 = players.emplace_back();
        oa::bind_planet_to_player(player_1, planet);

        expect(throws<std::runtime_error>([&] {
            oa::bind_planet_to_player(player_2, planet);
        })) << "throws runtime_error";
        expect(player_2.planets.size() == 0_i);
    };
}
