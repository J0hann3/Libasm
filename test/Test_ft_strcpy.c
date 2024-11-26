#include "unity.h"
#include <string.h>

#define EMPTY_STRING ""
#define STRING_SHORTER "hello"
#define STRING_SHORT "bonjour"

char *ft_strcpy(char *dest, const char *src);

void test_strcpy_empty_string(void)
{
	char dest_ft_strcpy[] = EMPTY_STRING;
	char *src = EMPTY_STRING;
	char *res = ft_strcpy(dest_ft_strcpy, src);

	char dest_strcpy[] = EMPTY_STRING;
	src = EMPTY_STRING;
	char *res_cmp = strcpy(dest_strcpy, src);
	TEST_ASSERT_EQUAL_STRING(res_cmp, res);
	TEST_ASSERT_EQUAL_STRING(dest_strcpy, dest_ft_strcpy);
}

void test_strcpy_normal_string(void)
{
	char dest_ft_strcpy[] = STRING_SHORT;
	char *src = STRING_SHORTER;
	char *res = ft_strcpy(dest_ft_strcpy, src);

	char dest_strcpy[] = STRING_SHORT;
	src = STRING_SHORTER;
	char *res_cmp = strcpy(dest_strcpy, src);
	TEST_ASSERT_EQUAL_STRING(res_cmp, res);
	TEST_ASSERT_EQUAL_STRING(dest_strcpy, dest_ft_strcpy);
}

void test_strcpy_same_string(void)
{
	char dest_ft_strcpy[] = STRING_SHORT;
	char *src = &STRING_SHORT[3];
	char *res = ft_strcpy(dest_ft_strcpy, src);

	char dest_strcpy[] = STRING_SHORT;
	src = &STRING_SHORT[3];
	char *res_cmp = strcpy(dest_strcpy, src);
	TEST_ASSERT_EQUAL_STRING(res_cmp, res);
	TEST_ASSERT_EQUAL_STRING(dest_strcpy, dest_ft_strcpy);
}

void test_ft_strcpy(void)
{
	RUN_TEST(test_strcpy_empty_string);
	RUN_TEST(test_strcpy_normal_string);
	RUN_TEST(test_strcpy_same_string);
}
