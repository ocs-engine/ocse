#include "functions/planet.h"

#include <array>
#include <stdexcept>
#include <random>
#include <utility>

namespace ocse::functions {
    FieldRange get_max_field_range_by_position(
        oe::PlanetCoordinates::Position planet_position
    ) {
        static constexpr const std::array ranges{
            FieldRange{95, 108},
            FieldRange{97, 110},
            FieldRange{98, 137},
            FieldRange{100, 150},
            FieldRange{105, 163},

            FieldRange{123, 203},
            FieldRange{148, 210},
            FieldRange{148, 226},
            FieldRange{141, 273},
            FieldRange{169, 246},

            FieldRange{164, 240},
            FieldRange{161, 238},
            FieldRange{154, 224},
            FieldRange{148, 204},
            FieldRange{136, 171},

            FieldRange{109, 121},
            FieldRange{81, 93},
            FieldRange{65, 74},
            FieldRange{65, 74},
            FieldRange{65, 74},
        };

        int position_number = std::to_underlying(planet_position);

        if (
            position_number > std::ssize(ranges) ||
            position_number < 1
        ) {
            throw std::out_of_range{"Planet position out of the range"};
        }

        return ranges[static_cast<size_t>(position_number-1)];
    }

    oe::PlanetFieldCount get_initial_field_count(FieldRange max_field_range)
    {
        std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<> distrib(
            max_field_range.begin,
            max_field_range.end
        );
        int result = distrib(gen);

        return oe::PlanetFieldCount{0, result};
    }
}
