#include "pch.h"
#include <vector>
#include "../DSAlgs/Priority_Queue.h"

TEST(PriorityQueueTest, testPriorityQueue) {
    priority_queue minHeap;
    std::vector<int> items = { 12, 13, 1, -2, 9, 5, -21, 2, 0 };

    for (auto x : items) minHeap.add(x);
    EXPECT_TRUE(minHeap.isMinHeap(0));

    std::sort(items.begin(), items.end(), [](const int& a, const int& b) {
        return a < b;
    });

    int index = 0;
    while (!minHeap.isEmpty())
    {
        EXPECT_EQ(minHeap.peek(), items[index++]);
        minHeap.pop();
    }
}

