#include "unity.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>

char *ft_strdup(const char *s);

void verify_strdup_behavior(const char *message)
{
	errno = 0;
	char *res = ft_strdup(message);
	int new_errno = errno;

	errno = 0;
	char *std_res = strdup(message);
	int std_errno = errno;

	TEST_ASSERT_EQUAL_INT(std_errno, new_errno);

	if (res == NULL || std_res == NULL)
		TEST_ASSERT_EQUAL_PTR(std_res, res);
	else
		TEST_ASSERT_EQUAL_STRING(std_res, res);
	free(res);
	free(std_res);
}

void test_ft_strdup_empty_string()
{
	verify_strdup_behavior("");
}

void test_ft_strdup_single_character()
{
	verify_strdup_behavior("A");
}

void test_ft_strdup_normal_string()
{
	verify_strdup_behavior("hello world");
}

void test_ft_strdup_contains_end_of_string()
{
	verify_strdup_behavior("hello\0world");
}

void test_ft_strdup_long_string()
{
	verify_strdup_behavior("The  strdup() function returns a pointer to a new string which is a duplicate of the string s.\
	Memory for the new string is obtained with malloc(3), and can be freed with free(3).\
\
	The strndup() function is similar, but copies at most n bytes.  If s is longer than n, only  n\
	bytes are copied, and a terminating null byte ('\0') is added.\
\
	strdupa()  and  strndupa()  are  similar,  but use alloca(3) to allocate the buffer.  They are\
	available only when using the GNU GCC suite, and suffer from the same limitations described in\
	alloca(3).");
}

void test_ft_strdup(void)
{
	RUN_TEST(test_ft_strdup_empty_string);
	RUN_TEST(test_ft_strdup_single_character);
	RUN_TEST(test_ft_strdup_normal_string);
	RUN_TEST(test_ft_strdup_contains_end_of_string);
	RUN_TEST(test_ft_strdup_long_string);
}