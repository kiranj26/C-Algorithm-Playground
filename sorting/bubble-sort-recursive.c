/**
 * @file recursive_bubble_sort.c
 * @brief Implementation of the Recursive Bubble Sort Algorithm.
 *
 * @details
 * Bubble sort is a simple comparison-based sorting algorithm. It repeatedly
 * steps through the list, compares adjacent elements, and swaps them if they
 * are in the wrong order. The pass through the list is repeated until the
 * list is sorted.
 *
 * In the recursive version of bubble sort, the algorithm works as follows:
 * - Base Case: If the array has one or zero elements, it is already sorted.
 * - Recursive Case: Perform one pass of bubble sort to move the largest element
 *   to the end of the array. Then, recursively sort the remaining unsorted part
 *   of the array.
 *
 * @section Performance
 * - Best Case Time Complexity: O(n) - when the input array is already sorted.
 * - Average Case Time Complexity: O(n^2) - when the input array is randomly ordered.
 * - Worst Case Time Complexity: O(n^2) - when the input array is reverse sorted.
 * - Space Complexity: O(n) - due to the recursion stack.
 *
 * Bubble sort is not recommended for large data sets or performance-critical
 * applications due to its relatively slow average and worst-case time complexity.
 * However, it is simple to understand and implement, making it useful for
 * educational purposes or small data sets.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
 * @brief Sorts an array using recursive bubble sort algorithm.
 * 
 * This function sorts an array in ascending order using the bubble sort algorithm.
 * It repeatedly steps through the list, compares adjacent elements, and swaps them
 * if they are in the wrong order. The pass through the list is repeated until the
 * list is sorted. This version uses recursion to achieve the sorting.
 * 
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void bubble_sort_recursive(int *arr, int n) {
    // Base case: If the array has one or zero elements, it is already sorted
    if (n == 1) {
        return;
    }

    // Perform one pass of bubble sort to move the largest element to the end
    for (int i = 0; i < n - 1; i++) {
        // Swap if the current element is greater than the next element
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // Recursively call the function to sort the remaining unsorted part of the array
    bubble_sort_recursive(arr, n - 1);
}

/**
 * @brief Main function to test the recursive bubble sort algorithm.
 * 
 * This function creates an unsorted array, sorts it using recursive bubble sort,
 * and prints the sorted array.
 * 
 * @return int Returns 0 on successful execution.
 */
int main() {
    // Define and initialize an unsorted array
    int unsorted_array[5] = {5, 2, 8, 12, 3};
    // Calculate the number of elements in the array
    int n = sizeof(unsorted_array) / sizeof(unsorted_array[0]);

    // Sort the array using recursive bubble sort
    bubble_sort_recursive(unsorted_array, n);
    // Print the sorted array
    printf_array(unsorted_array, n);

    return 0;
}
