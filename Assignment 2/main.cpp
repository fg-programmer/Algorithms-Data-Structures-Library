#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include "Algorithms.h"

const int TABLE_SIZE = 250;

// Hash function
int hashFunction(const std::string& key) {
    int hash = 0;
    for (char ch : key) {
        hash = (37 * hash + ch) % TABLE_SIZE;
    }
    return hash;
}

// Hash Table Class with Chaining
class HashTable {
public:
    HashTable() : table(TABLE_SIZE) {}

    void insert(const std::string& key) {
        int index = hashFunction(key);
        table[index].emplace_back(key);
    }

    int retrieve(const std::string& key) {
        int index = hashFunction(key);
        int comparisons = 1;  // Initial comparison for accessing the bucket

        for (const auto& item : table[index]) {
            comparisons++;
            if (item == key) return comparisons;
        }
        return comparisons;  // Return comparisons even if not found
    }

private:
    std::vector<std::list<std::string>> table;
};

int main() {
    // Load magic items from file
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

    // Sort the array for binary search
    mergeSort(magicItems);

    // Initialize hash table and load it with magic items
    HashTable hashTable;
    for (const auto& item : magicItems) {
        hashTable.insert(item);
    }

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


    // Perform hash table retrieval and calculate comparisons
    int totalHashComparisons = 0;
    std::cout << "\nHash Table Retrieval Comparisons:\n";
    for (const auto& item : searchItems) {
        int comparisons = hashTable.retrieve(item);
        totalHashComparisons += comparisons;
        std::cout << "Comparisons for " << item << ": " << comparisons << "\n";
    }
    double avgHashComparisons = static_cast<double>(totalHashComparisons) / searchItems.size();
    std::cout << "Average Hash Table Comparisons: " << avgHashComparisons << "\n";

    return 0;
}
