/**
 * Merge Sort Algorithm
 * DIVIDE CONQUER MERGE
 *
 * Merge Sort is a divide-and-conquer algorithm that divides an array into two halves,
 * sorts them separately, and then merges the sorted halves to produce a sorted array.
 * It follows the principle of "divide and conquer" to solve the problem.
 *
 * Performance:
 * - Time Complexity: O(n log n)
 * - Space Complexity: O(n)
 *
 * Merge Sort has a consistent performance of O(n log n) regardless of the input data.
 * It is efficient for sorting large data sets and is widely used in various applications.
 * However, it requires additional space for the temporary arrays used during the merging process.
 *
 * Steps of Merge Sort:
 * 1. Divide the unsorted array into two halves.
 *    - This is done recursively until each subarray contains a single element.
 *    - The `mergeSort` function is called with the left and right indices of the array/subarray.
 *    - Example: For array {64, 34, 25, 12, 22, 11, 90}, the first call is mergeSort(arr, 0, 6).
 * 2. Recursively sort the two halves.
 *    - Each half is sorted by recursively calling the `mergeSort` function on it.
 *    - Example: mergeSort(arr, 0, 3) and mergeSort(arr, 4, 6) for the left and right halves respectively.
 * 3. Merge the sorted halves to produce the final sorted array.
 *    - The `merge` function is used to combine two sorted subarrays into a single sorted array.
 *    - The `merge` function takes the array and three indices: left (l), middle (m), and right (r).
 *    - It creates two temporary arrays to hold the elements of the left and right subarrays.
 *    - It then merges these temporary arrays back into the original array in sorted order.
 *
 * Detailed Explanation of `merge` Function:
 * - The merge function merges two sorted subarrays of arr[].
 * - The first subarray is arr[l..m] and the second subarray is arr[m+1..r].
 * - It creates two temporary arrays L[] and R[] to hold the elements of the left and right subarrays.
 * - It copies the elements from the original array to these temporary arrays.
 * - It then merges the temporary arrays back into the original array in sorted order.
 * - Finally, it copies any remaining elements of L[] and R[] into the original array.
 *
 * Example Usage:
 * int arr[] = {64, 34, 25, 12, 22, 11, 90};
 * int n = sizeof(arr) / sizeof(arr[0]);
 * mergeSort(arr, 0, n - 1);
 *
 * This will sort the array in ascending order.
 *
 * Time Complexity:
 *  Best Case: O(n log n), When the array is already sorted or nearly sorted.
 * Average Case: O(n log n), When the array is randomly ordered.
 * Worst Case: O(n log n), When the array is sorted in reverse order.
 * Space Complexity: O(n), Additional space is required for the temporary array used during merging.

 * References:
 * - Introduction to Algorithms by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein
 * - GeeksforGeeks (https://www.geeksforgeeks.org/merge-sort/)
 */

#include <stdio.h>
#include <stdlib.h>

// Function to print an array
void printArray(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to merge two subarrays of arr[].
// First subarray is arr[l..m].
// Second subarray is arr[m+1..r].
void merge(int arr[], int l, int m, int r) {
    // Calculate the sizes of the two subarrays
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays to hold the elements of the subarrays
    int L[n1], R[n2];

    // Copy the elements from the original array to the temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into the original array
    int i = 0; // Initial index of the first subarray
    int j = 0; // Initial index of the second subarray
    int k = l; // Initial index of the merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[] into the original array
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[] into the original array
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive function to sort an array using merge sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Find the middle point of the array
        int m = l + (r - l) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Driver code
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}
