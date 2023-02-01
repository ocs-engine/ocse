#ifndef OCSE_PLANET_H
#define OCSE_PLANET_H

#include <string>

namespace ocse::entities
{
    class User;
    class Planet
    {
    public:
        std::string name;
        const User* user;
    };
}

#endif //OCSE_PLANET_H
