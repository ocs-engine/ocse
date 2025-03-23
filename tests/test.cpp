#include "actions/planet.h"
#include "entities/planet.h"
#include "entities/player.h"

#include <boost/ut.hpp>

#include <deque>
#include <stdexcept>

using namespace boost::ut;
using namespace ocse::literals;

namespace oa = ocse::actions;
namespace oe = ocse::entities;

namespace {
    detail::test skip_if(const detail::test& _it, bool skipped = false)
    {
        return skipped ? skip / _it : _it;
    }
} // anonymous namespace

int main() {
    std::deque<oe::Player> players;
    std::deque<oe::Planet> planets;

    oe::Player& player_1 = players.emplace_back();
    oe::Planet planet = oa::create_planet({1_p_gal, 1_p_sys, 1_p_pos});

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
        oe::Player& player_2 = players.emplace_back();
        oa::bind_planet_to_player(player_1, planet);

        expect(throws<std::runtime_error>([&] {
            oa::bind_planet_to_player(player_2, planet);
        })) << "throws runtime_error";
        expect(player_2.planets.size() == 0_i);
    };

    bool passed = true;

    "run UDL"_test = [&] {
        passed &= expect(42_i == 423);
        passed &= expect(43_i == 43);
    };

    skip_if("don't runololo UDL"_test, !passed) = [=] mutable {
        expect(44_i == 44) << "44";
    };
}
