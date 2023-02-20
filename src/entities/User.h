#ifndef OCSE_USER_H
#define OCSE_USER_H

#include <string>
#include <vector>

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
