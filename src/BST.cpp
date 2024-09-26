#include "BST.hpp"
#include <pthread.h>

void BST::Insert(int key) {
    std::cout << "Inserting: " << key << std::endl;
    root_node = InsertCompare(root_node, key);
}

Node *BST::InsertCompare(Node *node, int key) {
    // Reaches bottom of tree/subtree.
    if (node == nullptr) {
        Node *newNode = new Node(key);
        return newNode;
    }

    if (key < node->Key) {
        node->Left = InsertCompare(node->Left, key);
    }

    if (key > node->Key) {
        node->Right = InsertCompare(node->Right, key);
    }

    if (key == node->Key) {
        std::cout << "Insert: same value error." << std::endl;
        // Exit recursion.
    }

    return node;
}

void BST::Remove(int key) {
    std::cout << "Removing: " << key << std::endl;
    root_node = RemoveNode(root_node, key);
}

Node *BST::RemoveNode(Node *node, int key) {
    // Reaches bottom of tree/subtree.
    if (node == nullptr) {
        return node;
    }

    if (key < node->Key) {
        node->Left = RemoveNode(node->Left, key);
    }

    if (key > node->Key) {
        node->Right = RemoveNode(node->Right, key);
    }

    if (key == node->Key) {
        // If it's a leaf node (i.e no child).
        if (node->Left == nullptr && node->Right == nullptr) {
            delete node;
            return nullptr;
        }

        // If there is only one child, replace itself with child node and delete.
        // Covering cases for both sides.
        if (node->Left == nullptr) {
            Node *temp_node = node->Right;
            delete node;
            return temp_node;
        } else if (node->Right == nullptr) {
            Node *temp_node = node->Left;
            delete node;
            return temp_node;
        }
    }

    // TODO
    // need to cover more cases but require traverse function to find sub tree minimum value.

    return node;
}

void BST::Traversing(int mode) {
    // 1) Pre-order 2) Post-order 3) In-order
    switch (mode) {
    case pre_order:
        std::cout << "Pre-order traverse: ";
        PreOrderTraverse(root_node);
        std::cout << std::endl;
        break;
    case post_order:
        std::cout << "Post-order traverse: ";
        PostOrderTraverse(root_node);
        std::cout << std::endl;
        break;
    case in_order:
        std::cout << "In-order traverse: ";
        InOrderTraverse(root_node);
        std::cout << std::endl;
        break;
    }
}

void BST::PreOrderTraverse(Node *node) {
    // Reaches bottom of tree.
    if (node == nullptr) {
        return;
    }

    // Print node's key.
    std::cout << node->Key << " ";
    // Left subtree/node first.
    PreOrderTraverse(node->Left);
    // Then proceed to right subtree/node to finish up.
    PreOrderTraverse(node->Right);
}

void BST::PostOrderTraverse(Node *node) {
    // Reaches bottom of tree.
    if (node == nullptr) {
        return;
    }

    // Left subtree/node first.
    PostOrderTraverse(node->Left);
    // Then proceed to right subtree/node to finish up.
    PostOrderTraverse(node->Right);
    // Print node's key.
    std::cout << node->Key << " ";
}

void BST::InOrderTraverse(Node *node) {
    // Reaches bottom of tree.
    if (node == nullptr) {
        return;
    }

    // Left subtree/node first.
    InOrderTraverse(node->Left);
    // Print node's key.
    std::cout << node->Key << " ";
    // Then proceed to right subtree/node to finish up.
    InOrderTraverse(node->Right);
}

bool BST::Search(int key) {
    Node *node = SimepleSearch(root_node, key);

    // Key not found (i.e. node is pointing to null)
    if (node == nullptr) {
        std::cout << "Key: " << key << "  was not found in the tree." << std::endl;
        return false;
    }

    // Key found, print address and key.
    if (node != nullptr && key == node->Key) {
        std::cout << "Found key at: " << &node << " and its value is " << node->Key << std::endl;
        return true;
    }

    return false;
}

Node *BST::SimepleSearch(Node *node, int key) {
    // if node is null
    if (node == nullptr) {
        return nullptr;
    }

    // if the key is found at present node.
    if (key == node->Key) {
        return node;
    }

    // if key is smaller go left subtree.
    if (node != nullptr && key < node->Key) {
        node = SimepleSearch(node->Left, key);
    }

    // if key is larger go right subtree.
    if (node != nullptr && key > node->Key) {
        node = SimepleSearch(node->Right, key);
    }

    return node;
}
