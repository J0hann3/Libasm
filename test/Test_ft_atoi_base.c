#include "unity.h"

int ft_atoi_base(char *str, char *base);

void verify_atoi_base_behavior(char *str, char *base, int std_res)
{
	int res = ft_atoi_base(str, base);

	TEST_ASSERT_EQUAL_INT(std_res, res);
}

void test_ft_atoi_base_empty_base()
{
	verify_atoi_base_behavior("coucou", "", 0);
}

void test_ft_atoi_base_base_size_1()
{
	verify_atoi_base_behavior("coucou", "a", 0);
}

void test_ft_atoi_base_base_duplicate()
{
	verify_atoi_base_behavior("coucou", "123345", 0);
	verify_atoi_base_behavior("coucou", "52345", 0);
	verify_atoi_base_behavior("coucou", "06852345", 0);
	verify_atoi_base_behavior("coucou", "coucou", 0);
}

void test_ft_atoi_base_base_invalid_character()
{
	verify_atoi_base_behavior("coucou", "sad+fgh", 0);
	verify_atoi_base_behavior("coucou", "sad-fgh", 0);
	verify_atoi_base_behavior("coucou", "sad fgh", 0);
	verify_atoi_base_behavior("coucou", "sad	fgh", 0);
	verify_atoi_base_behavior("coucou", "sadfgh+", 0);
	verify_atoi_base_behavior("coucou", "sadfgh-", 0);
	verify_atoi_base_behavior("coucou", "sadfgh ", 0);
	verify_atoi_base_behavior("coucou", "sadfgh	", 0);
	verify_atoi_base_behavior("coucou", "+sadfgh", 0);
	verify_atoi_base_behavior("coucou", "-sadfgh", 0);
	verify_atoi_base_behavior("coucou", " sadfgh", 0);
	verify_atoi_base_behavior("coucou", "\tsadfgh", 0);
	verify_atoi_base_behavior("coucou", "\nsadfgh", 0);
	verify_atoi_base_behavior("coucou", "\rsadfgh", 0);
	verify_atoi_base_behavior("coucou", "\vsadfgh", 0);
	verify_atoi_base_behavior("coucou", "\fsadfgh", 0);
}

void test_ft_atoi_base_invalid_number()
{
	verify_atoi_base_behavior("dfgdg", "0123456789", 0);
	verify_atoi_base_behavior("d59", "0123456789", 0);
}

void test_ft_atoi_base_base_10()
{
	verify_atoi_base_behavior("0", "0123456789", 0);
	verify_atoi_base_behavior("9", "0123456789", 9);
	verify_atoi_base_behavior("53", "0123456789", 53);
	verify_atoi_base_behavior("15690", "0123456789", 15690);
}

void test_ft_atoi_base_base_2()
{
	verify_atoi_base_behavior("1100", "01", 12);
	verify_atoi_base_behavior("0000000000", "01", 0);
	verify_atoi_base_behavior("11111111", "01", 255);
	verify_atoi_base_behavior("100000000", "01", 256);
}

void test_ft_atoi_base_signed()
{
	verify_atoi_base_behavior("+-+-+-+-+0", "0123456789", 0);
	verify_atoi_base_behavior("--9", "0123456789", 9);
	verify_atoi_base_behavior("---9", "0123456789", -9);
	verify_atoi_base_behavior("+++++++53", "0123456789", 53);
	verify_atoi_base_behavior("++++--+-53", "0123456789", -53);
	verify_atoi_base_behavior("+-+-+-+-+-+-+-+++-+-+-+-+-+-+-+-15690", "0123456789", -15690);
	verify_atoi_base_behavior("+15690", "0123456789", +15690);
	verify_atoi_base_behavior("-15690", "0123456789", -15690);
}

void test_ft_atoi_base_whitespace()
{
	verify_atoi_base_behavior("              +-+-+-+-+0", "0123456789", 0);
	verify_atoi_base_behavior(" --9", "0123456789", 9);
	verify_atoi_base_behavior("	 	 	 	---9", "0123456789", -9);
	verify_atoi_base_behavior("\r\t\f\v\n +++++++53", "0123456789", 53);
	verify_atoi_base_behavior("   \r \t \f \v    ++++--+-53", "0123456789", -53);
}

void test_ft_atoi_base_end_with_invalid_character()
{
	verify_atoi_base_behavior("0d", "0123456789", 0);
	verify_atoi_base_behavior("9sdf", "0123456789", 9);
	verify_atoi_base_behavior("53\ncxv", "0123456789", 53);
	verify_atoi_base_behavior("15690  t", "0123456789", 15690);
}


void test_ft_atoi_base(void)
{
	RUN_TEST(test_ft_atoi_base_empty_base);
	RUN_TEST(test_ft_atoi_base_base_size_1);
	RUN_TEST(test_ft_atoi_base_base_duplicate);
	RUN_TEST(test_ft_atoi_base_base_invalid_character);
	RUN_TEST(test_ft_atoi_base_invalid_number);
	RUN_TEST(test_ft_atoi_base_base_10);
	RUN_TEST(test_ft_atoi_base_base_2);
	RUN_TEST(test_ft_atoi_base_signed);
	RUN_TEST(test_ft_atoi_base_whitespace);
	RUN_TEST(test_ft_atoi_base_end_with_invalid_character);
}