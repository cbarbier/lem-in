/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/10 20:25:34 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/includes/libft.h"

typedef struct	s_node
{
	int				id;
	char			*name;
	int				x;
	int				y;
	int				nb_child;
	struct s_node	**child;
	struct s_node	*next;
	struct s_node	*qnext;
	struct s_node	*pprev;
	int				state;
}				t_node;

typedef struct	s_lemin
{
	char	**file;
	t_node	***links;
	int		nb_ant;
	int		nb_room;
	int		nb_link;
	t_node	*rooms;
	t_node	*start;
	t_node	*end;
	t_list	*paths;
}				t_lemin;
int				parse(t_lemin *lemin);
t_node			*add_room(t_lemin *lemin, t_node *lst,  char *str);
int				parse_nodes(t_lemin *lemin, char *str);
t_node			***links_to_tab(t_lemin *lemin, t_node ***tab, char *str);
int				save_links(t_lemin *lemin, char *line);
int				set_links(t_node ***links);
int				is_blank_tab(char c);
t_node			*get_room(t_node *rooms, char *name);
int				bfs(t_lemin *lemin, t_node	*queue);

#endif
