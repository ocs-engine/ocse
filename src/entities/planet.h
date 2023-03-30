#ifndef OCSE_ENTITIES_PLANET_H
#define OCSE_ENTITIES_PLANET_H

#include <string>

namespace ocse::entities
{
    class Player;
    class Planet
    {
    public:
        std::string name;
        const Player* player;
    };
}

#endif //OCSE_ENTITIES_PLANET_H
