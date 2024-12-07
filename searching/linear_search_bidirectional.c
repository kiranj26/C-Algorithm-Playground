/**
 * @file bidirectional_linear_search.c
 * @brief Boilerplate code for bidirectional linear search.
 *
 * @author Kiran
 * 
 * @details
 * Bidirectional linear search involves searching for a target value from both 
 * ends of the array simultaneously. This approach reduces the average number of 
 * comparisons in large datasets and can be particularly useful for unsorted arrays.
 *
 * @note
 * - Time Complexity: O(n) in the worst case.
 * - Space Complexity: O(1).
 */

#include <stdio.h>

/**
 * @brief Bidirectional linear search function.
 * @param arr[] Array to search.
 * @param size Size of the array.
 * @param target Element to search for.
 * @return Index of the target element if found, otherwise -1.
 */
int bidirectional_linear_search(int arr[], int size, int target) {
    // Handle empty array
    if (size == 0) {
        return -1;
    }

    // Search from both ends simultaneously
    for (int i = 0, j = size - 1; i <= j; i++, j--) {
        if (arr[i] == target) {
            return i; // Found from the left
        }
        if (arr[j] == target) {
            return j; // Found from the right
        }
    }

    return -1; // Target not found
}

int main() {
    // Test Case 1: Small array with target in the middle
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 3;
    printf("Searching for %d. Result: %d\n", target1, bidirectional_linear_search(arr1, size1, target1));

    // Test Case 2: Large array with target at the beginning
    int arr2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 9;
    printf("Searching for %d. Result: %d\n", target2, bidirectional_linear_search(arr2, size2, target2));

    // Test Case 3: Large array with target at the end
    int arr3[] = {10, 20, 30, 40, 50};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int target3 = 50;
    printf("Searching for %d. Result: %d\n", target3, bidirectional_linear_search(arr3, size3, target3));

    // Test Case 4: Target not present
    int arr4[] = {2, 4, 6, 8, 10};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int target4 = 5;
    printf("Searching for %d. Result: %d\n", target4, bidirectional_linear_search(arr4, size4, target4));

    // Test Case 5: Array with duplicate elements
    int arr5[] = {1, 2, 3, 3, 4, 5};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    int target5 = 3;
    printf("Searching for %d. Result: %d\n", target5, bidirectional_linear_search(arr5, size5, target5));

    // Test Case 6: Empty array
    int arr6[] = {};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    int target6 = 7;
    printf("Searching for %d. Result: %d\n", target6, bidirectional_linear_search(arr6, size6, target6));

    // Add more test cases as needed
    return 0;
}
