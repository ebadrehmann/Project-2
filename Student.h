#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "StudyTracker.h"
using namespace std;



class Student{
    private:
    string name;
    string studentID;
    string major;
    StudyTracker tracker;

    public:
    Student();
    void displayProfile();
    void saveStudentData(string filename);
    void loadStudentData(string filename);
    void startSession();

};

#endif