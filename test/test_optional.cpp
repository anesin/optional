#include "gtest/gtest.h"
#include "optional.h"



TEST(optional, op_bool)
{
	const bool t = true;
	const bool f = false;

	op_bool a;
	op_bool b = true;
	op_bool c(false);
	op_bool d = b;

	EXPECT_TRUE(!a);
	EXPECT_FALSE(a.initialized());
	//EXPECT_FALSE(a.get());  // ASSERTION!!
	EXPECT_TRUE(a.get_value_or(true));
	EXPECT_FALSE(a == t);
	EXPECT_FALSE(t == a);
	EXPECT_TRUE(a != t);
	EXPECT_TRUE(t != a);

	EXPECT_TRUE(b.initialized());
	EXPECT_TRUE(b.get());
	EXPECT_TRUE(b == t);
	EXPECT_TRUE(t == b);
	EXPECT_TRUE(b != f);
	EXPECT_TRUE(f != b);

	EXPECT_TRUE(c.initialized());
	EXPECT_FALSE(c.get());
	EXPECT_TRUE(c == f);
	EXPECT_TRUE(f == c);
	EXPECT_TRUE(c != t);
	EXPECT_TRUE(t != c);

	EXPECT_TRUE(d.initialized());
	EXPECT_TRUE(d.get());
	EXPECT_TRUE(b == d);
	EXPECT_TRUE(d == t);
	EXPECT_TRUE(t == d);
	EXPECT_TRUE(d != f);
	EXPECT_TRUE(f != d);
}


TEST(optional, op_int)
{
	op_int a = 1;
	op_int b = 2;
	op_int c = 2;
	op_int d = 3;

	EXPECT_TRUE(a == 1);
	EXPECT_TRUE(1 == a);
	EXPECT_TRUE(b != 1);
	EXPECT_TRUE(1 != b);

	EXPECT_TRUE(a <= 1);
	EXPECT_TRUE(a < 2);
	EXPECT_TRUE(c >= 1);
	EXPECT_TRUE(c > 1);

	EXPECT_TRUE(1 >= a);
	EXPECT_TRUE(2 > a);
	EXPECT_TRUE(1 <= c);
	EXPECT_TRUE(1 < c);

	EXPECT_TRUE(a < b);
	EXPECT_TRUE(b <= c);
	EXPECT_TRUE(b >= c);
	EXPECT_TRUE(d > a);
}
