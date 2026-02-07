#include <iostream>
#ifndef TASK_H
#define TASK_H

using namespace std;

class Task{
    private:
    string title;
    string type;
    string course;
    string dueDate;
    int priority;
    bool isCompleted;

    public:

    Task(string title, string type, string course, string dueDate, int priority, bool isCompleted);
    void markAsComplete();
    void display();

    // getters 
    string getTitle();
    string getType();
    string getCourse();
    string getDueDate();
    int getPriority();
    bool getIsCompleted();
};
#endif