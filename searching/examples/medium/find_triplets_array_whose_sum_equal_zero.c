/**
 * @file find_triplets_array_whose_sum_equal_zero.c
 * @brief Provides functions to find triplets in an array whose sum is equal to zero.
 * 
 * This program demonstrates how to find triplets in an array whose sum is equal to zero.
 * 
 * @details 
 * The approaches include:
 * - **Brute Force**: Iterate over the array to find all possible triplets and check if their sum is zero.
 * - **Hashing**: Use a hashmap to store elements and find the triplets efficiently.
 * 
 * @complexity
 * - **Brute Force**: O(n^3) time complexity for iterating over all possible triplets.
 * - **Hashing**: O(n^2) time complexity for iterating over pairs and O(n) space complexity for storing elements in the hashmap.
 * 
 * @approach Explanation:
 * - **Brute Force**:
 *   - Iterate over the array to find all possible triplets and check if their sum is zero.
 * - **Hashing**:
 *   - Iterate over the array to find all possible pairs.
 *   - Use a hashmap to check if the required third element to form a triplet that sums to zero exists.
 * 
 * Author: Kiran Jojare
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX 10000

// Approach 1  : Using Brute Force
/**
 * @brief Function to find and print triplets with 0 sum.
 * 
 * @param arr The input array.
 * @param n The size of the array.
 * @return The number of triplets found.
 */
/*
int findTripletsBruteForce(int arr[], int n) {
    int triplet_count = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    printf("%d %d %d\n", arr[i], arr[j], arr[k]);
                    triplet_count++;
                }
            }
        }
    }
    return triplet_count;
}
*/

// Approach 2  : Using Hashing
/**
 * @brief Function to find and print triplets with 0 sum using a hashmap.
 * 
 * @param arr The input array.
 * @param n The size of the array.
 * @return The number of triplets found.
 */
int findTriplets(int arr[], int n) {
    int triplet_count = 0;
    bool hashmap[20001] = {false};

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            int required_value = -sum;

            if (required_value >= -10000 && required_value <= 10000 && hashmap[required_value + 10000]) {
                printf("%d %d %d\n", required_value, arr[i], arr[j]);
                triplet_count++;
            }
        }

        // Reset the hashmap for the current i
        for (int j = 0; j < n; j++) {
            hashmap[arr[j] + 10000] = false; // Adjusted to handle negative numbers
        }

        // Add the current element to the hashmap
        hashmap[arr[i] + 10000] = true; // Adjusted to handle negative numbers
    }

    return triplet_count;
}


/**
 * @brief Driver code to demonstrate the findTriplets function.
 * 
 * This function creates multiple test cases and calls the findTriplets function to find and print
 * the triplets whose sum is zero in an array.
 * 
 * @return 0 on successful execution.
 */
int main() {
    int arr1[] = {-1, 0, 1, 2, -1, -4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int result_size1;

    result_size1 = findTriplets(arr1, n1);
    printf("Test 1 - Found %d triplets.\n", result_size1);
    assert(result_size1 == 2);

    printf("All test cases passed successfully.\n");

    return 0; // Return 0 to indicate successful execution
}
