/**
 * @file find_ceiling_and_floor_in_sorted_array.c
 * @brief Provides functions to find the ceiling and floor of a value in a sorted array.
 * 
 * This program demonstrates how to find the ceiling and floor of a given value in a sorted array.
 * 
 * @details 
 * The approaches include:
 * - **Linear Search**: Iterate over the array to find the ceiling and floor of the given value.
 * - **Binary Search**: Use binary search to efficiently find the ceiling and floor of the given value.
 * 
 * @complexity
 * - **Linear Search**: O(n) time complexity for iterating over all elements in the array.
 * - **Binary Search**: O(log n) time complexity for binary search.
 * 
 * @approach Explanation:
 * - **Ceiling**: The ceiling of `x` is the smallest element in the array which is greater than or equal to `x`.
 *   - Linear Search: Iterate over the array to find the first element that is greater than or equal to `x`.
 *   - Binary Search: Use binary search to find the first element that is greater than or equal to `x`.
 * - **Floor**: The floor of `x` is the largest element in the array which is less than or equal to `x`.
 *   - Linear Search: Iterate over the array to find the largest element that is less than or equal to `x`.
 *   - Binary Search: Use binary search to find the largest element that is less than or equal to `x`.
 * 
 * Author: Kiran Jojare
 */

#include <stdio.h>
#include <assert.h>

/**
 * @brief Finds the ceiling of `x` in a sorted array using linear search.
 * The ceiling of `x` is the smallest element in the array which is greater than or equal to `x`.
 * 
 * @param arr The sorted array.
 * @param n The size of the array.
 * @param x The value to find the ceiling for.
 * @return The ceiling of `x`, or -1 if no ceiling is found.
 */
/*
int findCeilingLinear(int arr[], int n, int x) {
    // If the first element is greater than or equal to x
    if (x <= arr[0]) {
        return arr[0];
    }

    // Linear search for the ceiling
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == x) {
            return arr[i];
        }
        if (arr[i] < x && arr[i + 1] >= x) {
            return arr[i + 1];
        }
    }

    // If no ceiling is found
    return -1;
}
*/

/**
 * @brief Finds the ceiling of `x` in a sorted array using binary search.
 * The ceiling of `x` is the smallest element in the array which is greater than or equal to `x`.
 * 
 * @param arr The sorted array.
 * @param n The size of the array.
 * @param x The value to find the ceiling for.
 * @return The ceiling of `x`, or -1 if no ceiling is found.
 */
int findCeiling(int arr[], int n, int x) {
    if (x > arr[n - 1]) {
        return -1;
    }

    int low = 0, high = n - 1;
    int ceil = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return arr[mid];
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            ceil = arr[mid];
            high = mid - 1;
        }
    }

    return ceil;
}

/**
 * @brief Finds the floor of `x` in a sorted array using linear search.
 * The floor of `x` is the largest element in the array which is less than or equal to `x`.
 * 
 * @param arr The sorted array.
 * @param n The size of the array.
 * @param x The value to find the floor for.
 * @return The floor of `x`, or -1 if no floor is found.
 */
/*
int findFloorLinear(int arr[], int n, int x) {
    // If the last element is less than or equal to x
    if (x >= arr[n - 1]) {
        return arr[n - 1];
    }

    // If the first element is greater than x
    if (x < arr[0]) {
        return -1;
    }

    // Linear search for the floor
    for (int i = 1; i < n; i++) {
        if (arr[i] > x) {
            return arr[i - 1];
        }
    }

    // If no floor is found
    return -1;
}
*/

/**
 * @brief Finds the floor of `x` in a sorted array using binary search.
 * The floor of `x` is the largest element in the array which is less than or equal to `x`.
 * 
 * @param arr The sorted array.
 * @param n The size of the array.
 * @param x The value to find the floor for.
 * @return The floor of `x`, or -1 if no floor is found.
 */
int findFloor(int arr[], int n, int x) {
    if (x < arr[0]) {
        return -1;
    }

    int low = 0, high = n - 1;
    int floor = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return arr[mid];
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            floor = arr[mid];
            low = mid + 1;
        }
    }

    return floor;
}

/**
 * @brief Driver code to demonstrate the findCeiling and findFloor functions.
 * 
 * This function creates multiple test cases and calls the findCeiling and findFloor functions to find and print
 * the ceiling and floor of given values in a sorted array.
 * 
 * @return 0 on successful execution.
 */
int main() {
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int x = 5;
    assert(findCeiling(arr, n, x) == 8);
    assert(findFloor(arr, n, x) == 2);

    int x2 = 20;
    assert(findCeiling(arr, n, x2) == -1);
    assert(findFloor(arr, n, x2) == 19);

    int x3 = 0;
    assert(findCeiling(arr, n, x3) == 1);
    assert(findFloor(arr, n, x3) == -1);

    int x4 = 10;
    assert(findCeiling(arr, n, x4) == 10);
    assert(findFloor(arr, n, x4) == 10);

    int x5 = 2;
    assert(findCeiling(arr, n, x5) == 2);
    assert(findFloor(arr, n, x5) == 2);

    printf("All test cases passed successfully.\n");

    return 0; // Return 0 to indicate successful execution
}
