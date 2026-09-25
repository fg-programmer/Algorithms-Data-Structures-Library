#include <iostream>   
#include <fstream>   
#include <vector>    
#include <string>     
#include <cctype>    
#include <algorithm>
#include <ctime> 


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



// Linear search function with comparison counting
int linearSearch(const std::vector<std::string>& arr, const std::string& target) {
    int comp = 0;
    for (const auto& item : arr) {
        comp++;
        if (item == target) {
            break;  
        }
    }
    return comp;
}

// Binary search function with comparison counting
int binarySearch(const std::vector<std::string>& arr, const std::string& target) {
    int left = 0, right = arr.size() - 1;
    int comp = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        comp++;

        if (arr[mid] == target) {
            return comp;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return comp;  // Item not found, return comparisons made
}
