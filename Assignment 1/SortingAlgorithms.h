#include <iostream>   
#include <fstream>   
#include <vector>    
#include <string>     
#include <cctype>    
#include <algorithm>
#include <ctime> 


// Fisher-Yates (Knuth) Shuffle
void knuthShuffle(std::vector<std::string>& arr) {
    std::srand(std::time(0)); // Seed random number generator
    for (int i = arr.size() - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}

int selectionSort(std::vector<std::string>& arr) {
    int comparisons = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
    return comparisons;
}

int insertionSort(std::vector<std::string>& arr) {
    int comparisons = 0;
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        std::string key = arr[i];
        int j = i - 1;
        
        // Compare and shift elements to insert the current element at its correct position
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        comparisons++; // Comparison for exiting the while loop
        arr[j + 1] = key;
    }
    return comparisons;
}
