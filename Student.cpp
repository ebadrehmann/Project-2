#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

Student::Student(){
    string name, studentID, major;

    cout << "What is the student's name?" << endl;
    getline(cin, name);
    cout << "What is the student's major" << endl;
    getline(cin, major);
    cout << "What is the student's ID number?" << endl;
    getline(cin, studentID);

    this->name = name;
    this->studentID = studentID;
    this->major = major;
}

void Student::displayProfile(){
    cout << "This is " << name << "'s Profile:" << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Major: " << major << endl;
}

void Student::saveStudentData(string filename){
    ofstream out(filename); // make this append?

    if (out.is_open()){
        out << name << endl;
        out << studentID << endl;
        out << major << endl;
        tracker.saveToFile(out);
        out.close();
    }
}

void Student::loadStudentData(string filename){
    ifstream ifs(filename);


    if (ifs.is_open()){
        string name, id, major;
        getline(ifs, name);
        getline(ifs, id);
        getline(ifs, major);
        this->name = name;
        this->studentID = id;
        this->major = major;

        tracker.loadFromFile(filename);
        ifs.close();
    }
}

void Student::startSession() {
    int choice;

    do {
        cout << "\n===========================\n";
        cout << "TASK MANAGER\n";
        cout << "===========================\n";
        cout << "1. Add Task\n";
        cout << "2. View All Tasks\n";
        cout << "3. View by Priority (NOT WORKING YET) \n";
        cout << "4. View by Course\n";
        cout << "5. Mark Task Complete\n";
        cout << "6. Log Study Session\n";
        cout << "7. View Study Summary (NOT WORKING YET)\n";
        cout << "8. Save\n";
        cout << "9. Load\n";
        cout << "10. View Student Profile\n";
        cout << "11. Return to Main Menu\n";
        cout << "Choice: ";

        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            tracker.addTask();
        }
        else if (choice == 2) {
            tracker.displayAllTasks();
        }
        else if (choice == 3) {
            tracker.displayByPriority();
        }
        else if (choice == 4) {
            string course;
            cout << "Enter course name: ";
            getline(cin, course);
            tracker.displayByCourse(course);
        }
        else if (choice == 5) {
            tracker.markTaskComplete();
        }
        else if (choice == 6) {
            tracker.addStudySession();
        }
        else if (choice == 7) {
            tracker.displayStudySummary();
        }
        else if (choice == 8) {
            string filename;
            cout << "Enter filename to save: ";
            getline(cin, filename);
            saveStudentData(filename);
        }
        else if (choice == 9) {
            string filename;
            cout << "Enter filename to load: ";
            getline(cin, filename);
            loadStudentData(filename);
        }
        else if (choice == 10) {
            displayProfile();
        }

    } while (choice != 11);
}
