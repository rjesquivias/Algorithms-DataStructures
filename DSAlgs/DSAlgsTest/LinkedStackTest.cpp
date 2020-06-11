#include "pch.h"
#include "../DSAlgs/LinkedStack.h"
#include "../DSAlgs/Stack.h"

TEST(LinkedStackTest, TestConstruction) {
    LinkedStack myStack;
    EXPECT_EQ(myStack.size(), 0);
}

TEST(LinkedStackTest, TestCopyConstructor) {
    LinkedStack myStack;

    for (int i = 0; i < 10; i++)
    {
        myStack.push(i);
    }

    LinkedStack newStack(myStack);
    EXPECT_EQ(newStack.size(), 10);
    for (int i = 0; i < 10; i++)
    {
        EXPECT_EQ(newStack.top(), myStack.top());
        newStack.pop();
        myStack.pop();
    }

    EXPECT_TRUE(myStack.empty());
    EXPECT_TRUE(newStack.empty());
}

TEST(LinkedStackTest, TestOverloadedAssignment) {
    LinkedStack myStack;

    for (int i = 0; i < 10; i++)
    {
        myStack.push(i);
    }

    LinkedStack newStack;
    EXPECT_EQ(newStack.size(), 0);

    newStack = myStack;
    EXPECT_EQ(newStack.size(), 10);
    for (int i = 0; i < 10; i++)
    {
        EXPECT_EQ(newStack.top(), myStack.top());
        newStack.pop();
        myStack.pop();
    }

    EXPECT_TRUE(myStack.empty());
    EXPECT_TRUE(newStack.empty());
}

TEST(LinkedStackTest, TestEmpty) {
    LinkedStack myStack;
    EXPECT_TRUE(myStack.empty());

    myStack.push(1);
    EXPECT_FALSE(myStack.empty());

    myStack.pop();
    EXPECT_TRUE(myStack.empty());

    for (int i = 0; i < 100; i++)
    {
        myStack.push(i);
        EXPECT_FALSE(myStack.empty());
    }

    while (!myStack.empty())
        myStack.pop();

    EXPECT_TRUE(myStack.empty());
}

TEST(LinkedStackTest, TestSize) {
    LinkedStack myStack;
    EXPECT_EQ(myStack.size(), 0);

    for (int i = 0; i < 100; i++)
    {
        myStack.push(i);
        EXPECT_EQ(myStack.size(), i + 1);
    }

    while (!myStack.empty())
        myStack.pop();

    EXPECT_EQ(myStack.size(), 0);
}

TEST(LinkedStackTest, TestPush) {
    LinkedStack myStack;
    EXPECT_EQ(myStack.top(), -1);
    int capacity = 50;
    for (int i = 0; i < capacity; i++)
    {
        myStack.push(i);
        EXPECT_EQ(myStack.top(), i);
    }

    EXPECT_EQ(capacity, myStack.size());
    myStack.push(123);
    EXPECT_EQ(myStack.top(), 123);
}

TEST(LinkedStackTest, TestPop) {
    LinkedStack myStack;
    EXPECT_EQ(myStack.top(), -1);
    int capacity = 50;
    for (int i = 0; i < capacity; i++)
    {
        myStack.push(i);
    }

    int top = myStack.top();
    while (!myStack.empty())
    {
        EXPECT_EQ(myStack.top(), top--);
        myStack.pop();
    }
}