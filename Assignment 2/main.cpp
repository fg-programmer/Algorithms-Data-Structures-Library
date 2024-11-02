#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Algorithms.h"


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

    // Step 4: Perform linear and binary search, tracking comparisons
    int totalLinearComparisons = 0;
    int totalBinaryComparisons = 0;

    std::cout << "Linear Search Comparisons:\n";
    for (const auto& item : searchItems) {
        int linearComp = linearSearch(magicItems, item);
        totalLinearComparisons += linearComp;
        std::cout << "Comparisons for " << item << ": " << linearComp << "\n";
    }

    std::cout << "Binary Search Comparisons:\n";
    for (const auto& item : searchItems) {
        int binaryComp = binarySearch(magicItems, item);
        totalBinaryComparisons += binaryComp;
        std::cout << "Comparisons for " << item << ": " << binaryComp << "\n";
    }

    // Step 5: Calculate and display averages
    double averageLinear = static_cast<double>(totalLinearComparisons) / searchItems.size();
    double averageBinary = static_cast<double>(totalBinaryComparisons) / searchItems.size();
    
    std::cout << "Average Linear Search Comparisons: " << averageLinear << "\n";
    std::cout << "Average Binary Search Comparisons: " << averageBinary << "\n";

    return 0;
}
