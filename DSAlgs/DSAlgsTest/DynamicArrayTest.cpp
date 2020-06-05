#include "pch.h"
#include "../DSAlgs/DynamicArray.h"

TEST(DynamicArrayTest, TestConstruction) {
    DynamicArray arr;
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_EQ(arr.getCapacity(), 10);
    for (int i = 0; i < arr.getSize(); i++)
    {
        EXPECT_EQ(arr[i], 0);
    }
}

TEST(DynamicArrayTest, TestCopyConstructor) {
    DynamicArray arr;
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(i);
    }

    DynamicArray newArray(arr);
    EXPECT_EQ(newArray.getSize(), 10);
    EXPECT_EQ(newArray.getCapacity(), 20);
    for (int i = 0; i < newArray.getSize(); i++)
    {
        EXPECT_EQ(newArray[i], i);
    }
}

TEST(DynamicArrayTest, TestOverloadedAssignment) {
    DynamicArray arr;
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(i);
    }

    DynamicArray newArray;
    newArray = arr;
    EXPECT_EQ(newArray.getSize(), 10);
    EXPECT_EQ(newArray.getCapacity(), 20);
    for (int i = 0; i < newArray.getSize(); i++)
    {
        EXPECT_EQ(newArray[i], i);
    }
}

TEST(DynamicArrayTest, TestPushBack) {
    DynamicArray arr;
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(i);
        EXPECT_EQ(arr.getSize(), i + 1);
        EXPECT_EQ(arr[i], i);
    }

    EXPECT_EQ(arr.getSize(), 10);
    EXPECT_EQ(arr.getCapacity(), 20);
}

TEST(DynamicArrayTest, TestPopBack) {
    DynamicArray arr;
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(i);
    }

    EXPECT_EQ(arr.getSize(), 10);
    EXPECT_EQ(arr.getCapacity(), 20);

    int valueAtLastIndex = 9;
    while (!arr.empty())
    {
        EXPECT_EQ(valueAtLastIndex--, arr[arr.getSize() - 1]);
        arr.pop_back();
    }
    EXPECT_GT(arr.getCapacity(), 0);
}