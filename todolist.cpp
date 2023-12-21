#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 10;
const int TASK_LENGTH = 50;

string tasks[MAX_TASKS];
int completed[MAX_TASKS] = {0};
int taskCount = 0;

void addTask(const string &newTask) {
    if (taskCount < MAX_TASKS) {
        tasks[taskCount] = newTask;
        taskCount++;
        cout << "Task added successfully." << endl;
    } else {
        cout << "Task list is full." << endl;
    }
}

void viewTasks() {
    if (taskCount == 0) {
        cout << "No tasks in the list." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (int i = 0; i < taskCount; i++) {
            cout << i + 1 << ". " << tasks[i] << " - " << (completed[i] ? "Completed" : "Pending") << endl;
        }
    }
}

void markCompleted(int taskNumber) {
    if (taskNumber > 0 && taskNumber <= taskCount) {
        completed[taskNumber - 1] = 1;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void removeTask(int taskNumber) {
    if (taskNumber > 0 && taskNumber <= taskCount) {
        for (int i = taskNumber - 1; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
            completed[i] = completed[i + 1];
        }
        taskCount--;
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    int choice;
    string newTask;
    int taskNumber;

    do {
        cout << "\nSimple To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from input buffer

        switch (choice) {
            case 1:
                cout << "Enter task to add: ";
                getline(cin, newTask);
                addTask(newTask);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                markCompleted(taskNumber);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                removeTask(taskNumber);
                break;
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);

    return 0;
}
