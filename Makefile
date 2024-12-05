NAME = libasm.a
AS = nasm
ASFLAGS = -felf64 -g -s -i srcs

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

SRCS_DIR = srcs/
SRCS_LIST = ft_strlen.s\
			ft_strcpy.s\
			ft_strcmp.s\
			ft_write.s\
			ft_read.s\
			ft_strdup.s\
			ft_atoi_base.s\
			ft_list_push_front.s\
			ft_list_size.s\
			ft_list_sort.s\
			ft_list_remove_if.s

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

HEADERS = srcs/tools.inc

OBJS_DIR = objs/
OBJS_LIST = $(SRCS_LIST:.s=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_LIST))

UNIT_TEST_URL = https://github.com/ThrowTheSwitch/Unity.git
UNIT_TEST = Unity/

TESTS_DIR = test/
TESTS_LIST = Test_main.c\
			Test_ft_strlen.c\
			Test_ft_strcpy.c\
			Test_ft_strcmp.c\
			Test_ft_write.c\
			Test_ft_read.c\
			Test_ft_strdup.c\
			Test_ft_atoi_base.c\
			Test_ft_list_push_front.c\
			Test_ft_list_size.c\
			Test_ft_list_sort.c\
			Test_ft_list_remove_if.c

TEST_OBJS_DIR = test/objs/
TEST_OBJS_LIST = $(TESTS_LIST:.c=.o)
TEST_OBJS = $(addprefix $(TEST_OBJS_DIR), $(TEST_OBJS_LIST))

TEST_UNIT_SRC = ./Unity/src/unity.c
TEST_UNIT_INC = -I./Unity/src/
TEST_NAME = unitTest

all:	$(NAME)

bonus:	$(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.s Makefile $(HEADERS)
	$(AS) $(ASFLAGS) $< -o $@

$(UNIT_TEST):
	@echo "~-~-~-~-~ COMPILING UNIT_TEST ~-~-~-~-~"
	@echo "   - Fetching sources..."
	@if [ ! -d "$(UNIT_TEST)" ]; then \
		git clone $(UNIT_TEST_URL) $(UNIT_TEST); \
	else \
		cd $(UNIT_TEST) && git pull; \
	fi
	@echo "~ DONE ~\n"

$(TEST_NAME): $(NAME) $(UNIT_TEST) $(TEST_OBJS_DIR) $(TEST_OBJS)
	$(CC) $(CFLAGS) -DUNITY_INCLUDE_EXEC_TIME -DUNITY_OUTPUT_COLOR $(TEST_OBJS) $(TEST_UNIT_SRC) $(TEST_UNIT_INC) -L. -lasm -o $(TEST_NAME);

test: $(TEST_NAME)
	./$(TEST_NAME)

valgrind_test: $(TEST_NAME)
	valgrind ./$(TEST_NAME)

$(TEST_OBJS_DIR):
	mkdir -p $(TEST_OBJS_DIR)

$(TEST_OBJS_DIR)%.o: $(TESTS_DIR)%.c Makefile test/Test_libasm.h
	$(CC) $(CFLAGS) -c $< -o $@ $(TEST_UNIT_INC) 

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(TEST_OBJS_DIR)

clean_unittest:
	rm -rf $(UNIT_TEST)

fclean: clean clean_unittest
	rm -rf $(NAME)
	rm -rf $(TEST_NAME)

re: fclean all

.PHONY: all bonus clean fclean re test valgrind_test clean_unittest