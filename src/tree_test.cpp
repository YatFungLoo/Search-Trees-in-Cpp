#include "BST.hpp"
#include <gtest/gtest.h>

TEST(BSTtest, Main) {
    BST testBST(100);
    // Insert()
    testBST.Insert(20);
    testBST.Insert(10);
    testBST.Insert(30);
    testBST.Insert(200);
    testBST.Insert(150);
    testBST.Insert(300);

    // FindMinValue()
    int min_value = testBST.FindMinValue();
    assert(min_value == 10 && "Minimum value returned is incorrect.");
    std::cout << "Minimum key found is " << min_value << '\n';

    // FindMaxValue()
    int max_value = testBST.FindMaxValue();
    assert(max_value == 300 && "Maximum value returned is incorrect.");
    std::cout << "Maximum key found is " << max_value << '\n';

    // Remove() TODO: implement removing node other than leave.
    testBST.Remove(8);
    testBST.Remove(100);

    // Traversing()
    testBST.Traversing(in_order);
    testBST.Traversing(pre_order);
    testBST.Traversing(post_order);
    testBST.Traversing(level_order);

    // Search()
    testBST.Search(200);
    testBST.Search(100);
    testBST.Search(300);

    /* expected output:
    Creating tree with root node: 100
    Inserting: 20
    Inserting: 10
    Inserting: 30
    Inserting: 200
    Inserting: 150
    Inserting: 300
    Minimum key found is 10
    Maximum key found is 300
    Removing: 8
    Removing: 100
    In-order traverse: 10 20 30 150 200 300
    Pre-order traverse: 150 20 10 30 200 300
    Post-order traverse: 10 30 20 300 200 150
    Level-order traverse: 150, 20, 200, 10, 30, 300,
    Found key at: 0x16bcaef30 and its value is 200
    Key: 100  was not found in the tree.
    Found key at: 0x16bcaef30 and its value is 300
    */
}
