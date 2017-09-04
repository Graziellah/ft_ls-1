/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:53:09 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 16:56:11 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_element			*check_argv(int begin_path_index, \
int total_file_index, char **av)
{
	t_head_element	*head;
	int				ret;

	head = NULL;
	init_head_element_and_field(&head);
	while (begin_path_index < total_file_index)
	{
		ret = kind_of_parameter(av[begin_path_index]);
		if (ret == FILE)
			create_elm_file_for_head_element(&head, av[begin_path_index]);
		else if (ret == ERROR)
			create_elm_error_for_head_element(&head, av[begin_path_index]);
		else if (ret == DIRECTORY)
			create_elm_repository_for_head_element(&head, av[begin_path_index]);
		begin_path_index++;
	}
	sorte_element_error_and_file_and_dir(&head);
	print_element_error_and_file(head);
	return (head->direct_head);
}
