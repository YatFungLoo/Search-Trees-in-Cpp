#include <iostream>
#include <queue>

// Red black tree colours
enum Colour { BLACK, RED };
// Traversing mode
enum Mode { pre_order, post_order, in_order, level_order };

struct Node {
    // public:
    int Key;
    Node *Left;
    Node *Right;
    // Constructors
    Node(int key) : Key(key), Left(nullptr), Right(nullptr) {}
};

struct Coloured_Node : public Node {
    // public:
    bool colour;
    // Constructors
    Coloured_Node(int key) : Node(key), colour(BLACK){};
};

/*
Basic functions:
1) Create(), Traversing(), Insert(), Search(), Remove(), PrintTree().
2) Depth-First-Search Traversing includes 1) Pre-order 2) Post-order and 3) In-order.
3) Breadth-First-Search Travering includes Level-order.
 */

class BST {
    Node *root_node = nullptr;

  public:
    BST(int key) {
        std::cout << "Creating tree with root node: " << key << std::endl;
        root_node = new Node(key);
    };
    void Insert(int key);
    void Remove(int key);
    // @param Mode: pre_order, post_order, in_order and level_order.
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
    void LevelOrderTraverse(Node *node);
    Node *SimpleSearch(Node *node, int key);
    Node *FindMinValueNode(Node *node);
    Node *FindMaxValueNode(Node *node);
};

class RBT {
    Coloured_Node *root_node = nullptr;

  public:
    RBT(int key) {
        std::cout << "Creating red-black tree with root node: " << key << std::endl;
        root_node = new Coloured_Node(key);
    }

  private:
    bool TurnRed(Coloured_Node *node);
    Coloured_Node *RotateLeft(Coloured_Node *node);
    Coloured_Node *RotateRight(Coloured_Node *node);
    Coloured_Node *FlipColours(Coloured_Node *node);
    int size() { return size(root_node); };
    int size(Coloured_Node *node) {
        if (node == nullptr) {
            return 0;
        }
        return 0;
    };
};
