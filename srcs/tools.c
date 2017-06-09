/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:08:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/06/09 16:58:12 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			ft_strtab_pop(char **tab)
{
	int		index;
	char	**tmp;

	index = 0;
	tmp = 0;
	while (tab[index])
	{
		tmp = tab + index;
		index++;
	}
	if (tmp)
		ft_strdel(tmp);
	return (1);
}

int			free_lemin(t_lemin *lemin)
{
	t_node		*r;
	int			index;

	index = 0;
	if (lemin->links)
	{
		while (lemin->links[index])
			free(lemin->links[index++]);
		free(lemin->links);
	}
	while (lemin->rooms)
	{
		r = lemin->rooms->next;
		ft_strdel(&(lemin->rooms->name));
		free(lemin->rooms->child);
		free(lemin->rooms);
		lemin->rooms = r;
	}
	ft_strtabdel(&(lemin->file));
	if (lemin->paths)
		free(lemin->paths);
	return (1);
}
