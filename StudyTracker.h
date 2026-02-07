#ifndef STUDYTRACKER_H
#define STUDYTRACKER_H
#include <iostream>
#include <vector>
#include "Task.h"
#include "StudySession.h"

class StudyTracker{
    private:
    vector<Task*> tasks;
    vector<StudySession*> sessions;

    public:
    ~StudyTracker();
    void addTask();
    void displayAllTasks();
    void displayByPriority();
    void displayByCourse(string course);
    void markTaskComplete();
    void addStudySession();
    void displayStudySummary();
    void saveToFile(ofstream& out);
    void loadFromFile(string filename);
    vector<Task*> getTasks();
    vector<StudySession*> getSessions();

};

#endif