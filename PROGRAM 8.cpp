#include
#include
#include
using namespace std;

// ---------------- Base class ----------------
class Student {
protected:
int rollNo;
char name[64];

public:
void getStudentData() {
cout << "Enter Roll No : ";
cin >> rollNo;
cout << "Enter Name : ";
cin.ignore();
cin.getline(name, 64);
}

void showStudentData() {
    cout << "Roll No : " << rollNo << "\n";
    cout << "Name    : " << name   << "\n";
}
};

// ---------------- Derived class (Level 1) ----------------
// Exam inherits Student
class Exam : public Student {
protected:
float marks[6]; // marks in 6 subjects

public:
void getExamData() {
cout << "\nEnter marks in 6 subjects (out of 100 each):\n";
for (int i = 0; i < 6; i++) {
cout << " Subject " << (i + 1) << " : ";
cin >> marks[i];
}
}

void showExamData() {
    cout << "\nMarks obtained:\n";
    for (int i = 0; i < 6; i++)
        cout << "  Subject " << (i + 1) << " : " << marks[i] << "\n";
}
};

// ---------------- Derived class (Level 2) ----------------
// Result inherits Exam, which inherits Student -> MULTILEVEL INHERITANCE
class Result : public Exam {
private:
float totalMarks;
float percentage;
char grade;

void calculateResult() {
    totalMarks = 0;
    for (int i = 0; i < 6; i++)
        totalMarks += marks[i];

    percentage = totalMarks / 6.0f;   // 6 subjects, out of 100 each

    if (percentage >= 90)      grade = 'A';
    else if (percentage >= 75) grade = 'B';
    else if (percentage >= 60) grade = 'C';
    else if (percentage >= 40) grade = 'D';
    else                       grade = 'F';
}
public:
void processResult() {
getStudentData(); // from Student
getExamData(); // from Exam
calculateResult(); // own method
}

void displayResult() {
    cout << "\n==================================================\n";
    cout << "                   RESULT SHEET\n";
    cout << "==================================================\n";
    showStudentData();  // from Student
    showExamData();     // from Exam
    cout << fixed << setprecision(2);
    cout << "\nTotal Marks : " << totalMarks << " / 600\n";
    cout << "Percentage  : " << percentage   << " %\n";
    cout << "Grade       : " << grade        << "\n";
    cout << "==================================================\n";
}
};

int main() {
int n;
cout << "Enter number of students: ";
cin >> n;

Result *res = new Result[n];

for (int i = 0; i < n; i++) {
    cout << "\n--- Student " << (i + 1) << " ---\n";
    res[i].processResult();
}

cout << "\n\n############ FINAL RESULTS ############\n";
for (int i = 0; i < n; i++)
    res[i].displayResult();

delete [] res;
return 0;
}

OUTPUT
Enter number of students: 2

--- Student 1 ---
Enter Roll No : 20
Enter Name : AYUSHI

Enter marks in 6 subjects (out of 100 each):
Subject 1 : 80
Subject 2 : 89
Subject 3 : 70
Subject 4 : 65
Subject 5 : 90
Subject 6 : 78

--- Student 2 ---
Enter Roll No : 30
Enter Name : ANNA

Enter marks in 6 subjects (out of 100 each):
Subject 1 : 34
Subject 2 : 45
Subject 3 : 78
Subject 4 : 89
Subject 5 : 98
Subject 6 : 30

############ FINAL RESULTS ############

==================================================
RESULT SHEET
Roll No : 20
Name : AYUSHI

Marks obtained:
Subject 1 : 80
Subject 2 : 89
Subject 3 : 70
Subject 4 : 65
Subject 5 : 90
Subject 6 : 78

Total Marks : 472.00 / 600
Percentage : 78.67 %
Grade : B
==================================================
RESULT SHEET
Roll No : 30
Name : ANNA

Marks obtained:
Subject 1 : 34.00
Subject 2 : 45.00
Subject 3 : 78.00
Subject 4 : 89.00
Subject 5 : 98.00
Subject 6 : 30.00

Total Marks : 374.00 / 600
Percentage : 62.33 %
Grade : C