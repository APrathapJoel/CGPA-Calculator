#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Course 
{
    string name;
    string gradeLetter;
    double gradePoint;
    int creditHours;
};

double convertGradeToPoint(const string &grade) {
    string g = grade;
    for (char &c : g) c = toupper(c);

    if (g == "A+" || g == "A") return 10.0;
    if (g == "A-") return 9.0;
    if (g == "B+") return 8.0;
    if (g == "B")  return 7.0;
    if (g == "C+") return 6.0;
    if (g == "C")  return 5.0;
    if (g == "D")  return 4.0;
    return 0.0; // F / anything else
}

int main() {
    int numberOfCourses;
    cout << "==============================\n";
    cout << "        CGPA CALCULATOR       \n";
    cout << "==============================\n\n";

    cout << "Enter number of courses in this semester: ";
    cin >> numberOfCourses;

    while (numberOfCourses <= 0) {
        cout << "Invalid number. Please enter again: ";
        cin >> numberOfCourses;
    }

    vector<Course> courses;
    courses.reserve(numberOfCourses);

    cout << "\nPlease enter details for each course.\n";
    cout << "(Example grade: A, A-, B+, B, C, D, F)\n\n";

    for (int i = 0; i < numberOfCourses; ++i) {
        Course c;
        cout << "---------------------------------\n";
        cout << "Course " << (i + 1) << " name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, c.name);

        cout << "Credit hours for \"" << c.name << "\": ";
        cin >> c.creditHours;
        while (c.creditHours <= 0) {
            cout << "Credit hours must be positive. Enter again: ";
            cin >> c.creditHours;
        }

        cout << "Grade obtained in \"" << c.name << "\": ";
        cin >> c.gradeLetter;

        c.gradePoint = convertGradeToPoint(c.gradeLetter);
        courses.push_back(c);
    }

    double totalGradePoints = 0.0;
    int totalCredits = 0;

    for (const Course &c : courses) {
        totalGradePoints += c.gradePoint * c.creditHours;
        totalCredits += c.creditHours;
    }

    double semesterGPA = 0.0;
    if (totalCredits > 0) {
        semesterGPA = totalGradePoints / totalCredits;
    }

    double previousCGPA = 0.0;
    int previousTotalCredits = 0;
    char hasPrevious;
    cout << "\nDo you have previous semester CGPA to include? (y/n): ";
    cin >> hasPrevious;

    if (hasPrevious == 'y' || hasPrevious == 'Y') {
        cout << "Enter previous overall CGPA: ";
        cin >> previousCGPA;
        cout << "Enter total credits completed before this semester: ";
        cin >> previousTotalCredits;
        if (previousTotalCredits < 0) previousTotalCredits = 0;
    }

    double overallCGPA = semesterGPA;
    if (previousTotalCredits > 0) {
        double previousTotalGradePoints = previousCGPA * previousTotalCredits;
        double combinedGradePoints = previousTotalGradePoints + totalGradePoints;
        int combinedCredits = previousTotalCredits + totalCredits;
        if (combinedCredits > 0) {
            overallCGPA = combinedGradePoints / combinedCredits;
        }
    }

    cout << "\n==============================\n";
    cout << "        RESULT SUMMARY        \n";
    cout << "==============================\n\n";

    cout << left << setw(25) << "Course"
         << setw(10) << "Credits"
         << setw(10) << "Grade"
         << setw(10) << "Points" << "\n";

    cout << string(55, '-') << "\n";

    for (const Course &c : courses) {
        cout << left << setw(25) << c.name
             << setw(10) << c.creditHours
             << setw(10) << c.gradeLetter
             << setw(10) << c.gradePoint << "\n";
    }

    cout << string(55, '-') << "\n";
    cout << "Total Credits: " << totalCredits << "\n";
    cout << fixed << setprecision(2);
    cout << "Semester GPA:  " << semesterGPA << "\n";
    cout << "Overall CGPA:  " << overallCGPA << "\n";

    cout << "\nThank you for using the CGPA Calculator!\n";

    return 0;
}
