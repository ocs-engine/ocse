#ifndef OCSE_HTTP_ROUTES_ENTRYPOINT_H
#define OCSE_HTTP_ROUTES_ENTRYPOINT_H

#include "lithium_http_server.hh"

namespace ocse::http::routes {
    void register_routes(li::http_api& api);
}


#endif //OCSE_HTTP_ROUTES_ENTRYPOINT_H
