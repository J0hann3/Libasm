#include "Test_libasm.h"

void setUp(){}

void tearDown(){}

int main(void)
{
	UNITY_BEGIN();
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
	return UNITY_END();
}