/**
 * @file ternary_search_simple.c
 * @brief This file contains the implementation of the ternary search algorithm.
 *
 * The ternary search algorithm is a divide-and-conquer algorithm used to find the position of a target value within a sorted array.
 * It repeatedly divides the search space into three parts and determines which part the target value must be in.
 * This implementation assumes that the input array is sorted in ascending order.
 *
 * @author Kiran Jojare
 */

#include <stdio.h>

/**
 * @brief Ternary search algorithm.
 *
 * @param arr The sorted array to search in.
 * @param left The left index of the search space.
 * @param right The right index of the search space.
 * @param target The target value to search for.
 * @return The index of the target value if found, otherwise -1.
 */
int ternarySearch(int arr[], int left, int right, int target)
{
    while(left <= right)
    {
        int mid1 = left  + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target)
        {
            return mid1;
        }
        if (arr[mid2] == target)
        {
            return mid2;
        }

        if (target < arr[mid1])
        {
            return ternarySearch(arr, left, mid1 - 1, target);
        }else if (target > arr[mid2])
        {
            return ternarySearch(arr, mid2 + 1, right, target);
        }else{
            return ternarySearch(arr, mid1 + 1, mid2 - 1 , target);
        }
    }
    
    return -1; // Return -1 if the target value is not found
}

/**
 * @brief 
 *
 * @param arr The sorted array to search in.
 * @param left The left index of the search space.
 * @param right The right index of the search space.
 * @param target The target value to search for.
 * @return The index of the target value if found, otherwise -1.
 */
/*int ternarySearchIterative(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if (arr[mid1] == target)
        {
            return mid1;
        }
        if (arr[mid2] == target)
        {
            return mid2;
        }
        if (target < arr[mid1])
        {
            right = mid1 - 1;
        }
        else if (target > arr[mid2])
        {
            left = mid2 + 1;
        }
        else
        {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }

    return -1; // Return -1 if the target value is not found
}*/
 
/**
 * @brief Main function to test the ternary search algorithm.
 *
 * @return 0 on success.
 */
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int result = ternarySearch(arr, 0, n - 1, target);
    if (result == -1) {
        printf("Element %d is not present in the array.\n", target);
    } else {
        printf("Element %d is present at index %d.\n", target, result);
    }
    
    target = 8;
    result = ternarySearch(arr, 0, n - 1, target);
    if (result == -1) {
        printf("Element %d is not present in the array.\n", target);
    } else {
        printf("Element %d is present at index %d.\n", target, result);
    }
    
    target = 15;
    result = ternarySearch(arr, 0, n - 1, target);
    if (result == -1) {
        printf("Element %d is not present in the array.\n", target);
    } else {
        printf("Element %d is present at index %d.\n", target, result);
    }
    
    return 0;
}
