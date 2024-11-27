NAME = libasm.a
AS = nasm
ASFLAGS = -felf64 -g -s -i srcs

CC = cc
CFLAGS = -g -Wall -Werror -Wextra

SRCS_DIR = srcs/
SRCS_LIST = ft_strlen.s\
			ft_strcpy.s\
			ft_strcmp.s\
			ft_write.s

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
			Test_ft_write.c

TESTS = $(addprefix $(TESTS_DIR), $(TESTS_LIST))
TEST_UNIT_SRC = ./Unity/src/unity.c
TEST_UNIT_INC = -I./Unity/src/
TEST_NAME = unitTest

all:	$(NAME)

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

test: $(NAME) $(UNIT_TEST)
	$(CC) $(CFLAGS) -DUNITY_INCLUDE_EXEC_TIME -DUNITY_OUTPUT_COLOR $(TESTS) $(TEST_UNIT_SRC) $(TEST_UNIT_INC) -L. -lasm -o $(TEST_NAME);
	./$(TEST_NAME)

valgrind_test: $(NAME) $(UNIT_TEST)
	$(CC) $(CFLAGS) -DUNITY_INCLUDE_EXEC_TIME -DUNITY_OUTPUT_COLOR $(TESTS) $(TEST_UNIT_SRC) $(TEST_UNIT_INC) -L. -lasm -o $(TEST_NAME);
	valgrind --trace-children=yes ./$(TEST_NAME)

clean:
	rm -rf $(OBJS_DIR)

clean_unittest:
	rm -rf $(UNIT_TEST)

fclean: clean clean_unittest
	rm -rf $(NAME)
	rm -rf $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test