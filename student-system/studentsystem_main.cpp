
//  Created by Elif Nehir Özer on 13.04.2025.


#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;


struct Student {
    int id;
    string name;
    int age;
    float grade;
};


vector<Student> students;
set<int> studentIDs;
unordered_map<int, Student> studentMap;


void addStudent() {
    Student s;
    cout << "Enter ID: ";
    cin >> s.id;

    if (studentIDs.find(s.id) != studentIDs.end()) {
        cout << "Student with ID " << s.id << " already exists.\n";
        return;
    }

    cout << "Enter name: ";
    cin >> s.name;
    cout << "Enter age: ";
    cin >> s.age;
    cout << "Enter grade: ";
    cin >> s.grade;

    students.push_back(s);
    studentIDs.insert(s.id);
    studentMap[s.id] = s;

    cout << "Student added successfully!\n";
}


void displayAllStudents() {
    if (students.empty()) {
        cout << "No students to display.\n";
        return;
    }

    cout << "\nList of Students:\n";
    for (const auto& s : students) {
        cout << "ID: " << s.id << ", Name: " << s.name
             << ", Age: " << s.age << ", Grade: " << s.grade << endl;
    }
}


void findStudentByID(int id) {
    if (studentMap.find(id) != studentMap.end()) {
        Student s = studentMap[id];
        cout << "Found: ID: " << s.id << ", Name: " << s.name
             << ", Age: " << s.age << ", Grade: " << s.grade << endl;
    } else {
        cout << "Student with ID " << id << " not found.\n";
    }
}


void deleteStudentByID(int id) {
    if (studentMap.find(id) == studentMap.end()) {
        cout << "Student with ID " << id << " not found.\n";
        return;
    }

    
    studentMap.erase(id);
    studentIDs.erase(id);

    
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            break;
        }
    }

    cout << "Student deleted successfully!\n";
}


float getAverageGrade(const vector<Student>& sList) {
    if (sList.empty()) return 0.0;

    float sum = 0.0;
    for (const auto& s : sList) {
        sum += s.grade;
    }

    return sum / sList.size();
}


int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}


int main() {
    int choice;

    while (true) {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Find Student by ID\n";
        cout << "4. Delete Student by ID\n";
        cout << "5. Calculate Average Grade\n";
        cout << "6. Factorial (recursive)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addStudent();
        } else if (choice == 2) {
            displayAllStudents();
        } else if (choice == 3) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            findStudentByID(id);
        } else if (choice == 4) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            deleteStudentByID(id);
        } else if (choice == 5) {
            float avg = getAverageGrade(students);
            cout << "Average grade: " << avg << endl;
        } else if (choice == 6) {
            int n;
            cout << "Enter number: ";
            cin >> n;
            cout << "Factorial of " << n << " is " << factorial(n) << endl;
        } else if (choice == 7) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}

    

