#ifndef RBT_H
#define RBT_H

#include "BST.hpp"

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

#endif
