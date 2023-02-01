#include "entrypoint.h"
#include "controllers/Home.h"

namespace ohc = ocse::http::controllers;

namespace ocse::http::routes {
    void register_routes(li::http_api& api)
    {
        api.get("/") = ohc::home::index;
    }
}
