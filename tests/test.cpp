#include "actions/actions.h"
#include "entities/Planet.h"
#include "entities/User.h"

#include "boost/ut.hpp"

#include <deque>
#include <stdexcept>

using namespace boost::ut;

namespace oa = ocse::actions;
namespace oe = ocse::entities;

int main() {
    std::deque<oe::User> users;
    std::deque<oe::Planet> planets;

    auto& user_1 = users.emplace_back();
    auto& user_2 = users.emplace_back();
    auto& planet = planets.emplace_back();

    "bind new planet to user_1"_test = [&] {
        oa::bind_planet_to_user(user_1, planet);
        expect(that % planet.user == &user_1);
        expect(user_1.planets.size() == 1_i);
    };

    "trying bind planet to user_1 twice"_test = [&] {
        expect(throws<std::logic_error>([&] {
            oa::bind_planet_to_user(user_1, planet);
        })) << "throws logic_error";
        expect(user_1.planets.size() == 1_i);
    };

    "trying bind planet to user_2"_test = [&] {
        expect(throws<std::runtime_error>([&] {
            oa::bind_planet_to_user(user_2, planet);
        })) << "throws runtime_error";
        expect(user_2.planets.size() == 0_i);
    };
}
