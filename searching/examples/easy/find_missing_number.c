#include <stdio.h>


/* // Approach 1 – Using Hashing: O(n) time and O(n) space

void findMissing(int arr[], int N)
{
    int ans = 0;
    int freq[N];
    for (int i = 0; i < N; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        freq[arr[i] - 1] = 1;
    }
    for (int i = 0; i < N; i++)
    {
        if (freq[i] == 0)
        {
            ans = i + 1;
            break;
        }
    }
    printf("%d", ans);
} */

/* // Approach 2 – Using Summation Formula: O(n) time and O(1) space
// The sum of the first N natural numbers is given by the formula N * (N + 1) / 2. 
// Compute this sum and subtract the sum of all elements in the array from it to get the missing number.
void findMissing(int arr[], int N)
{
    int ans;
    int range  = N+1;
    int sum = range * (range + 1) / 2;
    int sum_array = 0;
    for (int i = 0; i < N; i++)
    {
        sum_array += arr[i];
    }
    ans = sum - sum_array;
    printf("Missing NUmber  = %d\n", ans);
} */

// Approach 3 – Using XOR Operation: O(n) time and O(1) space
// The XOR operation has useful properties for this problem. XOR of a number with itself is 0, and XOR of a number with 0 is the number itself. Using these properties, XOR all numbers in the range [1, N] and XOR all elements of the array. The result will be the missing number.


void findMissing(int arr[], int N)
{
    int ans1 = 1;
    for (int i = 2; i <= N+1; i++)
    {
        ans1 ^= i;
    }
    int ans2 = arr[0];
    for (int i = 1; i < N; i++)
    {
        ans2 ^= arr[i];
    }
    printf("Missing NUmber  = %d\n", ans1^ ans2);
}
/* Driver code */
int main()
{
    int arr[] = { 1, 3, 7, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findMissing(arr, n);
}

// This code is contributed by nikhilm2302
