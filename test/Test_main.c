#include "Test_libasm.h"

void setUp(){}

void tearDown(){}

int main(void)
{
	UNITY_BEGIN();
	printf("\033[32mMandatory part:\n\033[0m");
	printf("\033[32m\nRunning Test: 'ft_strlen'\n\033[0m");
	test_ft_strlen();

	printf("\033[32m\nRunning Test: 'ft_strcpy'\n\033[0m");
	test_ft_strcpy();

	printf("\033[32m\nRunning Test: 'ft_strcmp'\n\033[0m");
	test_ft_strcmp();

	printf("\033[32m\nRunning Test: 'ft_write'\n\033[0m");
	test_ft_write();

	printf("\033[32m\nRunning Test: 'ft_read'\n\033[0m");
	test_ft_read();

	printf("\033[32m\nRunning Test: 'ft_strdup'\n\033[0m");
	test_ft_strdup();

	printf("\033[32m\nBonus part:\n\033[0m");

	printf("\033[32m\nRunning Test: 'ft_atoi_base'\n\033[0m");
	test_ft_atoi_base();

	printf("\033[32m\nRunning Test: 'ft_list_push_front'\n\033[0m");
	test_ft_list_push_front();

	printf("\033[32m\nRunning Test: 'ft_list_size'\n\033[0m");
	test_ft_list_size();
	return UNITY_END();
}