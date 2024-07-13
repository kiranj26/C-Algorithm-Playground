/**
 * @file quick_sort_simple.c
 * @brief Implementation of the Quick Sort Algorithm.
 *
 * @details
 * Quick sort is an efficient comparison-based sorting algorithm. It works by selecting a 'pivot' element 
 * from the array and partitioning the other elements into two sub-arrays, according to whether they are 
 * less than or greater than the pivot. The sub-arrays are then sorted recursively.
 *
 * @section Performance
 * - Best Case Time Complexity: O(n log n) - when the pivot divides the array into two equal parts.
 * - Average Case Time Complexity: O(n log n) - on average, the pivot will divide the array into balanced parts.
 * - Worst Case Time Complexity: O(n^2) - when the pivot divides the array into highly unbalanced parts (e.g., already sorted array).
 * - Space Complexity: O(log n) - due to the recursion stack.
 *
 * Quick sort is generally faster than other O(n log n) algorithms and is widely used in practice for large data sets.
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
 * @brief Partitions the array for quick sort.
 * 
 * This function partitions the array by selecting a pivot element and ensuring all elements less than
 * the pivot are on the left of the pivot and all elements greater than the pivot are on the right.
 * 
 * @param arr The array to be partitioned.
 * @param low The starting index of the array segment to be partitioned.
 * @param high The ending index of the array segment to be partitioned.
 * @return int The index of the pivot element after partitioning.
 */
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/**
 * @brief Sorts an array using quick sort algorithm.
 * 
 * This function sorts an array in ascending order using the quick sort algorithm.
 * It recursively partitions the array and sorts the sub-arrays.
 * 
 * @param arr The array to be sorted.
 * @param low The starting index of the array segment to be sorted.
 * @param high The ending index of the array segment to be sorted.
 */
void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

/**
 * @brief Main function to test the quick sort algorithm.
 * 
 * This function creates an unsorted array, sorts it using quick sort,
 * and prints the sorted array.
 * 
 * @return int Returns 0 on successful execution.
 */
int main() {
    // Define and initialize an unsorted array
    int unsorted_array[5] = {5, 2, 8, 12, 3};
    // Calculate the number of elements in the array
    int n = sizeof(unsorted_array) / sizeof(unsorted_array[0]);

    // Sort the array using quick sort
    quick_sort(unsorted_array, 0, n - 1);
    // Print the sorted array
    printf_array(unsorted_array, n);

    return 0;
}


