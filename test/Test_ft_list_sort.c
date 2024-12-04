#include "unity.h"
#include "Test_libasm.h"
#include <stdlib.h>
#include <string.h>

void ft_list_push_front(t_list **begin_list, void *data);

void ft_list_sort(t_list **begin_list, int (*cmp)());

void verify_list_sort_behavior(t_list *list, int (*cmp)(), void **list_sort)
{
	ft_list_sort(&list, cmp);

	int i = 0;
	while(list != NULL)
	{
		t_list *tmp = list;
		TEST_ASSERT_EQUAL_PTR(list_sort[i], tmp->data);
		free(tmp);
		list = list->next;
		i++;
	}
}

void test_ft_list_sort_empty_list()
{
	t_list *list = NULL;
	verify_list_sort_behavior(list, &strcmp, NULL);
}

void test_ft_list_sort_single_element()
{
	t_list *list = NULL;
	char *data = "hey";
	ft_list_push_front(&list, data);
	verify_list_sort_behavior(list, &strcmp, (void *)&data);
}

void test_ft_list_sort_two_elements()
{
	{
		t_list *list = NULL;
		char *data[2] = {"hey", "coucou"};
		ft_list_push_front(&list, data[0]);
		ft_list_push_front(&list, data[1]);

		verify_list_sort_behavior(list, &strcmp, (void *)data);
	}
	{
		t_list *list = NULL;
		char *data[2] = {"coucou", "coucou"};
		ft_list_push_front(&list, data[0]);
		ft_list_push_front(&list, data[1]);
		
		verify_list_sort_behavior(list, &strcmp, (void *)data);
	}
	{
		t_list *list = NULL;
		char *data[2] = {"coucou", "hey"};
		ft_list_push_front(&list, data[0]);
		ft_list_push_front(&list, data[1]);
		
		verify_list_sort_behavior(list, &strcmp, (void *)data);
	}
}

void test_ft_list_sort_multiple_elements()
{
	{
		t_list *list = NULL;
		char *data[6] = {"hey", "coucou", "12345", "hello", "a", "54gd21"};
		ft_list_push_front(&list, data[0]);
		ft_list_push_front(&list, data[1]);
		ft_list_push_front(&list, data[2]);
		ft_list_push_front(&list, data[3]);
		ft_list_push_front(&list, data[4]);
		ft_list_push_front(&list, data[5]);

		verify_list_sort_behavior(list, &strcmp, (void *)data);
	}
	{
		t_list *list = NULL;
		char *data[6] = {"12345", "54gd21", "a", "coucou", "hello", "hey"};
		ft_list_push_front(&list, data[0]);
		ft_list_push_front(&list, data[1]);
		ft_list_push_front(&list, data[2]);
		ft_list_push_front(&list, data[3]);
		ft_list_push_front(&list, data[4]);
		ft_list_push_front(&list, data[5]);
		
		verify_list_sort_behavior(list, &strcmp, (void *)data);
	}
	{
		t_list *list = NULL;
		char *data[6] = {"12345", "12345", "a", "coucou", "hello", "12345"};
		ft_list_push_front(&list, data[0]);
		ft_list_push_front(&list, data[1]);
		ft_list_push_front(&list, data[2]);
		ft_list_push_front(&list, data[3]);
		ft_list_push_front(&list, data[4]);
		ft_list_push_front(&list, data[5]);
		
		verify_list_sort_behavior(list, &strcmp, (void *)data);
	}
}

void test_ft_list_sort(void)
{
	RUN_TEST(test_ft_list_sort_empty_list);
	RUN_TEST(test_ft_list_sort_single_element);
	RUN_TEST(test_ft_list_sort_two_elements);
	RUN_TEST(test_ft_list_sort_multiple_elements);
}