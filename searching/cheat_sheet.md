
# Searching Algorithms Cheat Sheet

## Introduction

This cheat sheet covers essential tips and tricks for solving searching algorithm problems commonly found in technical interviews and on platforms like LeetCode. Use this guide to quickly recall key concepts and improve your problem-solving skills.

---

## Table of Contents
1. [Binary Search](#binary-search)
2. [Depth-First Search (DFS)](#depth-first-search-dfs)
3. [Breadth-First Search (BFS)](#breadth-first-search-bfs)
4. [Two-Pointer Technique](#two-pointer-technique)
5. [Sliding Window](#sliding-window)
6. [Trie (Prefix Tree)](#trie-prefix-tree)
7. [Graph Search](#graph-search)

---

## Binary Search

### Concept
Binary search is used on a sorted array to find the position of a target value. It repeatedly divides the search interval in half.

### Key Points
- **Time Complexity**: O(log n)
- **Space Complexity**: O(1) for iterative, O(log n) for recursive
- Always check for overflow when calculating `mid`.

### Visualization

\`\`\`
Initial Array: [1, 2, 3, 4, 5, 6, 7, 8, 9]
Target: 5

1. Calculate mid: (low + high) / 2
2. Compare mid with target
3. Adjust low or high
4. Repeat until found or low > high
\`\`\`

---

## Depth-First Search (DFS)

### Concept
DFS explores as far as possible along each branch before backtracking.

### Key Points
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V)
- Can be implemented using a stack (iterative) or recursion.

### Visualization

\`\`\`
Graph:
1 - 2
|   |
3 - 4

1. Start at node 1
2. Visit nodes 2, 4, 3 recursively
\`\`\`

---

## Breadth-First Search (BFS)

### Concept
BFS explores all nodes at the present depth before moving on to nodes at the next depth level.

### Key Points
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V)
- Uses a queue for implementation.

### Visualization

\`\`\`
Graph:
1 - 2
|   |
3 - 4

1. Start at node 1
2. Visit nodes 2, 3
3. Visit node 4
\`\`\`

---

## Two-Pointer Technique

### Concept
Two pointers are used to iterate through the array to find pairs that meet certain criteria.

### Key Points
- Commonly used for problems involving pairs or triplets.
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

### Visualization

\`\`\`
Array: [1, 2, 3, 4, 5, 6]
Target Sum: 7

1. Set left pointer at start and right pointer at end
2. Move pointers based on sum comparison
\`\`\`

---

## Sliding Window

### Concept
A dynamic window slides over the array to find subarrays that meet certain conditions.

### Key Points
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- Useful for problems involving subarrays or substrings.

### Visualization

\`\`\`
Array: [1, 2, 3, 4, 5]
Window Size: 3

1. Initialize window with first k elements
2. Slide window across array, updating sum
\`\`\`

---

## Trie (Prefix Tree)

### Concept
Trie is a tree-like data structure used to store a dynamic set of strings, where the keys are usually strings.

### Key Points
- **Time Complexity**: O(m) for insertion and search, where m is the length of the word.
- **Space Complexity**: O(n * m), where n is the number of keys and m is the average key length.

### Visualization

\`\`\`
Words: ["apple", "ape", "bat"]

         root
        /    \
       a      b
      / \      \
     p   e      a
    /     \      \
   p       n      t
  /         \
 l           d
/
e
\`\`\`

---

## Graph Search

### Concept
Graph search algorithms like DFS and BFS are used to explore nodes and edges in a graph.

### Key Points
- **DFS** is good for exploring all paths.
- **BFS** is optimal for finding the shortest path in unweighted graphs.
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V)

### Visualization

\`\`\`
Graph:
A - B - C
|   |
D - E

1. Use DFS or BFS to explore the graph from node A
\`\`\`

---

## Contact

Kiran Jojare  
Embedded Software Engineer  
Phone: 720-645-6212  
Email: kijo7257@colorado.edu
