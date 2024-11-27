#include "unity.h"
#include <string.h>

char *ft_strcpy(char *dest, const char *src);

void verify_strcpy_behavior(const char *src, size_t dest_size) {
	char std_dest[dest_size];
	char custom_dest[dest_size];

	strcpy(std_dest, src);
	char *custom_result = ft_strcpy(custom_dest, src);

	TEST_ASSERT_EQUAL_STRING(std_dest, custom_dest);
	TEST_ASSERT_EQUAL_PTR(custom_dest, custom_result);
}

void test_ft_strcpy_empty_string(void) {
	verify_strcpy_behavior("", 5);
}

void test_ft_strcpy_single_character(void) {
	verify_strcpy_behavior("A", 5);
}

void test_ft_strcpy_normal_string(void) {
	verify_strcpy_behavior("Hello, Unity!", 25);
	verify_strcpy_behavior("This is a long string", 50);
	verify_strcpy_behavior("1234567890", 11);
	verify_strcpy_behavior("Trailing null test\0Hidden", 30);
}

void test_ft_strcpy_long_string(void) {
	verify_strcpy_behavior("This is a very long string for testing strcpy functionality.", 100);
}

void test_ft_strcpy_to_self(void) {
	char std_buffer[50] = "Self copy test";
	char custom_buffer[50] = "Self copy test";

	strcpy(std_buffer, std_buffer);
	char *custom_result = ft_strcpy(custom_buffer, custom_buffer);

	TEST_ASSERT_EQUAL_STRING(std_buffer, custom_buffer);
	TEST_ASSERT_EQUAL_PTR(custom_buffer, custom_result);
}


void test_ft_strcpy_overlap(void) {
	char std_buffer[50] = "Overlap test";
	char custom_buffer[50] = "Overlap test";

	strcpy(std_buffer, std_buffer + 5);
	char *custom_result = ft_strcpy(custom_buffer, custom_buffer + 5);

	TEST_ASSERT_EQUAL_STRING(std_buffer, custom_buffer);
	TEST_ASSERT_EQUAL_PTR(custom_buffer, custom_result);

}

void test_ft_strcpy(void)
{
	RUN_TEST(test_ft_strcpy_empty_string);
	RUN_TEST(test_ft_strcpy_single_character);
	RUN_TEST(test_ft_strcpy_normal_string);
	RUN_TEST(test_ft_strcpy_long_string);
	RUN_TEST(test_ft_strcpy_to_self);
	RUN_TEST(test_ft_strcpy_overlap);
}
