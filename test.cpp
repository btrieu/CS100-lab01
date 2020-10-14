#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
 	EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
	char* test_val[1]; test_val[0] = "./c-echo";
	EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, ForeignCharacters) {
	char* test_val[2]; test_val[0] = "./c-echo"; test_val[1] = "沈むように溶けてゆくように";
	EXPECT_EQ("沈むように溶けてゆくように", echo(2, test_val));
}

TEST(EchoTest, SpecialCharacters) {
	char* test_val[4]; test_val[0] = "./c-echo"; test_val[1] = "you're"; test_val[2] = "Jimmy's"; test_val[3] = "!@#$%^&*()";
	EXPECT_EQ("you're Jimmy's !@#$%^&*()", echo(4, test_val));
}

TEST(EchoTest, UpperCase) {
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "HELLO"; test_val[2] = "WORLD";
	EXPECT_EQ("HELLO WORLD", echo(3, test_val));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
