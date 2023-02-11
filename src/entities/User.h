#ifndef OCSE_USER_H
#define OCSE_USER_H

#include <string>

namespace ocse::entities
{
    class Planet;
    class User
    {
    public:
        std::string name;
        std::vector<Planet*> planets;
    };
}

#endif //OCSE_USER_H
