#include "unity.h"
#include <string.h>

char *ft_strcpy(char *dest, const char *src);

void test_strcpy_empty_string(void)
{
	char *dest = "";
	char *src = "";
	char *res = ft_strcpy(dest, src);

	dest = "";
	src = "";
	char *res_cmp = strcpy(dest, src);
	TEST_ASSERT_EQUAL_STRING(res_cmp, res);
}

void test_strcpy_normal_string(void)
{
	char *dest = "hello";
	char *src = "bonjour";
	char *res = ft_strcpy(dest, src);

	dest = "hello";
	src = "bonjour";
	char *res_cmp = strcpy(dest, src);
	TEST_ASSERT_EQUAL_STRING(res_cmp, res);
}

void test_strcpy_same_string(void)
{
	char *dest = "hello";
	char *src = &dest[3];
	char *res = ft_strcpy(dest, src);

	dest = "hello";
	src = &dest[3];
	char *res_cmp = strcpy(dest, src);
	TEST_ASSERT_EQUAL_STRING(res_cmp, res);
}

void test_ft_strcpy(void)
{
	RUN_TEST(test_strcpy_empty_string);
	RUN_TEST(test_strcpy_normal_string);
	RUN_TEST(test_strcpy_same_string);
}
