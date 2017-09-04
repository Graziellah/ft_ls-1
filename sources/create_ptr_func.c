/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ptr_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:43:14 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 16:43:54 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_func	*get_ptr_function(int i)
{
	static t_func *ptr_function[4] = {ft_compare_ascii, \
	ft_compare_time, \
	ft_compare_ascii_reverse, \
	ft_compare_time_reverse};

	return (ptr_function[i]);
}
