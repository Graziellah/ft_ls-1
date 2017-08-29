/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:34:54 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 17:37:04 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_usage_ls(void)
{
	ft_putendl(RED "usage: ft_ls [-Ralrt] [file ...]");
	exit(EXIT_FAILURE);
}

static void		print_illegal_option(char bad_option)
{
	ft_putstr(RED "ft_ls: illegal option -- ");
	ft_putchar(bad_option);
	ft_putstr("\n");
	ft_usage_ls();
}

int				get_option(char valid_option)
{
	static int	flag = 0x20;

	if (valid_option == 'l')
		flag |= LONG;
	else if (valid_option == 'R')
		flag |= REC;
	else if (valid_option == 'a')
		flag |= DOT;
	else if (valid_option == 'r')
		flag |= REV;
	else if (valid_option == 't')
	{
		flag |= TIME;
		flag &= ~(ASCII);
	}
	return (flag);
}

int				check_option(int argc, char **argv)
{
	const char	*option = "lRart";
	int			i;
	int			j;

	i = 1;
	j = 1;
	argc -= 1;
	while (argc--)
	{
		if (ft_strcmp(argv[i], "--") == 0)
			return (++i);
		if (argv[i][0] != '-' || (ft_strlen(argv[i]) == 1 && argv[i][0] == '-'))
			return (i);
		while (argv[i][j])
		{
			if ((argv[i][j] == '-') || ft_strchr(option, argv[i][j]) == NULL)
				print_illegal_option(argv[i][j]);
			else
				get_option(argv[i][j]);
			j++;
		}
		j = 1;
		i++;
	}
	return (i);
}
