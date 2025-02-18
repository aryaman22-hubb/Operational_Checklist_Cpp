#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Task {
    string description;
    string deadline;
    bool completed;
    int priority; // 1 - High, 2 - Medium, 3 - Low
    bool recurring; // true if task is recurring

    Task(string desc, string dl, int prio, bool recur)
        : description(desc), deadline(dl), completed(false), priority(prio), recurring(recur) {}
};

class ToDoApp {
private:
    vector<Task> tasks;
    const string filename = "tasks.txt";

    // Helper function to parse the date (YYYY-MM-DD)
    tm parseDate(const string& dateStr) {
        tm date = {};
        stringstream ss(dateStr);
        ss >> get_time(&date, "%Y-%m-%d");
        return date;
    }

    // Helper function to format tm to string (YYYY-MM-DD)
    string formatDate(const tm& date) {
        stringstream ss;
        ss << put_time(&date, "%Y-%m-%d");
        return ss.str();
    }

    // Helper function to check if a task's deadline is within 2 days
    bool isDeadlineApproaching(const string& deadline) {
        time_t now = time(0);
        tm* current_time = localtime(&now);
        tm task_time = parseDate(deadline);

        // Add 2 days to current time for comparison
        time_t now_plus_two_days = now + (2 * 24 * 60 * 60);
        tm* future_time = localtime(&now_plus_two_days);

        return (mktime(&task_time) <= mktime(future_time) && mktime(&task_time) >= now);
    }

    // Function to save tasks to file
    void saveTasks() {
        ofstream file(filename);
        if (file.is_open()) {
            for (auto& task : tasks) {
                file << task.description << "|" << task.deadline << "|" 
                     << task.completed << "|" << task.priority << "|" << task.recurring << endl;
            }
        }
    }

    // Function to load tasks from file
    void loadTasks() {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string desc, dl;
                int prio;
                bool completed, recurring;
                getline(ss, desc, '|');
                getline(ss, dl, '|');
                ss >> completed;
                ss >> prio;
                ss >> recurring;

                tasks.push_back(Task(desc, dl, prio, recurring));
                tasks.back().completed = completed;
            }
        }
    }

public:
    ToDoApp() {
        loadTasks();
    }

    // Add a task
    void addTask(string description, string deadline, int priority, bool recurring) {
        tasks.push_back(Task(description, deadline, priority, recurring));
        saveTasks();
    }

    // Mark a task as completed
    void markCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            saveTasks();
        } else {
            cout << "Invalid task index.\n";
        }
    }

    // Display all tasks
    void displayTasks() {
        cout << "\n📝 To-Do List\n";
        for (int i = 0; i < tasks.size(); ++i) {
            string status = tasks[i].completed ? "✅ Completed" : "❌ Pending";
            string priority = tasks[i].priority == 1 ? "High" : tasks[i].priority == 2 ? "Medium" : "Low";
            cout << i + 1 << ". " << tasks[i].description << "\n"
                 << "   Deadline: " << tasks[i].deadline << " | Priority: " << priority << " | Status: " << status << endl;

            // Notify if the deadline is approaching
            if (!tasks[i].completed && isDeadlineApproaching(tasks[i].deadline)) {
                cout << "   🚨 Deadline is approaching!\n";
            }
        }
    }

    // Sort tasks by deadline
    void sortTasksByDeadline() {
        sort(tasks.begin(), tasks.end(), [this](const Task& a, const Task& b) {
            tm dateA = parseDate(a.deadline);
            tm dateB = parseDate(b.deadline);
            return mktime(&dateA) < mktime(&dateB);
        });
        saveTasks();
    }

    // Remove completed tasks (optional feature)
    void removeCompletedTasks() {
        tasks.erase(remove_if(tasks.begin(), tasks.end(), [](const Task& task) {
            return task.completed;
        }), tasks.end());
        saveTasks();
    }

    // View recurring tasks
    void viewRecurringTasks() {
        cout << "\n🔁 Recurring Tasks\n";
        for (const auto& task : tasks) {
            if (task.recurring) {
                cout << "- " << task.description << " | Deadline: " << task.deadline << endl;
            }
        }
    }
};

int main() {
    ToDoApp app;

    while (true) {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Sort Tasks by Deadline\n";
        cout << "5. Remove Completed Tasks\n";
        cout << "6. View Recurring Tasks\n";
        cout << "7. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cin.ignore();
            string description, deadline;
            int priority;
            bool recurring;
            cout << "Enter task description: ";
            getline(cin, description);
            cout << "Enter deadline (YYYY-MM-DD): ";
            getline(cin, deadline);
            cout << "Enter priority (1-High, 2-Medium, 3-Low): ";
            cin >> priority;
            cout << "Is this task recurring? (0-No, 1-Yes): ";
            cin >> recurring;
            app.addTask(description, deadline, priority, recurring);
        } else if (choice == 2) {
            app.displayTasks();
        } else if (choice == 3) {
            int index;
            cout << "Enter task number to mark as completed: ";
            cin >> index;
            app.markCompleted(index - 1);
        } else if (choice == 4) {
            app.sortTasksByDeadline();
        } else if (choice == 5) {
            app.removeCompletedTasks();
        } else if (choice == 6) {
            app.viewRecurringTasks();
        } else if (choice == 7) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
