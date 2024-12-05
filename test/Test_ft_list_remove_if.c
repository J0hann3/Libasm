#include "unity.h"
#include "Test_libasm.h"
#include <stdlib.h>
#include <string.h>

void ft_list_push_front(t_list **begin_list, void *data);

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

void verify_list_remove_if_behavior(t_list *list, void *data_ref, int (*cmp)(), void (*free_fct)(void *), void **res_data)
{
	ft_list_remove_if(&list, data_ref, cmp, free_fct);

	if (res_data == NULL || *res_data == NULL)
	{
		TEST_ASSERT_NULL(list);
		return;
	}
	int i = 0;
	while(list != NULL)
	{
		t_list *tmp = list;
		TEST_ASSERT_EQUAL_PTR(res_data[i], list->data);
		list = list->next;
		free_fct(tmp->data);
		free(tmp);
		i++;
	}
}

void test_ft_list_remove_if_null_pointer()
{
	verify_list_remove_if_behavior(NULL, "coucou", &strcmp, &free, NULL);
	verify_list_remove_if_behavior(NULL, NULL, &strcmp, &free, NULL);
}

void test_ft_list_remove_if_single_element_in_list()
{
	{
		t_list *list = NULL;
		char *data[1] = {strdup("hello")};
		
		ft_list_push_front(&list, data[0]);
		verify_list_remove_if_behavior(list, "coucou", &strcmp, &free, (void **)data);
	}
	{
		t_list *list = NULL;
		char *data = strdup("hello");
		
		ft_list_push_front(&list, data);
		verify_list_remove_if_behavior(list, "hello", &strcmp, &free, NULL);
	}
	{
		t_list *list = NULL;
		char *data[1] = {strdup("helloooooo")};
		
		ft_list_push_front(&list, data[0]);
		verify_list_remove_if_behavior(list, "hello", &strcmp, &free, (void **)data);
	}
	{
		t_list *list = NULL;
		char *data[1] = {strdup("he")};
		
		ft_list_push_front(&list, data[0]);
		verify_list_remove_if_behavior(list, "hello", &strcmp, &free, (void **)data);
	}
}

void test_ft_list_remove_if_two_elements_in_list()
{
	{
		t_list *list = NULL;
		char *data[2] = {strdup("hello"), strdup("bonjour")};
		// list => hello, bonjour
		ft_list_push_front(&list, data[1]);
		ft_list_push_front(&list, data[0]);
		verify_list_remove_if_behavior(list, "coucou", &strcmp, &free, (void **)data);
	}
	{
		t_list *list = NULL;
		char *data[2] = {strdup("hello")};
		// list => hello, bonjour
		ft_list_push_front(&list, strdup("bonjour"));
		ft_list_push_front(&list, data[0]);
		verify_list_remove_if_behavior(list, "bonjour", &strcmp, &free, (void **)data);
	}
	{
		t_list *list = NULL;
		char *data[2] = {strdup("hello")};
		// list => bonjour, hello
		ft_list_push_front(&list, data[0]);
		ft_list_push_front(&list, strdup("bonjour"));
		verify_list_remove_if_behavior(list, "bonjour", &strcmp, &free, (void **)data);
	}
	{
		t_list *list = NULL;
		// list => bonjour, bonjour
		ft_list_push_front(&list, strdup("bonjour"));
		ft_list_push_front(&list, strdup("bonjour"));
		verify_list_remove_if_behavior(list, "bonjour", &strcmp, &free, NULL);
	}
}

void test_ft_list_remove_if_multiple_elements_in_list()
{
	{
		t_list *list = NULL;
		char *data[8] = {strdup("hello"), strdup("bonjour"), strdup("coucou"), strdup("good"), strdup("hey"), strdup("message"), strdup("test"), strdup("info")};
		ft_list_push_front(&list, data[7]);
		ft_list_push_front(&list, data[6]);
		ft_list_push_front(&list, data[5]);
		ft_list_push_front(&list, data[4]);
		ft_list_push_front(&list, data[3]);
		ft_list_push_front(&list, data[2]);
		ft_list_push_front(&list, data[1]);
		ft_list_push_front(&list, data[0]);
		verify_list_remove_if_behavior(list, "no", &strcmp, &free, (void **)data);
	}
	{
		t_list *list = NULL;
		char *data[8] = {strdup("hello"), strdup("bonjour"), strdup("coucou"), strdup("good"), strdup("hey"), strdup("message"), strdup("test")};
		ft_list_push_front(&list, strdup("info"));
		ft_list_push_front(&list, data[6]);
		ft_list_push_front(&list, data[5]);
		ft_list_push_front(&list, data[4]);
		ft_list_push_front(&list, data[3]);
		ft_list_push_front(&list, data[2]);
		ft_list_push_front(&list, data[1]);
		ft_list_push_front(&list, data[0]);
		verify_list_remove_if_behavior(list, "info", &strcmp, &free, (void **)data);
	}
	{
		t_list *list = NULL;
		char *data[8] = {strdup("hello"), strdup("information"), strdup("coucou"), strdup("in")};
		ft_list_push_front(&list, strdup("info"));
		ft_list_push_front(&list, data[3]);
		ft_list_push_front(&list, data[2]);
		ft_list_push_front(&list, strdup("info\0coucou"));
		ft_list_push_front(&list, data[1]);
		ft_list_push_front(&list, data[0]);
		ft_list_push_front(&list, strdup("info"));
		ft_list_push_front(&list, strdup("info"));
		verify_list_remove_if_behavior(list, "info", &strcmp, &free, (void **)data);
	}
	{
		t_list *list = NULL;
		ft_list_push_front(&list, strdup("info"));
		ft_list_push_front(&list, strdup("info"));
		ft_list_push_front(&list, strdup("info"));
		ft_list_push_front(&list, strdup("info"));
		ft_list_push_front(&list, strdup("info"));
		ft_list_push_front(&list, strdup("info"));
		ft_list_push_front(&list, strdup("info"));
		ft_list_push_front(&list, strdup("info"));
		verify_list_remove_if_behavior(list, "info", &strcmp, &free, NULL);
	}
}

void test_ft_list_remove_if(void)
{
	RUN_TEST(test_ft_list_remove_if_null_pointer);
	RUN_TEST(test_ft_list_remove_if_single_element_in_list);
	RUN_TEST(test_ft_list_remove_if_two_elements_in_list);
	RUN_TEST(test_ft_list_remove_if_multiple_elements_in_list);
}