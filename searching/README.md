# Searching Algorithms

This directory contains implementations of various searching algorithms in C.

## Algorithms

- **Binary Search** (`binary-search-simple.c`)
  - Binary Search is an efficient algorithm for finding an item from a sorted list. It works by repeatedly dividing in half the portion of the list that could contain the item until the possible locations are narrowed down to just one.
  - Time Complexity: O(log n)
  - Space Complexity: O(1)

- **Jump Search** (`jump-search-simple.c`)
  - Jump Search is a searching algorithm for sorted arrays. It works by jumping ahead by fixed steps and then performing a linear search in the block where the target value might be.
  - Time Complexity: O(√n)
  - Space Complexity: O(1)

- **Linear Search** (`linear-search-simple.c`)
  - Linear Search is the simplest searching algorithm. It checks every element in the list until the desired item is found or the list ends.
  - Time Complexity: O(n)
  - Space Complexity: O(1)

Each algorithm is implemented in C and includes example usage.

## Getting Started

To compile and run any of the algorithms:
1. Navigate to the directory:
    ```bash
    cd searching
    ```
2. Compile the C source file using GCC or any other C compiler:
    ```bash
    gcc -o binary_search binary-search-simple.c
    ```
3. Run the compiled program:
    ```bash
    ./binary_search
    ```

## Contributing

Feel free to contribute by adding new searching algorithms or improving existing ones. Please follow the contribution guidelines outlined in the [CONTRIBUTING.md](../CONTRIBUTING.md) file.

---

Happy Coding! 🚀
