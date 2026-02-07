#ifndef STUDYSESSION_H
#define STUDYSESSION_H
#include <iostream>

using namespace std;

class StudySession{
    private:
    string course;
    string date;
    string notes;
    int duration;

    public:
    StudySession(string course, string date, string notes, int duration);
    void display();

    // getters 

    string getCourse();
    string getDate();
    string getNotes();
    int getDuration();
};

#endif