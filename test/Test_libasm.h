#ifndef TEST_LIBASM_H
# define TEST_LIBASM_H

# include "unity.h"

typedef struct s_list
{
	void *data;
	struct s_list *next;
}	t_list;

// Mandatory part
int test_ft_strlen(void);
int test_ft_strcpy(void);
void test_ft_strcmp(void);
void test_ft_write(void);
void test_ft_read(void);
void test_ft_strdup(void);

// Bonus part
void test_ft_atoi_base(void);
void test_ft_list_push_front(void);
void test_ft_list_size(void);
void test_ft_list_sort(void);

#endif