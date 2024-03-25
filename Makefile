CC = gcc
AS = nasm
ASFLAGS = -f elf64
CFLAGS = -Wall -Wextra -Werror

SRCS_C = src/tester_main.c \
			src/test/test_strlen.c \
			src/test/test_strcpy.c \
			src/test/test_strdup.c \
			src/test/test_strcmp.c \
			src/test/test_write.c \
			src/test/test_read.c

SRCS_S = ../src/function/ft_strlen.s \
			../src/function/ft_strcpy.s \
			../src/function/ft_strdup.s \
			../src/function/ft_strcmp.s \
			../src/function/ft_write.s \
			../src/function/ft_read.s
		 

OBJS_C = $(SRCS_C:.c=.o)
OBJS_S = $(SRCS_S:.s=.o)

OUTPUT = ./libasm_tester

all: $(OUTPUT)

$(OUTPUT): $(OBJS_C) $(OBJS_S)
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	@$(AS) $(ASFLAGS) $< -o $@

clean:
	@rm -f $(OBJS_C) $(OBJS_S)

fclean: clean
	@rm -f $(OUTPUT)

m: all
	@./libasm_tester

re: fclean all

.PHONY: all clean fclean m re