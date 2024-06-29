# C Algorithm Playground

![Build Status](https://github.com/kiranj26/C-Algorithm-Playground/workflows/Build%20and%20Test/badge.svg)
[![Code Style](https://img.shields.io/badge/code%20style-clang--format-brightgreen)](https://clang.llvm.orgHere's how you can update the main `README.md` to include the results of the additional actions and add badges to highlight the tools used in your repository:

### Updated `README.md` with Badges

```markdown
# C Algorithm Playground

![Build Status](https://github.com/kiranj26/C-Algorithm-Playground/actions/workflows/build.yml/badge.svg)
[![Code Style](https://img.shields.io/badge/code%20style-clang--format-brightgreen)](https://clang.llvm.org/docs/ClangFormat.html)
[![Static Analysis](https://img.shields.io/badge/static%20analysis-clang--tidy-brightgreen)](https://clang.llvm.org/extra/clang-tidy/)
[![Memory Leak Detection](https://img.shields.io/badge/memory%20leak%20detection-valgrind-brightgreen)](https://valgrind.org/)
[![Code Coverage](https://img.shields.io/badge/code%20coverage-gcov%20%2B%20lcov-brightgreen)](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html)
[![Documentation](https://img.shields.io/badge/documentation-doxygen-brightgreen)](https://www.doxygen.nl/index.html)

Welcome to the C Algorithm Playground! This repository is a personal project to explore and implement various algorithms in C, inspired by the open-source repository [TheAlgorithms/C](https://github.com/TheAlgorithms/C).

## Purpose

The purpose of this repository is to:
- Understand and implement different algorithms in C.
- Improve coding skills and algorithmic thinking.
- Create a reference library of algorithms for future projects.

## Structure

The repository is structured into different categories of algorithms, each with its own directory. Each directory contains:
- The C source code file for the algorithm.
- A README file explaining the algorithm and its implementation.

## Categories

The algorithms are organized into the following categories:

### Basic
1. **Sorting Algorithms**:
   - Bubble Sort
   - Selection Sort
   - Insertion Sort

2. **Searching Algorithms**:
   - Linear Search
   - Binary Search

3. **Basic Data Structures**:
   - Arrays
   - Linked Lists
   - Stacks
   - Queues

4. **Bit Manipulation**:
   - Basic Bitwise Operations (AND, OR, XOR, NOT, shifts)

5. **Mathematical Algorithms**:
   - Greatest Common Divisor (GCD)
   - Least Common Multiple (LCM)

### Medium
1. **Sorting Algorithms**:
   - Merge Sort
   - Quick Sort
   - Heap Sort

2. **Searching Algorithms**:
   - Depth-First Search (DFS)
   - Breadth-First Search (BFS)

3. **Advanced Data Structures**:
   - Trees (Binary Trees, Binary Search Trees)
   - Graphs (Adjacency Matrix, Adjacency List)
   - Hash Tables

4. **Dynamic Programming**:
   - Fibonacci Sequence
   - Coin Change Problem
   - Knapsack Problem

5. **String Algorithms**:
   - String Matching (Knuth-Morris-Pratt, Boyer-Moore)
   - Trie Data Structure

6. **Numerical Methods**:
   - Newton-Raphson Method
   - Numerical Integration

### Hard
1. **Graph Algorithms**:
   - Dijkstra's Algorithm
   - Bellman-Ford Algorithm
   - Floyd-Warshall Algorithm

2. **Advanced Dynamic Programming**:
   - Longest Increasing Subsequence
   - Longest Common Subsequence
   - Matrix Chain Multiplication

3. **Complex Data Structures**:
   - AVL Trees
   - Red-Black Trees
   - B-Trees

4. **Concurrency and Real-Time Algorithms**:
   - Mutexes and Semaphores
   - Scheduling Algorithms (Rate Monotonic, Earliest Deadline First)

5. **Cryptography Algorithms**:
   - RSA Algorithm
   - AES Encryption
   - SHA Hashing

6. **Optimization Algorithms**:
   - Genetic Algorithms
   - Simulated Annealing
   - Ant Colony Optimization

## Additional Actions

### Code Formatting

We use `clang-format` to ensure consistent code style across the project.

### Static Code Analysis

We use `clang-tidy` and `cppcheck` for static code analysis to catch potential issues early.

### Memory Leak Detection

We use `valgrind` to check for memory leaks and other memory-related issues.

### Code Coverage

We use `gcov` and `lcov` to generate code coverage reports to ensure our tests cover the code effectively.

### Documentation

We use Doxygen to generate detailed documentation for our code.

## Getting Started

To get started with this repository:
1. Clone the repository:
    ```bash
    git clone https://github.com/kiranj26/C-Algorithm-Playground.git
    ```
2. Navigate to the directory of the algorithm you want to explore.
3. Compile the C source file using GCC or any other C compiler:
    ```bash
    gcc -o algorithm algorithm.c
    ```
4. Run the compiled program:
    ```bash
    ./algorithm
    ```

## Contributions

Feel free to contribute by adding new algorithms or improving the existing implementations. Please follow the contribution guidelines outlined in the [CONTRIBUTING.md](CONTRIBUTING.md) file.

## Contact

Kiran Jojare  
Embedded Software Engineer  
Phone: 720-645-6212  
Email: kijo7257@colorado.edu

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

Happy Coding! 🚀
