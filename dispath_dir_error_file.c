/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispath_dir_error_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:17:26 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 17:21:23 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		create_elm_file_for_head_element(t_head_element **head, char *av)
{
	char	path[1024];

	ft_strcpy(path, av);
	if ((*head)->file_head == NULL)
		head[0]->file_head = new_elem(av, path, 0);
	else
		insert_elem(head[0]->file_head, av, path, 0);
}

void		create_elm_repository_for_head_element(t_head_element **head, \
char *av)
{
	if ((*head)->direct_head == NULL)
		head[0]->direct_head = new_elem(av, av, 0);
	else
		insert_elem(head[0]->direct_head, av, av, 0);
}

void		init_head_element_and_field(t_head_element **head)
{
	if (*head == NULL)
	{
		*head = malloc(sizeof(t_head_element));
		head[0]->file_head = NULL;
		head[0]->err_head = NULL;
		head[0]->direct_head = NULL;
	}
}

void		sorte_element_error_and_file_and_dir(t_head_element **head)
{
	if ((*head)->err_head != NULL)
		ft_mergesort(&(head[0]->err_head), get_ptr_function(0));
	if (head[0]->file_head != NULL)
		ft_mergesort(&(head[0]->file_head), return_good_ptr_func());
	if (head[0]->direct_head != NULL)
		ft_mergesort(&(head[0]->direct_head), return_good_ptr_func());
}

void		print_element_error_and_file(t_head_element *head)
{
	if (head[0].err_head != NULL)
		print_elm_err(head->err_head);
	if (head[0].file_head != NULL)
	{
		print_elm_file(head->file_head, FILE);
		if (head[0].direct_head != NULL)
			ft_putstr("\n");
	}
}
