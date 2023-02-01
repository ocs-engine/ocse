#include "Home.h"

#include <ctime>

namespace bj = boost::json;

namespace ocse::http::controllers::home {
    void tag_invoke(
        const bj::value_from_tag&,
        bj::value& jv,
        const IndexResponse& ir
    ) {
        jv = {
            {"title",   ir.title},
            {"message", ir.message},
            {"time",    ir.time}
        };
    }

    IndexResponse tag_invoke(
        const bj::value_to_tag<IndexResponse>&,
        const bj::value& jv
    ) {
        auto jo = jv.as_object();
        return {
            jo["title"].as_string().c_str(),
            jo["message"].as_string().c_str(),
            jo["time"].to_number<long>(),
        };
    }

    void index(li::http_request&, li::http_response& li_response) {
        IndexResponse response_object{
            "OCSE PoC — Home Page",
            "Hello OCSE!",
            time(nullptr)
        };

        li_response.set_header("Content-Type", "application/json");
        li_response.write(
            bj::serialize(bj::value_from(response_object))
        );
    }
}
