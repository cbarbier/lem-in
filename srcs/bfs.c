/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:36:18 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/10 20:39:30 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			bfs(t_lemin *lemin, t_node	*queue)
{
	t_node		*tmp;
	int			index;

	tmp = queue;
	while (tmp != lemin->end)
	{
		index = 0;
		ft_printf("queue head  %s\n", queue->name);
		while (queue && index < queue->nb_child)
		{
			if (queue->child[index]->state == 0)
			{
				ft_printf("queue tail %s\n", queue->child[index]->name);
				queue->child[index]->pprev = queue;
				queue->child[index]->state = 1;
				tmp->qnext = queue->child[index];
				tmp = tmp->qnext;
				if (tmp == lemin->end)
					break;
			}
			index++;
		}
		queue = queue->qnext;
	}
	return (1);
}
