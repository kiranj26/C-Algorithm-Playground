/**
 * @file quick_sort_dual_pivot.c
 * @brief Implementation of the Dual-Pivot Quick Sort Algorithm.
 *
 * @details
 * Dual-Pivot Quick sort is an efficient comparison-based sorting algorithm. It works by selecting two 'pivot' elements 
 * from the array and partitioning the other elements into three sub-arrays, according to whether they are 
 * less than the first pivot, between the two pivots, or greater than the second pivot. The sub-arrays are then sorted recursively.
 *
 * @section Performance
 * - Best Case Time Complexity: O(n log n) - when the pivots divide the array into balanced parts.
 * - Average Case Time Complexity: O(n log n) - on average, the pivots will divide the array into balanced parts.
 * - Worst Case Time Complexity: O(n^2) - when the pivots divide the array into highly unbalanced parts (e.g., already sorted array).
 * - Space Complexity: O(log n) - due to the recursion stack.
 *
 * Dual-Pivot Quick sort can be faster than traditional quicksort by reducing the number of comparisons and swaps.
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
 * @brief Swaps two elements in an array.
 * 
 * This function swaps the values of two elements in the array.
 * 
 * @param a Pointer to the first element.
 * @param b Pointer to the second element.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Partitions the array for dual-pivot quick sort.
 * 
 * This function partitions the array into three parts: elements less than the first pivot,
 * elements between the two pivots, and elements greater than the second pivot.
 * 
 * @param arr The array to be partitioned.
 * @param low The starting index of the array segment to be partitioned.
 * @param high The ending index of the array segment to be partitioned.
 * @param lp Pointer to the index of the first pivot after partitioning.
 * @param rp Pointer to the index of the second pivot after partitioning.
 */
void dual_pivot_partition(int *arr, int low, int high, int *lp, int *rp) {
    if (arr[low] > arr[high]) {
        swap(&arr[low], &arr[high]);
    }
    int pivot1 = arr[low];
    int pivot2 = arr[high];
    int i = low + 1;
    int lt = low + 1;
    int gt = high - 1;

    while (i <= gt) {
        if (arr[i] < pivot1) {
            swap(&arr[i], &arr[lt]);
            lt++;
        } else if (arr[i] > pivot2) {
            swap(&arr[i], &arr[gt]);
            gt--;
            i--;
        }
        i++;
    }
    lt--;
    gt++;
    swap(&arr[low], &arr[lt]);
    swap(&arr[high], &arr[gt]);
    *lp = lt;
    *rp = gt;
}

/**
 * @brief Sorts an array using dual-pivot quick sort algorithm.
 * 
 * This function sorts an array in ascending order using the dual-pivot quick sort algorithm.
 * It recursively partitions the array and sorts the sub-arrays.
 * 
 * @param arr The array to be sorted.
 * @param low The starting index of the array segment to be sorted.
 * @param high The ending index of the array segment to be sorted.
 */
void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int lp, rp;
        dual_pivot_partition(arr, low, high, &lp, &rp);

        quick_sort(arr, low, lp - 1);
        quick_sort(arr, lp + 1, rp - 1);
        quick_sort(arr, rp + 1, high);
    }
}

/**
 * @brief Main function to test the dual-pivot quick sort algorithm.
 * 
 * This function creates an unsorted array, sorts it using dual-pivot quick sort,
 * and prints the sorted array.
 * 
 * @return int Returns 0 on successful execution.
 */
int main() {
    // Define and initialize an unsorted array
    int unsorted_array[10] = {4, 9, 4, 4, 2, 3, 4, 9, 2, 9};
    // Calculate the number of elements in the array
    int n = sizeof(unsorted_array) / sizeof(unsorted_array[0]);

    // Sort the array using dual-pivot quick sort
    quick_sort(unsorted_array, 0, n - 1);
    // Print the sorted array
    printf_array(unsorted_array, n);

    return 0;
}


