#ifndef NODE_H
#define NODE_H

#include <memory>

enum Colour { BLACK, RED };

struct Node {
    int Key;
    std::unique_ptr<Node> Left;
    std::unique_ptr<Node> Right;
    Node(int key) : Key(key), Left(nullptr), Right(nullptr) {}
};

struct Coloured_Node : public Node {
    Colour colour;
    Coloured_Node(int key) : Node(key), colour(BLACK){};
};

#endif
