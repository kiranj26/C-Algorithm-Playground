/**
 * @file simple_sort.c
 * @brief Implementation of the Bubble Sort Algorithm in C.
 * @version 0.1
 * @date 2022-03-14
 * 
 * @details
 * This program implements the bubble sort algorithm in C. 
 * It defines a function bubbleSort that takes an array of integers and its length, 
 * and sorts the array in ascending order using the bubble sort algorithm.
 * 
 * The main function initializes an array of integers, calculates its length, 
 * and calls the bubbleSort function to sort it. 
 * After sorting, it prints the sorted array to the standard output.
 * 
 * @section Performance
 * - Time Complexity: O(n^2), where n is the number of elements in the array.
 * - Space Complexity: O(1)
 * 
 * @param arr The array of integers to be sorted.
 * @param n The number of elements in the array.
 * 
 * @see https://www.geeksforgeeks.org/bubble-sort/
 * 
 * @author Kiran Jojare
 */

#include <stdio.h>

/**
 * @brief Sorts an array using bubble sort algorithm.
 * 
 * This function sorts an array in ascending order using the bubble sort algorithm.
 * It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
 * 
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/**
 * @brief Main function to test the bubble sort algorithm.
 * 
 * This function contains a test case to demonstrate the functionality of the bubble sort algorithm.
 * 
 * @return int Returns 0 on successful execution.
 */
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
