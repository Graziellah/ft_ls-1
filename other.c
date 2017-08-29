/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:42:39 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 17:43:06 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				strsearch(const char *target, const char *token, int len)
{
	int			i;

	i = 0;
	while (len-- && target[i] && token[i])
	{
		if (target[i] != token[i])
			return (-1);
		i++;
	}
	return (0);
}

int				kind_of_parameter(const char *name)
{
	struct stat	file_stat;

	if (stat(name, &file_stat) == -1 && lstat(name, &file_stat) == -1)
		return (ERROR);
	else if (S_ISDIR(file_stat.st_mode))
		return (DIRECTORY);
	else
		return (FILE);
	return (ERROR);
}
