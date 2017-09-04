/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   major_minor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:40:49 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 17:41:04 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_special_file(struct stat file_stat)
{
	if ((S_ISCHR(file_stat.st_mode)) || S_ISBLK(file_stat.st_mode))
		return (1);
	return (0);
}

int			major_device(unsigned int dev)
{
	int		res;

	res = dev >> 24 & 0xff;
	return (res);
}

int			minor_device(int dev)
{
	int		res;

	res = dev & 0xffffff;
	return (res);
}

void		display_major_minor(struct stat file_stat)
{
	ft_putnbr(major_device(file_stat.st_rdev));
	ft_putstr(", ");
	ft_putnbr(minor_device(file_stat.st_rdev));
	ft_putchar(' ');
}
