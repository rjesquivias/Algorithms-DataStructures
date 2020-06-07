#include "pch.h"
#include "../DSAlgs/SinglyLinkedList.h"

TEST(SinglyLinkedListTest, TestConstruction) {
    SinglyLinkedList list;
    EXPECT_EQ(list.getSize(), 0);
    EXPECT_TRUE(list.empty());
}

TEST(SinglyLinkedListTest, TestCopyConstructor) {
    SinglyLinkedList list;
    list.push_front(1);
    list.push_front(3);
    list.push_front(5);

    SinglyLinkedList testList(list);
    EXPECT_EQ(testList.getSize(), 3);
    EXPECT_EQ(testList.front(), 5);
    EXPECT_EQ(testList.back(), 1);
}

TEST(SinglyLinkedListTest, TestOverloadedAssignment) {
    SinglyLinkedList list;
    list.push_front(1);
    list.push_front(3);
    list.push_front(5);

    SinglyLinkedList testList;
    testList = list;
    EXPECT_EQ(testList.getSize(), 3);
    EXPECT_EQ(testList.front(), 5);
    EXPECT_EQ(testList.back(), 1);
}

TEST(SinglyLinkedListTest, TestClear) {
    SinglyLinkedList list;
    for (int i = 0; i < 50; i++)
    {
        list.push_front(i);
    }
    EXPECT_EQ(list.getSize(), 50);

    list.clear();
    EXPECT_EQ(list.getSize(), 0);
}

TEST(SinglyLinkedListTest, TestPushFront) {
    SinglyLinkedList list;
    list.push_front(15);
    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.front(), 15);
    EXPECT_FALSE(list.empty());

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    EXPECT_EQ(list.getSize(), 5);
    EXPECT_EQ(list.front(), 4);
}

TEST(SinglyLinkedListTest, TestPopFront) {
    SinglyLinkedList list;
    list.push_front(15);
    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.front(), 15);
    EXPECT_FALSE(list.empty());

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    EXPECT_EQ(list.getSize(), 5);
    EXPECT_EQ(list.front(), 4);

    list.pop_front();
    EXPECT_EQ(list.getSize(), 4);
    EXPECT_EQ(list.front(), 3);

    list.pop_front();
    EXPECT_EQ(list.getSize(), 3);
    EXPECT_EQ(list.front(), 2);

    list.pop_front();
    EXPECT_EQ(list.getSize(), 2);
    EXPECT_EQ(list.front(), 1);

    list.pop_front();
    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.front(), 15);
}

TEST(SinglyLinkedListTest, TestInsertAt) {
    SinglyLinkedList list;
    list.push_front(15);
    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.front(), 15);
    EXPECT_FALSE(list.empty());

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    EXPECT_EQ(list.getSize(), 5);
    EXPECT_EQ(list.front(), 4);

    // insert at front
    list.insertAt(25, 0);
    EXPECT_EQ(list.front(), 25);

    // insert at back
    list.insertAt(100, list.getSize());
    EXPECT_EQ(list.back(), 100);
    EXPECT_EQ(list.getSize(), 7);

    list.insertAt(50, 3);
    list.pop_front();
    list.pop_front();
    list.pop_front();
    EXPECT_EQ(list.front(), 50);
    EXPECT_EQ(list.back(), 100);
}

TEST(SinglyLinkedListTest, testRemoveAt) {
    SinglyLinkedList list;
    list.push_front(15);
    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.front(), 15);
    EXPECT_FALSE(list.empty());

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    EXPECT_EQ(list.getSize(), 5);
    EXPECT_EQ(list.front(), 4);

    // remove at front
    list.remove(0);
    EXPECT_EQ(list.front(), 3);

    // remove at back
    EXPECT_EQ(list.back(), 15);
    list.remove(list.getSize() - 1);
    EXPECT_EQ(list.back(), 1);
}