/**
 * @file radix_sort_simple.c
 * @brief Provides functions to sort an array using the Radix Sort algorithm.
 * 
 * This program demonstrates the Radix Sort algorithm to sort an array.
 * 
 * @details 
 * The steps include:
 * - **Find the Maximum Number**: Determine the maximum number to know the number of digits.
 * - **Counting Sort for Each Digit**: Use counting sort to sort the array based on each digit. Start from the least significant digit (LSD) to the most significant digit (MSD).
 * 
 * Pseudo Code:
 * 1. Find the maximum number to know the number of digits.
 * 2. Initialize the count array and output array.
 * 3. Use counting sort for each digit from least significant to most significant.
 * 4. Place elements in the output array based on the count array.
 * 5. Copy the sorted elements back to the original array.
 * 
 * Radix Sort is used for sorting integers by processing individual digits.
 * 
 * @complexity
 * - **Time Complexity**: O(d * (n + k))
 * - **Space Complexity**: O(n + k)
 * 
 * @approach Explanation:
 * - **Radix Sort**: An efficient sorting algorithm for integers.
 * 
 * @reference
 * - https://www.geeksforgeeks.org/radix-sort/
 * 
 * Advantages of Radix Sort:
 * - Radix sort generally performs faster than comparison-based sorting algorithms, such as merge sort and quicksort, for large datasets.
 * - Radix sort is a stable sorting algorithm.
 * 
 * Disadvantages of Radix Sort:
 * - Radix sort is inefficient for large ranges of values.
 * - Radix sort is not an in-place sorting algorithm. It uses extra space for sorting the array elements.
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
 * @brief Perform counting sort on an array based on the digit represented by exp.
 * 
 * @param arr The array to be sorted.
 * @param n The size of the array.
 * @param exp The exponent representing the digit position.
 */
void countingSort(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int)); // Output array
    int count[10] = {0}; // Count array for digits 0-9

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Accumulate counts to get the prefix sum
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Place elements in the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output); // Free the allocated memory for the output array
}

/**
 * @brief Perform radix sort on an array.
 * 
 * @param arr The array to be sorted.
 * @param n The size of the array.
 */
void radixSort(int arr[], int n) {
    int max = findMax(arr, n); // Find the maximum value in the array

    // Perform counting sort for each digit (exponentially increasing)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
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
 * @brief Driver code to demonstrate the radixSort function.
 * 
 * This function creates multiple test cases and calls the radixSort function to sort arrays.
 * It then prints and verifies the sorted arrays using assertions.
 * 
 * @return 0 on successful execution.
 */
int main() {
    int arr1[] = {170, 45, 75, 90, 802, 24, 2, 66}; // Test case 1
    int n1 = sizeof(arr1) / sizeof(arr1[0]); // Calculate the size of the array
    radixSort(arr1, n1); // Sort the array
    printArray(arr1, n1); // Print the sorted array
    int expected1[] = {2, 24, 45, 66, 75, 90, 170, 802}; // Expected result
    for (int i = 0; i < n1; i++) {
        assert(arr1[i] == expected1[i]); // Assert to verify the result
    }

    int arr2[] = {4, 3, 1, 4, 2, 7, 9, 8}; // Test case 2
    int n2 = sizeof(arr2) / sizeof(arr2[0]); // Calculate the size of the array
    radixSort(arr2, n2); // Sort the array
    printArray(arr2, n2); // Print the sorted array
    int expected2[] = {1, 2, 3, 4, 4, 7, 8, 9}; // Expected result
    for (int i = 0; i < n2; i++) {
        assert(arr2[i] == expected2[i]); // Assert to verify the result
    }

    int arr3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; // Test case 3
    int n3 = sizeof(arr3) / sizeof(arr3[0]); // Calculate the size of the array
    radixSort(arr3, n3); // Sort the array
    printArray(arr3, n3); // Print the sorted array
    int expected3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Expected result
    for (int i = 0; i < n3; i++) {
        assert(arr3[i] == expected3[i]); // Assert to verify the result
    }

    printf("All test cases passed successfully.\n");

    return 0; // Return 0 to indicate successful execution
}
