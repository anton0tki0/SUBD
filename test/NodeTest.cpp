#include <gtest/gtest.h>
#include "../src/Node.hpp"


TEST(NodeTest, dataConstructorTest) {
    Node<int>* node = new Node<int>(0);
    ASSERT_EQ(0, node->getData());
    ASSERT_EQ(nullptr, node->getLeft());
    ASSERT_EQ(nullptr, node->getRight());
}

TEST(NodeTest, intCompareOperatorTest) {
    Node<int>* otherNode = new Node<int>(15);
    Node<int>* node = new Node<int>(10);

    ASSERT_EQ(false, *node == *otherNode);
    ASSERT_EQ(true, *node != *otherNode);
    ASSERT_EQ(false, *node > *otherNode);
    ASSERT_EQ(true, *node < *otherNode);
}

TEST(NodeTest, stringCompareOperatorTest) {
    Node<std::string>* node = new Node<std::string>("ozob");
    Node<std::string>* otherNode = new Node<std::string>("bozo");

    ASSERT_EQ(false, *node == *otherNode);
    ASSERT_EQ(true, *node != *otherNode);
    ASSERT_EQ(true, *node > *otherNode);
    ASSERT_EQ(false, *node < *otherNode);
}

TEST(NodeTest, dataSwapTest) {
    Node<int>* otherNode = new Node<int>(15);
    Node<int>* node = new Node<int>(10);
    node->dataSwap(otherNode);
    ASSERT_EQ(15, node->getData());
    ASSERT_EQ(10, otherNode->getData());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}