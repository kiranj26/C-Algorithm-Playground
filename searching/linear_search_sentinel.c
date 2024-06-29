/**
 * @file linear_search_sentinel.c
 * @brief Implementation of the Linear Search Algorithm with Sentinel.
 *
 * @author Kiran
 *
 * @details
 * Linear search with sentinel is a variation of the linear search algorithm that uses a sentinel value to simplify
 * the code and improve performance. In this variation, the target value is placed at the end of the array, and the
 * search loop is modified to terminate when the target value is found. This eliminates the need for an additional
 * comparison inside the loop, resulting in faster execution.
 *
 * The algorithm does not require the list to be sorted and is straightforward to implement. The primary operation
 * of the linear search is comparison, where each element of the list is compared with the value being searched for.
 *
 * @note
 * Linear search with sentinel has a time complexity of O(n), where n is the number of elements in the list. This means
 * that, in the worst-case scenario, the algorithm will have to check each element once. However, the use of a sentinel
 * value improves the average-case performance by reducing the number of comparisons required.
 *
 * @section Usage in DSA
 * Linear search with sentinel is often used as an optimization technique in scenarios where the list sizes are small
 * or the data is unsorted and cannot be efficiently searched using more advanced algorithms like binary search. It is
 * also used as a building block in more complex algorithms and applications.
 *
 * @section Example
 * Below is the updated code for performing a linear search with sentinel in C. The main logic of the search is
 * implemented in the `linear_search_sentinel` function, which takes an array of integers, the size of the array, and
 * the target value to search for as its parameters. It returns the index of the target value if found; otherwise, it
 * returns -1.
 *
 * @section Performance
 * - Time Complexity: O(n)
 * - Space Complexity: O(1)
 */

#include <stdio.h>

/**
 * @brief Linear search with sentinel function.
 * @param arr[] Array to search.
 * @param size Size of the array.
 * @param target Element to search for.
 * @return Index of the target element if found, otherwise -1.
 */
int linear_search_sentinel(int arr[], int size, int target)
{
    // Store the last element of the array
    int last = arr[size - 1];
    
    // Replace the last element with the target value
    arr[size - 1] = target;
    
    int i = 0;
    while (arr[i] != target)
    {
        i++;
    }
    
    // Restore the last element
    arr[size - 1] = last;
    
    if (i < size - 1 || arr[size - 1] == target)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
int main() {
    // Test cases
    int arr1[] = {1, 3, 5, 7, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 7;
    
    int arr2[] = {2, 4, 6, 8, 10, 12};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 5;
    
    int arr3[] = {0, 2, 4, 6, 8, 10};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int target3 = 0;
    
    int arr4[] = {1, 2, 3, 4, 5};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int target4 = 6;
    
    int arr5[] = {10, 20, 30, 40, 50};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    int target5 = 30;
    
    int arr6[] = {5, 10, 15, 20, 25};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    int target6 = 25;
    
    int arr7[] = {100, 200, 300, 400, 500};
    int size7 = sizeof(arr7) / sizeof(arr7[0]);
    int target7 = 200;
    
    int arr8[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size8 = sizeof(arr8) / sizeof(arr8[0]);
    int target8 = 5;
    
    int arr9[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int size9 = sizeof(arr9) / sizeof(arr9[0]);
    int target9 = 9;
    
    int arr10[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int size10 = sizeof(arr10) / sizeof(arr10[0]);
    int target10 = 1;
    
    printf("Searching for %d. Result: %d\n", target1, linear_search_sentinel(arr1, size1, target1));
    printf("Searching for %d. Result: %d\n", target2, linear_search_sentinel(arr2, size2, target2));
    printf("Searching for %d. Result: %d\n", target3, linear_search_sentinel(arr3, size3, target3));
    printf("Searching for %d. Result: %d\n", target4, linear_search_sentinel(arr4, size4, target4));
    printf("Searching for %d. Result: %d\n", target5, linear_search_sentinel(arr5, size5, target5));
    printf("Searching for %d. Result: %d\n", target6, linear_search_sentinel(arr6, size6, target6));
    printf("Searching for %d. Result: %d\n", target7, linear_search_sentinel(arr7, size7, target7));
    printf("Searching for %d. Result: %d\n", target8, linear_search_sentinel(arr8, size8, target8));
    printf("Searching for %d. Result: %d\n", target9, linear_search_sentinel(arr9, size9, target9));
    printf("Searching for %d. Result: %d\n", target10, linear_search_sentinel(arr10, size10, target10));

    return 0;
}
