/**
 * @file find_pair_with_given_difference.c
 * @brief Provides functions to find a pair of elements in an array with a given difference.
 * 
 * This program demonstrates how to find a pair of elements in an array such that their difference equals a given target.
 * 
 * @details 
 * The approaches include:
 * - **Brute Force**: Checks all pairs of elements to find the pair with the given difference.
 * - **Sorting and Binary Search**: Sorts the array and uses binary search to find the pair with the given difference.
 * 
 * @complexity
 * - **Brute Force**: O(n^2) time complexity because it checks all pairs.
 * - **Sorting and Binary Search**: O(n log n) time complexity for sorting and O(n log n) for finding the pair, resulting in O(n log n) overall.
 * 
 * Author: Kiran Jojare
 */

#include <stdio.h>
#include <stdlib.h>

/** 
 * @brief Finds a pair of elements in an array with a given difference using the Brute Force approach.
 * 
 * @param arr Array of integers.
 * @param size Number of elements in the array.
 * @param target The target difference.
 */
/*
void find_pair_diff_brute_force(int * arr, int size, int target)
{
    for(int i = 0 ; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (abs(arr[i] - arr[j]) == target)
            {
                printf("The pair is %d and %d\n", arr[i], arr[j]);
                return;
            }
        }
    }
    printf("No such pair found\n");
}
*/

/**
 * @brief Comparator function for qsort.
 * 
 * @param a Pointer to the first element.
 * @param b Pointer to the second element.
 * @return The difference between the two elements.
 */
int compare(const void * a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

/** 
 * @brief Finds a pair of elements in an array with a given difference using the Sorting and Binary Search approach.
 * 
 * @param arr Array of integers.
 * @param size Number of elements in the array.
 * @param target The target difference.
 */
void find_pair_diff(int * arr, int size, int target)
{
    // Sort the array
    qsort(arr, size, sizeof(int), compare);
    
    // Use binary search to find the pair with the given difference
    for (int i = 0; i < size; ++i) {
        int low = i + 1, high = size - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] - arr[i] == target) {
                printf("The pair is %d and %d\n", arr[i], arr[mid]);
                return;
            } else if (arr[mid] - arr[i] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    printf("No pair found\n");
}

/**
 * @brief Driver code to demonstrate the find_pair_diff function.
 * 
 * This function creates multiple test cases and calls the find_pair_diff function to find and print
 * the pair of elements with the given difference.
 * 
 * @return 0 on successful execution.
 */
int main()
{
    int arr[] = {5, 20, 3, 2, 50, 80}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]);
    int diff = 78; // Example target difference
    find_pair_diff(arr, size, diff); // Call function to find pair with given difference

    // Additional test cases
    int arr1[] = {5, 20, 3, 2, 50, 80}; // Example array 1
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int diff1 = 78; // Example target difference 1
    find_pair_diff(arr1, size1, diff1);

    int arr2[] = {1, 8, 30, 40, 100}; // Example array 2
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int diff2 = 60; // Example target difference 2
    find_pair_diff(arr2, size2, diff2);

    int arr3[] = {1, 2, 3, 4, 5}; // Example array 3
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int diff3 = 3; // Example target difference 3
    find_pair_diff(arr3, size3, diff3);

    return 0; // Return 0 to indicate successful execution
}
