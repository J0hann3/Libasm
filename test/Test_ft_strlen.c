#include "unity.h"
#include <string.h>

size_t ft_strlen(const char *s);

void setUp(){}

void tearDown(){}

void test_empty(void)
{
	char *var = "";

	int value = ft_strlen(var);
	TEST_ASSERT_EQUAL_UINT64(strlen(var), value);
}

void test_null(void)
{
	char *var = "";//TODO NULL

	int value = ft_strlen(var);
	TEST_ASSERT_EQUAL_UINT64(strlen(var), value);
}

void test_short_string(void)
{
	char *var = "hello";

	int value = ft_strlen(var);
	TEST_ASSERT_EQUAL_UINT64(strlen(var), value);
}

void test_long_string(void)
{
	char *var = "The strlen() function calculates the length of the string pointed to by s, excluding the terminating null byte ('\0').";

	int value = ft_strlen(var);
	TEST_ASSERT_EQUAL_UINT64(strlen(var), value);
}

void test_very_long_string(void)
{
	char *var = "The AAA (Arrange-Act-Assert) pattern has become almost a standard across the industry. It suggests that you should divide your test method into three sections: arrange, act and assert. Each one of them only responsible for the part in which they are named after.\
\
So the arrange section you only have code required to setup that specific test. Here objects would be created, mocks setup (if you are using one) and potentially expectations would be set. Then there is the Act, which should be the invocation of the method being tested. And on Assert you would simply check whether the expectations were met. More info can be found HERE.\
\
Following this pattern does make the code quite well structured and easy to understand. In general lines, it would look like this:";

	int value = ft_strlen(var);
	TEST_ASSERT_EQUAL_UINT64(strlen(var), value);
}

void test_ft_strlen(void)
{
	RUN_TEST(test_empty);
	RUN_TEST(test_null);
	RUN_TEST(test_short_string);
	RUN_TEST(test_long_string);
	RUN_TEST(test_very_long_string);
}