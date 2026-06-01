# Learning Data structures and Algorithms

# Learning Resources
1. [Common DSA Patterns](https://docs.google.com/document/d/1LTpzSVhrPj4PU44UiDX4JwNvO4F-H_SuU6g7v9H6Jik/edit?usp=sharing)
2. [Common DP Patterns](https://docs.google.com/document/d/1e9fvE4hJuC5BBROFj8QJbr6anoKLfrBbxEoHrozSTfg/edit?usp=sharing)

# Neetcode 150 + Blind 75 Extended

## Arrays, Hashing & String Manipulation

| Pattern / Concept | Trivial Prerequisite | Core Problem (Blind 75 / NC 150) |
| :--- | :--- | :--- |
| **Max/Min Values** | Find the maximum element in an array. | Kth Largest Element in an Array |
| **Hash Map Counting** | Count the frequency of each character in a string. | Valid Anagram / Group Anagrams |
| **Set Lookups** | Check if a specific target number exists in an array. | Contains Duplicate / Two Sum |
| **Prefix Sum** | Create a running sum array from a standard array. | Product of Array Except Self |
| **Sequence Tracking** | Find if an array is strictly increasing. | Longest Consecutive Sequence |

## Pointers & Sliding Windows

| Pattern / Concept | Trivial Prerequisite | Core Problem (Blind 75 / NC 150) |
| :--- | :--- | :--- |
| **Two Pointers (Opposite)** | Reverse an array in-place using left and right pointers. | Valid Palindrome / Two Sum II |
| **Two Pointers (Same Dir)** | Move all zeros to the end of an array. | Remove Duplicates from Sorted Array |
| **Three Pointers** | Find three numbers that sum to exactly zero in a sorted array. | 3Sum |
| **Fixed Window** | Find the sum of all subarrays of size `k`. | Maximum Average Subarray I |
| **Dynamic Window** | Find the longest subarray consisting of only 1s. | Longest Repeating Character Replacement |

## Stacks & Binary Search

| Pattern / Concept | Trivial Prerequisite | Core Problem (Blind 75 / NC 150) |
| :--- | :--- | :--- |
| **LIFO Mechanics** | Implement a basic Push/Pop stack using a standard array. | Min Stack |
| **Bracket Matching** | Check if a string has an equal number of open and closed brackets. | Valid Parentheses |
| **Monotonic Stack** | Find the next greater element for each item in an array. | Daily Temperatures |
| **Standard Binary Search** | Return the index of a target in a perfectly sorted array. | Binary Search |
| **Modified Binary Search** | Find the index where a sorted array was pivoted/rotated. | Find Minimum in Rotated Sorted Array |

## Linked Lists & Trees

| Pattern / Concept | Trivial Prerequisite | Core Problem (Blind 75 / NC 150) |
| :--- | :--- | :--- |
| **List Traversal** | Traverse a linked list and return its total length. | Middle of the Linked List |
| **Pointer Manipulation** | Swap the values of two adjacent nodes. | Reverse Linked List |
| **Multiple Pointers** | Traverse two lists simultaneously until one reaches `null`. | Merge Two Sorted Lists |
| **Tree Traversal** | Print a tree using recursive Pre/In/Post-order functions. | Binary Tree Inorder Traversal |
| **Depth/Height** | Count the total number of nodes in a binary tree. | Maximum Depth of Binary Tree |
| **Tree Properties** | Swap the left and right child of a single root node. | Invert Binary Tree |

## Graphs & Backtracking

| Pattern / Concept | Trivial Prerequisite | Core Problem (Blind 75 / NC 150) |
| :--- | :--- | :--- |
| **Graph Representation** | Build an Adjacency List from an array of edges. | Clone Graph |
| **Grid Traversal** | Write a DFS function to visit all cells in a 2D matrix. | Number of Islands |
| **Cycle Detection** | Track visited nodes in a simple directed graph to find a loop. | Course Schedule |
| **Combinations** | Generate all subsets of an array of length 2. | Subsets |
| **Permutations** | Swap elements to find all orderings of 3 distinct numbers. | Permutations |

## Dynamic Programming

| Pattern / Concept | Trivial Prerequisite | Core Problem (Blind 75 / NC 150) |
| :--- | :--- | :--- |
| **1D Memoization** | Write a recursive Fibonacci function, then cache the results. | Climbing Stairs |
| **1D Tabulation** | Build an iterative Fibonacci sequence using an array. | House Robber |
| **2D DP / Grid** | Find the number of paths from top-left to bottom-right in an empty grid. | Unique Paths |
| **Knapsack Variations** | Determine if you can make exact change with given coins. | Coin Change |

# Solving Problems 101

1. Simplify the Problem
Most of the questions have lot of unnecessary information, make sure that you understand what truly matters.
Every question has input that you have to transform into the desired outputs, make sure to manually walkthrough an example to understand the crux of the problem before jumping to finding a solution.

These points should be clarified.
- "The inputs are X"
- "We perform Z operation on X"
- "We get Y as output"

*Make sure you ask clarifying questions to remove any ambiguity. Also make sure that you think about edge cases.*

2. Pattern Recognition
Most of the problems revolve around some problem solving pattern, to recognize what pattern to use you should be familir with data structures and algorithms and Big O notations particularly as they help you in pattern recognition.

*Start out by explaining/thinking the straight forward solution (brute force solution), even if it is not efficient. Just identify the Time and Space complexities, this way you find the gaps for optimizing the solution and then moving towards finding the optimal solution.*

**Always look at constraints, they act as a hint**

3. Implementation
Implement your solution. Through enough practice you will start recognizing patterns quickly.

*Before implementing a solution, make sure that you have thought about every possible edge case and a optimal solution for the given problem.*

Make sure before you submit the solution, you have not made any syntactical and logical errors for this you can dry run the example that you had walkthrough before and see if it works as intended.

4. Debug
If your solution fails straight away, then either you have made mistake in your implementation or your solution is wrong for the given problem. Identify the failed test cases, and check if they are edge cases or not. Rethink about the solution and implement it again.


