/**
 * @file kth_smallest_element_in_a_row_wise_and_column_wise_sorted_2d_array.c
 * @brief Provides functions to find the kth smallest element in a row-wise and column-wise sorted 2D array.
 * 
 * This program demonstrates how to find the kth smallest element in a 2D array where each row and column is sorted in non-decreasing order.
 * 
 * @details 
 * The approaches include:
 * - **Brute Force**: Flatten the 2D array into a 1D array, sort it, and then find the kth smallest element.
 * - **Binary Search**: Use binary search to efficiently find the kth smallest element without sorting.
 * 
 * @complexity
 * - **Brute Force**: O(n^2 log n^2) time complexity for sorting the flattened array.
 * - **Binary Search**: O(n log(max - min)) time complexity.
 * 
 * @approach2 Binary Search Explanation:
 * - Determine the range of the elements (`low` and `high`) from the smallest element (top-left) to the largest element (bottom-right).
 * - Perform binary search on this range:
 *   - Calculate the mid value.
 *   - Count the number of elements less than or equal to the mid value.
 *   - If the count is less than k, move the `low` pointer to `mid + 1`.
 *   - Otherwise, move the `high` pointer to `mid - 1`.
 * - The `low` pointer will eventually point to the kth smallest element.
 * 
 * Author: Kiran Jojare
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
    return (*(int *)a - *(int *)b);
}
*/

/** 
 * @brief Finds the kth smallest element in a 2D array using the Brute Force approach.
 * 
 * @param arr 2D array of integers.
 * @param n Size of the 2D array (n x n).
 * @param k The kth position to find the smallest element.
 * @return The kth smallest element.
 */
/*
int find_kth_smallest_element_brute_force(int * arr[], int n, int k)
{
    int index = 0;
    int * temp = (int *)malloc(n * n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < n; j++)
        {
            temp[index++] = arr[i][j];
        }
    }
    qsort(temp, n * n, sizeof(int), compare);
    int result = temp[k - 1];
    free(temp);
    return result;
}
*/

/**
 * @brief Finds the kth smallest element in a 2D array using the Binary Search approach.
 * 
 * @param arr 2D array of integers.
 * @param n Size of the 2D array (n x n).
 * @param k The kth position to find the smallest element.
 * @return The kth smallest element.
 */
int find_kth_smallest_element(int **arr, int n, int k) {
    int low = arr[0][0]; // Start with the smallest element
    int high = arr[n - 1][n - 1]; // End with the largest element

    while (low <= high) { // Perform binary search within the range
        int mid = low + (high - low) / 2; // Calculate the middle element
        int count = 0; // Initialize count of elements <= mid
        int j = n - 1; // Initialize column pointer to the last column

        // Count elements less than or equal to mid
        for (int i = 0; i < n; i++) {
            while (j >= 0 && arr[i][j] > mid) { // Move left in the row until elements are <= mid
                j--;
            }
            count += (j + 1); // Add the number of elements <= mid in this row
        }

        if (count < k) {
            low = mid + 1; // Search in the higher half
        } else {
            high = mid - 1; // Search in the lower half
        }
    }

    return low; // low will be the kth smallest element
}

/**
 * @brief Driver code to demonstrate the find_kth_smallest_element function.
 * 
 * This function creates multiple test cases and calls the find_kth_smallest_element function to find and print
 * the kth smallest element in each 2D array.
 * 
 * @return 0 on successful execution.
 */
int main() {
    // Test case 1
    int n = 4;
    int k = 3;
    int *arr[] = {
        (int[]){10, 20, 30, 40},
        (int[]){15, 25, 35, 45},
        (int[]){24, 29, 37, 48},
        (int[]){32, 33, 39, 50}
    };
    int result = find_kth_smallest_element(arr, n, k);
    printf("Test 1 - Expected: 20, Got: %d\n", result);
    assert(result == 20);

    // Test case 2
    int n1 = 3;
    int k1 = 7;
    int *arr1[] = {
        (int[]){10, 20, 30},
        (int[]){15, 25, 35},
        (int[]){24, 29, 37}
    };
    int result1 = find_kth_smallest_element(arr1, n1, k1);
    printf("Test 2 - Expected: 30, Got: %d\n", result1);
    assert(result1 == 30);

    // Additional test cases
    // Test case 3
    int n2 = 3;
    int k2 = 5;
    int *arr2[] = {
        (int[]){1, 5, 9},
        (int[]){10, 11, 13},
        (int[]){12, 13, 15}
    };
    int result2 = find_kth_smallest_element(arr2, n2, k2);
    printf("Test 3 - Expected: 11, Got: %d\n", result2);
    assert(result2 == 11);

    // Test case 4
    int n3 = 2;
    int k3 = 2;
    int *arr3[] = {
        (int[]){1, 2},
        (int[]){1, 3}
    };
    int result3 = find_kth_smallest_element(arr3, n3, k3);
    printf("Test 4 - Expected: 1, Got: %d\n", result3);
    assert(result3 == 1);

    // Test case 5
    int n4 = 4;
    int k4 = 6;
    int *arr4[] = {
        (int[]){1, 2, 3, 4},
        (int[]){2, 3, 4, 5},
        (int[]){3, 4, 5, 6},
        (int[]){4, 5, 6, 7}
    };
    int result4 = find_kth_smallest_element(arr4, n4, k4);
    printf("Test 5 - Expected: 3, Got: %d\n", result4);
    assert(result4 == 3);

    return 0; // Return 0 to indicate successful execution
}
