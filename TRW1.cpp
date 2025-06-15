#include "task_manager.hpp"
#include <iostream>
#include <cstdlib>  
using namespace std;


void clear_console() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    TaskManager m;
    bool work = true;
    int num;

    while (work) {
        clear_console();  

        cout << "Hello, welcome to Task Manager!\n\n";

        cout << "\nMenu:\n"
            << "1 - List tasks\n"
            << "2 - Add task\n"
            << "3 - Mark task done\n"
            << "4 - Delete task\n"
            << "5 - Save tasks\n"
            << "6 - Load tasks\n"
            << "0 - Exit\n"
            << "> ";

        cin >> num;

        if (num == 0) {
            work = false;
            continue;
        }

        switch (num) {
        case 1: {
            m.list_tasks();
            break;
        }

        case 2: {
            cin.ignore(); 
            string t;
            cout << "Enter task title: ";
            getline(cin, t);
            m.add_task(t);
            break;
        }
        case 3: {
            int id;
            cout << "ID of completed task: ";
            cin >> id;
            m.mark_done(id);
            break;
        }
        case 4: {
            int id;
            cout << "ID of task to delete: ";
            cin >> id;
            m.delete_task(id);
            break;
        }
        case 5:
            m.save("tasks.json");
            cout << "Tasks saved.\n";
            break;
        case 6:
            m.load("tasks.json");
            cout << "Tasks loaded.\n";
            break;
        default:
            cout << "Unknown command.\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
}
