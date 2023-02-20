#include "kernel.h"
#include "routes/entrypoint.h"

#include <utility>

int main()
{
    auto api{ocse::http::init_router()};
    ocse::http::routes::register_routes(api);
    ocse::http::serve_app(std::move(api));

    return 0;
}
