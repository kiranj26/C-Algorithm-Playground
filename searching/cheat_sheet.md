# Searching Algorithm Interview Tricks Cheat Sheet

## Introduction

This cheat sheet covers essential tips, tricks, and strategies to tackle common searching algorithm problems in technical interviews. These insights will help you solve problems efficiently and effectively.

---

## Binary Search Tricks

1. **Handling Duplicates**: Use left and right pointers to find the first or last occurrence.
2. **Finding Pivot Point**: In rotated sorted arrays, find the pivot by comparing middle and end elements.
3. **Search in 2D Matrix**: Treat the matrix as a flat array using index transformation.
4. **Search in Rotated Array**: Adjust the mid calculation to handle the rotated part.
5. **Finding Square Root**: Use binary search to find the square root of a number.
6. **Search Insert Position**: Find the position where a target should be inserted in a sorted array.
7. **Find Peak Element**: Use binary search to find a peak element in an array.
8. **Find Minimum in Rotated Sorted Array**: Use binary search to find the minimum element.
9. **Median of Two Sorted Arrays**: Use binary search to find the median of two sorted arrays.
10. **Aggressive Cows Problem**: Use binary search to solve allocation problems.
11. **Allocate Minimum Pages**: Use binary search to find the optimal allocation of pages.
12. **Painters Partition Problem**: Use binary search to minimize the maximum partition sum.
13. **Capacity to Ship Packages**: Use binary search to find the minimum capacity of a ship.
14. **Kth Smallest Element**: Use binary search in a matrix to find the kth smallest element.
15. **Divide Chocolate**: Use binary search to divide chocolate pieces optimally.
16. **Magnetic Force Between Balls**: Use binary search to maximize the minimum magnetic force.
17. **Split Array Largest Sum**: Use binary search to split an array into subarrays with minimized largest sum.
18. **Smallest Divisor**: Use binary search to find the smallest divisor given a threshold.
19. **Find Right Interval**: Use binary search to find the right interval for each interval.
20. **Missing Element in Sorted Array**: Use binary search to find the missing element.
21. **Find Duplicate Number**: Use binary search to find the duplicate number in an array.
22. **Minimize Max Distance to Gas Station**: Use binary search to minimize the maximum distance.
23. **Koko Eating Bananas**: Use binary search to find the minimum eating speed.
24. **Minimize Max Distance to Gas Station**: Use binary search to place gas stations optimally.
25. **Search in Infinite Array**: Use binary search by expanding the search range exponentially.

---

## Two-Pointer Technique Tricks

26. **Pair Sum Problem**: Use two pointers to find pairs that sum up to a target in a sorted array.
27. **Removing Duplicates**: Use slow and fast pointers to remove duplicates in-place.
28. **Partitioning**: Use two pointers to partition arrays based on a pivot.
29. **Palindromes**: Check if a string is a palindrome by using two pointers from both ends.
30. **Container With Most Water**: Use two pointers to find the container that holds the most water.
31. **3Sum Problem**: Use two pointers within a loop to find triplets that sum up to zero.
32. **4Sum Problem**: Use two pointers within nested loops to find quadruplets that sum up to a target.
33. **Subarray Product Less Than K**: Use two pointers to find subarrays with a product less than K.
34. **Max Consecutive Ones III**: Use two pointers to find the maximum number of consecutive 1s after flipping K zeros.
35. **Minimum Window Substring**: Use two pointers to find the smallest substring containing all characters of another string.
36. **Sort Colors**: Use two pointers to sort an array with three unique elements.
37. **Fruit Into Baskets**: Use two pointers to collect the maximum number of fruits in two baskets.
38. **Backspace String Compare**: Use two pointers to compare two strings considering backspaces.
39. **Squares of a Sorted Array**: Use two pointers to merge squares of a sorted array.
40. **Subarray Sum Equals K**: Use two pointers to find subarrays that sum up to K.
41. **Remove Nth Node From End of List**: Use two pointers to remove the nth node from the end of a linked list.
42. **Reverse Words in a String**: Use two pointers to reverse the order of words in a string.
43. **Longest Substring Without Repeating Characters**: Use two pointers to find the longest substring without repeating characters.
44. **Valid Palindrome II**: Use two pointers to check if a string can be a palindrome after deleting at most one character.
45. **Max Area of Island**: Use two pointers to find the maximum area of an island in a grid.
46. **Trap Rain Water**: Use two pointers to find the maximum water that can be trapped.
47. **Dutch National Flag Problem**: Use two pointers to sort an array of 0s, 1s, and 2s.
48. **Subarrays with K Different Integers**: Use two pointers to find the number of subarrays with exactly K different integers.
49. **Move Zeroes**: Use two pointers to move all zeroes to the end of the array.
50. **Longest Mountain in Array**: Use two pointers to find the longest mountain in an array.

---

## Sliding Window Tricks

51. **Maximum Sum Subarray**: Use a sliding window to find the maximum sum of subarrays of a fixed size.
52. **Minimum Window Substring**: Use sliding window to find the smallest substring containing all characters of another string.
53. **Longest Substring Without Repeating Characters**: Use sliding window to find the longest substring without repeating characters.
54. **Sliding Window Maximum**: Use a deque to find the maximum value in each sliding window.
55. **Subarrays with K Different Integers**: Use sliding window to find the number of subarrays with exactly K different integers.
56. **Longest Repeating Character Replacement**: Use sliding window to find the longest substring after replacing at most K characters.
57. **Permutation in String**: Use sliding window to check if one string's permutation is a substring of another string.
58. **Find All Anagrams in a String**: Use sliding window to find all anagrams of a pattern in a string.
59. **Grumpy Bookstore Owner**: Use sliding window to maximize the number of satisfied customers.
60. **Subarray Product Less Than K**: Use sliding window to find the number of subarrays with a product less than K.
61. **Longest Substring with At Most K Distinct Characters**: Use sliding window to find the longest substring with at most K distinct characters.
62. **Longest Substring with At Least K Repeating Characters**: Use sliding window to find the longest substring with at least K repeating characters.
63. **Smallest Subarray with Sum Greater Than K**: Use sliding window to find the smallest subarray with sum greater than K.
64. **Replace Elements with Greatest Element on Right Side**: Use sliding window to replace each element with the greatest element on its right.
65. **Check If All 1's Are at Least Length K Places Away**: Use sliding window to check if all 1's are at least K places away.
66. **Max Consecutive Ones III**: Use sliding window to find the maximum number of consecutive 1s after flipping K zeros.
67. **Number of Subarrays of Size K and Average Greater Than or Equal to Threshold**: Use sliding window to find the number of subarrays of size K with average greater than or equal to threshold.
68. **Binary Subarrays With Sum**: Use sliding window to find the number of subarrays with a sum equal to a given value.
69. **Minimum Size Subarray Sum**: Use sliding window to find the minimum length of a subarray with sum equal to or greater than a given value.
70. **Contains Duplicate II**: Use sliding window to check if there are any duplicate numbers within a given range.
71. **Longest Substring with Exactly K Distinct Characters**: Use sliding window to find the longest substring with exactly K distinct characters.
72. **Maximum Points You Can Obtain from Cards**: Use sliding window to find the maximum points you can obtain from cards.
73. **Maximum Erasure Value**: Use sliding window to find the maximum sum of a subarray with all unique elements.
74. **Find K-Length Substrings with No Repeated Characters**: Use sliding window to find all K-length substrings with no repeated characters.
75. **Count Number of Nice Subarrays**: Use sliding window to count the number of subarrays with exactly K odd numbers.

---

## Contact

Kiran Jojare  
Embedded Software Engineer  
Phone: 720-645-6212  
Email: kijo7257@colorado.edu
