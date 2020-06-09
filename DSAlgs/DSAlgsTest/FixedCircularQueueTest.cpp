#include "pch.h"
#include "../DSAlgs/FixedCircularQueue.h"
#include "../DSAlgs/Queue.h"

TEST(FixedCircularQueueTest, TestConstruction) {
    FixedCircularQueue myQueue(10);
    EXPECT_EQ(myQueue.size(), 0);
    EXPECT_EQ(myQueue.capacity(), 10);
}

TEST(FixedCircularQueueTest, TestCopyConstructor) {
    FixedCircularQueue myQueue(10);

    for (int i = 0; i < 10; i++)
    {
        myQueue.enqueue(i);
    }

    FixedCircularQueue newQueue(myQueue);
    EXPECT_EQ(newQueue.size(), 10);
    EXPECT_EQ(newQueue.capacity(), 10);
    for (int i = 0; i < 10; i++)
    {
        EXPECT_EQ(newQueue.front(), myQueue.front());
        newQueue.dequeue();
        myQueue.dequeue();
    }

    EXPECT_TRUE(myQueue.empty());
    EXPECT_TRUE(newQueue.empty());
}

TEST(FixedCircularQueueTest, TestOverloadedAssignment) {
    FixedCircularQueue myQueue(10);

    for (int i = 0; i < 10; i++)
    {
        myQueue.enqueue(i);
    }

    FixedCircularQueue newQueue(100);
    EXPECT_EQ(newQueue.size(), 0);
    EXPECT_EQ(newQueue.capacity(), 100);

    newQueue = myQueue;
    EXPECT_EQ(newQueue.size(), 10);
    EXPECT_EQ(newQueue.capacity(), 10);
    for (int i = 0; i < 10; i++)
    {
        EXPECT_EQ(newQueue.front(), myQueue.front());
        newQueue.dequeue();
        myQueue.dequeue();
    }

    EXPECT_TRUE(myQueue.empty());
    EXPECT_TRUE(newQueue.empty());
}

TEST(FixedCircularQueueTest, TestEmpty) {
    FixedCircularQueue myQueue(100);
    EXPECT_TRUE(myQueue.empty());

    myQueue.enqueue(1);
    EXPECT_FALSE(myQueue.empty());

    myQueue.dequeue();
    EXPECT_TRUE(myQueue.empty());

    for (int i = 0; i < 100; i++)
    {
        myQueue.enqueue(i);
        EXPECT_FALSE(myQueue.empty());
    }

    while (!myQueue.empty())
        myQueue.dequeue();

    EXPECT_TRUE(myQueue.empty());
}

TEST(FixedCircularQueueTest, TestSize) {
    FixedCircularQueue myQueue(100);
    EXPECT_EQ(myQueue.size(), 0);

    for (int i = 0; i < 100; i++)
    {
        myQueue.enqueue(i);
        EXPECT_EQ(myQueue.size(), i + 1);
    }

    while (!myQueue.empty())
        myQueue.dequeue();

    EXPECT_EQ(myQueue.size(), 0);
}

TEST(FixedCircularQueueTest, TestEnqueue) {
    FixedCircularQueue myQueue(10);
    EXPECT_EQ(myQueue.front(), -1);
    for (int i = 0; i < myQueue.capacity(); i++)
    {
        myQueue.enqueue(i);
        EXPECT_EQ(myQueue.front(), 0);
        EXPECT_EQ(myQueue.back(), i);
    }

    EXPECT_EQ(myQueue.capacity(), myQueue.size());
    myQueue.enqueue(123);
    EXPECT_EQ(myQueue.front(), 0);

    for (int i = 0; i < myQueue.capacity(); i++)
    {
        EXPECT_EQ(myQueue.front(), i);
        EXPECT_EQ(myQueue.back(), myQueue.capacity() - 1);
        myQueue.dequeue();
    }
}

TEST(FixedCircularQueueTest, TestDequeue) {
    FixedCircularQueue myQueue(10);
    EXPECT_EQ(myQueue.front(), -1);
    for (int i = 0; i < myQueue.capacity(); i++)
    {
        myQueue.enqueue(i);
    }

    int front = myQueue.front();
    while (!myQueue.empty())
    {
        EXPECT_EQ(myQueue.front(), front++);
        myQueue.dequeue();
    }
}