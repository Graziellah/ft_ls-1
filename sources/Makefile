
NAME= ft_ls
SRC= src/blue_print.c \
	 src/check_argv.c \
	 src/check_type_file.c \
	 src/choose_ptr_func.c \
	 src/convert_block_file.c \
	 src/my_compare_time.c \
	 src/create_path.c \
	 src/direct_file_travel.c \
	 src/dispath_dir_error_file.c \
	 src/element_error.c \
	 src/ft_merge_sort.c \
	 src/get_option.c \
	 src/link_element.c \
	 src/main.c \
	 src/major_minor.c \
	 src/other.c \
	 src/create_ptr_func.c \
	 src/print_directory.c \
	 src/ptr_func_detail.c
CC= clang
CFLAGS= -Wall -Werror -Wextra
INC= inc
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)  -L libft/ -lft

%.o: %.c
		$(CC) $(CFLAGS) -I $(INC) $< -c -o $@

clean:
		make -C libft/ clean
		rm -f $(OBJ)

fclean: clean
		make -C libft/ fclean
		rm -f $(NAME)

re: fclean all
