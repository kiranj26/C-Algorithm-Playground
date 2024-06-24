/**
 * Merge Sort Algorithm
 * DIVIDE CONQUER MERGE
 *
 * Merge Sort is a divide-and-conquer algorithm that divides an array into two halves,
 * sorts them separately, and then merges the sorted halves to produce a sorted array.
 * It follows the principle of "divide and conquer" to solve the problem.
 *
 * Performance:
 * - Time Complexity: O(n log n)
 * - Space Complexity: O(n)
 *
 * Merge Sort has a consistent performance of O(n log n) regardless of the input data.
 * It is efficient for sorting large data sets and is widely used in various applications.
 * However, it requires additional space for the temporary arrays used during the merging process.
 *
 * Steps of Merge Sort:
 * 1. Divide the unsorted array into two halves.
 * 2. Recursively sort the two halves.
 * 3. Merge the sorted halves to produce the final sorted array.
 *
 * Example Usage:
 * int arr[] = {64, 34, 25, 12, 22, 11, 90};
 * int n = sizeof(arr) / sizeof(arr[0]);
 * mergeSort(arr, 0, n - 1);
 *
 * References:
 * - Introduction to Algorithms by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein
 * - GeeksforGeeks (https://www.geeksforgeeks.org/merge-sort/)
 */

// Rest of the code...
