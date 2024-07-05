/**
 * @file two_elements_whose_sum_is_closest_to_zero.c
 * @brief Provides functions to find two elements in an array whose sum is closest to zero.
 * 
 * This program demonstrates how to find two elements in an array whose sum is closest to zero.
 * 
 * @details 
 * The approaches include:
 * - **Brute Force**: Checks all pairs of elements to find the pair with the sum closest to zero.
 * - **Sorting + Two Pointers**: Sorts the array and uses two pointers to find the pair with the sum closest to zero.
 * 
 * @complexity
 * - **Brute Force**: O(n^2) time complexity because it checks all pairs.
 * - **Sorting + Two Pointers**: O(n log n) time complexity for sorting and O(n) for finding the pair, resulting in O(n log n) overall.
 * 
 * Author: Kiran Jojare
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * @brief Comparator function for qsort.
 * 
 * @param a Pointer to the first element.
 * @param b Pointer to the second element.
 * @return The difference between the two elements.
 */
int32_t compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/** 
 * @brief Finds two elements in an array whose sum is closest to zero using the Brute Force approach.
 * 
 * @param arr Array of integers.
 * @param n Number of elements in the array.
 */
/*
void sum_closest_to_zero_brute_force(int arr[], int n) {
    int min_sum = INT_MAX; // Initialize min_sum to maximum possible integer value
    int p = 0, q = 0; // Indices of the two elements

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] + arr[j]) < abs(min_sum)) {
                min_sum = arr[i] + arr[j]; // Update min_sum
                p = i;
                q = j;
            }
        }
    }
    printf("The two elements whose sum is closest to zero are %d and %d.\n", arr[p], arr[q]);
}
*/

/** 
 * @brief Finds two elements in an array whose sum is closest to zero using the Sorting + Two Pointers approach.
 * 
 * @param arr Array of integers.
 * @param n Number of elements in the array.
 */
void sum_closest_to_zero(int arr[], int n) {
    // Sort the array
    qsort(arr, n, sizeof(arr[0]), compare);

    // Initialize two pointers
    int left = 0;
    int right = n - 1;
    int p = 0;
    int q = 0;
    int min_sum = INT_MAX;

    // Use two pointers to find the pair with the sum closest to zero
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            p = left;
            q = right;
        }
        if (sum > 0) {
            right--;
        } else if (sum < 0) {
            left++;
        } else {
            // If sum is 0, this is the closest we can get to zero
            break;
        }
    }

    // Print the two elements whose sum is closest to zero
    printf("The two elements whose sum is closest to zero are %d and %d.\n", arr[p], arr[q]);
}

/**
 * @brief Driver code to demonstrate the sum_closest_to_zero function.
 * 
 * This function creates multiple test cases and calls the sum_closest_to_zero function to find and print
 * the two elements whose sum is closest to zero.
 * 
 * @return 0 on successful execution.
 */
int main() {
    int arr1[] = {1, 60, -10, 70, -80, 85}; // Example test case 1
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    sum_closest_to_zero(arr1, n1);

    // Additional test cases
    int arr2[] = {-7, 9, 5, 2, -4, 6}; // Example test case 2
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    sum_closest_to_zero(arr2, n2);

    int arr3[] = {15, 5, -20, 30, -45}; // Example test case 3
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    sum_closest_to_zero(arr3, n3);

    return 0; // Return 0 to indicate successful execution
}
