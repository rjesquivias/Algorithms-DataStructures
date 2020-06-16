#include "pch.h"
#include "../DSAlgs/HashTable.h"

TEST(HashTableTest, TestSearch) {
    HashTable table;
    int randomNumber = 2947;
    table.insert(randomNumber);
    EXPECT_EQ(table.search(randomNumber), randomNumber);
    EXPECT_EQ(table.search(randomNumber + 1), -1);
    EXPECT_EQ(table.search(randomNumber - 1), -1);
}

TEST(HashTableTest, TestInsert) {
    HashTable table;
    int randomNumber = 2947;
    table.insert(randomNumber);
    EXPECT_EQ(table.search(randomNumber), randomNumber);
    EXPECT_EQ(table.search(randomNumber + 1), -1);
    EXPECT_EQ(table.search(randomNumber - 1), -1);


    for (int i = 0; i < 100; i++)
    {
        EXPECT_EQ(table.search(i), -1);
        table.insert(i);
        EXPECT_EQ(table.search(i), i);
        EXPECT_EQ(table.search(i - 1), i - 1);
        EXPECT_EQ(table.search(i + 1), -1);
    }
}

TEST(HashTableTest, TestRemove) {
    HashTable table;

    for (int i = 0; i < 100; i++)
    {
        EXPECT_EQ(table.search(i), -1);
        table.insert(i);
        EXPECT_EQ(table.search(i), i);

        table.remove(i);
        EXPECT_EQ(table.search(i), -1);
    }
}
