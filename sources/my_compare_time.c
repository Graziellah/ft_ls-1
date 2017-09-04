/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_compare_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:41:30 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 17:42:20 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		compare_nano_time(char *file1, char *file2)
{
	struct stat	bstat1;
	struct stat	bstat2;

	lstat(file1, &bstat1);
	lstat(file2, &bstat2);
	if (bstat1.st_mtimespec.tv_nsec == bstat2.st_mtimespec.tv_nsec)
		return (0);
	else if (bstat1.st_mtimespec.tv_nsec > bstat2.st_mtimespec.tv_nsec)
		return (-1);
	else if (bstat1.st_mtimespec.tv_nsec < bstat2.st_mtimespec.tv_nsec)
		return (1);
	return (0);
}

int				compare_time(t_infos_file *file1, t_infos_file *file2)
{
	struct stat	bstat1;
	struct stat	bstat2;
	char		*str1;
	char		*str2;

	if (ft_strcmp(file1->path, file1->file_name) == 0)
	{
		str1 = file1->path;
		str2 = file2->path;
		lstat(str1, &bstat1);
		lstat(str2, &bstat2);
	}
	else
	{
		str1 = create_path_for_lstat(file1);
		str2 = create_path_for_lstat(file2);
		lstat(str1, &bstat1);
		lstat(str2, &bstat2);
	}
	if (bstat1.st_mtime == bstat2.st_mtime)
		return (compare_nano_time(str1, str2));
	else if (bstat1.st_mtime > bstat2.st_mtime)
		return (-1);
	else
		return (1);
}
