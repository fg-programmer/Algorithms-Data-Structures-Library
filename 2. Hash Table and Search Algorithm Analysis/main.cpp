#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <cmath>
#include <iomanip>
#include "Algorithms.h"

const int TABLE_SIZE = 250;
const int LINES_IN_FILE = 666;
const std::string FILE_NAME = "magicitems.txt";


// Hash function
int hashFunction(const std::string& str) {
        int hash = 0;
        for (char ch : str) {
            hash += static_cast<int>(std::toupper(ch));
        }
        return (hash * 1) % TABLE_SIZE; 
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
    void analyzeHashValues(const std::vector<std::string>& searchItems) {
       std::vector<int> bucketCount(TABLE_SIZE, 0);
        int totalComparisons = 0;
        
        std::cout << "Hash Table Retrieval for Selected Items:\n";
        
        // Count items in each relevant bucket and track comparisons for retrieval
        for (const auto& item : searchItems) {
            int index = hashFunction(item);
            bucketCount[index]++;
            int comparisons = retrieve(item);
            totalComparisons += comparisons;
            std::cout << "Hash: " << item << ", Comparisons: " << comparisons << "\n";
        }

       // Display bucket usage for the selected items only
        int relevantBuckets = 0;
        std::cout << "\nHash Table Usage for Selected Buckets:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (bucketCount[i] > 0) {
                relevantBuckets++;
                std::cout << std::setw(3) << i << " ";
                for (int j = 0; j < bucketCount[i]; ++j) {
                    std::cout << "*";
                }
                std::cout << " " << bucketCount[i] << "\n";
            }
        }

        // Calculate and display average load and standard deviation for selected buckets
        double averageLoad = static_cast<double>(totalComparisons) / searchItems.size();
        std::cout << "\nAverage comparisons for selected items: "
                  << std::fixed << std::setprecision(2) << averageLoad << "\n";

        double sum = 0;
        for (int count : bucketCount) {
            if (count > 0) {
                double deviation = count - averageLoad;
                sum += deviation * deviation;
            }
        }
        double stdDev = std::sqrt(sum / relevantBuckets);
        std::cout << "Standard Deviation for selected buckets: "
                  << std::fixed << std::setprecision(2) << stdDev << "\n";
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


    hashTable.analyzeHashValues(searchItems);

    return 0;
}
