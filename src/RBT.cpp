#include "RBT.hpp"

bool RBT::TurnRed(Coloured_Node *node) {
    if (node == nullptr) {
        return false;
    }
    return node->colour == RED;
}

Coloured_Node *RBT::RotateLeft(Coloured_Node *node) { return node; }
Coloured_Node *RBT::RotateRight(Coloured_Node *node) { return node; }
Coloured_Node *RBT::FlipColours(Coloured_Node *node) { return node; }
