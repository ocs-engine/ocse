#ifndef OCSE_HTTP_CONTROLLERS_HOME_H
#define OCSE_HTTP_CONTROLLERS_HOME_H

#include "boost/json.hpp"
#include "lithium_http_server.hh"

namespace ocse::http::controllers::home {
    struct IndexResponse {
        const std::string title;
        std::string message;
        long time;
    };

    void tag_invoke(
        const boost::json::value_from_tag&,
        boost::json::value& jv,
        const IndexResponse& ir
    );

    IndexResponse tag_invoke(
        const boost::json::value_to_tag<IndexResponse>&,
        const boost::json::value& jv
    );

    void index(
        li::http_request& li_request,
        li::http_response& li_response
    );
}

#endif //OCSE_HTTP_CONTROLLERS_HOME_H
