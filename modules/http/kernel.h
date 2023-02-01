#ifndef OCSE_HTTP_KERNEL_H
#define OCSE_HTTP_KERNEL_H

#include "lithium_http_server.hh"

namespace ocse::http
{
    void serve_app(li::http_api api);
    li::http_api init_router();
}

#endif //OCSE_HTTP_KERNEL_H
