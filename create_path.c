/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:09:55 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 17:10:16 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*create_path_for_lstat(t_infos_file *file)
{
	char	*new_path_lstat;

	new_path_lstat = ft_strjoin(file->path, "/");
	new_path_lstat = ft_strjoin(new_path_lstat, file->file_name);
	return (new_path_lstat);
}

char		*create_new_path(const char *src_parent, const char *src_name)
{
	char	*new_path;

	new_path = malloc(ft_strlen(src_name) + ft_strlen(src_parent) + 2);
	ft_strcpy(new_path, src_parent);
	ft_strcat(new_path, "/");
	ft_strcat(new_path, src_name);
	return (new_path);
}
