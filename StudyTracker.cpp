#include <iostream>
#include <fstream>
#include <map>
#include "StudyTracker.h"

StudyTracker:: ~StudyTracker(){
    for (Task* t: tasks){
        delete t;
    }
    for (StudySession* s: sessions){
        delete s;
    }
}
void StudyTracker::addTask(){
    string title, type, course, dueDate;
    int priority;
    string check;
    bool isCompleted;
    cout << "What is the name of the task?" << endl;
    getline(cin, title);
    cout << "What is the type of task?  (Assignment, Exam, Reading, Project)" << endl;
    getline(cin, type);
    cout << "What is the course name?  (e.g., CS101, Math200)" << endl;
    getline(cin, course);
    cout << "What is the deadline for the task?" << endl;
    getline(cin, dueDate);
    cout << "What is the priority level for the task? (1=High, 2=Medium, 3=Low)" << endl;
    cin >> priority;
    cout << "Has the task been completed? (write Yes / No)" << endl;
    cin >> check;
    cin.ignore(); 
    if (check == "Yes" || check == "yes"){
        isCompleted = true;
    }
    else{
        isCompleted = false;
    }
    
    tasks.push_back(new Task(title, type, course, dueDate, priority, isCompleted));
}
void StudyTracker::displayAllTasks(){
    cout << "Displaying all tasks:" << endl;
    for (Task* t: tasks){
        t->display();
    }
}
void StudyTracker::displayByCourse(string course){
    cout << "Printing the tasks by Courses named: " << course << ":" << endl;
    for (Task* t: tasks){
        if (t->getCourse() == course){
            t->display();
        }
    }
}

//unsure
//skip implementation
void StudyTracker::displayByPriority(){
}



void StudyTracker::markTaskComplete(){
    cout << "Please select which task you would like to mark as complete: " << endl;
    for (Task* t: tasks){
        string q;
        t->display();
        cout << "Mark this as complete? (Yes/No): ";
        getline(cin, q);
        if (q == "yes" || q == "Yes"){
            t->markAsComplete();
        }
    }
}

void StudyTracker::addStudySession(){
    string course, date, notes;
    int duration;

    cout << "Please enter the course studied: " << endl;
    getline(cin, course);
    cout << "Please enter the date of the study session" << endl;
    getline(cin, date);
    cout << "Please enter brief notes about the study session" << endl;
    getline(cin, notes);
    cout << "Please enter the duration of the study session" << endl;
    cin >> duration;
    cin.ignore();

    sessions.push_back(new StudySession(course, date, notes, duration));
}
//unsure
// skip implementation

void StudyTracker::displayStudySummary(){

}

// unsure
void StudyTracker::saveToFile(ofstream& out){
    if (out.is_open())
    {
        out << tasks.size() << endl;

        for (Task* t: tasks){
            out << t->getTitle() << endl;
            out << t->getType() << endl;
            out << t->getCourse() << endl;
            out << t->getDueDate() << endl;
            out << t->getPriority() << endl; // int
            out << t->getIsCompleted() << endl; // bool
        }

        out << sessions.size() << endl;

        for (StudySession* s: sessions){
            out << s->getCourse() << endl;
            out << s->getDate() << endl;
            out << s->getNotes() << endl;
            out << s->getDuration() << endl;
        }
    }
}

// unsure cins could be wrong
void StudyTracker::loadFromFile(string filename){
    tasks.clear();
    sessions.clear();
    ifstream inp(filename);
    if (inp.is_open())
    {
        int size;

        inp >> size;
        inp.ignore();

        for (int i = 0; i < size; i++){
            string title, type, course, dueDate;
            int priority;
            bool isCompleted;
            getline(inp, title);
            getline(inp, type);
            getline(inp, course);
            getline(inp, dueDate);
            inp >> priority;
            inp >> isCompleted; // could be wrong to use cin here
            inp.ignore();
            tasks.push_back(new Task(title, type, course, dueDate, priority, isCompleted));
        }
        inp >> size;
        inp.ignore();

        for (int i = 0; i < size; i++){
            string course, date, notes;
            int duration;
            getline(inp, course);
            getline(inp, date);
            getline(inp, notes);
            inp >> duration;
            inp.ignore(); // safeguard

            sessions.push_back(new StudySession(course, date, notes, duration));
        }
        inp.close();
    }

}

vector<Task*> StudyTracker::getTasks(){
    return tasks;
}
vector<StudySession*> StudyTracker::getSessions(){
    return sessions;
}

// unsure about anything dealing with filestreams, esp because I errored out the last project due to file crap, I didn't even see the output file n shit. I'm skeptical over whether the person writing the instructions were able to do it correctly and if filename is correct in this scase.