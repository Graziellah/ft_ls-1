/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_file_travel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:10:51 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/28 18:18:35 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long				filen(const char *path, const char *file_name)
{
	struct stat		bufstat;
	char			*buffer;

	buffer = ft_strjoin(path, "/");
	buffer = ft_strjoin(buffer, file_name);
	if (lstat(buffer, &bufstat) == -1)
		ft_putendl(strerror(errno));
	return (bufstat.st_blocks);
}

static t_element	*list_file(const char *name, int type_of_element)
{
	DIR				*dir;
	struct dirent	*ent;
	t_element		*elm_file;

	elm_file = NULL;
	dir = opendir(name);
	while ((ent = readdir(dir)))
	{
		if (((get_option('0') & DOT) != DOT) && ent->d_name[0] == '.')
			continue;
		if (elm_file == NULL)
			elm_file = new_elem(ent->d_name, name, filen(name, ent->d_name));
		else
			insert_elem(elm_file, ent->d_name, name, filen(name, ent->d_name));
	}
	if (elm_file != NULL)
	{
		ft_mergesort(&elm_file, return_good_ptr_func());
		if ((get_option('0') & LONG) == LONG)
			print_total_long_files(elm_file);
		print_elm_file(elm_file, type_of_element);
	}
	closedir(dir);
	return (elm_file);
}

static int			is_directory_we_want_to_list(const char *parent, \
const char *name)
{
	struct stat		st_buf;
	char			*path;

	if (!ft_strcmp(".", name) || !ft_strcmp("..", name))
		return (0);
	path = create_new_path(parent, name);
	lstat(path, &st_buf);
	free(path);
	return (S_ISDIR(st_buf.st_mode));
}

void				list(const char *name, int is_first_launching)
{
	DIR				*dir;
	char			*next;
	t_element		*elmt;

	if (is_first_launching == 0)
		print_directory_name(name);
	if ((dir = opendir(name)) == NULL)
	{
		print_error_open_directory(name);
		return ;
	}
	is_first_launching = 0;
	elmt = list_file(name, DIRECTORY);
	while (((get_option('0') & REC) == REC) && elmt != NULL)
	{
		if (is_directory_we_want_to_list(name, elmt->data->file_name))
		{
			next = create_new_path(name, elmt->data->file_name);
			ft_putstr("\n");
			list(next, is_first_launching);
			free(next);
		}
		elmt = elmt->next;
	}
	closedir(dir);
}
