#include <iostream>
#include "StudySession.h"


StudySession::StudySession(string course, string date, string notes, int duration){
    this->course = course;
    this->date = date;
    this->notes = notes;
    this->duration = duration;
}

void StudySession::display(){
    cout << "This is information about the study session" << endl;
    cout << "Course: " << course << endl;
    cout << "Date: " << date << endl;
    cout << "Duration: " << duration << endl;
    cout << "Notes: " << notes << endl;
}

string StudySession::getCourse() {
    return course;
}

string StudySession::getDate() {
    return date;
}

string StudySession::getNotes() {
    return notes;
}

int StudySession::getDuration() {
    return duration;
}
