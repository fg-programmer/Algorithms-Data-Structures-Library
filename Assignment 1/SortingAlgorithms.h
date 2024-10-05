

#include <iostream>   
#include <fstream>   
#include <vector>    
#include <string>     
#include <cctype>    
#include <algorithm>
#include <ctime> 

// Loop from the last element down to the second element
void knuthShuffle(std::vector<std::string>& arr) {
    std::size_t n = arr.size();  // Use std::size_t for n
    for (std::size_t i = n - 1; i > 0; --i) {  
        std::size_t j = static_cast<std::size_t>(rand()) % (i + 1);  
        std::swap(arr[i], arr[j]);  
    }
}
//Selection Sort
int selectionSort(std::vector<std::string>& arr) {
    int comparisons = 0;
    std::size_t n = arr.size();  // Change int to std::size_t
    
    // Loop over the array, treating each element as the starting point for selection
    for (std::size_t i = 0; i < n - 1; ++i) { 
        std::size_t minIndex = i;  
        for (std::size_t j = i + 1; j < n; ++j) { // Find the index of the smallest element in the remaining unsorted array
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);          // Swap the found minimum element with the first element of the unsorted part

    }
    return comparisons;
}
//Insertion Sort
int insertionSort(std::vector<std::string>& arr) {
    int comparisons = 0;
    std::size_t n = arr.size();  // Get the size of the vector

    // Loop over the array starting from the second element
    for (std::size_t i = 1; i < n; ++i) {
        std::string key = arr[i];  // Store the current element (key)
        std::size_t j = i;

        // Shift elements that are greater than the key to the right
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];  
            j--;  //
            comparisons++;  
        }

        // Insert the key into its correct position
        arr[j] = key;

        // Increment comparisons to account for the last comparison that failed the while loop
        comparisons++;
    }

    return comparisons;
}
// Merge Sort
int merge(std::vector<std::string>& arr, std::vector<std::string>& temp, std::size_t left, std::size_t mid, std::size_t right) {
    std::size_t i = left, j = mid + 1, k = left;
    int comparisons = 0;

    // Merge the two halves into temp[]
    while (i <= mid && j <= right) {
        comparisons++;
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy the remaining elements of left half, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of right half, if any
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the merged elements back into the original array
    for (std::size_t m = left; m <= right; m++) {
        arr[m] = temp[m];
    }

    return comparisons;
}

// Helper function for merge sort that recursively sorts and merges parts of the array
int mergeSortHelper(std::vector<std::string>& arr, std::vector<std::string>& temp, std::size_t left, std::size_t right) {
    int comparisons = 0;

    if (left < right) {
        std::size_t mid = left + (right - left) / 2;

        comparisons += mergeSortHelper(arr, temp, left, mid);   // Recursively sort the left half of the array

        comparisons += mergeSortHelper(arr, temp, mid + 1, right);   // Recursively sort the right half of the array

        comparisons += merge(arr, temp, left, mid, right);
    }

    return comparisons;
}

// Main function to perform merge sort on the array
int mergeSort(std::vector<std::string>& arr) {
    std::vector<std::string> temp(arr.size());
    return mergeSortHelper(arr, temp, 0, arr.size() - 1);
}

int partition(std::vector<std::string>& arr, std::size_t low, std::size_t high, int& comparisons) {
    std::string pivot = arr[high];  // Pivot
    std::size_t i = low - 1;  // Index of smaller element

    for (std::size_t j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}
