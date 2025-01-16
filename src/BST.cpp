#include "BST.hpp"

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

    // Traverse to left child node when key is smaller.
    if (key < node->Key) {
        node->Left = RemoveNode(node->Left, key);
    }

    // Traverse to right child node when key is greater.
    if (key > node->Key) {
        node->Right = RemoveNode(node->Right, key);
    }

    // When key is found.
    if (key == node->Key) {
        // Case 1: If it's a leaf node (i.e no child).
        if (node->Left == nullptr && node->Right == nullptr) {
            delete node;
            return nullptr;
        }

        // Case 2: If there is only one child, replace itself with child node and delete.
        // Covering cases for both sides.
        if (node->Left == nullptr && node->Right != nullptr) {
            Node *temp_node = node->Right;
            delete node;
            return temp_node;
        } else if (node->Right == nullptr && node->Left != nullptr) {
            Node *temp_node = node->Left;
            delete node;
            return temp_node;
        }

        // Case 3: If node has two children, either:
        // 1) find node's right hand side inorder successor (smallest value), replace itself
        // with its successor, and delete the found inorder successor.
        Node *temp_min = FindMinValueNode(root_node->Right);
        node->Key = temp_min->Key;
        node->Right = RemoveNode(node->Right, temp_min->Key);

        ////////////////////////////////////////////////////////////////////////////////////
        // 2) find node's left hand side biggest value, replace itself with its successor,
        // and delete the found inorder successor.
        // Node *temp_max = FindMaxValueNode(root_node->Left);
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
    case level_order:
        std::cout << "Level-order traverse: ";
        LevelOrderTraverse(root_node);
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

/* Iterative Queue implementation.
   1. Add root / pop to visited.
   2. Add left node then right node to queue.
   3. Repeat until queue is empty.
 */
void BST::LevelOrderTraverse(Node *node) {
    std::queue<Node *> node_queue;
    std::queue<Node *> visited;
    node_queue.push(node);

    while (!node_queue.empty()) {
	int queue_length = node_queue.size();
        for (int i = 0; i < queue_length; i++) {
	    auto dequeu_node = (node_queue.front());
	    node_queue.pop();
	    visited.push(dequeu_node);
	    if (dequeu_node->Left != nullptr) {
		node_queue.push(dequeu_node->Left);
	    }
	    if (dequeu_node->Right != nullptr) {
		node_queue.push(dequeu_node->Right);
	    }
        }
    }

    // Printer.
    int length = visited.size();
    for (int i = 0 ; i < length; i++) {
	std::cout << visited.front()->Key << ", ";
	visited.pop();
    }
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

// Return minimun value of the tree.
int BST::FindMinValue() {
    Node *node = nullptr;
    node = FindMinValueNode(root_node);
    return node->Key;
}

Node *BST::FindMinValueNode(Node *node) {
    if (node->Left != nullptr) {
        node = FindMinValueNode(node->Left);
    }
    return node;
}

// Return maximum calue of the tree.
int BST::FindMaxValue() {
    Node *node = nullptr;
    node = FindMaxValueNode(root_node);
    return node->Key;
}

Node *BST::FindMaxValueNode(Node *node) {
    if (node->Right != nullptr) {
        node = FindMaxValueNode(node->Right);
    }
    return node;
}
