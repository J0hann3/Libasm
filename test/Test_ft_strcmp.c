#include "unity.h"
#include <string.h>
#define EMPTY_STRING ""
#define SINGLE_CHARACTER "A"
#define SHORT_STRING "Hello"
#define NORMAL_STRING "int strcmp(const char *s1, const char *s2);"
#define LONG_STRING "The strcmp() and strncmp() functions return an integer less than, equal to, or greater than zero if s1  (or  the  first  n  bytes\
		thereof) is found, respectively, to be less than, to match, or be greater than s2."

int ft_strcmp(const char *s1, const char *s2);

void verify_strcmp_behavior(const char *s1, const char *s2)
{
	int std_res = strcmp(s1, s2);
	int res = ft_strcmp(s1, s2);
	
	TEST_ASSERT_EQUAL_INT(std_res, res);
}

void test_ft_strcmp_two_empty_string(void)
{
	verify_strcmp_behavior(EMPTY_STRING, EMPTY_STRING);
}

void test_ft_strcmp_empty_string_and_single_character(void)
{
	verify_strcmp_behavior(EMPTY_STRING, SINGLE_CHARACTER);
	verify_strcmp_behavior(SINGLE_CHARACTER, EMPTY_STRING);
}

void test_ft_strcmp_single_character(void)
{
	verify_strcmp_behavior(SINGLE_CHARACTER, SINGLE_CHARACTER);
	verify_strcmp_behavior(SINGLE_CHARACTER, "b");
	verify_strcmp_behavior("b", SINGLE_CHARACTER);
}

void test_ft_strcmp_equal_string(void)
{
	verify_strcmp_behavior(SHORT_STRING, SHORT_STRING);
	verify_strcmp_behavior(NORMAL_STRING, NORMAL_STRING);
	verify_strcmp_behavior(LONG_STRING, LONG_STRING);
}

void test_ft_strcmp_short_and_normal_string(void)
{
	verify_strcmp_behavior(SHORT_STRING, NORMAL_STRING);
	verify_strcmp_behavior(NORMAL_STRING, SHORT_STRING);
}

void test_ft_strcmp_short_and_long_string(void)
{
	verify_strcmp_behavior(SHORT_STRING, LONG_STRING);
	verify_strcmp_behavior(LONG_STRING, SHORT_STRING);
}

void test_ft_strcmp_normal_and_long_string(void)
{
	verify_strcmp_behavior(NORMAL_STRING, LONG_STRING);
	verify_strcmp_behavior(LONG_STRING, NORMAL_STRING);
}

void test_ft_strcmp(void)
{
	RUN_TEST(test_ft_strcmp_two_empty_string);
	RUN_TEST(test_ft_strcmp_empty_string_and_single_character);
	RUN_TEST(test_ft_strcmp_single_character);
	RUN_TEST(test_ft_strcmp_equal_string);
	RUN_TEST(test_ft_strcmp_short_and_normal_string);
	RUN_TEST(test_ft_strcmp_short_and_long_string);
	RUN_TEST(test_ft_strcmp_normal_and_long_string);
}
