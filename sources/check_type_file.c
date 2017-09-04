/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:01:07 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 17:03:15 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			type_file(mode_t mode)
{
	if ((mode & S_IFMT) == S_IFBLK)
		return ('b');
	if ((mode & S_IFMT) == S_IFCHR)
		return ('c');
	if ((mode & S_IFMT) == S_IFDIR)
		return ('d');
	if ((mode & S_IFMT) == S_IFIFO)
		return ('p');
	if ((mode & S_IFMT) == S_IFREG)
		return ('-');
	if ((mode & S_IFMT) == S_IFLNK)
		return ('l');
	if ((mode & S_IFMT) == S_IFSOCK)
		return ('s');
	return ('?');
}

char			*permission_of_file(mode_t mode)
{
	char		perm[11];

	perm[0] = type_file(mode);
	perm[1] = (mode & S_IRUSR) ? 'r' : '-';
	perm[2] = (mode & S_IWUSR) ? 'w' : '-';
	perm[3] = (mode & S_IXUSR) ? 'x' : '-';
	perm[4] = (mode & S_IRGRP) ? 'r' : '-';
	perm[5] = (mode & S_IWGRP) ? 'w' : '-';
	perm[6] = (mode & S_IXGRP) ? 'x' : '-';
	perm[7] = (mode & S_IROTH) ? 'r' : '-';
	perm[8] = (mode & S_IWOTH) ? 'w' : '-';
	perm[9] = (mode & S_IXOTH) ? 'x' : '-';
	perm[10] = '\0';
	return (ft_strdup(perm));
}
