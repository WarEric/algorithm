#include"max.h"
#include"gtest/gtest.h"

TEST(MAXTest, BIGGER){
	EXPECT_EQ(1, max(1, 0));
}


TEST(MAXTest, Equal){
	EXPECT_EQ(1, max(1, -1));
	EXPECT_EQ(2, max(2, 2));
}
