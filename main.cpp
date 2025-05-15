// todo_list_app.cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isDone;
};

class ToDoList {
private:
    vector<Task> tasks;
    const string filename = "tasks.txt";

public:
    ToDoList() {
        loadFromFile();
    }

    void addTask(const string &desc) {
        tasks.push_back({desc, false});
        cout << "Task added successfully.\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list.\n";
            return;
        }
        cout << "\n--- TO-DO LIST ---\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". [" << (tasks[i].isDone ? 'x' : ' ') << "] " << tasks[i].description << "\n";
        }
    }

    void markTaskDone(int index) {
        if (index <= 0 || index > (int)tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }
        tasks[index - 1].isDone = true;
        cout << "Task marked as done.\n";
    }

    void deleteTask(int index) {
        if (index <= 0 || index > (int)tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully.\n";
    }

    void saveToFile() {
        ofstream file(filename);
        for (const auto &task : tasks) {
            file << task.isDone << '|' << task.description << '\n';
        }
        file.close();
    }

    void loadFromFile() {
        ifstream file(filename);
        if (!file) return;
        tasks.clear();
        string line;
        while (getline(file, line)) {
            size_t sep = line.find('|');
            if (sep != string::npos) {
                bool done = line.substr(0, sep) == "1";
                string desc = line.substr(sep + 1);
                tasks.push_back({desc, done});
            }
        }
        file.close();
    }
};

int main() {
    ToDoList todo;
    int choice;
    string desc;
    int index;

    do {
        cout << "\n\n1. Add Task\n2. View Tasks\n3. Mark Task as Done\n4. Delete Task\n5. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // clear buffer

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, desc);
                todo.addTask(desc);
                break;
            case 2:
                todo.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as done: ";
                cin >> index;
                todo.markTaskDone(index);
                break;
            case 4:
                cout << "Enter task number to delete: ";
                cin >> index;
                todo.deleteTask(index);
                break;
            case 5:
                todo.saveToFile();
                cout << "Exiting and saving tasks.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
