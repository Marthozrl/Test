// Exercise 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

void Print(std::string str, int n, std::string separator) {
    if (n == 1) {
        std::cout << str;
        return;
    }
    std::cout << str + separator;
    Print(str, n - 1, separator);
}

int main() {
    std::string inputString;
    int n;
    std::string separator;

    std::cout << "Enter the input string: ";
    std::cin >> inputString;

    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::cout << "Enter the separator: ";
    std::cin >> separator;

    Print(inputString, n, separator);

    return 0;
}