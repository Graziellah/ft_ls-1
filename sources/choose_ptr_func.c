/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_ptr_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:00:36 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 17:00:38 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_func	*return_good_ptr_func(void)
{
	int	option;

	option = get_option('0');
	if (((option & REV) != REV) && ((option & ASCII) == ASCII))
		return (get_ptr_function(0));
	if (((option & REV) != REV) && ((option & TIME) == TIME))
		return (get_ptr_function(1));
	if (((option & REV) == REV) && ((option & ASCII) == ASCII))
		return (get_ptr_function(2));
	if (((option & REV) == REV) && ((option & TIME) == TIME))
		return (get_ptr_function(3));
	return (get_ptr_function(0));
}
