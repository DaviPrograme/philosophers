/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *person)
{
	pthread_mutex_lock(person->fork_left);
	display("has taken a fork", person);
	if (g_eneral.n_philos > 1)
	{
		pthread_mutex_lock(person->fork_right);
		display("has taken a fork", person);
	}
	else
		usleep(g_eneral.time_die * 1000 * 2);
}

void	drop_forks(t_philo *person)
{
	pthread_mutex_unlock(person->fork_left);
	pthread_mutex_unlock(person->fork_right);
}

void	eat(t_philo *person)
{
	display("is eating", person);
	usleep(g_eneral.time_eat * 1000);
	if (!g_eneral.a_philo_died)
		person->t_life += g_eneral.time_die;
	person->meals += 1;
}

void	_sleep(t_philo *person)
{
	display("is sleeping", person);
	usleep(g_eneral.time_sleep * 1000);
}

void	think(t_philo *person)
{
	display("is thinking", person);
}
