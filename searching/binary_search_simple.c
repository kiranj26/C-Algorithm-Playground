/**
 * @file binary_search_simple.c
 * @brief Implementation of the Binary Search Algorithm.
 *
 * @author Kiran
 * @date 2021-09-29
 *
 * @details
 * Binary search is an efficient algorithm used to search for an element in a sorted array.
 * It works by repeatedly dividing the search space in half until the target element is found.
 * The algorithm compares the target element with the middle element of the array and
 * eliminates half of the remaining elements in each iteration.
 *
 * @note
 * Binary search assumes that the input array is sorted in ascending order.
 * If the array is not sorted, it needs to be sorted first before applying binary search.
 *
 * @section Performance
 * - Time Complexity: O(log n) - Binary search has a logarithmic time complexity,
 *   as it divides the search space in half at each step.
 * - Space Complexity: O(1) - Binary search has a constant space complexity,
 *   as it does not require any additional space proportional to the input size.
 */

#include <stdio.h>

/**
 * @brief Binary search function.
 * @param arr[] Sorted array to search.
 * @param left Starting index of the search range.
 * @param right Ending index of the search range.
 * @param target Element to search for.
 * @return Index of the target element if found, otherwise -1.
 */
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        // Calculate the middle index
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;  // Target found at index mid
        } else if (arr[mid] < target) {
            left = mid + 1;  // Target is in the right half of the array
        } else {
            right = mid - 1;  // Target is in the left half of the array
        }
    }
    return -1;  // Target not found in the array
}

int main() {
    // Test cases
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;
    int result = binarySearch(arr, 0, n - 1, target);
    printf("Target %d found at index %d\n", target, result);

    target = 8;
    result = binarySearch(arr, 0, n - 1, target);
    printf("Target %d found at index %d\n", target, result);

    target = 1;
    result = binarySearch(arr, 0, n - 1, target);
    printf("Target %d found at index %d\n", target, result);

    target = 11;
    result = binarySearch(arr, 0, n - 1, target);
    printf("Target %d found at index %d\n", target, result);

    target = 5;
    result = binarySearch(arr, 0, n - 1, target);
    printf("Target %d found at index %d\n", target, result);

    return 0;
}
