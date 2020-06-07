#include "pch.h"
#include "../DSAlgs/DynamicArrayStack.h"
#include "../DSAlgs/Stack.h"

TEST(DynamicArrayStackTest, TestConstruction) {
    DynamicArrayStack myStack;
    EXPECT_EQ(myStack.size(), 0);
}

TEST(DynamicArrayStackTest, TestCopyConstructor) {
    DynamicArrayStack myStack;

    for (int i = 0; i < 10; i++)
    {
        myStack.push(i);
    }

    DynamicArrayStack newStack(myStack);
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

TEST(DynamicArrayStackTest, TestOverloadedAssignment) {
    DynamicArrayStack myStack;

    for (int i = 0; i < 10; i++)
    {
        myStack.push(i);
    }

    DynamicArrayStack newStack;
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

TEST(DynamicArrayStackTest, TestEmpty) {
    DynamicArrayStack myStack;
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

TEST(DynamicArrayStackTest, TestSize) {
    DynamicArrayStack myStack;
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

TEST(DynamicArrayStackTest, TestPush) {
    DynamicArrayStack myStack;
    EXPECT_EQ(myStack.top(), -1);
    int numsToPush = 50;
    for (int i = 0; i < numsToPush; i++)
    {
        myStack.push(i);
        EXPECT_EQ(myStack.top(), i);
    }

    EXPECT_EQ(numsToPush, myStack.size());
    myStack.push(123);
    EXPECT_EQ(myStack.top(), 123);
}

TEST(DynamicArrayStackTest, TestPop) {
    DynamicArrayStack myStack;
    EXPECT_EQ(myStack.top(), -1);
    int numsToPush = 50;
    for (int i = 0; i < numsToPush; i++)
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