#include "BST.hpp"

int main() {
    BST myBST(100);

    // Insert()
    myBST.Insert(20);
    myBST.Insert(10);
    myBST.Insert(30);
    myBST.Insert(200);
    myBST.Insert(150);
    myBST.Insert(300);

    // Remove() TODO: implement removing node other than leave.
    // myBST.Remove(8);

    // Traversing()
    myBST.Traversing(in_order);
    myBST.Traversing(pre_order);
    myBST.Traversing(post_order);

    // Search()
    myBST.Search(200);
    myBST.Search(15);
    myBST.Search(300);

    return 0;
}
