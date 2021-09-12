/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int letra)
{
	if (letra >= 48 && letra <= 57)
		return (1);
	return (0);
}

bool	check_they_are_valid_numbers(char **argv)
{
	int	line;
	int	colum;

	line = 0;
	while (argv[++line])
	{
		colum = -1;
		while (argv[line][++colum])
		{
			if (!(ft_isdigit(argv[line][colum])))
				return (false);
		}
	}
	return (true);
}
