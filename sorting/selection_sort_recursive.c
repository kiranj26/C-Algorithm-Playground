/**
 * @file recursive_selection_sort.c
 * @brief Implementation of the Recursive Selection Sort Algorithm.
 *
 * @details
 * The recursive selection sort algorithm is a variation of the selection sort algorithm
 * that uses recursion to sort an array in ascending order. It works by dividing the
 * array into two parts: the sorted part and the unsorted part. In each iteration, it
 * finds the minimum element from the unsorted part and swaps it with the first element
 * of the unsorted part, thus expanding the sorted part by one element.
 *
 * @section Performance
 * - Time Complexity: O(n^2)
 *   - Best Case: O(n^2) - Even if the array is already sorted, the algorithm still performs
 *     n^2/2 comparisons.
 *   - Average Case: O(n^2) - The algorithm performs n^2/2 comparisons on average, where n
 *     is the number of elements in the array.
 *   - Worst Case: O(n^2) - The algorithm performs n^2/2 comparisons in the worst case.
 * - Space Complexity: O(n)
 *   - The recursive implementation uses stack space proportional to the number of
 *     elements in the array. Each recursive call adds a new frame to the call stack, which
 *     takes up additional memory.
 *   - The algorithm is not in-place with respect to the call stack usage but does not require
 *     any additional arrays or data structures.
 *
 * Although the recursive selection sort algorithm has the same time complexity as the
 * iterative selection sort algorithm, it uses recursion to achieve the sorting process.
 * This recursive approach can be useful in certain scenarios or for educational purposes.
 *
 * @section Algorithm Steps
 * 1. If the array has only one element or is empty, it is already sorted.
 * 2. Find the minimum element in the unsorted part of the array.
 * 3. Swap the minimum element with the first element of the unsorted part.
 * 4. Recursively call the selection sort function on the remaining unsorted part.
 *
 * @section Example Usage
 * @code
 * int arr[] = {5, 2, 8, 12, 3};
 * int n = sizeof(arr) / sizeof(arr[0]);
 * selection_sort_recursive(arr, 0, n);
 * @endcode
 *
 * This implementation assumes that the array contains integers.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Prints the elements of an array.
 * 
 * This function iterates through the array and prints each element.
 * 
 * @param arr The array to be printed.
 * @param length The number of elements in the array.
 */
void printf_array(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Recursive function to perform selection sort.
 * 
 * This function sorts an array in ascending order using the recursive selection sort algorithm.
 * It divides the array into a sorted and an unsorted part, finds the minimum element in the unsorted
 * part, and swaps it with the first element of the unsorted part. The process is repeated recursively
 * for the remaining unsorted part.
 * 
 * @param arr The array to be sorted.
 * @param start The starting index of the unsorted part of the array.
 * @param length The number of elements in the array.
 */
void selection_sort_recursive(int *arr, int start, int length) {
    // Base case: If the array has only one element or is empty, it is already sorted
    if (start >= length - 1) {
        return;
    }

    // Find the minimum element in the unsorted part of the array
    int min_index = start;
    for (int i = start + 1; i < length; i++) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
    }

    // Swap the minimum element with the first element of the unsorted part
    int temp = arr[start];
    arr[start] = arr[min_index];
    arr[min_index] = temp;

    // Recursively call the selection sort function on the remaining unsorted part
    selection_sort_recursive(arr, start + 1, length);
}

int main() {
    // Test case 1: Regular unsorted array
    int unsorted_array1[5] = {5, 2, 8, 12, 3};
    int n1 = sizeof(unsorted_array1) / sizeof(unsorted_array1[0]);
    selection_sort_recursive(unsorted_array1, 0, n1);
    printf("Sorted array 1: ");
    printf_array(unsorted_array1, n1);

    // Test case 2: Array with negative numbers
    int unsorted_array2[6] = {-3, 10, -1, 7, -20, 5};
    int n2 = sizeof(unsorted_array2) / sizeof(unsorted_array2[0]);
    selection_sort_recursive(unsorted_array2, 0, n2);
    printf("Sorted array 2: ");
    printf_array(unsorted_array2, n2);

    // Test case 3: Already sorted array
    int sorted_array[5] = {1, 2, 3, 4, 5};
    int n3 = sizeof(sorted_array) / sizeof(sorted_array[0]);
    selection_sort_recursive(sorted_array, 0, n3);
    printf("Sorted array 3: ");
    printf_array(sorted_array, n3);

    // Test case 4: Array with all elements the same
    int same_elements_array[4] = {5, 5, 5, 5};
    int n4 = sizeof(same_elements_array) / sizeof(same_elements_array[0]);
    selection_sort_recursive(same_elements_array, 0, n4);
    printf("Sorted array 4: ");
    printf_array(same_elements_array, n4);

    // Test case 5: Array with a single element
    int single_element_array[1] = {42};
    int n5 = sizeof(single_element_array) / sizeof(single_element_array[0]);
    selection_sort_recursive(single_element_array, 0, n5);
    printf("Sorted array 5: ");
    printf_array(single_element_array, n5);

    // Test case 6: Empty array
    int empty_array[0] = {};
    int n6 = sizeof(empty_array) / sizeof(empty_array[0]);
    selection_sort_recursive(empty_array, 0, n6);
    printf("Sorted array 6: ");
    printf_array(empty_array, n6);

    return 0;
}
