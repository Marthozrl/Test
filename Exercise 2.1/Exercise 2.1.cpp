// Exercise 2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class Student {
private:
    std::string name;
    int facultyNumber;
    std::vector<int> marks;

public:
    // Constructor
    Student(const std::string& studentName) : name(studentName) {
        // Generate a random faculty number (for simplicity, using a random number between 1000 and 9999)
        facultyNumber = 1000 + rand() % 9000;
    }

    // Set methods
    void setMarks(const std::vector<int>& studentMarks) {
        marks = studentMarks;
    }

    // Get methods
    std::string getName() const {
        return name;
    }

    int getFacultyNumber() const {
        return facultyNumber;
    }

    std::vector<int> getMarks() const {
        return marks;
    }

    // Calculate and return GPA
    float calculateGPA() const {
        if (marks.empty()) {
            return 0.0;
        }

        int totalMarks = 0;
        for (int mark : marks) {
            totalMarks += mark;
        }

        return static_cast<float>(totalMarks) / marks.size();
    }
};

// Function to find and output GPA by student name
void findAndOutputGPA(const std::vector<Student>& students, const std::string& studentName) {
    for (const Student& student : students) {
        if (student.getName() == studentName) {
            std::cout << "Student: " << student.getName() << std::endl;
            std::cout << "Faculty Number: " << student.getFacultyNumber() << std::endl;
            std::cout << "GPA: " << student.calculateGPA() << std::endl;
            return;
        }
    }
    std::cout << "Student not found." << std::endl;
}

int main() {
    srand(time(nullptr));

    // Create a vector to store student objects
    std::vector<Student> students;

    // Input student information
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        std::string studentName;
        std::cout << "Enter student name: ";
        std::cin >> studentName;

        int numMarks;
        std::cout << "Enter the number of marks: ";
        std::cin >> numMarks;

        std::vector<int> studentMarks;
        for (int j = 0; j < numMarks; ++j) {
            int mark;
            std::cout << "Enter mark " << j + 1 << ": ";
            std::cin >> mark;
            studentMarks.push_back(mark);
        }

        Student student(studentName);
        student.setMarks(studentMarks);
        students.push_back(student);
    }

    // Find and output GPA for a specific student
    std::string targetStudent;
    std::cout << "Enter the name of the student to find GPA for: ";
    std::cin >> targetStudent;
    findAndOutputGPA(students, targetStudent);

    return 0;
}