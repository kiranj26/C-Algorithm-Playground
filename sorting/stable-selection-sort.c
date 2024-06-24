/**
 * Stable Selection Sort
 * 
 * This algorithm performs a stable sorting of an array using the Selection Sort technique.
 * It repeatedly selects the minimum element from the unsorted portion of the array and
 * inserts it at the beginning of the unsorted portion, maintaining the relative order
 * of equal elements.
 * 
 * Examples:
 * 
 * Example 1:
 * Input: [4A, 5, 3, 2, 4B, 1]
 * Output: [1, 2, 3, 4A, 4B, 5]
 * Explanation: In this example, the algorithm performs forward pushing instead of swapping
 * when inserting the minimum element in its correct place. This ensures that the relative
 * order of equal elements is maintained.
 * 
 * Performance:
 * 
 * - Time Complexity: O(n^2)
 *   The algorithm has a worst-case time complexity of O(n^2), where n is the number of elements
 *   in the array. This is because it requires nested loops to compare and swap elements.
 * 
 * - Space Complexity: O(1)
 *   The algorithm has a constant space complexity as it does not require any additional data
 *   structures. It performs in-place sorting by swapping elements within the given array.
 * 
 * Note:
 * 
 * - Stability:
 *   The Stable Selection Sort algorithm is stable, meaning that it preserves the relative order
 *   of equal elements. If there are multiple elements with the same value, their order will be
 *   maintained after sorting. This property is useful in certain scenarios where the original
 *   order of equal elements needs to be preserved.
 * 
 * - Comparison with other sorting algorithms:
 *   The Stable Selection Sort algorithm is not as efficient as some other sorting algorithms,
 *   such as Quick Sort or Merge Sort. However, it has the advantage of being stable, which can
 *   be beneficial in certain situations. It is also relatively simple to implement and does not
 *   require additional memory. Therefore, it can be a good choice for small arrays or when stability
 *   is a requirement.
 */

#include <stdio.h>
#include <stdlib.h>

// Function to print the elements of an array
void printf_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to shift elements of the array to the right by one position
void shift_right_by_1(int *arr, int start, int end) {
    for (int i = end; i > start; i--) {
        arr[i] = arr[i - 1];
    }
}

// Function to perform stable selection sort
void stable_selection_sort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int min_val_index = i;
        for (int j = i + 1; j < n; j++) {
            // Find the minimum value in the unsorted part of the array
            if (arr[j] < arr[min_val_index]) {
                min_val_index = j;
            }
        }

        // Store the minimum value temporarily
        int min_val = arr[min_val_index];
        // Shift elements to the right to make space for the minimum value
        shift_right_by_1(arr, i, min_val_index);
        // Place the minimum value at the correct position
        arr[i] = min_val;
    }
}

int main() {
    // Test case 1: Regular unsorted array
    int unsorted_array1[5] = {64, 34, 25, 12, 22};
    int n1 = sizeof(unsorted_array1) / sizeof(unsorted_array1[0]);
    stable_selection_sort(unsorted_array1, n1);
    printf("Sorted array 1: ");
    printf_array(unsorted_array1, n1);

    // Test case 2: Array with negative numbers
    int unsorted_array2[6] = {-3, 10, -1, 7, -20, 5};
    int n2 = sizeof(unsorted_array2) / sizeof(unsorted_array2[0]);
    stable_selection_sort(unsorted_array2, n2);
    printf("Sorted array 2: ");
    printf_array(unsorted_array2, n2);

    // Test case 3: Already sorted array
    int sorted_array[5] = {1, 2, 3, 4, 5};
    int n3 = sizeof(sorted_array) / sizeof(sorted_array[0]);
    stable_selection_sort(sorted_array, n3);
    printf("Sorted array 3: ");
    printf_array(sorted_array, n3);

    // Test case 4: Array with all elements the same
    int same_elements_array[4] = {5, 5, 5, 5};
    int n4 = sizeof(same_elements_array) / sizeof(same_elements_array[0]);
    stable_selection_sort(same_elements_array, n4);
    printf("Sorted array 4: ");
    printf_array(same_elements_array, n4);

    // Test case 5: Array with a single element
    int single_element_array[1] = {42};
    int n5 = sizeof(single_element_array) / sizeof(single_element_array[0]);
    stable_selection_sort(single_element_array, n5);
    printf("Sorted array 5: ");
    printf_array(single_element_array, n5);

    // Test case 6: Empty array
    int empty_array[0] = {};
    int n6 = sizeof(empty_array) / sizeof(empty_array[0]);
    stable_selection_sort(empty_array, n6);
    printf("Sorted array 6: ");
    printf_array(empty_array, n6);

    return 0;
}
