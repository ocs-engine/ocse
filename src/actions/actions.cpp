#include "actions.h"

#include <stdexcept>

namespace ocse::actions {
    void bind_planet_to_user(oe::User& user, oe::Planet& planet)
    {
        if (planet.user == &user) {
            throw std::logic_error{"This planet already owned this user"};
        }
        if (planet.user) {
            throw std::runtime_error{"This planet already owned another user"};
        }
        planet.user = &user;
        user.planets.push_back(&planet);
    }
}
