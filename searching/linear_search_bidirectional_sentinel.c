/**
 * @file linear_search_bidirectional_sentinel.c
 * @brief Implementation of Bidirectional Sentinel Linear Search Algorithm.
 *
 * @details
 * This program implements a combination of bidirectional linear search and sentinel linear search
 * to efficiently find a target element in an unsorted array. The algorithm begins by replacing
 * the first and last elements of the array with sentinel values (the target itself) to eliminate
 * boundary checks. The search is performed simultaneously from both ends of the array, halving
 * the number of comparisons on average.
 *
 * The implementation ensures that the original array is restored after the search, maintaining data integrity.
 * Test cases using assertions are included to validate correctness, with one test case intentionally designed
 * to fail if the logic is incorrect.
 *
 * @note
 * - Time Complexity: O(n) in the worst case.
 * - Space Complexity: O(1).
 * - The array is restored to its original state after the search, ensuring no permanent modifications.
 *
 * @author Kiran
 */

#include <stdio.h>
#include <assert.h>

/**
 * @brief Performs bidirectional sentinel linear search to find the target in an array.
 * @param arr[] Array to search.
 * @param size Size of the array.
 * @param target Element to search for.
 * @return Index of the target element if found; otherwise, -1.
 */
int linear_search_bidirectional_sentinel(int arr[], int size, int target) {
    // Handle edge case: empty array
    if (size == 0) {
        return -1; // Target not found
    }

    // Check if the target is already at the start or end of the array
    if (arr[0] == target) {
        return 0; // Target found at the first position
    }
    if (arr[size - 1] == target) {
        return size - 1; // Target found at the last position
    }

    // Save the original boundary values for restoration later
    int start = arr[0];
    int last = arr[size - 1];

    // Place sentinels at the boundaries
    arr[0] = target;
    arr[size - 1] = target;

    // Perform bidirectional search
    int i = 1, j = size - 2; // Initialize pointers
    while (arr[i] != target && arr[j] != target) {
        i++; // Move left pointer forward
        j--; // Move right pointer backward
    }

    // Restore the original boundary values
    arr[0] = start;
    arr[size - 1] = last;

    // Return the index of the found target
    if (arr[i] == target) {
        return i; // Target found by the left pointer
    }
    if (arr[j] == target) {
        return j; // Target found by the right pointer
    }

    return -1; // Target not found
}

/**
 * @brief Runs a series of test cases to validate the correctness of the search function.
 * Uses assertions to ensure expected behavior. Fails if any test case is incorrect.
 */
void run_tests() {
    // Test Case 1: Target in the middle of the array
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 3;
    assert(linear_search_bidirectional_sentinel(arr1, size1, target1) == 2);

    // Test Case 2: Target at the beginning of the array
    int arr2[] = {10, 20, 30, 40, 50};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 10;
    assert(linear_search_bidirectional_sentinel(arr2, size2, target2) == 0);

    // Test Case 3: Target at the end of the array
    int arr3[] = {5, 15, 25, 35, 45};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int target3 = 45;
    assert(linear_search_bidirectional_sentinel(arr3, size3, target3) == 4);

    // Test Case 4: Target not present in the array
    int arr4[] = {2, 4, 6, 8, 10};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int target4 = 5;
    assert(linear_search_bidirectional_sentinel(arr4, size4, target4) == -1);

    // Test Case 5: Array with duplicate elements
    int arr5[] = {1, 3, 3, 3, 7};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    int target5 = 3;
    assert(linear_search_bidirectional_sentinel(arr5, size5, target5) == 1);

    // Test Case 6: Single-element array
    int arr6[] = {42};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    int target6 = 42;
    assert(linear_search_bidirectional_sentinel(arr6, size6, target6) == 0);

    // Test Case 7: Empty array
    int arr7[] = {};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    int target7 = 100;
    assert(linear_search_bidirectional_sentinel(arr7, size7, target7) == -1);

    // Uncomment the following test case to see a deliberate failure
    /* int arr8[] = {1, 2, 3, 4, 5};
    int size8 = sizeof(arr8) / sizeof(arr8[0]);
    int target8 = 5;
    assert(linear_search_bidirectional_sentinel(arr8, size8, target8) == 0); // Incorrect expected value */
}

/**
 * @brief Main function to execute test cases.
 * @return 0 if all tests pass successfully.
 */
int main() {
    printf("Running test cases...\n");
    run_tests();
    printf("All test cases passed successfully!\n");
    return 0;
}
