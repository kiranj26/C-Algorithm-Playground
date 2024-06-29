
/*
Author: Kiran
Description: This program implements the Jump Search algorithm, which is used to search for an element in a sorted array. It works by jumping ahead by a fixed step size and then performing a linear search in the subarray where the element might be present. This algorithm is efficient for large arrays and provides better performance than linear search.

Performance:
- Time Complexity: O(sqrt(n)), where n is the size of the array.
- Space Complexity: O(1), as it uses a constant amount of extra space.
- The algorithm performs better than linear search for large arrays, as it reduces the number of comparisons required.
*/

#include <stdio.h>

int jumpSearch(int arr[], int n, int target) {
    // Implement the jump search algorithm here
    // ...
    for (int i = 0 ; i < n ; i = i+4)
    {
        if (target == arr[i])
        {
            return i;
        }else{
            if (target < arr[i])
            {
                for(int j = i - 4; j < i ; j++)
                {
                    if (target == arr[j])
                    {
                        return j;
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    // Test cases
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 14;

    int result = jumpSearch(arr, n, target);

    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    // Additional test cases
    int arr2[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int target2 = 11;

    int result2 = jumpSearch(arr2, n2, target2);

    if (result2 == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result2);
    }

    int arr3[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int target3 = 8;

    int result3 = jumpSearch(arr3, n3, target3);

    if (result3 == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result3);
    }

    int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int target4 = 5;

    int result4 = jumpSearch(arr4, n4, target4);

    if (result4 == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result4);
    }

    int arr5[] = {10, 20, 30, 40, 50, 60, 65, 80, 90, 100};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int target5 = 70;

    int result5 = jumpSearch(arr5, n5, target5);

    if (result5 == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result5);
    }

    return 0;
}
