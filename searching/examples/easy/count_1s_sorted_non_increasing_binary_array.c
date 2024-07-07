/**
 * @file count_1s_sorted_non_increasing_binary_array.c
 * @brief Provides functions to count the number of 1s in a sorted non-increasing binary array.
 * 
 * This program demonstrates how to count the number of 1s in a sorted non-increasing binary array.
 * 
 * @details 
 * The approaches include:
 * - **Linear Search**: Counts the number of 1s by traversing the array.
 * - **Binary Search**: Uses binary search to find the first occurrence of 0 and counts the number of 1s.
 * 
 * @complexity
 * - **Linear Search**: O(n) time complexity because it traverses the entire array.
 * - **Binary Search**: O(log n) time complexity because it uses binary search.
 * 
 * Author: Kiran Jojare
 */

#include <stdio.h>
#include <stdlib.h>

/** 
 * @brief Counts the number of 1s in a sorted non-increasing binary array using linear search.
 * 
 * @param arr Array of integers (binary values).
 * @param size Number of elements in the array.
 * @return The count of 1s in the array.
 */
/*
int count1s_linear(int arr[], int size) {
    int count1s = 0; // Initialize count of 1s
    for (int i = 0 ; i < size; i++) {
        if (arr[i] == 1) {
            count1s++; // Increment count if element is 1
        }
    }
    return count1s; // Return the count of 1s
}
*/

/** 
 * @brief Counts the number of 1s in a sorted non-increasing binary array using binary search.
 * 
 * @param arr Array of integers (binary values).
 * @param size Number of elements in the array.
 * @return The count of 1s in the array.
 */
int count1s(int arr[], int size) {
    int low = 0;
    int high = size - 1;

    // Perform binary search to find the first occurrence of 0
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if this is the last 1
        if (((mid == high) || (arr[mid + 1] == 0)) && (arr[mid] == 1)) {
            return mid + 1; // Return the count of 1s
        }
        // If the element is 1, then move to the right half
        else if (arr[mid] == 1) {
            low = mid + 1;
        }
        // If the element is 0, then move to the left half
        else {
            high = mid - 1;
        }
    }
    return 0; // Return 0 if no 1s are found
}

/**
 * @brief Driver code to demonstrate the count1s function.
 * 
 * This function creates multiple test cases and calls the count1s function to count the number of 1s in each array.
 * 
 * @return 0 on successful execution.
 */
int main() {
    int test1[] = {1, 1, 1, 1, 0, 0, 0}; // Example test case 1
    int test2[] = {1, 0, 0, 0, 0, 0, 0}; // Example test case 2
    int test3[] = {1, 1, 1, 1, 1, 1, 1}; // Example test case 3
    int test4[] = {1, 1, 0, 0, 0, 0, 0}; // Example test case 4
    int test5[] = {1, 1}; // Example test case 5
    int test6[] = {1, 0}; // Example test case 6

    // Print the count of 1s for each test case
    printf("Test 1: %d\n", count1s(test1, sizeof(test1) / sizeof(test1[0])));
    printf("Test 2: %d\n", count1s(test2, sizeof(test2) / sizeof(test2[0])));
    printf("Test 3: %d\n", count1s(test3, sizeof(test3) / sizeof(test3[0])));
    printf("Test 4: %d\n", count1s(test4, sizeof(test4) / sizeof(test4[0])));
    printf("Test 5: %d\n", count1s(test5, sizeof(test5) / sizeof(test5[0])));
    printf("Test 6: %d\n", count1s(test6, sizeof(test6) / sizeof(test6[0])));

    return 0; // Return 0 to indicate successful execution
}
