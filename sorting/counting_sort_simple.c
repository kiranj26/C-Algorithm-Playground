/**
 * @file counting_sort_simple.c
 * @brief Provides functions to sort an array using the Counting Sort algorithm.
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
 * Pseudo Code:
 * 1. Declare an auxiliary array countArray[] of size max(inputArray[])+1 and initialize it with 0.
 * 2. Traverse array inputArray[] and map each element of inputArray[] as an index of countArray[] array,
 *    i.e., execute countArray[inputArray[i]]++ for 0 <= i < N.
 * 3. Calculate the prefix sum at every index of array inputArray[].
 * 4. Create an array outputArray[] of size N.
 * 5. Traverse array inputArray[] from end and update outputArray[countArray[inputArray[i]] – 1] = inputArray[i].
 *    Also, update countArray[inputArray[i]] = countArray[inputArray[i]] - 1.
 * 
 * Counting Sort is used when the range of input is small even if the number of inputs is large.
 * 
 * @complexity
 * - **Time Complexity**: O(n + k)
 * - **Space Complexity**: O(n + k)
 * 
 * @approach Explanation:
 * - **Counting Sort**: An efficient sorting algorithm for small ranges of integer values.
 * 
 * @reference
 * - https://www.geeksforgeeks.org/counting-sort/
 * 
 * Advantages of Counting Sort:
 * - Counting sort generally performs faster than all comparison-based sorting algorithms, such as merge sort and quicksort,
 *   if the range of input is of the order of the number of inputs.
 * - Counting sort is easy to code.
 * - Counting sort is a stable algorithm.
 * 
 * Disadvantages of Counting Sort:
 * - Counting sort doesn’t work on decimal values.
 * - Counting sort is inefficient if the range of values to be sorted is very large.
 * - Counting sort is not an in-place sorting algorithm. It uses extra space for sorting the array elements.
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
    int max = arr[0]; // Initialize max with the first element
    for (int i = 1; i < n; i++) { // Iterate through the array
        if (arr[i] > max) { // Update max if current element is greater
            max = arr[i];
        }
    }
    return max; // Return the maximum value
}

/**
 * @brief Perform counting sort on an array.
 * 
 * @param arr The array to be sorted.
 * @param n The size of the array.
 */
void countingSort(int arr[], int n) {
    int max = findMax(arr, n); // Find the maximum value in the array
    int *count = (int *)calloc(max + 1, sizeof(int)); // Initialize count array
    int *output = (int *)malloc(n * sizeof(int)); // Initialize output array

    // Count the occurrences of each value
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Accumulate counts to get the prefix sum
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Place elements in the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count); // Free the allocated memory for count array
    free(output); // Free the allocated memory for output array
}

/**
 * @brief Print an array.
 * 
 * @param arr The array to be printed.
 * @param n The size of the array.
 */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) { // Iterate through the array
        printf("%d ", arr[i]); // Print each element
    }
    printf("\n"); // Print a new line
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
    int arr1[] = {4, 2, 2, 8, 3, 3, 1}; // Test case 1
    int n1 = sizeof(arr1) / sizeof(arr1[0]); // Calculate the size of the array
    countingSort(arr1, n1); // Sort the array
    printArray(arr1, n1); // Print the sorted array
    int expected1[] = {1, 2, 2, 3, 3, 4, 8}; // Expected result
    for (int i = 0; i < n1; i++) {
        assert(arr1[i] == expected1[i]); // Assert to verify the result
    }

    int arr2[] = {7, 1, 3, 9, 7, 6, 2}; // Test case 2
    int n2 = sizeof(arr2) / sizeof(arr2[0]); // Calculate the size of the array
    countingSort(arr2, n2); // Sort the array
    printArray(arr2, n2); // Print the sorted array
    int expected2[] = {1, 2, 3, 6, 7, 7, 9}; // Expected result
    for (int i = 0; i < n2; i++) {
        assert(arr2[i] == expected2[i]); // Assert to verify the result
    }

    int arr3[] = {4, 3, 2, 1, 4, 3, 2, 1}; // Test case 3
    int n3 = sizeof(arr3) / sizeof(arr3[0]); // Calculate the size of the array
    countingSort(arr3, n3); // Sort the array
    printArray(arr3, n3); // Print the sorted array
    int expected3[] = {1, 1, 2, 2, 3, 3, 4, 4}; // Expected result
    for (int i = 0; i < n3; i++) {
        assert(arr3[i] == expected3[i]); // Assert to verify the result
    }

    printf("All test cases passed successfully.\n");

    return 0; // Return 0 to indicate successful execution
}
