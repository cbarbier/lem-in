/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:25:38 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/12 12:41:31 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_node	**set_paths(t_lemin *lemin, t_node *start)
{
	t_node	**paths;
	int		index;
	int		index_path;

	if (!(paths = (t_node **)ft_memalloc(lemin->nb_path * sizeof(t_node *))))
		return (0);
	index = 0;
	while (index < start->nb_child)
	{
		if (start->child[index]->state < 0)
		{
			index_path = -start->child[index]->state - 1;
			paths[index_path] = start->child[index];
		}
		index++;
	}
	return (paths);
}

static int		put_helper(t_lemin *lemin, t_node *room)
{
	int			i;
	char		c;

	c = ' ';
	i = 0;
	//lemin->start->ant = 0;
	while (room != lemin->start)
	{
		if (room->ant)
			ft_printf((i++ ? " L%d-%s" : "L%d-%s"), room->ant, room->name);
		room = room->pnext;
	}
	return (i);
}

int				put_ants(t_lemin *lemin, int nb_ant)
{
	t_node		*end;
	t_node		*tmp;
	int			ants[2];

	ft_bzero(ants, 2 * sizeof(int));
	while (ants[1] < nb_ant)
	{
		end = lemin->end;
		tmp = 0;
		lemin->start->ant = (ants[0] < nb_ant ? ++ants[0] : 0);
		lemin->start->pnext = 0;
		if (end->ant)
			ants[1]++;
		while (end)
		{
			if (tmp)
				tmp->ant = end->ant;
			tmp = end;
			end = end->pnext;
		}
		put_helper(lemin, lemin->end);
		ft_printf("\n");
	}
	return (1);
}
