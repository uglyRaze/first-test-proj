#pragma once

#include <string>
#include "json.hpp"


struct task {
    int id;
    bool done;
    std::string title;

    task(int id_, const std::string& title_, bool done_ = false)
        : id(id_), title(title_), done(done_) {
    }
    task() = default;
};


void to_json(nlohmann::json& j, const task& t);
void from_json(const nlohmann::json& j, task& t);
