/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(int num_philos)
{
	g_philos = (t_philo *)malloc(sizeof(t_philo) * num_philos);
	if (!g_philos)
		error(4);
	while (--num_philos >= 0)
	{
		g_philos[num_philos].num = num_philos + 1;
		g_philos[num_philos].is_alive = true;
		g_philos[num_philos].t_born = 0;
		g_philos[num_philos].t_life = 0;
		g_philos[num_philos].meals = 0;
		g_philos[num_philos].fork_left = &g_eneral.forks[num_philos];
		g_philos[num_philos].fork_right = &g_eneral.forks[(num_philos + 1) % \
										g_eneral.n_philos];
	}
}

void	init_general_infos(char **args, int count_args)
{
	unsigned int	count_philos;

	g_eneral.n_philos = atoi(args[1]);
	g_eneral.time_die = atoi(args[2]);
	g_eneral.time_eat = atoi(args[3]);
	g_eneral.time_sleep = atoi(args[4]);
	g_eneral.a_philo_died = false;
	g_eneral.opt_eat = false;
	g_eneral.num_eat = 0;
	if (count_args == 5)
	{
		g_eneral.opt_eat = true;
		g_eneral.num_eat = atoi(args[5]);
	}
	g_eneral.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
			g_eneral.n_philos);
	if (!g_eneral.forks)
		error(3);
	count_philos = -1;
	while (++count_philos < g_eneral.n_philos)
		pthread_mutex_init(&g_eneral.forks[count_philos], NULL);
	pthread_mutex_init(&g_eneral.display, NULL);
}

void	init_globals(int argc, char **args)
{
	init_general_infos(args, argc - 1);
	init_philos(g_eneral.n_philos);
}
