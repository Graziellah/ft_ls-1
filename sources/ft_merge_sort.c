/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:23:34 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/28 17:57:52 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_element			*sortedmerge(t_element *a, t_element *b, \
t_element *(*ft_cmp)(t_element *a, t_element *b))
{
	t_element		*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	result = ft_cmp(a, b);
	return (result);
}

void				frontbacksplit(t_element *source, t_element **front, \
t_element **back)
{
	t_element		*fast;
	t_element		*slow;

	if (source == NULL || source->next == NULL)
	{
		*front = source;
		*back = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = source;
		*back = slow->next;
		slow->next = NULL;
	}
}

void				ft_mergesort(t_element **head_ref, \
t_element *(*ft_cmp)(t_element *a, t_element *b))
{
	t_element		*head;
	t_element		*a;
	t_element		*b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	frontbacksplit(head, &a, &b);
	ft_mergesort(&a, ft_cmp);
	ft_mergesort(&b, ft_cmp);
	*head_ref = sortedmerge(a, b, ft_cmp);
}
