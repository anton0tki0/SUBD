#include <gtest/gtest.h>
#include "../src/BST.hpp"

TEST(BSTTest, insertTest) {
    BST<int>* tree = new BST<int>();
    tree->insertNode(10);
    tree->insertNode(15);
    tree->insertNode(5);

    ASSERT_EQ(10, tree->getRoot()->getData());
    ASSERT_EQ(5, tree->getRoot()->getLeft()->getData());
    ASSERT_EQ(15, tree->getRoot()->getRight()->getData());
}
TEST(BSTTest, isContainsTest) {
    BST<int>* tree = new BST<int>();
    tree->insertNode(10);
    tree->insertNode(15);
    tree->insertNode(5);

    ASSERT_EQ(true, tree->isContains(5));
    ASSERT_EQ(false, tree->isContains(55));
}
TEST(BSTTest, findMinTest) {
    BST<int>* tree = new BST<int>();
    tree->insertNode(10);
    tree->insertNode(15);
    tree->insertNode(5);

    ASSERT_EQ(5, tree->getMin()->getData());
}
TEST(BSTTest, findMaxTest) {
    BST<int>* tree = new BST<int>();
    tree->insertNode(10);
    tree->insertNode(15);
    tree->insertNode(5);

    ASSERT_EQ(15, tree->getMax()->getData());
}
TEST(BSTTest, removeTest) {
    BST<int>* tree = new BST<int>();
    tree->insertNode(10);
    tree->insertNode(15);
    tree->insertNode(5);
    tree->insertNode(7);
    tree->insertNode(12);
    tree->insertNode(3);
    tree->insertNode(17);

    ASSERT_EQ(true, tree->isContains(15));
    tree->deleteNode(15);
    ASSERT_EQ(false, tree->isContains(15));
}