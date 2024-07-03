/**
 * @file exponential_search_simple.c
 * @brief Implementation of the Exponential Search Algorithm.
 *
 * Exponential search is an efficient algorithm for finding a target value within a sorted array. 
 * This algorithm is particularly useful when the size of the array is unbounded or very large. 
 * The search process is divided into two main phases: finding the range where the target value 
 * may exist and performing a binary search within that range.
 *
 * ## Algorithm Overview
 * 
 * 1. Begin with an index at 1 (i.e., the second element of the array).
 * 2. Double the index value in each step (i.e., 1, 2, 4, 8, ...) until finding an index that is 
 *    out of bounds or the value at the index is greater than or equal to the target value.
 * 3. Once the range is determined (between the last index where the value was less than the target 
 *    and the current index), perform a binary search in this range to find the target value.
 *
 * ## Key Features
 * 
 * - Efficient for searching in unbounded or large arrays where the size is not known in advance.
 * - Combines the speed of exponential growth to quickly find a suitable range with the precision 
 *   of binary search to locate the target value within that range.
 * - Particularly efficient when the target value is closer to the beginning of the array.
 *
 * ## Time Complexity
 * 
 * - O(log n), where n is the position of the target value in the array. The time complexity arises 
 *   from the fact that finding the range takes O(log n) time (due to the exponential increase in index) 
 *   and binary search within the range also takes O(log n) time.
 *
 * ## Space Complexity
 * 
 * - O(1), as it requires a constant amount of space. The algorithm iteratively finds the range and 
 *   performs binary search without additional space for data storage.
 *
 * @note Exponential search is best used in scenarios where the array size is potentially infinite or 
 *       very large, and the distribution of values is not known in advance. It is an adaptive algorithm 
 *       that quickly narrows down the search range for efficient searching.
 */

#include <stdio.h>

// Function to perform binary search on the sub-array
int binary_search(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

/**
 * @brief Performs an exponential search on an array to find the index of a given element.
 * 
 * The function tries to find the range where the element might be present by starting with the first element
 * and doubling the index until it finds an element greater than or equal to the search element or until it exceeds the bounds of the array.
 * Once the range is found, it calls binary_search to find the exact index of the element within that range.
 * 
 * @param arr The array to search in.
 * @param n The size of the array.
 * @param x The element to search for.
 * @return The index of the element if found, -1 otherwise.
 */
int exponential_search(int arr[], int n, int x) {
    if (n == 0) return -1; // Handle empty array case

    int i = 1;
    // Start with the first element, and exponentially increase the index
    while (i < n && arr[i] <= x) {
        i *= 2; // Double the index to find the range where the element might be present
    }
    // Once the range is found, perform binary search in that range
    return binary_search(arr, i / 2, (i < n) ? i : n - 1, x);
}

/**
 * @brief Main function to demonstrate the use of exponential search.
 * 
 * Initializes an array and a set of target values, then searches for each target
 * in the array using exponential search. Prints the result of each search.
 * 
 * @return int Returns 0 on successful execution.
 */

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 70, 100, 120};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targets[] = {10, 50, 70, 100, 3, 2};
    int results[sizeof(targets) / sizeof(targets[0])];

    for (int i = 0; i < sizeof(targets) / sizeof(targets[0]); i++) {
        results[i] = exponential_search(arr, n, targets[i]);
        printf("Target %d is %s\n", targets[i], (results[i] == -1) ? "not found" : "found");
    }

    return 0;
}
