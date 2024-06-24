/*
 * Bubble Sort Algorithm
 *
 * Bubble sort is a simple comparison-based sorting algorithm. It repeatedly
 * steps through the list, compares adjacent elements, and swaps them if they
 * are in the wrong order. The pass through the list is repeated until the
 * list is sorted.
 *
 * Performance:
 * - Best Case Time Complexity: O(n) - when the input array is already sorted.
 * - Average Case Time Complexity: O(n^2) - when the input array is randomly ordered.
 * - Worst Case Time Complexity: O(n^2) - when the input array is reverse sorted.
 * - Space Complexity: O(1) - bubble sort is an in-place sorting algorithm.
 *
 * Bubble sort is not recommended for large data sets or performance-critical
 * applications due to its relatively slow average and worst-case time complexity.
 * However, it is simple to understand and implement, making it useful for
 * educational purposes or small data sets.
 */

#include <stdio.h>

/**
 * @brief Prints the elements of an array.
 * 
 * This function iterates through the array and prints each element.
 * 
 * @param arr The array to be printed.
 * @param len The number of elements in the array.
 */
void printf_array(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Sorts an array using bubble sort algorithm.
 * 
 * This function sorts an array in ascending order using the bubble sort algorithm.
 * It repeatedly steps through the list, compares adjacent elements, and swaps them
 * if they are in the wrong order. The pass through the list is repeated until the list is sorted.
 * 
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void bubble_sort(int *arr, int n) {
    // Outer loop for traversing through all elements
    for (int i = 0; i < n; i++) {
        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief Main function to test the bubble sort algorithm.
 * 
 * This function creates an unsorted array, sorts it using bubble sort,
 * and prints the sorted array.
 * 
 * @return int Returns 0 on successful execution.
 */
int main() {
    // Define and initialize an unsorted array
    int unsorted_array[5] = {5, 2, 8, 12, 3};
    // Calculate the number of elements in the array
    int n = sizeof(unsorted_array) / sizeof(unsorted_array[0]);

    // Sort the array using bubble sort
    bubble_sort(unsorted_array, n);
    // Print the sorted array
    printf_array(unsorted_array, n);

    return 0;
}
