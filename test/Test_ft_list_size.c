#include "unity.h"
#include "Test_libasm.h"
#include <stdlib.h>

int ft_list_size(t_list *begin_list);
void ft_list_push_front(t_list **begin_list, void *data);

void verify_list_size_behavior(t_list *list, int size_list)
{
	int size = ft_list_size(list);

	TEST_ASSERT_EQUAL_INT(size_list, size);
}

void test_ft_list_size_null()
{
	verify_list_size_behavior(NULL, 0);
}

void test_ft_list_size_1()
{
	t_list *list = NULL;
	ft_list_push_front(&list, "coucou");

	verify_list_size_behavior(list, 1);

	free(list);
}

void test_ft_list_size_long()
{
	t_list *list = NULL;
	ft_list_push_front(&list, "coucou");
	ft_list_push_front(&list, "coucou1");
	ft_list_push_front(&list, "coucou2");
	ft_list_push_front(&list, "coucou3");
	ft_list_push_front(&list, "coucou4");
	ft_list_push_front(&list, "coucou5");
	ft_list_push_front(&list, "coucou6");
	ft_list_push_front(&list, "coucou7");

	verify_list_size_behavior(list, 8);

	while(list != NULL)
	{
		t_list *tmp = list;
		list = list->next;
		free(tmp);
	}
}

void test_ft_list_size()
{
	RUN_TEST(test_ft_list_size_null);
	RUN_TEST(test_ft_list_size_1);
	RUN_TEST(test_ft_list_size_long);
}