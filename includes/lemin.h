/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/06/08 09:12:09 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define DEBUG 0
# include "../libft/includes/libft.h"

typedef struct	s_node
{
	int				ant;
	char			*name;
	int				x;
	int				y;
	int				nb_child;
	struct s_node	**child;
	struct s_node	*next;
	struct s_node	*qnext;
	struct s_node	*pprev;
	struct s_node	*pnext;
	int				state;
}				t_node;

typedef struct	s_lemin
{
	char	**file;
	t_node	***links;
	t_node	**paths;
	int		nb_ant;
	int		nb_room;
	int		nb_link;
	int		nb_path;
	t_node	*rooms;
	t_node	*start;
	t_node	*end;
	int		opt_m;
	int		opt_p;
}				t_lemin;
int				parse(t_lemin *lemin);
t_node			*add_room(t_lemin *lemin, t_node *lst, char *str);
int				parse_nodes(t_lemin *lemin, char *str);
t_node			***links_to_tab(t_lemin *lemin, t_node ***tab, char *str);
int				save_links(t_lemin *lemin, char *line);
int				set_links(t_node ***links);
int				is_blank_tab(char c);
t_node			*get_room(t_node *rooms, char *name);
int				find_path(t_lemin *lemin, int multi);
void			put_tree(t_lemin *lemin);
int				put_ants(t_lemin *lemin, int nb_ant);
int				free_lemin(t_lemin *lemin);

#endif
