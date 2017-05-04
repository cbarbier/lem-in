/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myatoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 12:05:14 by cbarbier          #+#    #+#             */
/*   Updated: 2017/05/04 17:24:56 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int					ft_myatoi(char *str, int *a)
{
	unsigned int	res;
	unsigned int	i;
	int				sign;

	res = 0;
	i = 0;
	sign = 1;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-' ? -1 : 1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 10 * res + str[i] - '0';
		if ((sign > 0 && res > 2147483647) || (sign < 0 && res > 2147483648))
			return (0);
		i++;
	}
	*a = sign * res;
	return (str[i] ? 0 : 1);
}
