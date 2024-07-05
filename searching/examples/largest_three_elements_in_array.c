/**
 * @file largest_three_elements_in_an_array.c
 * @brief C program to find the largest three elements in an array.
 * 
 * This program takes an array of integers and finds the three largest elements 
 * in that array. The largest elements are then printed to the console.
 * 
 * @details The algorithm iterates through the given array once to find the 
 * three largest elements. It maintains three variables (`first`, `second`, 
 * `third`) to store the largest, second largest, and third largest elements 
 * respectively. As it processes each element in the array, it updates these 
 * variables accordingly to ensure they always contain the three largest values 
 * encountered so far.
 * 
 * @note This code is designed to be compatible with Doxygen for documentation generation.
 * 
 * @author 
 * Kiran Jojare
 */

#include <limits.h> /* For INT_MIN */
#include <stdio.h>

/**
 * @brief Function to print the three largest elements in an array.
 * 
 * This function iterates through the given array to find the three largest elements 
 * and prints them to the console.
 * 
 * @param arr Array of integers.
 * @param arr_size Size of the array.
 */
void print3largest(int arr[], int arr_size)
{
    int first, second, third; // Initialize variables to hold the three largest elements
    first = INT_MIN;          // Set first to the minimum integer value
    second = INT_MIN;         // Set second to the minimum integer value
    third = INT_MIN;          // Set third to the minimum integer value

    // Iterate through all elements in the array
    for (int i = 0; i < arr_size; i++)
    {
        // If current element is greater than the first largest element
        if (arr[i] > first)
        {
            third = second;   // Update third to the previous second
            second = first;   // Update second to the previous first
            first = arr[i];   // Update first to the current element
        }
        // If current element is greater than the second largest element and not equal to the first
        else if (arr[i] > second && arr[i] != first)
        {
            third = second;   // Update third to the previous second
            second = arr[i];  // Update second to the current element
        }
        // If current element is greater than the third largest element and not equal to first or second
        else if (arr[i] > third && arr[i] != second && arr[i] != first)
        {
            third = arr[i];   // Update third to the current element
        }
    }

    // Handle cases where there are fewer than three unique elements
    if (third == INT_MIN) {
        third = second == INT_MIN ? first : second;
    }
    if (second == INT_MIN) {
        second = first;
    }

    // Print the three largest elements
    printf("Three largest elements are %d, %d, and %d\n", first, second, third);
}

/**
 * @brief Driver program to test the print3largest function.
 * 
 * This function creates multiple arrays of integers and calls the print3largest function
 * to find and print the three largest elements in each array.
 * 
 * @return 0 on successful execution.
 */
int main()
{
    int arr1[] = { 12, 13, 1, 10, 34, 1 };  // Test case 1: Mixed values
    int n1 = sizeof(arr1) / sizeof(arr1[0]); // Calculate size of arr1
    printf("Test Case 1:\n");
    print3largest(arr1, n1);  // Call function with arr1

    int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  // Test case 2: Sequential increasing values
    int n2 = sizeof(arr2) / sizeof(arr2[0]); // Calculate size of arr2
    printf("Test Case 2:\n");
    print3largest(arr2, n2);  // Call function with arr2

    int arr3[] = { 10, 10, 10, 10, 10 };  // Test case 3: All identical values
    int n3 = sizeof(arr3) / sizeof(arr3[0]); // Calculate size of arr3
    printf("Test Case 3:\n");
    print3largest(arr3, n3);  // Call function with arr3

    int arr4[] = { -1, -2, -3, -4, -5 };  // Test case 4: Negative values
    int n4 = sizeof(arr4) / sizeof(arr4[0]); // Calculate size of arr4
    printf("Test Case 4:\n");
    print3largest(arr4, n4);  // Call function with arr4

    int arr5[] = { 1, 2, 3 };  // Test case 5: Exactly three values
    int n5 = sizeof(arr5) / sizeof(arr5[0]); // Calculate size of arr5
    printf("Test Case 5:\n");
    print3largest(arr5, n5);  // Call function with arr5

    return 0;  // Return 0 to indicate successful execution
}
