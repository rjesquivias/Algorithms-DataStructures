#include "pch.h"
#include "../DSAlgs/BinarySearchTree.h"

TEST(BinarySearchTreeTest, TestSearch) {
    BinarySearchTree tree;
    int randomNumber = 2947;
    tree.insert(randomNumber);
    EXPECT_EQ(tree.search(randomNumber), randomNumber);
    EXPECT_EQ(tree.search(randomNumber + 1), -1);
    EXPECT_EQ(tree.search(randomNumber - 1), -1);
}

TEST(BinarySearchTreeTest, TestInsert) {
    BinarySearchTree tree;
    int randomNumber = 2947;
    tree.insert(randomNumber);
    EXPECT_EQ(tree.search(randomNumber), randomNumber);
    EXPECT_EQ(tree.search(randomNumber + 1), -1);
    EXPECT_EQ(tree.search(randomNumber - 1), -1);


    for (int i = 0; i < 100; i++)
    {
        EXPECT_EQ(tree.search(i), -1);
        tree.insert(i);
        EXPECT_EQ(tree.search(i), i);
        EXPECT_EQ(tree.search(i - 1), i - 1);
        EXPECT_EQ(tree.search(i + 1), -1);
    }
}

TEST(BinarySearchTreeTest, TestRemove) {
    BinarySearchTree tree;

    for (int i = 0; i < 100; i++)
    {
        EXPECT_EQ(tree.search(i), -1);
        tree.insert(i);
        EXPECT_EQ(tree.search(i), i);

        tree.remove(i);
        EXPECT_EQ(tree.search(i), -1);
    }
}
