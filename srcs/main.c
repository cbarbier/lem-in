/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/06/08 14:23:56 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void		set_opt(t_lemin *lemin, int argc, char **argv)
{
	int		index;

	index = 1;

	while (index < argc)
	{
		if (ft_strlen(argv[index]) > 1 && argv[index][0] == '-')
		{
			if (ft_strchr(argv[index], 'm'))
					lemin->opt_m = 1;
			if (ft_strchr(argv[index], 'p'))
					lemin->opt_p = 1;
		}
		else
			break;
		index++;
	}
}

void			put_tree(t_lemin *lemin)
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
		ft_printf("{grn}%s {yel}[%d,  %d]{no}  nb_child: %d\n",
				rooms->name, rooms->x, rooms->y, rooms->nb_child);
		while (index < rooms->nb_child)
		{
			ft_printf("{blu} %s {%d}",
					rooms->child[index]->name, rooms->child[index]->state);
			index++;
		}
		rooms = rooms->next;
	}
	ft_printf("{red}END OF TREE{no}\n");
}

static int		put_a_path(t_lemin *lemin, t_node *room, int mark)
{
	int			index;
	t_node		*last;

	last = 0;
	while (room != lemin->end)
	{
		ft_printf("%s -> ", room->name);
		index = 0;
		while (index < room->nb_child)
		{
			if ((room->child[index] != last
			&& room->child[index]->state == mark)
			|| room->child[index] == lemin->end)
			{
				last = room;
				room = room->child[index];
				break ;
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

	ft_printf("\n\n{red}#####INFOS#######\n");
	ft_printf("{yel}  >number of path found: %d\n", lemin->nb_path);
	index = 1;
	while (index <= lemin->nb_path)
	{
		ft_printf("{grn}  >path %d\n", index);
		put_a_path(lemin, lemin->start, -index);
		ft_printf("\n");
		index++;
	}
	ft_printf("\n{red}#################\n{no}");
	return (1);
}

int				main(int argc, char **argv)
{
	t_lemin		lemin;

	ft_bzero(&lemin, sizeof(t_lemin));
	set_opt(&lemin, argc, argv);
	if (!parse(&lemin) || !set_links(lemin.links)
	|| !find_path(&lemin, lemin.opt_m))
	{
		free_lemin(&lemin);
		ft_printf("ERROR\n");
		return (0);
	}
	ft_putstrtab(lemin.file);
	ft_printf("\n");
	if (DEBUG)
		put_tree(&lemin);
	put_ants(&lemin, 0);
	if (lemin.opt_p)
		put_paths(&lemin);
	free_lemin(&lemin);
	return (1);
}
