/**
 * @file interpolation_search_simple.c
 * @brief Implementation of the Interpolation Search Algorithm.
 *
 * Interpolation search is an algorithm for searching for a specific value within a sorted array. 
 * This search algorithm works on the principle of predicting where the value being searched for 
 * is likely to be located within the list by using a linear interpolation formula. The key idea 
 * is that if the values in the array are uniformly distributed, the time complexity can be better 
 * than binary search.
 *
 * ## Algorithm Overview
 * 
 * The formula used for predicting the position of the target value is:
 * pos = lo + [(hi - lo) / (A[hi] - A[lo])] * (x - A[lo])
 * where:
 * - pos is the position where the target value is likely to be,
 * - lo and hi are the lower and upper bounds of the array, respectively,
 * - A[] is the array containing the data,
 * - x is the target value.
 *
 * The algorithm checks the value at the calculated position. If it matches the target value, 
 * the search is successful. If the target value is larger, the search continues in the right sub-array, 
 * and if the target value is smaller, the search continues in the left sub-array. This process is 
 * repeated until the value is found or the sub-array becomes empty. The search is recursive, with 
 * the function calling itself with updated bounds based on the comparison between the target value 
 * and the value at the calculated position.
 *
 * ## Differences from Binary Search
 * 
 * - Binary search always checks the middle element of the array, while interpolation search may check 
 *   different places based on the estimated position of the target value.
 * - Interpolation search is more efficient than binary search for sorted arrays with uniformly distributed 
 *   values, as it can reach the target value faster. However, for arrays with non-uniform distributions, 
 *   binary search may be more efficient.
 *
 * ## Time Complexity
 * 
 * - Average: O(log(log n)) for uniformly distributed datasets,
 * - Worst-case: O(n) for non-uniformly distributed datasets or when the calculation does not lead to 
 *   a closer approximation of the target's position.
 *
 * ## Space Complexity
 * 
 * - O(1), as it requires a constant amount of space. The recursive implementation may have a call stack 
 *   size up to O(log n) in the best case or O(n) in the worst case.
 *
 * @note Interpolation search's performance heavily depends on the distribution of values in the array. 
 *       It is particularly useful for large datasets with uniformly distributed values.
 */
#include <stdio.h>

/**
 * @brief Interpolation search algorithm.
 *
 * @param arr The sorted array to search in.
 * @param low The starting index of the array.
 * @param high The ending index of the array.
 * @param target The target value to search for.
 * @return The index of the target value if found, otherwise -1.
 */
int interpolation_search(int *arr, int low, int high, int target)
{
    int pos;
    if (low <= high && target >= arr[low] && target <= arr[high])
    {
        pos = low + (target - arr[low]) *(high - low)/(arr[high] - arr[low]);
        if (arr[pos] == target)
        {
            return pos;
        }
        if (arr[pos] < target)
        {
            return interpolation_search(arr, pos + 1, high, target);
        }
        if (arr[pos] > target)
        {
            return interpolation_search(arr, low, pos - 1, target);
        }
    }
    return -1;
}
/*

*/
int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target1 = 5;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int result1 = interpolation_search(arr1, 0, n1 - 1, target1);
    printf("Test Case 1 - Target: %d, Result: %s\n", target1, (result1 != -1) ? "Found" : "Not Found");

    int arr2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int target2 = 25;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2 = interpolation_search(arr2, 0, n2 - 1, target2);
    printf("Test Case 2 - Target: %d, Result: %s\n", target2, (result2 != -1) ? "Found" : "Not Found");

    int arr3[] = {-5, 0, 5, 10, 15, 20, 25, 30};
    int target3 = -5;
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int result3 = interpolation_search(arr3, 0, n3 - 1, target3);
    printf("Test Case 3 - Target: %d, Result: %s\n", target3, (result3 != -1) ? "Found" : "Not Found");

    int arr4[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target4 = 14;
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int result4 = interpolation_search(arr4, 0, n4 - 1, target4);
    printf("Test Case 4 - Target: %d, Result: %s\n", target4, (result4 != -1) ? "Found" : "Not Found");

    int arr5[] = {100, 200, 300, 400, 500};
    int target5 = 500;
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int result5 = interpolation_search(arr5, 0, n5 - 1, target5);
    printf("Test Case 5 - Target: %d, Result: %s\n", target5, (result5 != -1) ? "Found" : "Not Found");

    return 0;
}