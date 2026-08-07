#ifndef TASK_LIST_HPP
#define TASK_LIST_HPP

#include <string>

struct Task {
    std::string description;
    int priority;
    bool completed;
};

struct TaskNode {
    Task data;
    TaskNode* next;
};

bool isValidPriority(int priority);
Task createTask(std::string description, int priority);

void insertFront(TaskNode*& head, Task task);
int countTasks(const TaskNode* head);
TaskNode* findTask(TaskNode* head, std::string description);
bool markTaskComplete(TaskNode* head, std::string description);
int removeCompletedTasks(TaskNode*& head);
void clearTasks(TaskNode*& head);

void printTask(const Task& task);
void printTasks(const TaskNode* head);

#endif
