/*
 * Ieterative Selection Sort
 *
 * Selection sort is a simple comparison-based sorting algorithm. It works by dividing the input
 * array into two parts: the sorted part at the left end and the unsorted part at the right end.
 * Initially, the sorted part is empty and the unsorted part is the entire array. The algorithm
 * repeatedly selects the smallest (or largest) element from the unsorted part and moves it to the
 * sorted part. This process continues until the unsorted part becomes empty.
 *
 * Time Complexity:
 * - Best Case: O(n^2)
 * - Average Case: O(n^2)
 * - Worst Case: O(n^2)
 *
 * Space Complexity: O(1)
 *
 * Note: Selection sort is not suitable for large data sets due to its quadratic time complexity.
 * However, it performs well for small lists or when the auxiliary memory is limited.
 * 
 * Reference: https://www.geeksforgeeks.org/selection-sort/
 */

#include <stdio.h>
#include <stdlib.h>

// Function to print the elements of an array
void printing_arrays(int * arr, int length){
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform selection sort on an array
void selection_sort(int * arr, int length)
{
    // Traverse through all array elements
    for (int i = 0; i < length; i++)
    {
        // Assume the first element is the minimum
        int min_val_index = i;
        // Traverse the unsorted part of the array to find the actual minimum
        for (int j = i+1; j < length ; j++)
        {
            // If the current element is smaller than the current minimum, update min_val_index
            if (arr[j] < arr[min_val_index])
            {
                min_val_index = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        int temp = arr[min_val_index];
        arr[min_val_index] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    // Test case 1: Regular unsorted array
    int unsorted_array1[5] = {64, 34, 25, 12, 22};
    selection_sort(unsorted_array1, 5);
    printf("Sorted array 1: ");
    printing_arrays(unsorted_array1, 5);

    // Test case 2: Array with negative numbers
    int unsorted_array2[6] = {-3, 10, -1, 7, -20, 5};
    selection_sort(unsorted_array2, 6);
    printf("Sorted array 2: ");
    printing_arrays(unsorted_array2, 6);

    // Test case 3: Already sorted array
    int sorted_array[5] = {1, 2, 3, 4, 5};
    selection_sort(sorted_array, 5);
    printf("Sorted array 3: ");
    printing_arrays(sorted_array, 5);

    // Test case 4: Array with all elements the same
    int same_elements_array[4] = {5, 5, 5, 5};
    selection_sort(same_elements_array, 4);
    printf("Sorted array 4: ");
    printing_arrays(same_elements_array, 4);

    // Test case 5: Array with a single element
    int single_element_array[1] = {42};
    selection_sort(single_element_array, 1);
    printf("Sorted array 5: ");
    printing_arrays(single_element_array, 1);

    // Test case 6: Empty array
    int empty_array[0] = {};
    selection_sort(empty_array, 0);
    printf("Sorted array 6: ");
    printing_arrays(empty_array, 0);

    return 0;
}
