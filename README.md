# Simple BST in C++

Simple implementation of a BST tree written in C++.

## To build the project

Software requirement:

1. cmake version 3.22.1
2. Ubuntu clang version 14.0.0-1ubuntu1.1

Use the following Bash script to compile the project:
```
mkdir build && cd build
cmake .. --preset=clang_debug
make
```

When build finishes, run the executable in the `build/` directory:
```
./BST
```

## Structure

All functions are recursive, the user cannot access the recursive part of the library but are all controller via the functions wrapper on top of any the recursion to prevent bug.

List of function:

1. Creating the tree with `BST ${object_name}(${key})`.
2. `Insert(${key})` to insert node.
3. `Search(${key})` to find a specific node.
4. `Traversing(${mode})` to traverse while printing every node in order of traverse:
   1. In-order
   2. Pre-order
   3. Post-order
5. `FindMinvalue(${key})` to print the minimum key node,
6. `FindMaxvalue(${key})` to print the maximum key node,
