#include "task.hpp"

void to_json(nlohmann::json& j, const task& t) {
    j = nlohmann::json{
        {"id", t.id},
        {"title", t.title},
        {"done", t.done}
    };
}
void from_json(const nlohmann::json& j, task& t) {
    j.at("id").get_to(t.id);
    j.at("title").get_to(t.title);
    j.at("done").get_to(t.done);
}
