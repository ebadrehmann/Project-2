#include <iostream>
#include "Student.h"

using namespace std;

int main() {
    Student* student = nullptr;
    int choice;

    do {
        cout << "\n===========================\n";
        cout << "STUDYTRACKER MAIN MENU\n";
        cout << "===========================\n";
        cout << "1. Load Student Profile\n";
        cout << "2. Create New Student\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string filename;
            cout << "Enter filename: ";
            getline(cin, filename);

            student = new Student(); // temp, will be overwritten
            student->loadStudentData(filename);
            student->startSession();
        }
        else if (choice == 2) {
            student = new Student();
            student->startSession();
        }

    } while (choice != 3);

    cout << "Goodbye!\n";
    return 0;
}
