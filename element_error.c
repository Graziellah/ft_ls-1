/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:22:00 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 17:22:38 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	create_elm_error_for_head_element(t_head_element **head, char *av)
{
	if ((*head)->err_head == NULL)
		head[0]->err_head = new_elem(av, av, 0);
	else
		insert_elem(head[0]->err_head, av, av, 0);
}

void	print_elm_err(t_element *elm)
{
	while (elm)
	{
		ft_putstr(RED "ft_ls: ");
		ft_putstr(elm->data->file_name);
		ft_putstr(": ");
		ft_putendl("No such file or directory");
		elm = elm->next;
	}
}
