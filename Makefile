NAME = libasm.a
AS = nasm
ASFLAGS = -felf64 -g -s -O0 -Wall

CC = cc
CFLAGS = 

SRCS_DIR = srcs/
SRCS_LIST = ft_strlen.s
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR = objs/
OBJS_LIST = $(SRCS_LIST:.s=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_LIST))

TESTS_DIR = test/
TESTS_LIST = Test_main.c\
			Test_ft_strlen.c
TESTS = $(addprefix $(TESTS_DIR), $(TESTS_LIST))
TEST_UNIT_SRC = ./Unity/src/unity.c
TEST_UNIT_INC = -I./Unity/src/
TEST_NAME = unitTest

all:	$(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.s Makefile
	$(AS) $(ASFLAGS) $< -o $@

test: $(NAME)
	$(CC) $(CFLAGS) $(TESTS) $(TEST_UNIT_SRC) $(TEST_UNIT_INC) -L. -lasm -o $(TEST_NAME);
	./$(TEST_NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test