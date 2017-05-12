/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:08:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/12 18:47:24 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

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
