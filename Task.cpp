#include <iostream>
#include "Task.h"

Task::Task(string title, string type, string course, string dueDate, int priority, bool isCompleted){
    this->title = title;
    this->type = type;
    this->course = course;
    this->dueDate = dueDate;
    this->priority = priority;
    this->isCompleted = isCompleted;
}

void Task:: markAsComplete(){
    isCompleted = true;
}

void Task:: display(){
    cout << "This is information about the task:" << endl;
    cout << "Title: " <<  title << endl;
    cout << "Type: " << type << endl;
    cout << "Course: " << course << endl;
    cout << "Due Date: " << dueDate << endl;
    cout << "Priority: " << priority << endl;
    cout << "isCompleted? " << isCompleted << endl;
}

string Task::getCourse(){
    return course;
}
string Task::getTitle() {
    return title;
}

string Task::getType() {
    return type;
}

string Task::getDueDate() {
    return dueDate;
}

int Task::getPriority() {
    return priority;
}

bool Task::getIsCompleted() {
    return isCompleted;
}
