/**
 * Insertion Sort
 * 
 * Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time. 
 * It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. 
 * However, insertion sort provides several advantages such as simplicity, stability, and efficiency for small data sets or partially sorted arrays.
 * 
 * Algorithm:
 * 1. Start with the second element of the array.
 * 2. Compare the current element with the one before it.
 * 3. If the current element is smaller, shift the larger element to the right.
 * 4. Repeat step 3 until the current element is in its correct position.
 * 5. Move to the next element and repeat steps 2-4 until the entire array is sorted.
 * 
 * Performance:
 * - Best Case: O(n) - when the array is already sorted.
 * - Average Case: O(n^2) - when the array is partially sorted or contains random elements.
 * - Worst Case: O(n^2) - when the array is sorted in reverse order.
 * 
 * Note: Insertion sort is an in-place sorting algorithm, meaning it does not require any additional memory space.
 */

#include <stdio.h>
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
 * @brief Sorts an array using insertion sort algorithm.
 * 
 * This function sorts an array in ascending order using the insertion sort algorithm.
 * It builds the final sorted array one item at a time by comparing the current element with
 * the previous elements and shifting the larger elements to the right.
 * 
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // The element to be positioned
        int j = i - 1;

        // Shift elements of arr[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Place key at after the element just smaller than it.
    }
}

int main() {
    // Test case 1: Regular unsorted array
    int unsorted_array1[5] = {50, 20, 40, 10, 5};
    int n1 = sizeof(unsorted_array1) / sizeof(unsorted_array1[0]);

    // Test case 2: Array with negative numbers
    int unsorted_array2[5] = {-1, -3, -2, -5, -4};
    int n2 = sizeof(unsorted_array2) / sizeof(unsorted_array2[0]);

    // Test case 3: Array already sorted
    int sorted_array[5] = {1, 2, 3, 4, 5};
    int n3 = sizeof(sorted_array) / sizeof(sorted_array[0]);

    // Test case 4: Array sorted in reverse order
    int reverse_sorted_array[5] = {5, 4, 3, 2, 1};
    int n4 = sizeof(reverse_sorted_array) / sizeof(reverse_sorted_array[0]);

    // Test case 5: Array with duplicate elements
    int duplicate_array[5] = {3, 3, 2, 1, 2};
    int n5 = sizeof(duplicate_array) / sizeof(duplicate_array[0]);

    // Sort and print all test cases
    insertion_sort(unsorted_array1, n1);
    printf("Sorted array 1: ");
    printf_array(unsorted_array1, n1);

    insertion_sort(unsorted_array2, n2);
    printf("Sorted array 2: ");
    printf_array(unsorted_array2, n2);

    insertion_sort(sorted_array, n3);
    printf("Sorted array 3: ");
    printf_array(sorted_array, n3);

    insertion_sort(reverse_sorted_array, n4);
    printf("Sorted array 4: ");
    printf_array(reverse_sorted_array, n4);

    insertion_sort(duplicate_array, n5);
    printf("Sorted array 5: ");
    printf_array(duplicate_array, n5);

    return 0;
}
