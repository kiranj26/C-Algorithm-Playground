/**
 * @file counting_sort_recursive.c
 * @brief Provides functions to sort an array using the Counting Sort algorithm (recursive version).
 * 
 * This program demonstrates the Counting Sort algorithm to sort an array.
 * 
 * @details 
 * The steps include:
 * - **Find the Range**: Determine the range (minimum and maximum values) of the input data.
 * - **Count Occurrences**: Create a count array and count the occurrences of each unique value.
 * - **Accumulate Counts**: Modify the count array such that each element at each index stores the sum of previous counts.
 * - **Place Elements**: Place the elements in the output array based on the count array and decrement the counts accordingly.
 * 
 * @complexity
 * - **Time Complexity**: O(n + k)
 * - **Space Complexity**: O(n + k)
 * 
 * @approach Explanation:
 * - **Counting Sort**: An efficient sorting algorithm for small ranges of integer values.
 * 
 * Author: Kiran Jojare
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @brief Find the maximum value in an array.
 * 
 * @param arr The input array.
 * @param n The size of the array.
 * @return The maximum value in the array.
 */
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/**
 * @brief Recursively accumulate the counts.
 * 
 * @param count The count array.
 * @param max The maximum value in the input array.
 * @param i The current index.
 */
void accumulateCounts(int count[], int max, int i) {
    if (i > max) {
        return;
    }
    count[i] += count[i - 1];
    accumulateCounts(count, max, i + 1);
}

/**
 * @brief Place elements in the output array based on the count array recursively.
 * 
 * @param arr The input array.
 * @param output The output array.
 * @param count The count array.
 * @param n The size of the input array.
 * @param i The current index.
 */
void placeElements(int arr[], int output[], int count[], int n, int i) {
    if (i < 0) {
        return;
    }
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
    placeElements(arr, output, count, n, i - 1);
}

/**
 * @brief Perform counting sort on an array using a recursive approach.
 * 
 * @param arr The array to be sorted.
 * @param n The size of the array.
 */
void countingSort(int arr[], int n) {
    int max = findMax(arr, n);
    int *count = (int *)calloc(max + 1, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    // Count the occurrences of each value
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Accumulate counts recursively
    if (max > 0) {
        accumulateCounts(count, max, 1);
    }

    // Place elements in the output array recursively
    placeElements(arr, output, count, n, n - 1);

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

/**
 * @brief Print an array.
 * 
 * @param arr The array to be printed.
 * @param n The size of the array.
 */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Driver code to demonstrate the countingSort function.
 * 
 * This function creates multiple test cases and calls the countingSort function to sort arrays.
 * It then prints and verifies the sorted arrays using assertions.
 * 
 * @return 0 on successful execution.
 */
int main() {
    int arr1[] = {4, 2, 2, 8, 3, 3, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    countingSort(arr1, n1);
    printArray(arr1, n1);
    int expected1[] = {1, 2, 2, 3, 3, 4, 8};
    for (int i = 0; i < n1; i++) {
        assert(arr1[i] == expected1[i]);
    }

    int arr2[] = {7, 1, 3, 9, 7, 6, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    countingSort(arr2, n2);
    printArray(arr2, n2);
    int expected2[] = {1, 2, 3, 6, 7, 7, 9};
    for (int i = 0; i < n2; i++) {
        assert(arr2[i] == expected2[i]);
    }

    int arr3[] = {4, 3, 2, 1, 4, 3, 2, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    countingSort(arr3, n3);
    printArray(arr3, n3);
    int expected3[] = {1, 1, 2, 2, 3, 3, 4, 4};
    for (int i = 0; i < n3; i++) {
        assert(arr3[i] == expected3[i]);
    }

    printf("All test cases passed successfully.\n");

    return 0; // Return 0 to indicate successful execution
}


