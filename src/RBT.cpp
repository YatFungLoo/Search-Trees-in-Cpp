#include "RBT.hpp"
#include <stdexcept>

bool RBT::isRed(Coloured_Node *node) {
    if (node == nullptr) {
        std::runtime_error("Node does not exist.")
    }
    if (node->colour == BLACK) {
        return false;
    }
    if (node->colour == RED) {
        return true;
    }
    return false;
}

Coloured_Node *RBT::RotateLeft(Coloured_Node *node) { return node; }
Coloured_Node *RBT::RotateRight(Coloured_Node *node) { return node; }
Coloured_Node *RBT::FlipColours(Coloured_Node *node) { return node; }
