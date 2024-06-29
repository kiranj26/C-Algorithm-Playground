# Sorting Algorithms

This directory contains implementations of various sorting algorithms in C.

## Algorithms

### Basic Sorting Algorithms
- **Bubble Sort** (`bubble-sort.c`, `bubble-sort-recursive.c`)
  - Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
  - Time Complexity: O(n^2)
  - Space Complexity: O(1)

- **Selection Sort** (`selection-sort-iterative.c`, `selection-sort-recursive.c`, `selection-sort-stable.c`, `selection-sort-strings.c`)
  - Selection Sort is an in-place comparison sorting algorithm. It works by dividing the input list into two parts: the sublist of items already sorted, and the sublist of items remaining to be sorted.
  - Time Complexity: O(n^2)
  - Space Complexity: O(1)

- **Insertion Sort** (`insertion-sort-iterative.c`, `insertion-sort-recursive.c`)
  - Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms.
  - Time Complexity: O(n^2)
  - Space Complexity: O(1)

### Advanced Sorting Algorithms
- **Merge Sort** (`merge-sort.c`)
  - Merge Sort is an efficient, stable, comparison-based, divide and conquer sorting algorithm. Most implementations produce a stable sort, meaning that the implementation preserves the input order of equal elements in the sorted output.
  - Time Complexity: O(n log n)
  - Space Complexity: O(n)

Each algorithm is implemented in C and includes example usage.

## Getting Started

To compile and run any of the algorithms:
1. Navigate to the directory:
    ```bash
    cd sorting
    ```
2. Compile the C source file using GCC or any other C compiler:
    ```bash
    gcc -o bubble_sort bubble-sort.c
    ```
3. Run the compiled program:
