NAME = libasm.a
AS = nasm
ASFLAGS = -felf64 -g -s -O0 -Wall

SRCS_DIR = srcs/
SRCS_LIST = ft_strlen.s
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR = objs/
OBJS_LIST = $(SRCS_LIST:.s=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_LIST))

all:	$(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.s Makefile
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re