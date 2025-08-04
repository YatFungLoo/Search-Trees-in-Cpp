# Simple Search Trees in C++

Simple implementation of a search trees (BST, red-black) written in C++.

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Simple BST in C++](#simple-bst-in-c)
- [To build the project](#to-build-the-project)
- [Structure](#structure)
- [Tree Traversal](#tree-traversal)
  - [Note On Following Implementation](#note-on-following-implementation)
  - [In-order Traversal](#in-order-traversal)
  - [Pre-order Traversal](#pre-order-traversal)
  - [Post-order Traversal](#post-order-traversal)
  - [Level-order Traversal (Breadth First Search)](#level-order-traversal-breadth-first-search)
    - [Iterative Method Using Queue](#iterative-method-using-queue)
- [Balance Search Tree](#balance-search-tree)
  - [2-3 Search Tree (concept)](#2-3-search-tree-concept)
    - [Insertion method](#insertion-method)
  - [Red-Black BSTs](#red-black-bsts)

<!-- markdown-toc end -->


# To build the project

Software requirement:

1. cmake version 3.22.1
3. ninja 1.13.0.git
2. Ubuntu clang version 14.0.0-1ubuntu1.1


Use the following Bash script to compile the project:

```bash
cmake -S . --preset=debug -B build
```

or

```bash
cmake -S . --preset=release -B build
```

then run

```bash
cmake --build build
```
When build finishes, run the executable in the `build/` directory:
```
./build/BST
```

# Structure

All functions are recursive, the user cannot access the recursive part of the library but are all controller via the functions wrapper on top of any the recursion to prevent bug.

List of function:

1. Creating the tree with `BST ${object_name}(${key})`.
2. `Insert(${key})` to insert node.
3. `Search(${key})` to find a specific node.
4. `Traversing(${mode})` to traverse while printing every node in order of traverse:
    1. [In-order](#in-order)
    2. [Pre-order](#pre-order)
    3. [Post-order](#post-order)
5. `FindMinvalue(${key})` to print the minimum key node,
6. `FindMaxvalue(${key})` to print the maximum key node,

# Tree Traversal
Tree traversal in Binary Tree structure are techniques to visit each node of the tree exactly once. Done by visiting each node's left or right child pointer. All are done recursively. The following three traverse techniques are known as depth-first traversal.

It is an important concept in programming language design as different traverse method are used to emulate different expressions, in expression tree (which is a type of binary tree).

## Note On Following Implementation
The following traversal are not considered as depth-first-search algorithm but rather just traversal, they are done using recursion, meaning the call stack is used instead.

> Proper depth-first-search algorithm should implemented with stack. While breadth-first-search are implemented using queue.

## In-order Traversal
Instructions:
1. Traverse left subtree.
2. Visit root node.
3. Traverse right subtree.

Can be use to get nodes in sorted order. In case of binary tree, it gives non-decreasing order.

## Pre-order Traversal
Instructions.
1. Visit root node.
2. Visit left subtree.
3. Visit right subtree.

Can be use to create a copy of the tree.

## Post-order Traversal
1. Visit left subtree.
2. Visit right subtree.
3. Visit root node.

Can be use to delete a binary tree. In case of programming language it can be a helper algorithm in garbage collection.

## Level-order Traversal (Breadth First Search)
More special than the other traversal, level-order traverse nodes by level, from root to lower depth. It can be think of as visiting each node in the order of tree in array implementation, instead of linked list.

This can be achieved either recursively using stack, or iteratively using queue, white both uses O(n) space and time. This code uses iterative method with queue structure.

### Iterative Method Using Queue
This method uses two additional queue, 1) node queue and 2) visitied node.

Instructions:
1. Push root node into queue.
2. While queue is not empty:
   1. Get queue size (should be the same as the number of nodes of the level).
   2. Iterate node queue to queue size:
	  1. Pop nodes from node queue and push to visited queue.
	  2. Check node's children, from left to right.
	  3. If left node exist, push left node to node_queueu.
	  4. If right node exist, push right node to node_queueu.

# Balance Search Tree
A type of BST called Balance search tree, usually referred to it's most common implementation Red-Black tree, In comparison to binary search tree are searches are guaranteed to be logarithmic.

## 2-3 Search Tree (concept)
This tree allows extra link to be connected to each node, where each node can now held up to 2 keys and 3 links, hence the name 2 "to" 3 node search tree. A 2-3 search tree are perfectly balanced when all null links (link to empty tree) are the same distance from the root. 

2-3 search tree grows from the bottom up, opposite to BST.

### Insertion method
To keep tree perfectly balance, when the 2-3 node has a *single key* simple insert the new key into the node. When the 2-3 node already has *2 keys*, first insert the key into the node, then node then split the 3 keys into individual nodes, where the middle key is root.

For 3-links node (3 node) whose *parents is also a 3 node*, in simple term the process follows above but root node instead will perform the join then split again until there are no 4-links node. If the insertion whole way through are all 3-nodes, then the root node will be a 4-node. The root node will be splited, to create 3 individual 2-node.

## Red-Black BSTs
A simple implementation to encode 3-nodes using extra colour information on the link between node. Red link connection form a 3-node, while black link bind together the tree. Summary red link should lean left, where no node can have two red links, and tree has to be perfect black balance (all root to null link has to have the same number of black links).

Colour parameter can simply be a boolean, added to `node`. While getter function should function, we need to be able to rotate node from leaning left to right and vice versa. Rotate function flip the leaning side of the red-link.
