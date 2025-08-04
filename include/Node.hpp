#ifndef NODE_H
#define NODE_H

#include <memory>

// Red black tree colours
enum Colour { BLACK, RED };

struct Node {
    // public:
    int Key;
    std::unique_ptr<Node> Left;
    std::unique_ptr<Node> Right;
    // Constructors
    Node(int key) : Key(key), Left(nullptr), Right(nullptr) {}
};

struct Coloured_Node : public Node {
    // public:
    bool colour;
    // Constructors
    Coloured_Node(int key) : Node(key), colour(BLACK){};
};

#endif
