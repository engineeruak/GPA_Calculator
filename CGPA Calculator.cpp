//CGPA Calculator.
#include <iostream>
#include <vector>
using namespace std;

// Structure to store course details
struct Course {
    string name;
    double grade;
    int creditHours;
    double gradePoints;
};

// Function to calculate GPA for a semester
double calculateGPA(vector<Course>& courses, int& totalCredits) {
    double totalGradePoints = 0.0;
    totalCredits = 0;

    for (auto& course : courses) {
        course.gradePoints = course.grade * course.creditHours;
        totalGradePoints += course.gradePoints;
        totalCredits += course.creditHours;
    }

    return totalCredits > 0 ? totalGradePoints / totalCredits : 0.0;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);
    int totalCredits = 0;
    double totalGradePoints = 0.0;
    double overallCGPA = 0.0;

    // Input course details
    for (int i = 0; i < numCourses; ++i) {
        cout << "\nEnter details for course " << i + 1 << ":\n";
        cout << "Course name: ";
        cin >> courses[i].name;
        cout << "Grade (numeric value, e.g., 4.0 for A): ";
        cin >> courses[i].grade;
        cout << "Credit hours: ";
        cin >> courses[i].creditHours;
    }

    // Calculate semester GPA
    double semesterGPA = calculateGPA(courses, totalCredits);

    // Display individual course grades
    cout << "\nCourse Grades:\n";
    for (const auto& course : courses) {
        cout << "Course: " << course.name
             << ", Grade: " << course.grade
             << ", Credits: " << course.creditHours
             << ", Grade Points: " << course.gradePoints << endl;
    }

    // Display semester GPA
    cout << "\nSemester GPA: " << semesterGPA << endl;

    // Assuming CGPA is the same as semester GPA for simplicity
    // For cumulative CGPA, maintain history of all semesters
    overallCGPA = semesterGPA;

    cout << "Overall CGPA: " << overallCGPA << endl;
    system ("pause");

    return 0;
}
