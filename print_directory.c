/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:43:26 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 17:43:35 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_directory_name(const char *name)
{
	ft_putstr(GREEN "");
	ft_putstr(name);
	ft_putendl(":");
}

void	print_error_open_directory(const char *name)
{
	ft_putstr(MAGENTA "ft_ls: ");
	ft_putstr(name);
	ft_putstr(": ");
	ft_putendl(strerror(errno));
}
