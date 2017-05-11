/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:36:18 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/11 11:56:18 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int			bfs(t_lemin *lemin, t_node	*queue, int ipath)
{
	t_node		*tmp;
	int			index;

	tmp = queue;
	while (tmp != lemin->start)
	{
		index = 0;
		{
			if (queue->child[index]->state >= 0
			&& queue->child[index]->state != ipath)
			{
				queue->child[index]->pprev = queue;
				tmp->qnext = queue->child[index];
				tmp = tmp->qnext;
				if (tmp == lemin->start)
					break;
				queue->child[index]->state = ipath;
			}
			index++;
		}
		if (tmp == queue)
			break;
		queue = queue->qnext;
	}
	ft_printf("queue %p == %p tmp\n", queue, tmp);
	return (queue == tmp || tmp != lemin->start ? 0 : 1);
}

static int			mark_path(t_lemin *lemin, t_node *room, int ipath)
{
	t_node		*tmp;

	while (room != lemin->end)
	{
		ft_printf("%s\n", room->name);
		room->state = -ipath;
		tmp = room;
		room = room->pprev;
		tmp->pprev = 0;
		tmp->qnext = 0;
	}
	return (1);
}

int					find_path(t_lemin *lemin, int multi)
{
	int		ipath;

	ipath = 1;

	if (!multi && bfs(lemin, lemin->end, ipath))
	{
		lemin->nb_path++;
		return (mark_path(lemin, lemin->start, ipath));
	}
	while (bfs(lemin, lemin->end, ipath))
	{
		mark_path(lemin, lemin->start, ipath++);
//		put_tree(lemin);
		lemin->nb_path++;
	}
	return (lemin->nb_path);
}
