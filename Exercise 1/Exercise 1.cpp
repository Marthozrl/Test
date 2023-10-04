#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

struct Programmer {
    std::string position;
    double salary;
};

int main() {
    std::ofstream outputFile("salary.bin", std::ios::binary);

    if (!outputFile) {
        std::cerr << "Failed to open the file for writing." << std::endl;
        return 1;
    }

    std::cout << "Enter programmer data in the format: Position Salary" << std::endl;
    std::cout << "Type 'exit' to stop entering data." << std::endl;

    std::string input;
    while (true) {
        std::getline(std::cin, input);
        if (input == "exit") {
            break;
        }

        std::istringstream iss(input);
        Programmer programmer;
        iss >> programmer.position >> programmer.salary;

        outputFile.write(reinterpret_cast<const char*>(&programmer), sizeof(Programmer));
    }

    outputFile.close();

    std::string targetPosition;
    std::cout << "Enter a position to calculate the average salary for: ";
    std::getline(std::cin, targetPosition);

    std::ifstream inputFile("salary.bin", std::ios::binary);

    if (!inputFile) {
        std::cerr << "Failed to open the file for reading." << std::endl;
        return 1;
    }

    double totalSalary = 0;
    int count = 0;
    Programmer currentProgrammer;

    while (inputFile.read(reinterpret_cast<char*>(&currentProgrammer), sizeof(Programmer))) {
        if (currentProgrammer.position.find(targetPosition) != std::string::npos) {
            totalSalary += currentProgrammer.salary;
            count++;
        }
    }

    inputFile.close();

    if (count > 0) {
        double averageSalary = totalSalary / count;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Average " << targetPosition << " salary is: " << averageSalary << std::endl;
    }
    else {
        std::cout << "No data found for the specified position." << std::endl;
    }

    return 0;
}