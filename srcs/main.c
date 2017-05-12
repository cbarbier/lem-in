/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/12 11:13:25 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				put_tree(t_lemin *lemin)
{
	t_node		*rooms;
	int			index;

	rooms = lemin->rooms;
	ft_printf("{red}TREE{no}\n");
	while (rooms)
	{
		index = 0;
		if (rooms == lemin->start)
			ft_printf("{red}start{no}\n");
		if (rooms == lemin->end)
			ft_printf("{red}end{no}\n");
		ft_printf("{grn}%s {yel}[%d,  %d]{no}  nb_child: %d\n", rooms->name, rooms->x, rooms->y, rooms->nb_child);
		while (index < rooms->nb_child)
		{
			ft_printf("{blu} %s {%d}", rooms->child[index]->name, rooms->child[index]->state);
			index++;
		}
		ft_printf("\n{grn}------------{no}\n");
		rooms = rooms->next;
	}
	ft_printf("{red}END OF TREE{no}\n");
	return (1);
}

static int		put_a_path(t_lemin *lemin, t_node *room, int mark)
{
	int			index;
	t_node		*last;

	last = 0;
	while (room != lemin->end)
	{
		ft_printf("%s - ", room->name);
		index = 0;
		while (index < room->nb_child)
		{
			if ((room->child[index] != last
			&& room->child[index]->state == mark)
			|| room->child[index] == lemin->end)
			{
				last = room;
				room = room->child[index];
				break;
			}
			index++;
		}
	}
	ft_printf("%s\n", room->name);
	return (1);
}
		
static int		put_paths(t_lemin *lemin)
{
	int		index;

	ft_printf("number of path found: %d\n", lemin->nb_path);
	index = 1;
	while (index <= lemin->nb_path)
	{
		ft_printf("PATH %d\n", index);
		put_a_path(lemin, lemin->start, -index);
		ft_printf("-------\n");
		index++;
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_lemin		lemin;
	(void)argv;
	(void)argc;

	ft_bzero(&lemin, sizeof(t_lemin));
	if (!parse(&lemin) || !set_links(lemin.links))
	{
		ft_printf("ERROR\n");
		return (0);
	}
	ft_putstrtab(lemin.file);
	put_tree(&lemin);
	find_path(&lemin, 0);
	ft_printf("bfs done!\n");
	put_tree(&lemin);
	put_paths(&lemin);
	put_ants(&lemin, lemin.nb_ant);
	return (1);
}
