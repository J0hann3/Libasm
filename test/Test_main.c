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
	return UNITY_END();
}