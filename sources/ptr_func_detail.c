/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_func_detail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:43:54 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 17:47:53 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_element		*ft_compare_ascii(t_element *a, t_element *b)
{
	t_element	*result;

	if (ft_strcmp(a->data->file_name, b->data->file_name) < 0)
	{
		result = a;
		result->next = sortedmerge(a->next, b, ft_compare_ascii);
	}
	else
	{
		result = b;
		result->next = sortedmerge(a, b->next, ft_compare_ascii);
	}
	return (result);
}

t_element		*ft_compare_time(t_element *a, t_element *b)
{
	t_element	*result;

	if (compare_time(a->data, b->data) == 0)
		if (ft_strcmp(a->data->file_name, b->data->file_name) < 0)
		{
			result = a;
			result->next = sortedmerge(a->next, b, ft_compare_time);
		}
		else
		{
			result = b;
			result->next = sortedmerge(a, b->next, ft_compare_time);
		}
	else if (compare_time(a->data, b->data) > 0)
	{
		result = b;
		result->next = sortedmerge(a, b->next, ft_compare_time);
	}
	else
	{
		result = a;
		result->next = sortedmerge(a->next, b, ft_compare_time);
	}
	return (result);
}

t_element		*ft_compare_ascii_reverse(t_element *a, t_element *b)
{
	t_element	*result;

	if (ft_strcmp(a->data->file_name, b->data->file_name) > 0)
	{
		result = a;
		result->next = sortedmerge(a->next, b, ft_compare_ascii_reverse);
	}
	else
	{
		result = b;
		result->next = sortedmerge(a, b->next, ft_compare_ascii_reverse);
	}
	return (result);
}

t_element		*ft_compare_time_reverse(t_element *a, t_element *b)
{
	t_element	*result;

	if (compare_time(a->data, b->data) == 0)
		if (ft_strcmp(a->data->file_name, b->data->file_name) > 0)
		{
			result = a;
			result->next = sortedmerge(a->next, b, ft_compare_time_reverse);
		}
		else
		{
			result = b;
			result->next = sortedmerge(a, b->next, ft_compare_time_reverse);
		}
	else if (compare_time(a->data, b->data) < 0)
	{
		result = b;
		result->next = sortedmerge(a, b->next, ft_compare_time_reverse);
	}
	else
	{
		result = a;
		result->next = sortedmerge(a->next, b, ft_compare_time_reverse);
	}
	return (result);
}
