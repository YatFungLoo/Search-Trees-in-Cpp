#include "BST.hpp"
#include <queue>

void BST::Insert(int key) {
    std::cout << "Inserting: " << key << '\n';
    root_node = InsertCompare(root_node, key);
}

std::unique_ptr<Node> BST::InsertCompare(std::unique_ptr<Node> &node, int key) {
    // Reaches bottom of tree/subtree.
    if (node == nullptr) {
        std::unique_ptr<Node> newNode = std::make_unique<Node>(key);
        return newNode;
    }

    if (key < node->Key) {
        node->Left = InsertCompare(node->Left, key);
    }

    if (key > node->Key) {
        node->Right = InsertCompare(node->Right, key);
    }

    if (key == node->Key) {
        std::cout << "Insert: same value error." << '\n';
        // Exit recursion.
    }

    return std::move(node);
}

void BST::Remove(int key) {
    std::cout << "Removing: " << key << '\n';
    root_node = RemoveNode(std::move(root_node), key);
}

std::unique_ptr<Node> BST::RemoveNode(std::unique_ptr<Node> node, int key) {
    // Reaches bottom of tree/subtree.
    if (node == nullptr) {
        return nullptr;
    }

    // Traverse to left child node when key is smaller.
    if (key < node->Key) {
        node->Left = RemoveNode(std::move(node->Left), key);
    }

    // Traverse to right child node when key is greater.
    if (key > node->Key) {
        node->Right = RemoveNode(std::move(node->Right), key);
    }

    // When key is found.
    if (key == node->Key) {
        // Case 1: If it's a leaf node (i.e no child).
        if (node->Left == nullptr && node->Right == nullptr) {
            node = nullptr;
            return nullptr;
        }

        // Case 2: If there is only one child, replace itself with child node and delete.
        // Covering cases for both sides.
        if (node->Left == nullptr && node->Right != nullptr) {
            return std::move(node->Right);
        }
        if (node->Left != nullptr && node->Right == nullptr) {
            return std::move(node->Left);
        }

        // Case 3: If node has two children, either:
        // 1) find node's right hand side inorder successor (smallest value), replace itself
        // with its successor, and delete the found inorder successor.
        Node *temp_min= FindMinValueNode(node->Right.get());
        node->Key = temp_min->Key;
        // Remove the successor
        node->Right = RemoveNode(std::move(node->Right), temp_min->Key);

        ////////////////////////////////////////////////////////////////////////////////////
        // 2) find node's left hand side biggest value, replace itself with its successor,
        // and delete the found inorder successor.
        // std::unique_ptr<Node> temp_max = FindMaxValueNode(root_node->Left);
        // node->Key = temp_max->Key;
        // node->Left = RemoveNode(node->Left, temp_max->Key);
        ////////////////////////////////////////////////////////////////////////////////////
    }
    return node;
}

void BST::Traversing(int mode) {
    // 1) Pre-order 2) Post-order 3) In-order
    switch (mode) {
    case pre_order:
        std::cout << "Pre-order traverse: ";
        PreOrderTraverse(root_node);
        std::cout << '\n';
        break;
    case post_order:
        std::cout << "Post-order traverse: ";
        PostOrderTraverse(root_node);
        std::cout << '\n';
        break;
    case in_order:
        std::cout << "In-order traverse: ";
        InOrderTraverse(root_node);
        std::cout << '\n';
        break;
    case level_order:
        std::cout << "Level-order traverse: ";
        LevelOrderTraverse(root_node);
        std::cout << '\n';
        break;
    }
}

void BST::PreOrderTraverse(std::unique_ptr<Node> &node) {
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

void BST::PostOrderTraverse(std::unique_ptr<Node> &node) {
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

void BST::InOrderTraverse(std::unique_ptr<Node> &node) {
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

/* Iterative Queue implementation.
   1. Add root / pop to visited.
   2. Add left node then right node to queue.
   3. Repeat until queue is empty.
 */
void BST::LevelOrderTraverse(std::unique_ptr<Node> &node) {
    std::queue<Node *> node_queue;
    std::queue<Node *> visited;
    node_queue.push(node.get());

    while (!node_queue.empty()) {
        int queue_length = node_queue.size();
        for (int i = 0; i < queue_length; i++) {
            auto *dequeue_node = (node_queue.front());
            node_queue.pop();
            visited.push(dequeue_node);
            if (dequeue_node->Left != nullptr) {
                node_queue.push(dequeue_node->Left.get());
            }
            if (dequeue_node->Right != nullptr) {
                node_queue.push(dequeue_node->Right.get());
            }
        }
    }

    // Printer.
    int length = visited.size();
    for (int i = 0; i < length; i++) {
        std::cout << visited.front()->Key << ", ";
        visited.pop();
    }
}

bool BST::Search(int key) {
    std::unique_ptr<Node> node = SimpleSearch(root_node, key);

    // Key not found (i.e. node is pointing to null)
    if (node == nullptr) {
        std::cout << "Key: " << key << "  was not found in the tree." << '\n';
        return false;
    }

    // Key found, print address and key.
    if (node != nullptr && key == node->Key) {
        std::cout << "Found key at: " << &node << " and its value is " << node->Key << '\n';
        return true;
    }

    return false;
}

std::unique_ptr<Node> BST::SimpleSearch(std::unique_ptr<Node> &node, int key) {
    // if node is null
    if (node == nullptr) {
        return nullptr;
    }

    // if the key is found at present node.
    if (key == node->Key) {
        return std::move(node);
    }

    // if key is smaller go left subtree.
    if (node != nullptr && key < node->Key) {
        node = SimpleSearch(node->Left, key);
    }

    // if key is larger go right subtree.
    if (node != nullptr && key > node->Key) {
        node = SimpleSearch(node->Right, key);
    }

    return std::move(node);
}

// Return minimun value of the tree.
int BST::FindMinValue() { return FindMinValueNode(root_node.get())->Key; }

Node *BST::FindMinValueNode(Node *node) {
    if (node->Left != nullptr) {
        return FindMinValueNode(node->Left.get());
    }
    return node;
}

// Return maximum calue of the tree.
int BST::FindMaxValue() { return FindMaxValueNode(root_node.get())->Key; }

Node *BST::FindMaxValueNode(Node *node) {
    if (node->Right != nullptr) {
        return FindMaxValueNode(node->Right.get());
    }
    return node;
}
