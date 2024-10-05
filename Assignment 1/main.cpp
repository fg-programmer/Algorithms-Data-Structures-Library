#include <iostream>      
#include <fstream>       
#include <vector>        
#include <string>        
#include "Palindrome.h"

int main() {
    std::ifstream inputFile("magicitems.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open file magicitems.txt\n";
        return 1;
    }

    std::vector<std::string> magicItems;
    std::string line;

    // Reading the file line by line into the magicItems vector
    while (std::getline(inputFile, line)) {
        magicItems.push_back(line);
    }
    inputFile.close();

    // Check each line for palindrome
    std::cout << "Palindromes in the file:\n";
    for (const std::string& item : magicItems) {
        if (isPalindrome(item)) {
            std::cout << item << '\n';
        }
    }

    return 0;
}