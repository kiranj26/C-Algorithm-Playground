/**
 * @file bidirectional_linear_search.c
 * @brief Implementation of the Bidirectional Linear Search Algorithm.
 *
 * @author Kiran
 *
 * @details
 * Bidirectional linear search is a variation of the linear search algorithm that searches for the target value
 * from both ends of the array simultaneously. This approach reduces the average number of comparisons and can
 * be particularly useful for unsorted arrays or datasets with no specific order.
 *
 * The algorithm iterates from the beginning and the end of the array simultaneously, checking for the target
 * value at each step. If the target is found at either end, the search terminates, returning the index of the
 * target value. This makes it more efficient than a standard linear search in certain scenarios, especially
 * when the target is closer to the ends of the array.
 *
 * @note
 * Bidirectional linear search has a time complexity of O(n), where n is the number of elements in the array.
 * While it does not improve the worst-case complexity compared to standard linear search, it often improves
 * the average-case performance by reducing the number of iterations required.
 *
 * @section Usage in DSA
 * Bidirectional linear search is commonly used in scenarios where the array is unsorted, and the data does not
 * allow for advanced searching techniques like binary search. It is also useful in applications where the
 * target value is equally likely to be closer to either end of the array.
 *
 * @section Example
 * Below is the updated code for performing a bidirectional linear search in C. The main logic of the search
 * is implemented in the `bidirectional_linear_search` function, which takes an array of integers, the size of
 * the array, and the target value to search for as its parameters. It returns the index of the target value
 * if found; otherwise, it returns -1.
 *
 * @section Performance
 * - Time Complexity: O(n)
 * - Space Complexity: O(1)
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
    // Handle empty array case
    if (size == 0) {
        return -1; // No elements to search
    }

    // Perform bidirectional search
    for (int i = 0, j = size - 1; i <= j; i++, j--) {
        if (arr[i] == target) {
            return i; // Target found from the left side
        }
        if (arr[j] == target) {
            return j; // Target found from the right side
        }
    }

    return -1; // Target not found
}

int main() {
    // Test Case 1: Target in the middle
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 3;
    printf("Searching for %d. Result: %d\n", target1, bidirectional_linear_search(arr1, size1, target1));

    // Test Case 2: Target at the beginning
    int arr2[] = {9, 8, 7, 6, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 9;
    printf("Searching for %d. Result: %d\n", target2, bidirectional_linear_search(arr2, size2, target2));

    // Test Case 3: Target at the end
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

    return 0;
}
