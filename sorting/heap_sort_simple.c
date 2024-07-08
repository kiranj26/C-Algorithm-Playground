/**
 * @file heap_sort_simple.c
 * @brief Provides functions to sort an array using the Heap Sort algorithm.
 * 
 * This program demonstrates the Heap Sort algorithm to sort an array.
 * 
 * @details 
 * The steps include:
 * - **Build a Max Heap** from the input data.
 * - **Heapify** the heap to maintain the heap property.
 * - **Extract the maximum element** from the heap and swap it with the last element in the heap.
 * - **Repeat** the process for the reduced heap until all elements are sorted.
 * 
 * @complexity
 * - **Time Complexity**: O(n log n)
 * - **Space Complexity**: O(1)
 * 
 * @approach Explanation:
 * - **Build a Max Heap**: Rearrange the array elements to form a max heap.
 * - **Heapify**: Ensure that the heap property is maintained for all nodes.
 * - **Extract Maximum**: Swap the maximum element with the last element and reduce the heap size.
 * 
 * Author: Kiran Jojare
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @brief Swap two elements in an array.
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
 * @brief Heapify a subtree rooted with node i which is an index in arr[]. n is the size of the heap.
 * 
 * @param arr The array representing the heap.
 * @param n The size of the heap.
 * @param i The root index of the subtree to heapify.
 */
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

/**
 * @brief Perform heap sort on an array.
 * 
 * @param arr The array to be sorted.
 * @param n The size of the array.
 */
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/**
 * @brief Print an array.
 * 
 * @param arr The array to be printed.
 * @param n The size of the array.
 */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/**
 * @brief Driver code to demonstrate the heapSort function.
 * 
 * This function creates multiple test cases and calls the heapSort function to sort arrays.
 * It then prints and verifies the sorted arrays using assertions.
 * 
 * @return 0 on successful execution.
 */
int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    heapSort(arr1, n1);
    printArray(arr1, n1);
    int expected1[] = {5, 6, 7, 11, 12, 13};
    for (int i = 0; i < n1; i++) {
        assert(arr1[i] == expected1[i]);
    }

    int arr2[] = {4, 10, 3, 5, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    heapSort(arr2, n2);
    printArray(arr2, n2);
    int expected2[] = {1, 3, 4, 5, 10};
    for (int i = 0; i < n2; i++) {
        assert(arr2[i] == expected2[i]);
    }

    int arr3[] = {4, 6, 3, 2, 8, 7, 2, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    heapSort(arr3, n3);
    printArray(arr3, n3);
    int expected3[] = {1, 2, 2, 3, 4, 6, 7, 8};
    for (int i = 0; i < n3; i++) {
        assert(arr3[i] == expected3[i]);
    }

    printf("All test cases passed successfully.\n");

    return 0; // Return 0 to indicate successful execution
}
