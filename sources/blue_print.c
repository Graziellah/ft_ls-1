/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blue_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraheemu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:44:33 by mraheemu          #+#    #+#             */
/*   Updated: 2016/10/17 16:52:13 by mraheemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					print_total_long_files(t_element *elmt)
{
	long				total;

	total = 0;
	while (elmt)
	{
		total += elmt->data->size;
		elmt = elmt->next;
	}
	ft_putstr(BLUE "total ");
	ft_putendl(ft_itoa(total));
}

static void				print_long_helper_2(struct stat bufstat, \
t_infos_file *print, char *symlink)
{
	ft_putstr(print->file_name);
	ft_putchar(' ');
	if (type_file(bufstat.st_mode) == 'l')
		ft_putstr("->");
	ft_putchar(' ');
	if (type_file(bufstat.st_mode) == 'l')
		ft_putstr(symlink);
	ft_putchar('\n');
}

static void				print_long_helper(struct stat bufstat, \
struct passwd *pwd, struct group *grp)
{
	ft_putstr(permission_of_file(bufstat.st_mode));
	ft_putchar(' ');
	ft_putnbr(bufstat.st_nlink);
	ft_putchar(' ');
	ft_putstr(pwd->pw_name);
	ft_putchar(' ');
	ft_putstr(grp->gr_name);
	ft_putchar(' ');
	if (check_special_file(bufstat) == 1)
		display_major_minor(bufstat);
	else
		ft_putnbr(bufstat.st_size);
	ft_putchar(' ');
	ft_putstr(convert_time(bufstat.st_mtime));
	ft_putchar(' ');
}

void					print_with_long_opt(t_infos_file *print, \
int type_of_element)
{
	struct stat		bufstat;
	struct passwd	*pwd;
	struct group	*grp;
	char			symlink[1024];

	if (type_of_element == DIRECTORY)
		print->path = create_path_for_lstat(print);
	if (lstat(print->path, &bufstat) == -1)
		ft_putendl(strerror(errno));
	pwd = getpwuid(bufstat.st_uid);
	grp = getgrgid(bufstat.st_gid);
	if (type_file(bufstat.st_mode) == 'l')
	{
		ft_memset(symlink, 0, 1024);
		if (readlink(print->path, symlink, 1024) == -1)
			ft_putendl(strerror(errno));
	}
	print_long_helper(bufstat, pwd, grp);
	print_long_helper_2(bufstat, print, symlink);
}
