#include "../include/Stack.h"
#include <gtest/gtest.h>

class StackTest : public ::testing::Test {
  protected:
    void SetUp() override {
        //s2_.push(2);
        //s2_.push(3);
    }

    // void TearDown() override {}

    Stack<int> s0_;
    Stack<int> s1_;
    //Stack<int> s2_;
};

TEST_F(StackTest, IsEmptyInitially) {
    EXPECT_EQ(s0_.empty(), true);
}

TEST_F(StackTest, CanPushAllAndClear) {
    for(int i=0; i<50; i++)
        s1_.push(i+5);
    EXPECT_EQ(s1_.full(), true);
    EXPECT_EQ(s1_.empty(), false);
    s1_.clear();
    EXPECT_EQ(s1_.full(), false);
    EXPECT_EQ(s1_.empty(), true);
}

TEST_F(StackTest, CanCopy) {
    for(int i=0; i<50; i++)                                                                         
        s1_.push(i+5);
    Stack<int> s2_(s1_);
    EXPECT_EQ(s1_.top(), s2_.top());
    s1_.pop();
    EXPECT_NE(s1_.top(), s2_.top());

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
