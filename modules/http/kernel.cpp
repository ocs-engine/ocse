#include "kernel.h"

#include "boost/json/src.hpp"

namespace ocse::http
{
    void serve_app(li::http_api api)
    {
        li::http_serve(std::move(api), 80, s::nthreads = 1);
    }

    li::http_api init_router()
    {
        return li::http_api{};
    }
}
