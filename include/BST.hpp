#include <iostream>

class Node {
  public:
    int Key;
    Node *Left;
    Node *Right;
    Node *Parent;
    // Constructors
    Node() { Left = Right = Parent = nullptr; }
    Node(int key) {
        Key = key;
        Left = Right = Parent = nullptr;
    }
};

// Traversing mode
enum Mode { pre_order, post_order, in_order };

// Basic functions:
// Create(), Traversing(), Insert(), Search(), Remove(), PrintTree().
// Traversing includes 1) Pre-order 2) Post-order and 3) In-order.
class BST {
    Node *root_node = new Node();

  public:
    BST(int key) {
        std::cout << "Creating tree with root node: " << key << std::endl;
        root_node->Key = key;
    };
    void Insert(int key);
    void Remove(int key);
    // @param Mode: Pre_order, Post_order and In_order
    void Traversing(int mode);
    bool Search(int key);
    int FindMinValue();
    int FindMaxValue();
    Node *Create(int key);

  private:
    Node *InsertCompare(Node *node, int key);
    Node *RemoveNode(Node *node, int key);
    void PreOrderTraverse(Node *node);
    void PostOrderTraverse(Node *node);
    void InOrderTraverse(Node *node);
    Node *SimepleSearch(Node *node, int key);
    Node *FindMinValueNode(Node *node);
    Node *FindMaxValueNode(Node *node);
};
