#include "unity.h"
#include "Test_libasm.h"
#include <stdlib.h>
#include <stdio.h>

void ft_list_push_front(t_list **begin_list, void *data);

t_list *verify_list_push_front_behavior(t_list *begin_list, void *data)
{
	t_list *old_begin_list = begin_list;

	ft_list_push_front(&begin_list, data);

	printf("%p\n", begin_list);
	TEST_ASSERT_NOT_NULL_MESSAGE(begin_list, "Failed to allocate some memory");
	TEST_ASSERT_EQUAL_PTR(data, begin_list->data);
	TEST_ASSERT_EQUAL_PTR(old_begin_list, begin_list->next);

	return begin_list;
}

void test_ft_list_push_front_create_first_elem_in_list()
{
	t_list *list = verify_list_push_front_behavior(NULL, "coucou");
	free(list);

	int data = 42;
	list = verify_list_push_front_behavior(NULL, &data);
	free(list);

	list = verify_list_push_front_behavior(NULL, NULL);
	free(list);
}

void test_ft_list_push_front_create_list_with_multiple_elements()
{
	t_list *list;

	list = verify_list_push_front_behavior(NULL, "coucou1");
	list = verify_list_push_front_behavior(list, "coucou2");
	list = verify_list_push_front_behavior(list, "coucou3");
	list = verify_list_push_front_behavior(list, "coucou4");
	list = verify_list_push_front_behavior(list, "coucou5");

	int i = 0;
	while(list != NULL)
	{
		t_list *tmp = list;
		list = list->next;
		free(tmp);
		i++;
	}
	TEST_ASSERT_EQUAL_INT(5, i);
}

void test_ft_list_push_front()
{
	RUN_TEST(test_ft_list_push_front_create_first_elem_in_list);
	RUN_TEST(test_ft_list_push_front_create_list_with_multiple_elements);
}