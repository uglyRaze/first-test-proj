#include <iostream>
#include "task_manager.hpp"
#include <fstream> 
#include "json.hpp"
using json = nlohmann::json;

void TaskManager::add_task(const std::string& title) {
    tasks.push_back(task(next_id++, title));
}

void TaskManager::mark_done(int id) {
    for (auto& i : tasks) {
        if (i.id == id) {
            i.done = true;
            break;
        }
    }
}

void TaskManager::delete_task(int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            break;
        }
    }
}

void TaskManager::list_tasks() const {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        std::cout << "[" << it->id << "] "
            << "(" << (it->done ? "+" : "X") << ") "
            << it->title << std::endl;
    }
}

void TaskManager::save(const std::string& filename) const {
    json j = tasks;
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    file << j.dump(4);
}

void TaskManager::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }
    json j;
    file >> j;
    tasks = j.get<std::vector<task>>();

    int max_id = 0;
    for (const auto& t : tasks) {
        if (t.id > max_id)
            max_id = t.id;
    }
    next_id = max_id + 1;
}
