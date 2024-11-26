#include "Test_libasm.h"

int main(void)
{
	UNITY_BEGIN();
	printf("\033[32m\nRunning Test: 'ft_strlen'\n\033[0m");
	test_ft_strlen();
	return UNITY_END();
}