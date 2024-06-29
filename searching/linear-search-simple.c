      /**
 * Author: Kiran Jojare
 * 
 * Linear Search Algorithm Explanation:
 * 
 * Linear search, also known as sequential search, is a simple algorithm used in Data Structures and Algorithms (DSA) 
 * for finding a particular value within a list. It works by examining each element in the list sequentially until 
 * the desired value is found or the end of the list is reached.
 * 
 * The algorithm does not require the list to be sorted and is straightforward to implement. The primary operation 
 * of the linear search is comparison, where each element of the list is compared with the value being searched for.
 * 
 * Linear search has a time complexity of O(n), where n is the number of elements in the list. This means that, in the 
 * worst-case scenario, the algorithm will have to check each element once. Therefore, while linear search is simple 
 * and effective for small lists or unsorted data, its efficiency decreases as the size of the list increases.
 * 
 * Usage in DSA:
 * Linear search is often used in introductory programming courses to teach basic search algorithms and is also useful 
 * in scenarios where the list sizes are small, or the data is unsorted and cannot be efficiently searched using more 
 * advanced algorithms like binary search. It is also used as a building block in more complex algorithms and applications.
 * 
 * Sample Example in C (Boilerplate Code):
 * 
 * Below is the boilerplate code for performing a linear search in C. The main logic of the search is implemented in 
 * the `linear_search` function, which takes an array of integers, the size of the array, and the target value to search 
 * for as its parameters. It returns the index of the target value if found; otherwise, it returns -1.
 * 
 * Note: The main logic of the linear search algorithm is not included in this comment.
 */


#include <stdio.h>

// Function prototype
int linear_search(int arr[], int size, int target)
{
    for (int i = 0 ; i < size; i++)
    {
        if (target == arr[i])
        {
            return i;
        }
    }
    return -1;
}

// Test cases
int main() {
    int arr1[] = {1, 3, 5, 7, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 7;
    
    int arr2[] = {2, 4, 6, 8, 10, 12};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 5;
    
    // Add more test cases as needed

    printf("Searching for %d. Result: %d\n", target1, linear_search(arr1, size1, target1));
    printf("Searching for %d. Result: %d\n", target2, linear_search(arr2, size2, target2));

    // Add more test cases as needed

    return 0;
}