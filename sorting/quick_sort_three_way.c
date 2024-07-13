/**
 * @file quick_sort_three_way.c
 * @brief Implementation of the Three-Way Quick Sort Algorithm.
 *
 * @details
 * Three-Way Quick sort is an efficient comparison-based sorting algorithm. It works by selecting a 'pivot' element 
 * from the array and partitioning the other elements into three sub-arrays, according to whether they are 
 * less than, equal to, or greater than the pivot. The sub-arrays are then sorted recursively.
 *
 * @section Performance
 * - Best Case Time Complexity: O(n log n) - when the pivot divides the array into balanced parts.
 * - Average Case Time Complexity: O(n log n) - on average, the pivot will divide the array into balanced parts.
 * - Worst Case Time Complexity: O(n^2) - when the pivot divides the array into highly unbalanced parts (e.g., already sorted array with many duplicates).
 * - Space Complexity: O(log n) - due to the recursion stack.
 *
 * Three-Way Quick sort is particularly useful for arrays with many duplicate keys.
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
 * @brief Partitions the array for three-way quick sort.
 * 
 * This function partitions the array into three parts: elements less than the pivot,
 * elements equal to the pivot, and elements greater than the pivot.
 * 
 * @param arr The array to be partitioned.
 * @param low The starting index of the array segment to be partitioned.
 * @param high The ending index of the array segment to be partitioned.
 * @param lt Pointer to the index of the end of the 'less than pivot' segment.
 * @param gt Pointer to the index of the start of the 'greater than pivot' segment.
 */
void three_way_partition(int *arr, int low, int high, int *lt, int *gt) {
    int pivot = arr[low];
    int i = low;
    *lt = low;
    *gt = high;

    while (i <= *gt) {
        if (arr[i] < pivot) {
            swap(&arr[i], &arr[*lt]);
            (*lt)++;
            i++;
        } else if (arr[i] > pivot) {
            swap(&arr[i], &arr[*gt]);
            (*gt)--;
        } else {
            i++;
        }
    }
}

/**
 * @brief Sorts an array using three-way quick sort algorithm.
 * 
 * This function sorts an array in ascending order using the three-way quick sort algorithm.
 * It recursively partitions the array and sorts the sub-arrays.
 * 
 * @param arr The array to be sorted.
 * @param low The starting index of the array segment to be sorted.
 * @param high The ending index of the array segment to be sorted.
 */
void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int lt, gt;
        three_way_partition(arr, low, high, &lt, &gt);

        quick_sort(arr, low, lt - 1);
        quick_sort(arr, gt + 1, high);
    }
}

/**
 * @brief Main function to test the three-way quick sort algorithm.
 * 
 * This function creates an unsorted array, sorts it using three-way quick sort,
 * and prints the sorted array.
 * 
 * @return int Returns 0 on successful execution.
 */
int main() {
    // Define and initialize an unsorted array
    int unsorted_array[10] = {4, 9, 4, 4, 2, 3, 4, 9, 2, 9};
    // Calculate the number of elements in the array
    int n = sizeof(unsorted_array) / sizeof(unsorted_array[0]);

    // Sort the array using three-way quick sort
    quick_sort(unsorted_array, 0, n - 1);
    // Print the sorted array
    printf_array(unsorted_array, n);

    return 0;
}


