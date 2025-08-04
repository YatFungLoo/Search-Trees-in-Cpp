#ifndef BST_H
#define BST_H

#include "Node.hpp"
#include <iostream>
#include <memory>

/*
Basic functions:
1) Create(), Traversing(), Insert(), Search(), Remove(), PrintTree().
2) Depth-First-Search Traversing includes 1) Pre-order 2) Post-order and 3) In-order.
3) Breadth-First-Search Travering includes Level-order.
 */

// Traversing mode
enum Mode { pre_order, post_order, in_order, level_order };

class BST {
    std::unique_ptr<Node> root_node = nullptr;

  public:
    BST(int key) {
        std::cout << "Creating tree with root node: " << key << '\n';
        root_node = std::make_unique<Node>(key);
    };
    void Insert(int key);
    void Remove(int key);
    // @param Mode: pre_order, post_order, in_order and level_order.
    void Traversing(int mode);
    bool Search(int key);
    int FindMinValue();
    int FindMaxValue();
    std::unique_ptr<Node> Create(int key);

  private:
    std::unique_ptr<Node> InsertCompare(std::unique_ptr<Node> &node, int key);
    std::unique_ptr<Node> RemoveNode(std::unique_ptr<Node> &node, int key);
    void PreOrderTraverse(std::unique_ptr<Node> &node);
    void PostOrderTraverse(std::unique_ptr<Node> &node);
    void InOrderTraverse(std::unique_ptr<Node> &node);
    static void LevelOrderTraverse(std::unique_ptr<Node> &node);
    std::unique_ptr<Node> SimpleSearch(std::unique_ptr<Node> &node, int key);
    std::unique_ptr<Node> FindMinValueNode(std::unique_ptr<Node> &node);
    std::unique_ptr<Node> FindMaxValueNode(std::unique_ptr<Node> &node);
};

#endif
