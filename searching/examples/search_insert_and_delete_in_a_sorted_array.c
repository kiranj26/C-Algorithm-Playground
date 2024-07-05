/**
 * @file search_insert_delete_in_a_sorted_array.c
 * @brief Provides functions to search, insert, and delete elements in a sorted array.
 * 
 * This program demonstrates how to perform search, insert, and delete operations on a sorted array.
 * 
 * @details 
 * The operations include:
 * - **Search**: Uses binary search to find the index of an element in a sorted array.
 * - **Insert**: Inserts an element into its correct position in a sorted array.
 * - **Delete**: Deletes an element from a sorted array and maintains the sorted order.
 * 
 * @complexity
 * - **Search**: O(log n) time complexity due to binary search.
 * - **Insert**: O(n) time complexity because elements may need to be shifted.
 * - **Delete**: O(n) time complexity because elements may need to be shifted.
 * 
 * Author: Kiran Jojare
 */

#include <stdio.h>

/**
 * @brief Searches for an element in a sorted array.
 * 
 * @param arr Array of integers.
 * @param n Number of elements in the array.
 * @param x Element to search for.
 * @return Index of the element if found, -1 otherwise.
 */
int search(int arr[], int n, int x) {
    int low = 0, high = n - 1; // Initialize low and high pointers
    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate mid index
        if (arr[mid] == x) return mid; // Element found
        else if (arr[mid] < x) low = mid + 1; // Search in the right half
        else high = mid - 1; // Search in the left half
    }
    return -1; // Element not found
}

/**
 * @brief Inserts an element into a sorted array.
 * 
 * @param arr Array of integers.
 * @param n Pointer to the number of elements in the array.
 * @param x Element to insert.
 * @param capacity Maximum capacity of the array.
 * @return New size of the array.
 */
int insert(int arr[], int *n, int x, int capacity) {
    if (*n >= capacity) return *n; // Array is full

    int i;
    for (i = *n - 1; (i >= 0 && arr[i] > x); i--) {
        arr[i + 1] = arr[i]; // Shift elements to the right
    }
    arr[i + 1] = x; // Insert the new element
    (*n)++;
    return *n;
}

/**
 * @brief Deletes an element from a sorted array.
 * 
 * @param arr Array of integers.
 * @param n Pointer to the number of elements in the array.
 * @param x Element to delete.
 * @return New size of the array.
 */
int delete(int arr[], int *n, int x) {
    int pos = search(arr, *n, x); // Find the position of the element to delete
    if (pos == -1) return *n; // Element not found

    // Shift elements to the left to fill the gap
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    return *n;
}

/**
 * @brief Driver code to demonstrate search, insert, and delete operations.
 * 
 * This function creates an array of integers, performs search, insert, and delete operations,
 * and prints the results.
 * 
 * @return 0 on successful execution.
 */
int main() {
    int arr[20] = {2, 3, 5, 7, 11, 13, 17}; // Example array
    int n = 7; // Initial number of elements in the array
    int capacity = sizeof(arr) / sizeof(arr[0]);

    // Demonstrate search
    int searchIndex = search(arr, n, 11); // Search for element 11
    printf("Element 11 is at index: %d\n", searchIndex); // Print the result

    // Demonstrate insert
    n = insert(arr, &n, 8, capacity); // Insert element 8
    printf("After inserting 8, array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]); // Print the array
    printf("\n");

    // Demonstrate delete
    n = delete(arr, &n, 3); // Delete element 3
    printf("After deleting 3, array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]); // Print the array
    printf("\n");

    return 0; // Return 0 to indicate successful execution
}
