#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Todo_Task_List {
    string Description;
    bool Completed;
};

void Add_Todo_Task(vector<Todo_Task_List>& todo_List, const string& task_Description) {
    Todo_Task_List newTask;
    newTask.Description = task_Description;
    newTask.Completed = false;
    todo_List.push_back(newTask);
    cout << "Task added: " << task_Description << endl;
}

void View_Todo_Tasks(const vector<Todo_Task_List>& todo_List) {
    if (todo_List.empty()) {
        cout << "No tasks to display." << endl;
    } else {
        cout << "Todo Tasks:" << endl;
        for (size_t i = 0; i < todo_List.size(); i++) {
            const Todo_Task_List& task = todo_List[i];
            cout << "[" << (task.Completed ? "X" : " ") << "] " << i + 1 << ". " << task.Description << endl;
        }
    }
}

void Mark_Task_Completed(vector<Todo_Task_List>& todo_List, int task_Index) {
    if (task_Index >= 1 && task_Index <= todo_List.size()) {
        todo_List[task_Index - 1].Completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void Remove_Todo_Task(vector<Todo_Task_List>& todo_List, int task_Index) {
    if (task_Index >= 1 && task_Index <= todo_List.size()) {
        todo_List.erase(todo_List.begin() + task_Index - 1);
        cout << "Task removed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main(int argc, char** argv) {
    vector<Todo_Task_List> todo_List;

    while (true) {
        cout << "************* TO-DO Task LIST MANAGER ************* " << endl;
        cout << "1. Add Tasks" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Tasks" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string task_Description;
            cout << "Enter task description: ";
            cin.ignore(); 
            getline(cin, task_Description);
            Add_Todo_Task(todo_List, task_Description);
        } else if (choice == 2) {
            View_Todo_Tasks(todo_List);
        } else if (choice == 3) {
            int task_Index;
            cout << "Enter the task number to mark as completed: ";
            cin >> task_Index;
            Mark_Task_Completed(todo_List, task_Index);
        } else if (choice == 4) {
            int task_Index;
            cout << "Enter the task number to remove: ";
            cin >> task_Index;
            Remove_Todo_Task(todo_List, task_Index);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
