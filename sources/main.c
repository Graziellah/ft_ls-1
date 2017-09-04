/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:39:34 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 17:40:30 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				main(int ac, char **av)
{
	int			i;
	int			is_first_launching;
	t_element	*repository;

	i = check_option(ac, av);
	is_first_launching = 1;
	if (i == ac)
		repository = new_elem(".", ".", 0);
	else
	{
		if (ac - i == 1)
			is_first_launching = 1;
		else
			is_first_launching = 0;
		repository = check_argv(i, ac, av);
	}
	while (repository)
	{
		list(repository->data->file_name, is_first_launching);
		if (repository->next != NULL)
			ft_putstr("\n");
		repository = repository->next;
	}
	return (0);
}
