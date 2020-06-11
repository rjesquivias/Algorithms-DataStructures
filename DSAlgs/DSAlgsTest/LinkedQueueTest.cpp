#include "pch.h"
#include "../DSAlgs/LinkedQueue.h"
#include "../DSAlgs/Queue.h"

TEST(LinkedQueueTest, TestConstruction) {
    LinkedQueue myQueue;
    EXPECT_EQ(myQueue.size(), 0);
}

TEST(LinkedQueueTest, TestCopyConstructor) {
    LinkedQueue myQueue;

    for (int i = 0; i < 10; i++)
    {
        myQueue.enqueue(i);
    }

    LinkedQueue newQueue(myQueue);
    EXPECT_EQ(newQueue.size(), 10);
    for (int i = 0; i < 10; i++)
    {
        EXPECT_EQ(newQueue.front(), myQueue.front());
        newQueue.dequeue();
        myQueue.dequeue();
    }

    EXPECT_TRUE(myQueue.empty());
    EXPECT_TRUE(newQueue.empty());
}

TEST(LinkedQueueTest, TestOverloadedAssignment) {
    LinkedQueue myQueue;

    for (int i = 0; i < 10; i++)
    {
        myQueue.enqueue(i);
    }

    LinkedQueue newQueue;
    EXPECT_EQ(newQueue.size(), 0);

    newQueue = myQueue;
    EXPECT_EQ(newQueue.size(), 10);
    for (int i = 0; i < 10; i++)
    {
        EXPECT_EQ(newQueue.front(), myQueue.front());
        newQueue.dequeue();
        myQueue.dequeue();
    }

    EXPECT_TRUE(myQueue.empty());
    EXPECT_TRUE(newQueue.empty());
}

TEST(LinkedQueueTest, TestEmpty) {
    LinkedQueue myQueue;
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

TEST(LinkedQueueTest, TestSize) {
    LinkedQueue myQueue;
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

TEST(LinkedQueueTest, TestEnqueue) {
    LinkedQueue myQueue;
    EXPECT_EQ(myQueue.front(), -1);
    int capacity = 50;
    for (int i = 0; i < capacity; i++)
    {
        myQueue.enqueue(i);
        EXPECT_EQ(myQueue.front(), 0);
        EXPECT_EQ(myQueue.back(), i);
    }

    EXPECT_EQ(capacity, myQueue.size());
    myQueue.enqueue(123);
    EXPECT_EQ(myQueue.front(), 0);

    for (int i = 0; i < capacity; i++)
    {
        EXPECT_EQ(myQueue.front(), i);
        EXPECT_EQ(myQueue.back(), 123);
        myQueue.dequeue();
    }
}

TEST(LinkedQueueTest, TestDequeue) {
    LinkedQueue myQueue;
    EXPECT_EQ(myQueue.front(), -1);

    int capacity = 50;
    for (int i = 0; i < capacity; i++)
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