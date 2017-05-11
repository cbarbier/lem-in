/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:36:18 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/11 18:16:34 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int			reset_queue(t_node *queue)
{
	t_node		*tmp;

	tmp = 0;
	while (queue)
	{
		tmp = queue;
		queue = queue->qnext;
		tmp->qnext = 0;
	}
	return (1);
}

static int			bfs(t_lemin *lemin, t_node	*queue, int ipath)
{
	t_node		*tmp;
	int			index;

	tmp = queue;
	lemin->end->state = 1;
	while (queue)
	{
		index = 0;
		ft_printf("cur %s\n", queue->name);
		while (index < queue->nb_child)
		{
			if (queue->child[index]->state >= 0
			&& queue->child[index]->state != ipath)
			{
				ft_printf("child %s ", queue->child[index]->name);
				queue->child[index]->pprev = queue;
				tmp->qnext = queue->child[index];
				tmp = tmp->qnext;
				if (tmp == lemin->start)
					return (1);
				queue->child[index]->state = ipath;
			}
			index++;
		}
		ft_printf("\n");
		queue = queue->qnext;
	}
	return (0);
}

static int			mark_path(t_lemin *lemin, t_node *room, int ipath)
{
	t_node		*tmp;

	ft_printf("\nmarking path\n");
	while (room != lemin->end)
	{
		ft_printf("marking %s\n", room->name);
		room->state = -ipath;
		tmp = room;
		room = room->pprev;
		tmp->pnext = room;
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
		lemin->start->state = 0;
		reset_queue(lemin->end);
//		put_tree(lemin);
		ft_printf("#################next tour\n");
		lemin->nb_path++;
	}
	return (lemin->nb_path);
}
