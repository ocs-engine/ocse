#ifndef OCSE_ACTIONS_H
#define OCSE_ACTIONS_H

#include "entities/Planet.h"
#include "entities/User.h"

namespace oe = ocse::entities;

namespace ocse::actions {
    void bind_planet_to_user(oe::User& user, oe::Planet& planet);
}

#endif //OCSE_ACTIONS_H
