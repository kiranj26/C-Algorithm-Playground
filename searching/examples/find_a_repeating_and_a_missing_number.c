/**
 * @file find_a_repeating_and_a_missing_number.c
 * @brief C program to find a repeating and a missing number in an array of integers.
 * 
 * This program finds a repeating and a missing number in an array where the numbers are 
 * in the range from 1 to N. The array contains one repeating number and one missing number.
 * 
 * @details The approaches used are:
 * - Approach 1: Frequency Array (O(n) time and O(n) space)
 * - Approach 2: Mathematical Method (O(n) time and O(1) space)
 * 
 * @note This code is designed to be compatible with Doxygen for documentation generation.
 * 
 * @complexity
 * Approach 1: 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * Approach 2:
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * Approach 2 Explanation:
 * - Let the array be `arr` of size `n` containing numbers from 1 to n, with one number missing (x) and one number repeating (y).
 * - Calculate the sum of the first n natural numbers, `S = n * (n + 1) / 2`.
 * - Calculate the sum of the squares of the first n natural numbers, `S_sq = n * (n + 1) * (2 * n + 1) / 6`.
 * - Let `sum` be the sum of the elements in the array and `sum_sq` be the sum of the squares of the elements in the array.
 * - From the given array, we know:
 *   - `sum = S - x + y`
 *   - `sum_sq = S_sq - x^2 + y^2`
 * - By solving these equations:
 *   - `y - x = sum - S`  (Equation 1)
 *   - `y^2 - x^2 = sum_sq - S_sq`
 *   - `(y - x)(y + x) = sum_sq - S_sq`
 * - Using Equation 1: `y + x = (sum_sq - S_sq) / (sum - S)`
 * - Solving for `y` and `x`:
 *   - `y = (sum - S + (sum_sq - S_sq) / (sum - S)) / 2`
 *   - `x = y - (sum - S)`
 * 
 * Author: Kiran Jojare
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/** 
 * @brief Finds the repeating and missing numbers in an array using the Frequency Array approach.
 * 
 * @details This approach uses an auxiliary array to keep track of the frequency of each number 
 * in the input array. By checking the frequency array, it identifies the repeating and missing numbers.
 * 
 * @param arr Array of integers.
 * @param n Number of elements in the array.
 */
void findRepeatingAndMissing_Frequency(int arr[], int n)
{
    int temp[n]; // Auxiliary array to keep track of frequency

    // Initialize the frequency array to zero
    for (int i = 0; i < n; i++)
    {
        temp[i] = 0;
    }

    // Populate the frequency array based on the input array
    for(int i = 0; i < n; i++)
    {
        temp[arr[i] - 1]++;
    }

    int rep = -1; // Variable to store the repeating number
    int mis = -1; // Variable to store the missing number

    // Identify the repeating and missing numbers by checking the frequency array
    for (int i = 0; i < n; i++)
    {
        if (temp[i] == 0)
        {
            mis = i + 1; // Identify the missing number
        }

        if (temp[i] == 2)
        {
            rep = i + 1; // Identify the repeating number
        }
    }

    // Print the repeating and missing numbers
    printf("Repeating element is %d\n", rep);
    printf("Missing element is %d\n", mis);
}

/** 
 * @brief Finds the repeating and missing numbers in an array using the Mathematical Method.
 * 
 * @details This approach uses the mathematical properties of the sum and sum of squares 
 * of the first N natural numbers to find the repeating and missing numbers.
 * 
 * @param arr Array of integers.
 * @param n Number of elements in the array.
 */
void findRepeatingAndMissing_Math(int arr[], int n)
{
    int sum = 0, sum_sq = 0;
    int S = n * (n + 1) / 2;
    int S_sq = n * (n + 1) * (2 * n + 1) / 6;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        sum_sq += arr[i] * arr[i];
    }

    int diff = sum - S;
    int sq_diff = sum_sq - S_sq;
    int sum_diff = sq_diff / diff;

    int rep = (diff + sum_diff) / 2;
    int mis = rep - diff;

    // Print the repeating and missing numbers
    printf("Repeating element is %d\n", rep);
    printf("Missing element is %d\n", mis);
}

/**
 * @brief Driver code to test the findRepeatingAndMissing function.
 * 
 * This function creates multiple arrays of integers and calls the findRepeatingAndMissing function
 * to find and print the repeating and missing numbers in each array.
 * 
 * @return 0 on successful execution.
 */
int main()
{
    // Test case 1: Repeating element is 1, Missing element is 5
    int arr1[] = {4, 3, 6, 2, 1, 1}; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Test Case 1:\n");
    findRepeatingAndMissing_Math(arr1, n1);

    // Test case 2: Repeating element is 3, Missing element is 5
    int arr2[] = {1, 3, 3, 4, 2}; 
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Test Case 2:\n");
    findRepeatingAndMissing_Math(arr2, n2);

    // Test case 3: Repeating element is 2, Missing element is 3
    int arr3[] = {1, 2, 2, 4, 5}; 
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Test Case 3:\n");
    findRepeatingAndMissing_Math(arr3, n3);

    // Test case 4: Repeating element is 5, Missing element is 4
    int arr4[] = {1, 5, 3, 5, 2}; 
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("Test Case 4:\n");
    findRepeatingAndMissing_Math(arr4, n4);

    // Test case 5: Repeating element is 6, Missing element is 2
    int arr5[] = {6, 6, 4, 3, 5, 1}; 
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("Test Case 5:\n");
    findRepeatingAndMissing_Math(arr5, n5);

    return 0; // Return 0 to indicate successful execution
}
