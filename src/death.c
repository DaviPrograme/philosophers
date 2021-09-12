/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_all_philos(void)
{
	unsigned int	x;

	x = 0;
	while (x < g_eneral.n_philos)
	{
		g_philos[x].is_alive = false;
		++x;
	}
}

void	death(t_philo *person)
{
	person->is_alive = false;
	pthread_mutex_lock(&g_eneral.display);
	if (!g_eneral.a_philo_died)
		printf("%lu %d died\n", timestamp() - person->t_born, person->num);
	g_eneral.a_philo_died = true;
	kill_all_philos();
	pthread_mutex_unlock(&g_eneral.display);
}
