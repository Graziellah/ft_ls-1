/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:58:09 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 19:15:06 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include "libft.h"

# define GREEN				"\x1b[32m"
# define BLUE 				"\x1b[34m"
# define WHITE 				"\x1b[37m"
# define RED 				"\x1b[31m"
# define YELLOW 			"\x1b[33m"
# define MAGENTA 			"\x1b[35m"

# define LONG				1
# define REC				2
# define DOT				4
# define REV				8
# define TIME				16
# define ASCII				32

# define ERROR				0
# define DIRECTORY			1
# define FILE				2

# define SIX_MONTH_IN_SEC	15778800

typedef struct				s_infos_file
{
	char					*file_name;
	char					*path;
	long					size;
}							t_infos_file;

typedef struct				s_element
{
	t_infos_file			*data;
	struct s_element		*next;
}							t_element;

typedef struct				s_head_element
{
	t_element				*err_head;
	t_element				*file_head;
	t_element				*direct_head;
}							t_head_element;

typedef t_element			*t_func(t_element *a, t_element *b);

t_element					*ft_compare_ascii(t_element *a, t_element *b);
t_element					*ft_compare_time(t_element *a, t_element *b);
t_element					*ft_compare_ascii_reverse(t_element *a,
	t_element *b);
t_element					*ft_compare_time_reverse(t_element *a,
	t_element *b);

t_func						*get_ptr_function(int index);

int							get_option(char valid_option);
int							check_option(int argc, char **argv);

int							check_special_file(struct stat file_stat);
void						display_major_minor(struct stat file_stat);
int							major_device(unsigned int dev);

int							dated_more_than_six_month(time_t t_time);
char						*convert_time(time_t convert_to);

char						type_file(mode_t mode);
char						*permission_of_file(mode_t mode);

char						*create_path_for_lstat(t_infos_file *file);
char						*create_new_path(const char *src_parent,
	const char *src_name);

int							compare_time(t_infos_file *file1,
	t_infos_file *file2);

void						print_total_long_files(t_element *elmt);
void						print_with_long_opt(t_infos_file *print,
	int type_of_element);

t_func						*return_good_ptr_func(void);

t_element					*ft_compare_ascii(t_element *a, t_element *b);
t_element					*ft_compare_time(t_element *a, t_element *b);
t_element					*ft_compare_ascii_reverse(t_element *a,
	t_element *b);
t_element					*ft_compare_time_reverse(t_element *a,
	t_element *b);

t_element					*sortedmerge(t_element *a, t_element *b,
	t_element *(*ft_cmp)(t_element *a, t_element *b));
void						frontbacksplit(t_element *source, t_element **front,
	t_element **back);
void						ft_mergesort(t_element **head_ref,
	t_element *(*ft_cmp)(t_element *a, t_element *b));

t_element					*new_elem(char *f_name, const char *f_path,
	long size);
void						insert_elem(t_element *list, char *file_name,
	const char *file_path, long size);
void						reverse_linked_list(t_element **head);
void						print_elm_file(t_element *elm, int type_of_element);

void						print_error_open_directory(const char *name);
void						print_directory_name(const char *name);

long						filen(const char *path, const char *file_name);
void						list(const char *name, int is_first_launching);

int							strsearch(const char *target, const char *token,
	int len);
int							kind_of_parameter(const char *name);

void						create_elm_error_for_head_element(
	t_head_element **head, char *av);
void						print_elm_err(t_element *elm);

void						create_elm_file_for_head_element(
	t_head_element **head, char *av);
void						create_elm_repository_for_head_element(
	t_head_element **head, char *av);
void						init_head_element_and_field(t_head_element **head);
void						sorte_element_error_and_file_and_dir(
	t_head_element **head);
void						print_element_error_and_file(
	t_head_element *head);

t_element					*check_argv(int begin_path_index,
	int total_file_index, char **av);

int							main(int ac, char **av);

#endif
