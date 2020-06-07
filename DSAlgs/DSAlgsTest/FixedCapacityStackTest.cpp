#include "pch.h"
#include "../DSAlgs/FixedCapacityStack.h"
#include "../DSAlgs/Stack.h"

TEST(FixedCapacityStackTest, TestConstruction) {
    FixedCapacityStack myStack(10);
    EXPECT_EQ(myStack.size(), 0);
    EXPECT_EQ(myStack.capacity(), 10);
}

TEST(FixedCapacityStackTest, TestCopyConstructor) {
    FixedCapacityStack myStack(10);

    for (int i = 0; i < 10; i++)
    {
        myStack.push(i);
    }

    FixedCapacityStack newStack(myStack);
    EXPECT_EQ(newStack.size(), 10);
    EXPECT_EQ(newStack.capacity(), 10);
    for (int i = 0; i < 10; i++)
    {
        EXPECT_EQ(newStack.top(), myStack.top());
        newStack.pop();
        myStack.pop();
    }

    EXPECT_TRUE(myStack.empty());
    EXPECT_TRUE(newStack.empty());
}

TEST(FixedCapacityStackTest, TestOverloadedAssignment) {
    FixedCapacityStack myStack(10);

    for (int i = 0; i < 10; i++)
    {
        myStack.push(i);
    }

    FixedCapacityStack newStack(100);
    EXPECT_EQ(newStack.size(), 0);
    EXPECT_EQ(newStack.capacity(), 100);

    newStack = myStack;
    EXPECT_EQ(newStack.size(), 10);
    EXPECT_EQ(newStack.capacity(), 10);
    for (int i = 0; i < 10; i++)
    {
        EXPECT_EQ(newStack.top(), myStack.top());
        newStack.pop();
        myStack.pop();
    }

    EXPECT_TRUE(myStack.empty());
    EXPECT_TRUE(newStack.empty());
}

TEST(FixedCapacityStackTest, TestEmpty) {
    FixedCapacityStack myStack(100);
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

TEST(FixedCapacityStackTest, TestSize) {
    FixedCapacityStack myStack(100);
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

TEST(FixedCapacityStackTest, TestPush) {
    FixedCapacityStack myStack(10);
    EXPECT_EQ(myStack.top(), -1);
    for (int i = 0; i < myStack.capacity(); i++)
    {
        myStack.push(i);
        EXPECT_EQ(myStack.top(), i);
    }

    EXPECT_EQ(myStack.capacity(), myStack.size());
    myStack.push(123);
    EXPECT_EQ(myStack.top(), myStack.capacity() - 1);
}

TEST(FixedCapacityStackTest, TestPop) {
    FixedCapacityStack myStack(10);
    EXPECT_EQ(myStack.top(), -1);
    for (int i = 0; i < myStack.capacity(); i++)
    {
        myStack.push(i);
    }

    int top = myStack.top();
    while(!myStack.empty())
    { 
        EXPECT_EQ(myStack.top(), top--);
        myStack.pop();
    }
}