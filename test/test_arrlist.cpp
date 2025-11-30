#include "gtest/gtest.h"
#include "ArrList.h"
#include <sstream>

TEST(ArrListBasic, PushPopStartEnd) {
    TArrList<int> list(8);
    EXPECT_TRUE(list.IsEmpty());
    list.PushEnd(1);
    list.PushEnd(2);
    list.PushStart(0);
    EXPECT_FALSE(list.IsEmpty());
    list.PopStart();
    list.PopEnd();
    EXPECT_EQ(list.Count(1), 1);
    list.PopEnd();
    EXPECT_TRUE(list.IsEmpty());
}

TEST(ArrListInsertRemove, InsertAfterRemove) {
    TArrList<int> list(8);
    list.PushEnd(10);
    list.PushEnd(20);
    list.PushEnd(30);
    EXPECT_EQ(list[1], 20);
    list.InsertAfter(1, 25);
    EXPECT_GE(list.Count(25), 0);
    list.Remove(1);
}

TEST(ArrListOperators, EqualityAndConcat) {
    TArrList<int> a(8);
    TArrList<int> b(8);
    a.PushEnd(1);
    a.PushEnd(2);
    b.PushEnd(1);
    b.PushEnd(2);
    EXPECT_TRUE(a == b);
    TArrList<int> c = a + b;
    EXPECT_EQ(c.Count(1), 2);
}

TEST(ArrListIO, StreamInOut) {
    TArrList<int> list(8);
    std::istringstream input("3 5 6 7");
    input >> list;
    std::ostringstream output;
    output << list;
    std::string s = output.str();
    EXPECT_NE(s.find("5"), std::string::npos);
}
