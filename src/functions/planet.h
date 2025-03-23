#ifndef OCSE_FUNCTIONS_PLANET_H
#define OCSE_FUNCTIONS_PLANET_H

#include "entities/planet.h"

namespace oe = ocse::entities;

namespace ocse::functions {
    struct FieldRange {
        int begin;
        int end;
    };

    FieldRange get_max_field_range_by_position(
        oe::PlanetCoordinates::Position planet_position
    );
    oe::PlanetFieldCount get_initial_field_count(FieldRange max_field_range);
}

#endif //OCSE_FUNCTIONS_PLANET_H
