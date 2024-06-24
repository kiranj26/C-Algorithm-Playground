/**
 * @file selection-sort-strings.c
 * @brief Implementation of selection sort for strings.
 * @version 0.1
 * @date 2024-06-23
 * 
 * @details
 * The selection sort algorithm is a simple comparison-based sorting algorithm.
 * It divides the input array into a sorted and an unsorted part. Initially, the sorted part is empty, 
 * and the unsorted part contains all the elements. The algorithm repeatedly selects the smallest (or largest) 
 * element from the unsorted part and moves it to the sorted part. This process continues until the unsorted part becomes empty.
 * 
 * This implementation sorts an array of strings in ascending order, comparing the strings lexicographically 
 * and swapping their pointers to maintain the desired order.
 * 
 * Time Complexity: O(n^2), where n is the number of elements in the array.
 * Space Complexity: O(1)
 * 
 * @param arr The array of strings to be sorted.
 * @param n The number of elements in the array.
 * 
 * @author
 * Kiran Jojare
 * 
 * @see
 * https://www.geeksforgeeks.org/stable-selection-sort/?ref=lbp
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints the elements of an array of strings.
 * 
 * @param arr The array of strings to be printed.
 * @param n The number of elements in the array.
 */
void printf_array_strings(char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Performs selection sort on an array of strings.
 * 
 * This function sorts an array of strings in ascending order using the selection sort algorithm.
 * It compares the strings lexicographically and swaps their pointers to maintain the desired order.
 * 
 * @param arr The array of strings to be sorted.
 * @param n The number of elements in the array.
 */
void selection_sort_strings(char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min_index = i;        
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[min_index]) < 0) {
                min_index = j;
            }
        }
        // Swap pointers instead of strings
        char *temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

/**
 * @brief Main function to test the selection sort algorithm for strings.
 * 
 * This function contains multiple test cases to demonstrate the functionality of the selection sort algorithm for strings.
 * 
 * @return int Returns 0 on successful execution.
 */
int main() {
    char *unsorted_array_strings[5] = {"date", "banana", "fig", "cherry", "apple"};
    int n = sizeof(unsorted_array_strings) / sizeof(unsorted_array_strings[0]);
    
    selection_sort_strings(unsorted_array_strings, n);
    printf("Sorted array: ");
    printf_array_strings(unsorted_array_strings, n);

    return 0;
}
