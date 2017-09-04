/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:37:33 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 17:39:16 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_element		*new_elem(char *f_name, const char *f_path, long size)
{
	t_element	*new_elm;

	new_elm = malloc(sizeof(*new_elm));
	if (new_elm)
	{
		new_elm->data = malloc(sizeof(t_infos_file));
		new_elm->data->file_name = ft_strdup(f_name);
		new_elm->data->path = ft_strdup(f_path);
		new_elm->data->size = size;
		new_elm->next = NULL;
	}
	return (new_elm);
}

void			insert_elem(t_element *list, char *file_name, \
const char *file_path, long size)
{
	t_element	*new_elm;

	while (list->next != NULL)
		list = list->next;
	new_elm = new_elem(file_name, file_path, size);
	list->next = new_elm;
}

void			reverse_linked_list(t_element **head_ref)
{
	t_element	*prev;
	t_element	*current;
	t_element	*next;

	prev = NULL;
	current = *head_ref;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void			print_elm_file(t_element *elm, int type_of_element)
{
	int option;

	option = get_option('0');
	while (elm)
	{
		if ((option & LONG) == LONG)
			print_with_long_opt(elm->data, type_of_element);
		else
		{
			ft_putstr(BLUE);
			ft_putendl(elm->data->file_name);
		}
		elm = elm->next;
	}
}
