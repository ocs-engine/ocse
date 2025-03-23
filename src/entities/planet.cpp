#include "entities/planet.h"

namespace ocse::entities
{
    Planet::Planet(
        PlanetCoordinates coordinates,
        PlanetFieldCount field_count,
        int temperature,
        const std::string& name
    )
    : name{name},
      coordinates{coordinates},
      field_count{field_count},
      temperature{temperature}
    {}
}
