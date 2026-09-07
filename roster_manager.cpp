#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_CAPACITY = 50;

struct Student {
int id;
string name;
};

int findStudentById(const Student r[], int n, int id, int &c) {
c = 0;
for (int i = 0; i < n; i++) {
c++;
if (r[i].id == id) return i;
}
return -1;
}

bool addStudent(Student r[], int &n, int id, const string &name) {
if (n >= MAX_CAPACITY) {
cout << "Roster is full.\n";
return false;
}
int c;
if (findStudentById(r, n, id, c) != -1) {
cout << "ID already exists.\n";
return false;
}
r[n++] = {id, name};
cout << "Student added successfully.\n";
return true;
}

bool removeStudentById(Student r[], int &n, int id) {
if (n == 0) {
cout << "Roster is currently empty.\n";
return false;
}
int c, i = findStudentById(r, n, id, c);
if (i < 0) {
cout << "Student ID not found.\n";
return false;
}
for (; i < n - 1; i++)
r[i] = r[i + 1];
n--;
cout << "Student removed successfully.\n";
return true;
}

bool safeGetRecord(const Student r[], int n, int i, Student &out) {
if (i < 0 || i >= n) return false;
out = r[i];
return true;
}

void printRoster(const Student r[], int n) {
if (n == 0) {
cout << "Roster is currently empty.\n";
return;
}
cout << "\n=========== FULL ROSTER ===========\n";
cout << left << setw(8) << "Index"
<< setw(12) << "ID" << "Name\n";
for (int i = 0; i < n; i++)
cout << left << setw(8) << i
<< setw(12) << r[i].id << r[i].name << "\n";
cout << "Total Students: " << n << "\n";
}

int main() {
Student roster[MAX_CAPACITY];
int n = 0, choice;

do {
cout << "\n================================\n";
cout << " NTC CC105: STUDENT ROSTER\n";
cout << "================================\n";
cout << "1. Add Student Record\n";
cout << "2. Search Student by ID\n";
cout << "3. Remove Student by ID\n";
cout << "4. Safe Inspect Record by Index\n";
cout << "5. Display Full Roster\n";
cout << "6. Exit\n";
cout << "Enter selection [1-6]: ";
cin >> choice;

switch (choice) {
case 1: {
int id;
string name;
cout << "Enter Student ID: ";
cin >> id;
cin.ignore();
cout << "Enter Student Name: ";
getline(cin, name);
addStudent(roster, n, id, name);
break;
}

case 2: {
int id, c;
cout << "Enter Student ID: ";
cin >> id;
int i = findStudentById(roster, n, id, c);
if (i >= 0)
cout << "Found: " << roster[i].name
<< " at index " << i << "\n";
else
cout << "Student ID not found.\n";
cout << "Comparisons: " << c << "\n";
break;
}

case 3: {
int id;
cout << "Enter Student ID to remove: ";
cin >> id;
removeStudentById(roster, n, id);
break;
}

case 4: {
int i;
Student s;
cout << "Enter index: ";
cin >> i;
if (safeGetRecord(roster, n, i, s))
cout << "ID: " << s.id << ", Name: "
<< s.name << "\n";
else
cout << "Invalid index. No memory was accessed.\n";
break;
}

case 5:
printRoster(roster, n);
break;

case 6:
cout << "Exiting system. Memory cleaned successfully.\n";
break;

default:
cout << "Invalid selection.\n";
}

} while (choice != 6);

return 0;
}
