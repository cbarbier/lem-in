/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:25:38 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/12 16:06:20 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static t_node		**set_paths(t_lemin *lemin, t_node *end)
{
	t_node	**paths;
	int		index;
	int		index_path;

	if (!(paths = (t_node **)ft_memalloc(lemin->nb_path * sizeof(t_node *))))
		return (0);
	index = 0;
	while (index < end->nb_child)
	{
		if (end->child[index]->state < 0)
		{
			index_path = -end->child[index]->state - 1;
			paths[index_path] = end->child[index];
//			ft_printf("ip: %d  : %s\n", index_path, paths[index_path]->name);
		}
		index++;
	}
	return (paths);
}

static int		put_helper(t_lemin *lemin, t_node *room, int *nb, int left)
{
	int			i;
	char		c;
	int			ant;

	c = ' ';
	i = 0;
	while (room != lemin->start)
	{
		if ((*nb < lemin->nb_ant && room->pnext == lemin->start) || room->pnext->ant)
		{
			ant = (room->pnext == lemin->start ? ++(*nb) : room->pnext->ant);
			room->ant = ant;
			room->pnext->ant = 0;
			ft_printf((i++ || left ? " L%d-%s" : "L%d-%s"), ant, room->name);
		}
		room = room->pnext;
	}
	return (i);
}

int				put_ants(t_lemin *lemin, int nb_ant)
{
	t_node		*end;
	int			index;
	int			left;
	int			loop;

	lemin->paths = set_paths(lemin, lemin->end);
	left = 1;
	loop = 0;
	while (left || nb_ant < lemin->nb_ant)
	{
		left = 0;
		index = 0;
		while (index < lemin->nb_path)
		{
			end = lemin->end;
			end->pnext = lemin->paths[index];
			left += put_helper(lemin, end, &nb_ant, left);
			index++;
		}
		if (left)
			ft_printf("\n");
	}
	return (1);
}
