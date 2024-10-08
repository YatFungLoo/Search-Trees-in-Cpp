#include "BST.hpp"
#include "cassert"
#include <cassert>

int main() {
    BST myBST(100);

    // Insert()
    myBST.Insert(20);
    myBST.Insert(10);
    myBST.Insert(30);
    myBST.Insert(200);
    myBST.Insert(150);
    myBST.Insert(300);

    // FindMinValue()
    int min_value = myBST.FindMinValue();
    assert(min_value == 10 && "Minimum value returned is incorrect.");
    std::cout << "Minimum key found is " << min_value << std::endl;

    // FindMaxValue()
    int max_value = myBST.FindMaxValue();
    assert(max_value == 300 && "Maximum value returned is incorrect.");
    std::cout << "Maximum key found is " << max_value << std::endl;

    // Remove() TODO: implement removing node other than leave.
    myBST.Remove(8);
    myBST.Remove(100);

    // Traversing()
    myBST.Traversing(in_order);
    myBST.Traversing(pre_order);
    myBST.Traversing(post_order);

    // Search()
    myBST.Search(200);
    myBST.Search(100);
    myBST.Search(300);

    return 0;
}
