#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Algorithms.h"  // Include your sorting functions


int main() {
    // Step 1: Read items from magicitems.txt into a vector
    std::ifstream inputFile("magicitems.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open file magicitems.txt\n";
        return 1;
    }

    std::vector<std::string> magicItems;
    std::string line;
    while (std::getline(inputFile, line)) {
        magicItems.push_back(line);
    }
    inputFile.close();

    // Step 2: Sort the array
    mergeSort(magicItems); 

    // Step 3: Randomly select 42 items for searching
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<std::string> searchItems;
    for (int i = 0; i < 42; ++i) {
        int randomIndex = std::rand() % magicItems.size();
        searchItems.push_back(magicItems[randomIndex]);
    }
}