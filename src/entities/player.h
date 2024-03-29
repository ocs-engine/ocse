#ifndef OCSE_ENTITIES_PLAYER_H
#define OCSE_ENTITIES_PLAYER_H

#include <string>
#include <vector>

namespace ocse::entities
{
    class Planet;
    class Player
    {
    public:
        std::string name;
        std::vector<Planet*> planets;
    };
}

#endif //OCSE_ENTITIES_PLAYER_H
