#include <iostream>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

Task tasks[100];
int taskCount = 0;

void addTask() {
    if (taskCount >= 100) {
        cout << "Task list is full.\n";
        return;
    }
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, tasks[taskCount].description);
    tasks[taskCount].completed = false;
    taskCount++;
    cout << "Task added successfully.\n";
}

void viewTasks() {
    if (taskCount == 0) {
        cout << "No tasks in the list.\n";
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". " << tasks[i].description 
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted() {
    int index;
    viewTasks();
    if (taskCount == 0) return;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    if (index > 0 && index <= taskCount) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask() {
    int index;
    viewTasks();
    if (taskCount == 0) return;
    cout << "Enter task number to remove: ";
    cin >> index;
    if (index > 0 && index <= taskCount) {
        for (int i = index - 1; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
    return 0;
}
