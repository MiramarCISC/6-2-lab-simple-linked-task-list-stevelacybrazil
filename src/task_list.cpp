#include "task_list.hpp"
#include <iostream>
#include <string>

using namespace std;

bool isValidPriority(int priority) {
    return priority >= 1 && priority <= 5;
}

Task createTask(string description, int priority) {
    Task task;

    task.description = description;

    if (isValidPriority(priority)) {
        task.priority = priority;
    } else {
        task.priority = 1;
    }
    
    task.completed = false;
    
    return task; 
}

void insertFront(TaskNode*& head, Task task) {
    TaskNode* newNode = new TaskNode;

    newNode->data = task;
    newNode->next = head;

    head = newNode;
}

int countTasks(const TaskNode* head) {
    int count = 0;

    const TaskNode* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }
    
    return count;
}

TaskNode* findTask(TaskNode* head, string description) {
    TaskNode* current = head;

    while (current != nullptr) {
        if (current->data.description == description) {
            return current;
        }

        current = current->next;
    }

    return nullptr;
}

bool markTaskComplete(TaskNode* head, string description) {
    TaskNode* taskNode = findTask(head, description);

    if (taskNode == nullptr) {
        return false;
    }

    taskNode->data.completed = true;

    return true;
}

int removeCompletedTasks(TaskNode*& head) {
    int removed = 0;

    while (head != nullptr && head->data.completed) {
        TaskNode* temp = head;
        head = head->next;

        delete temp;
        removed++;
    }

    TaskNode* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->next->data.completed) {
            TaskNode* temp = current->next;

            current->next = temp->next;

            delete temp;
            removed++;
        } else {
            current = current->next;
        }
    }

    return removed;
}

void clearTasks(TaskNode*& head) {
    while (head != nullptr) {
        TaskNode* temp = head;

        head = head->next;

        delete temp;
    }

    head = nullptr;
}

void printTask(const Task& task) {
    cout << task.description
         << " | Priority: "
         << task.priority
         << " | ";

    if (task.completed) {
        cout << "Completed";
    } else {
        cout << "Incomplete";
    }

    cout << endl;
}

void printTasks(const TaskNode* head) {
    const TaskNode* current = head;

    while (current != nullptr) {
        printTask(current->data);
        current = current->next;
    }
}

void insertFront(TaskNode*& head, Task task) {
    TaskNode* newNode = new TaskNode

    newNode->data = task;
    newNode->next = head;

    head = newNode;
}
