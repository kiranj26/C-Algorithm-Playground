/**
 * @file k_largest_elements.c
 * @brief Provides functions to find the k largest elements in an array.
 * 
 * This program demonstrates how to find the k largest elements in an array.
 * 
 * @details 
 * The approaches include:
 * - **Sorting**: Sorts the array in descending order and picks the first k elements.
 * - **Binary Search**: Uses binary search to find the k largest elements.
 * 
 * @complexity
 * - **Sorting**: O(n log n) time complexity for sorting.
 * - **Binary Search**: O(n log(max - min)) time complexity.
 * 
 * @approach2 Binary Search Explanation:
 * - Find the minimum (`low`) and maximum (`high`) elements in the array.
 * - Perform binary search to find the `k` largest elements:
 *   - Calculate the mid value.
 *   - Count the number of elements greater than the mid value.
 *   - If the count is at least `k`, move the `low` pointer to `mid + 1`.
 *   - Otherwise, move the `high` pointer to `mid - 1`.
 * - The process narrows down to the threshold value that separates the `k` largest elements from the rest.
 * - Finally, print all elements greater than or equal to this threshold value.
 * 
 * Author: Kiran Jojare
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/** 
 * @brief Comparator function for qsort.
 * 
 * @param a Pointer to the first element.
 * @param b Pointer to the second element.
 * @return The difference between the two elements.
 */
/*
int compare(const void * a, const void * b)
{
    return (*(int *)b - *(int *)a);
}
*/

/** 
 * @brief Finds the k largest elements in an array using the Sorting approach.
 * 
 * @param arr Array of integers.
 * @param n Number of elements in the array.
 * @param k Number of largest elements to find.
 */
/*
void kLargestElements_Sorting(int arr[], int n, int k)
{
    // Sort the array in descending order
    qsort(arr, n, sizeof(arr[0]), compare);
    printf("The %d largest elements in the array are: ", k);
    // Print the first k elements
    for (int i = 0; i < k; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
*/

/** 
 * @brief Finds the k largest elements in an array using the Binary Search approach.
 * 
 * @param arr Array of integers.
 * @param n Number of elements in the array.
 * @param k Number of largest elements to find.
 */
void kLargestElements_BinarySearch(int arr[], int n, int k)
{
    int low = INT_MAX;
    int high = INT_MIN;

    // Find the minimum and maximum elements in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] < low) low = arr[i];
        if (arr[i] > high) high = arr[i];
    }

    // Use binary search to find the kth largest element
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        // Count the number of elements greater than mid
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                count++;
            }
        }

        // If the number of elements is at least k, move to the right
        if (count >= k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("The %d largest elements in the array are: ", k);
    for (int i = 0; i < n; i++) {
        if (arr[i] >= low) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

/**
 * @brief Driver code to demonstrate the kLargestElements_BinarySearch function.
 * 
 * This function creates multiple test cases and calls the kLargestElements_BinarySearch function to find and print
 * the k largest elements in each array.
 * 
 * @return 0 on successful execution.
 */
int main()
{
    int arr[] = {1, 23, 12, 9, 30, 2, 50}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Number of largest elements to find

    kLargestElements_BinarySearch(arr, n, k); // Call function to find k largest elements

    // Output: 50, 30, 23

    // Additional test cases
    int arr1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; // Example array 1
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 5; // Number of largest elements to find

    kLargestElements_BinarySearch(arr1, n1, k1); // Call function to find k largest elements

    return 0; // Return 0 to indicate successful execution
}
