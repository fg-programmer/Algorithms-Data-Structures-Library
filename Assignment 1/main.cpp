#include <iostream>      
#include <fstream>       
#include <vector>        
#include <string>        
#include "Palindrome.h"
#include "SortingAlgorithms.h"



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
    // Step 3: Perform sorting and count comparisons for each algorithm
    std::vector<std::string> itemsToSort;

    // Selection Sort
    itemsToSort = magicItems;  // Make a copy of the original list
    knuthShuffle(itemsToSort); // Shuffle before sorting
    int selectionComparisons = selectionSort(itemsToSort);
    std::cout << "Selection Sort comparisons: " << selectionComparisons << '\n';

    // Insertion Sort
    itemsToSort = magicItems;  // Reset to the original list
    knuthShuffle(itemsToSort); // Shuffle before sorting
    int insertionComparisons = insertionSort(itemsToSort);
    std::cout << "Insertion Sort comparisons: " << insertionComparisons << '\n';

    // Merge Sort
    itemsToSort = magicItems;  // Reset to the original list
    knuthShuffle(itemsToSort); // Shuffle before sorting
    int mergeComparisons = mergeSort(itemsToSort);
    std::cout << "Merge Sort comparisons: " << mergeComparisons << '\n';

    // Quick Sort
    itemsToSort = magicItems;  // Reset to the original list
    knuthShuffle(itemsToSort); // Shuffle before sorting
    int quickComparisons = quickSort(itemsToSort);
    std::cout << "Quick Sort comparisons: " << quickComparisons << '\n';

    return 0;
}