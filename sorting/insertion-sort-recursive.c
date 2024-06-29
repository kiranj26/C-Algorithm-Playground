/**
 * @file recursive_insertion_sort.c
 * @brief Implementation of the Recursive Insertion Sort Algorithm.
 *
 * @details
 * Recursive Insertion Sort is a sorting algorithm that builds the final sorted array one element at a time.
 * It is a variation of the Insertion Sort algorithm, but instead of using nested loops, it uses recursion to
 * sort the array. The algorithm divides the array into a sorted and an unsorted part. It then takes the first
 * element from the unsorted part and inserts it into its correct position in the sorted part. This process is
 * repeated until the entire array is sorted.
 *
 * @section Performance
 * - Best Case Time Complexity: O(n)
 * - Average Case Time Complexity: O(n^2)
 * - Worst Case Time Complexity: O(n^2)
 * - Space Complexity: O(n) (due to the recursive call stack)
 *
 * The performance of Recursive Insertion Sort is similar to that of the regular Insertion Sort algorithm.
 * It performs well for small arrays or partially sorted arrays, but it becomes inefficient for large arrays
 * or arrays with a random order of elements.
 */

#include <stdio.h>

/**
 * @brief Recursive function to sort an array using insertion sort.
 * 
 * This function sorts the first n elements of the array in ascending order using recursion.
 * It sorts the first n-1 elements, and then inserts the nth element into the sorted subarray.
 * 
 * @param arr The array to be sorted.
 * @param n The number of elements to be sorted.
 */
void recursiveInsertionSort(int arr[], int n) {
    // Base case: If the array has one or zero elements, it is already sorted.
    if (n <= 1) {
        return;
    }

    // Recursively sort the first n-1 elements of the array.
    recursiveInsertionSort(arr, n - 1);

    // Insert the nth element into the sorted subarray.
    int key = arr[n - 1];
    int j = n - 2;

    // Shift elements of arr[0..n-2], that are greater than key, to one position ahead.
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = key; // Place the key at its correct position.
}

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

int main() {
    // Test case 1: Regular unsorted array
    int arr1[] = {5, 2, 8, 12, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Original array 1: ");
    printf_array(arr1, n1);
    recursiveInsertionSort(arr1, n1);
    printf("Sorted array 1: ");
    printf_array(arr1, n1);

    // Test case 2: Array with negative numbers
    int arr2[] = {-1, -3, -2, -5, -4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Original array 2: ");
    printf_array(arr2, n2);
    recursiveInsertionSort(arr2, n2);
    printf("Sorted array 2: ");
    printf_array(arr2, n2);

    // Test case 3: Array already sorted
    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Original array 3: ");
    printf_array(arr3, n3);
    recursiveInsertionSort(arr3, n3);
    printf("Sorted array 3: ");
    printf_array(arr3, n3);

    // Test case 4: Array sorted in reverse order
    int arr4[] = {5, 4, 3, 2, 1};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("Original array 4: ");
    printf_array(arr4, n4);
    recursiveInsertionSort(arr4, n4);
    printf("Sorted array 4: ");
    printf_array(arr4, n4);

    // Test case 5: Array with duplicate elements
    int arr5[] = {3, 3, 2, 1, 2};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("Original array 5: ");
    printf_array(arr5, n5);
    recursiveInsertionSort(arr5, n5);
    printf("Sorted array 5: ");
    printf_array(arr5, n5);

    return 0;
}
