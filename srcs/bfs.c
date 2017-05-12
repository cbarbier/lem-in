/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:36:18 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/12 17:52:43 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int			reset_queue(t_node *queue)
{
	t_node		*tmp;

	tmp = 0;
	if (DEBUG)
		ft_printf("queue: ");
	while (queue)
	{
		if (DEBUG)
			ft_printf("%s ", queue->name);
		tmp = queue;
		queue = queue->qnext;
		tmp->qnext = 0;
	}
	if (DEBUG)
		ft_printf("\n");
	return (1);
}

static int			bfs(t_lemin *lemin, t_node *queue, int ipath)
{
	t_node		*tmp;
	int			index;

	tmp = queue;
	lemin->end->state = ipath;
	while (queue)
	{
		index = 0;
		while (index < queue->nb_child)
		{
			if (queue->child[index]->state >= 0
			&& queue->child[index]->state != ipath)
			{
				queue->child[index]->pprev = queue;
				tmp->qnext = queue->child[index];
				tmp = tmp->qnext;
				if (tmp == lemin->start)
					return (1);
				queue->child[index]->state = ipath;
			}
			index++;
		}
		queue = queue->qnext;
	}
	return (0);
}

static int			mark_path(t_lemin *lemin, t_node *room, int ipath)
{
	t_node		*tmp;

	while (room != lemin->end)
	{
		room->state = -ipath;
		tmp = room;
		room = room->pprev;
		room->pnext = tmp;
	}
	lemin->end->pnext = tmp;
	return (1);
}

int					find_path(t_lemin *lemin, int multi)
{
	int		ipath;

	ipath = 1;
	if (DEBUG)
		put_tree(lemin);
	if (!multi && bfs(lemin, lemin->end, ipath))
	{
		lemin->nb_path++;
		return (mark_path(lemin, lemin->start, ipath));
	}
	while (bfs(lemin, lemin->end, ipath))
	{
		mark_path(lemin, lemin->start, ipath++);
		reset_queue(lemin->end);
		if (!lemin->nb_path && lemin->start->pprev != lemin->end)
			lemin->start->state = 0;
		lemin->nb_path++;
	}
	return (lemin->nb_path);
}
