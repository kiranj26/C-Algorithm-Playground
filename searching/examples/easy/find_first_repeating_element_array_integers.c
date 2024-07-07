/**
 * @file find_first_repeating_element_array_integers.c
 * @brief C program to find the first repeating element in an array of integers.
 * 
 * This program demonstrates three different approaches to find the first repeating element 
 * in an array of integers. The first repeating element is the one that appears more than once 
 * and has the smallest index of its first occurrence.
 * 
 * @details The three approaches are:
 * - Approach 1: Brute Force (O(n^2) time and O(1) space)
 * - Approach 2: Sorting (O(n log n) time and O(n) space)
 * - Approach 3: Hash Set (O(n) time and O(n) space)
 * 
 * The Hash Set approach is currently active, while the other two are commented out.
 * 
 * @note This code is designed to be compatible with Doxygen for documentation generation.
 * 
 * @complexity
 * Approach 1: 
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 * 
 * Approach 2:
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 * 
 * Approach 3:
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * @author 
 * Kiran Jojare
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

/** 
 * @brief Finds the first repeating element in an array using the Brute Force approach.
 * 
 * @details This approach checks each element with every other element to find the first repeating element.
 * 
 * @param arr Array of integers.
 * @param n Number of elements in the array.
 * @return The index of the first repeating element, or -1 if no repeating element is found.
 */
 /*
int firstRepeatingElement_BruteForce(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return i; // Return the index of the first repeating element
            }
        }
    }
    return -1; // Return -1 if no repeating element is found
} */

/** 
 * @brief Compares two integers for use with qsort.
 * 
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 * @return The difference between the two integers.
 */
 /*
int compare(const void * a, const void * b)
{
    return (*(int *)a - *(int *)b);
} */

/** 
 * @brief Finds the first repeating element in an array using the Sorting approach.
 * 
 * @details This approach sorts the array and then checks for repeating elements.
 * 
 * @param arr Array of integers.
 * @param n Number of elements in the array.
 * @return The index of the first repeating element, or -1 if no repeating element is found.
 */
 /*
int firstRepeatingElement_Sorting(int arr[], int n)
{
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i]; // Copy elements to a temporary array
    }
    qsort(temp, n, sizeof(int), compare); // Sort the temporary array

    for (int i = 0; i < n - 1; i++)
    {
        if (temp[i] == temp[i + 1])
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == temp[i])
                {
                    return j; // Return the index of the first repeating element
                }
            }
        }
    }
    return -1; // Return -1 if no repeating element is found
} */

/** 
 * @brief Finds the first repeating element in an array using the Hash Set approach.
 * 
 * @details This approach uses a hash set to keep track of elements that have been seen before.
 * 
 * @param arr Array of integers.
 * @param n Number of elements in the array.
 * @return The value of the first repeating element, or -1 if no repeating element is found.
 */
int firstRepeatingElement_HashSet(int arr[], int n)
{
    int hashset[1000] = {0}; // Initialize hash set with zeros
    int min = -1; // Variable to store the first repeating element
    for (int i = n - 1; i >= 0; i--)
    {
        if (hashset[arr[i]] != 0)
        {
            min = arr[i]; // Update min if element is found in hash set
        }
        else
        {
            hashset[arr[i]] = 1; // Mark element as seen in hash set
        }
    }
    return min; // Return the value of the first repeating element
}

/**
 * @brief Driver code to test the firstRepeatingElement function.
 * 
 * This function creates multiple arrays of integers and calls the firstRepeatingElement function
 * to find and print the first repeating element in each array.
 * 
 * @return 0 on successful execution.
 */
int main()
{
    // Test case 1: First repeating element is 5
    int arr1[] = { 10, 5, 3, 4, 3, 5, 6 }; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Test Case 1:\n");
    int index1 = firstRepeatingElement_HashSet(arr1, n1);
    if (index1 == -1) {
        printf("No repeating element found!\n");
    } else {
        printf("First repeating element is %d\n", index1);
    }

    // Test case 2: First repeating element is 2
    int arr2[] = { 1, 2, 3, 4, 5, 2 }; 
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Test Case 2:\n");
    int index2 = firstRepeatingElement_HashSet(arr2, n2);
    if (index2 == -1) {
        printf("No repeating element found!\n");
    } else {
        printf("First repeating element is %d\n", index2);
    }

    // Test case 3: No repeating element
    int arr3[] = { 1, 2, 3, 4, 5 }; 
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Test Case 3:\n");
    int index3 = firstRepeatingElement_HashSet(arr3, n3);
    if (index3 == -1) {
        printf("No repeating element found!\n");
    } else {
        printf("First repeating element is %d\n", index3);
    }

    // Test case 4: First repeating element is 4
    int arr4[] = { 4, 5, 6, 4, 3, 2, 1 }; 
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("Test Case 4:\n");
    int index4 = firstRepeatingElement_HashSet(arr4, n4);
    if (index4 == -1) {
        printf("No repeating element found!\n");
    } else {
        printf("First repeating element is %d\n", index4);
    }

    // Test case 5: First repeating element is 1
    int arr5[] = { 1, 1, 2, 2, 3, 3 }; 
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("Test Case 5:\n");
    int index5 = firstRepeatingElement_HashSet(arr5, n5);
    if (index5 == -1) {
        printf("No repeating element found!\n");
    } else {
        printf("First repeating element is %d\n", index5);
    }

    return 0; // Return 0 to indicate successful execution
}
