#ifndef OCSE_ENTITIES_PLANET_H
#define OCSE_ENTITIES_PLANET_H

#include <string>

namespace ocse::entities
{
    struct PlanetFieldCount
    {
        int busy;
        int total;
    };

    struct PlanetCoordinates
    {
        enum struct Galaxy {};
        enum struct System {};
        enum struct Position {};

        Galaxy galaxy;
        System system;
        Position position;
    };

    class Player;
    class Planet
    {
    public:
        std::string name;
        PlanetCoordinates coordinates;
        PlanetFieldCount field_count;
        int temperature;
        const Player* player{};

    public:
        Planet(
            PlanetCoordinates coordinates,
            PlanetFieldCount field_count,
            int temperature,
            const std::string& name = ""
        );
    };
}

namespace ocse::literals
{
    using PlanetGalaxy = ocse::entities::PlanetCoordinates::Galaxy;
    using PlanetSystem = ocse::entities::PlanetCoordinates::System;
    using PlanetPosition = ocse::entities::PlanetCoordinates::Position;

    constexpr PlanetGalaxy operator""_p_gal(
        unsigned long long galaxy_number
    ) {
        return PlanetGalaxy{galaxy_number};
    }

    constexpr PlanetSystem operator""_p_sys(
        unsigned long long system_number
    ) {
        return PlanetSystem{system_number};
    }

    constexpr PlanetPosition operator""_p_pos(
        unsigned long long position_number
    ) {
        return PlanetPosition{position_number};
    }
}

#endif //OCSE_ENTITIES_PLANET_H
