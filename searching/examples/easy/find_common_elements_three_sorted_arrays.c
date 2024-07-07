/**
 * @file find_common_element_3_sorted_array.c
 * @brief Provides functions to find a common element in three sorted arrays.
 * 
 * This program demonstrates how to find a common element in three sorted arrays.
 * 
 * @details 
 * The approach includes using a hash set to keep track of elements seen in the arrays:
 * - **Hash Set**: Iterate over each array, marking elements in the hash set to identify the common element.
 * 
 * @complexity
 * - **Hash Set**: O(n1 + n2 + n3) time complexity for iterating over all elements in the three arrays.
 * 
 * @approach Explanation:
 * - Create a hash set to store elements.
 * - Iterate over the first array and mark elements in the hash set.
 * - Iterate over the second array and update the hash set for elements found in both first and second arrays.
 * - Iterate over the third array to find the first element common to all three arrays by checking the hash set.
 * 
 * Author: Kiran Jojare
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

/**
 * @brief Finds a common element in three sorted arrays using a hash set.
 * 
 * @param arr1 First sorted array.
 * @param n1 Size of the first array.
 * @param arr2 Second sorted array.
 * @param n2 Size of the second array.
 * @param arr3 Third sorted array.
 * @param n3 Size of the third array.
 * @return The common element if found, -1 otherwise.
 */
int find_common_element_3_sorted_array(int *arr1, int n1, int *arr2, int n2, int *arr3, int n3) {
    // Create a hashset with a large enough size to accommodate the maximum element
    int hashset[100000] = {0};

    // Iterate over the first array and mark the elements in the hashset
    for (int i = 0; i < n1; i++) {
        hashset[arr1[i]] = 1;
    }

    // Iterate over the second array and mark the elements in the hashset
    for (int i = 0; i < n2; i++) {
        if (hashset[arr2[i]] == 1) {
            hashset[arr2[i]] = 2;
        }
    }

    // Iterate over the third array and find the common element
    for (int i = 0; i < n3; i++) {
        if (hashset[arr3[i]] == 2) {
            return arr3[i];
        }
    }

    // Return -1 if no common element is found
    return -1;
}

/**
 * @brief Driver code to demonstrate the find_common_element_3_sorted_array function.
 * 
 * This function creates multiple test cases and calls the find_common_element_3_sorted_array function to find and print
 * the common element in three sorted arrays.
 * 
 * @return 0 on successful execution.
 */
int main() {
    // Test case 1
    int arr1[] = {1, 5, 10, 20, 40, 80};
    int arr2[] = {6, 7, 20, 80, 100};
    int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int result = find_common_element_3_sorted_array(arr1, n1, arr2, n2, arr3, n3);
    printf("Test 1 - Expected: 20, Got: %d\n", result);
    assert(result == 20);

    // Test case 2
    int arr4[] = {1, 5, 5};
    int arr5[] = {3, 4, 5, 5, 10};
    int arr6[] = {5, 5, 10, 20};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    int result1 = find_common_element_3_sorted_array(arr4, n4, arr5, n5, arr6, n6);
    printf("Test 2 - Expected: 5, Got: %d\n", result1);
    assert(result1 == 5);

    // Additional test cases
    // Test case 3
    int arr7[] = {1, 2, 3, 4, 5};
    int arr8[] = {5, 6, 7, 8, 9};
    int arr9[] = {5, 10, 11, 12, 13};
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    int n8 = sizeof(arr8) / sizeof(arr8[0]);
    int n9 = sizeof(arr9) / sizeof(arr9[0]);
    int result2 = find_common_element_3_sorted_array(arr7, n7, arr8, n8, arr9, n9);
    printf("Test 3 - Expected: 5, Got: %d\n", result2);
    assert(result2 == 5);

    // Test case 4
    int arr10[] = {1, 2, 3};
    int arr11[] = {4, 5, 6};
    int arr12[] = {7, 8, 9};
    int n10 = sizeof(arr10) / sizeof(arr10[0]);
    int n11 = sizeof(arr11) / sizeof(arr11[0]);
    int n12 = sizeof(arr12) / sizeof(arr12[0]);
    int result3 = find_common_element_3_sorted_array(arr10, n10, arr11, n11, arr12, n12);
    printf("Test 4 - Expected: -1, Got: %d\n", result3);
    assert(result3 == -1);

    // Test case 5
    int arr13[] = {1, 3, 4, 5, 6, 7};
    int arr14[] = {2, 3, 5, 7, 8, 9};
    int arr15[] = {1, 3, 5, 6, 7, 10};
    int n13 = sizeof(arr13) / sizeof(arr13[0]);
    int n14 = sizeof(arr14) / sizeof(arr14[0]);
    int n15 = sizeof(arr15) / sizeof(arr15[0]);
    int result4 = find_common_element_3_sorted_array(arr13, n13, arr14, n14, arr15, n15);
    printf("Test 5 - Expected: 3, Got: %d\n", result4);
    assert(result4 == 3);

    return 0; // Return 0 to indicate successful execution
}
