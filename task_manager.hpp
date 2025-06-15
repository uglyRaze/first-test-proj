#pragma once
#include <vector>
#include <string>
#include "task.hpp"

class TaskManager {
    
public:
    void add_task(const std::string& title);
    void mark_done(int id);
    void delete_task(int id);
    void list_tasks() const;
    void save(const std::string& filename) const;
    void load(const std::string& filename);

private:
    std::vector<task> tasks;
    int next_id = 1;

};
