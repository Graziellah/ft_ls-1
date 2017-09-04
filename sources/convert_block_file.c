/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_block_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:08:56 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 17:08:59 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*create_new_year(time_t t_time)
{
	char	*time_str;
	char	new_year_str[6];
	char	new_month_str[10];
	int		i;
	int		j;

	i = 4;
	j = 0;
	time_str = ctime(&t_time);
	while (i <= 9)
		new_month_str[j++] = time_str[i++];
	new_month_str[j++] = ' ';
	new_month_str[j] = 0;
	ft_strcpy(new_year_str, &time_str[ft_strlen(time_str) - 5]);
	new_year_str[4] = 0;
	return (ft_strjoin(new_month_str, new_year_str));
}

int			dated_more_than_six_month(time_t t_time)
{
	time_t	current;
	time_t	paste_diff;
	time_t	futur_diff;

	current = time(NULL);
	paste_diff = current - t_time;
	futur_diff = current + SIX_MONTH_IN_SEC;
	return (paste_diff > SIX_MONTH_IN_SEC || t_time > futur_diff);
}

char		*convert_time(time_t convert_to)
{
	char	buff[100];
	char	*new_time;
	int		len;

	if (dated_more_than_six_month(convert_to) == 1)
		return (create_new_year(convert_to));
	new_time = ctime(&convert_to);
	if (!new_time)
		return (NULL);
	while (*new_time && *new_time != ' ')
		new_time++;
	ft_strcpy(buff, new_time + 1);
	len = ft_strlen(buff);
	while (buff[--len] != ':')
		buff[len] = 0;
	buff[len] = 0;
	return (ft_strdup(buff));
}
