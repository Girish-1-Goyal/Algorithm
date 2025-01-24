# Tree Data Structures and Algorithms

This **README.md** file comprehensively lists important tree data structures, algorithms, their time complexities, space complexities, and constraints for competitive programming and DSA. It includes **best**, **worst**, and **average** cases for algorithms where applicable.

---

## **Tree Data Structures**

| Data Structure         | Description                                 | Operations                           | Time Complexities (Best/Worst/Average) | Space Complexity |
|------------------------|---------------------------------------------|--------------------------------------|-----------------------------------------|------------------|
| **Binary Tree**        | Each node has at most 2 children.          | Traversals, Height, Insert/Delete    | Insert/Delete: O(log n)/O(n)/O(log n)  | O(n)            |
| **Binary Search Tree** | Ordered binary tree (left < root < right). | Insert/Delete/Search                 | Insert/Delete/Search: O(log n)/O(n)/O(log n) | O(n)         |
| **AVL Tree**           | Self-balancing BST with height difference ≤ 1. | Insert/Delete/Search                 | O(log n)                                | O(n)            |
| **Red-Black Tree**     | Balanced BST with color constraints.       | Insert/Delete/Search                 | O(log n)                                | O(n)            |
| **Segment Tree**       | For range queries and updates.             | Build, Point Updates, Range Queries  | Build: O(n), Query/Update: O(log n)     | O(n)            |
| **Fenwick Tree**       | Tree for range queries and updates.        | Point Updates, Prefix Queries        | Update/Query: O(log n)                  | O(n)            |
| **Trie (Prefix Tree)** | For storing strings and prefix matching.   | Insert/Delete/Search                 | O(k) (k = length of word)               | O(n × k)       |
| **Suffix Tree**        | Compressed trie for suffixes.              | Substring Search, LCP                | Build: O(n), Query: O(m) (m = query length) | O(n)         |

---

## **Tree Algorithms**

| Algorithm                      | Description                                   | Time Complexity            | Space Complexity |
|--------------------------------|-----------------------------------------------|----------------------------|------------------|
| **Depth-First Search (DFS)**   | Preorder, Inorder, Postorder traversals.      | O(n)                       | O(h) (h = height)|
| **Breadth-First Search (BFS)** | Level-order traversal using a queue.          | O(n)                       | O(w) (w = width) |
| **Build Tree from Traversals** | Build tree from Preorder + Inorder/Postorder. | O(n)                       | O(n)             |
| **Lowest Common Ancestor (LCA)** | Find the LCA of two nodes.                   | Naive: O(n), Optimized: O(log n) | O(n log n) preprocessing |
| **Diameter of a Tree**         | Longest path between any two nodes.           | O(n)                       | O(h)             |
| **Maximum Path Sum**           | Max sum of any path in the tree.              | O(n)                       | O(h)             |
| **Heavy Light Decomposition**  | Efficient path queries and updates.           | O(log n) per query         | O(n)             |
| **Centroid Decomposition**     | Divide-and-conquer on tree paths.             | O(n log n)                 | O(n)             |
| **Trie Operations**            | Insert/Search/Delete in Trie.                 | O(k) (k = length of word)  | O(n × k)       |
| **Suffix Array + LCP Array**   | Efficient substring operations.               | Build: O(n log n), Query: O(1) | O(n)         |

---

## **Constraints**

| Constraint             | Value                                   |
|------------------------|-----------------------------------------|
| Maximum number of nodes| \(10^5 - 10^6\)                        |
| Memory Limit           | \(10^7 - 10^8\) bytes                  |

Use space-efficient techniques (e.g., iterative DFS, bit manipulation) for large constraints.

---

This README serves as a reference for tree data structures, their algorithms, and their complexities for efficient implementation in **C++** or other programming languages.

