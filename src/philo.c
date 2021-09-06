/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*create_thread_philo(void *philosopher)
{
	t_philo		*philo;
	pthread_t	mutex;

	philo = (t_philo *)philosopher;
	philo->t_born = timestamp();
	philo->t_life = philo->t_born + general.time_die;
	pthread_create(&mutex, NULL, monitor, philo);
	while (philo->is_alive && !general.a_philo_died)
	{
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		if (general.opt_eat && philo->meals >= general.num_eat)
			break ;
		_sleep(philo);
		think(philo);
	}
	philo->is_alive = false;
	pthread_join(mutex, NULL);
	return (NULL);
}

void	create_philos(t_philo *all_philos, int num_philos)
{
	int	count;

	count = num_philos - 1;
	while (count >= 0)
	{
		pthread_create(&all_philos[count].thread, \
				NULL, create_thread_philo, &all_philos[count]);
		usleep(50);
		count -= 2;
	}
	count = num_philos - 2;
	while (count >= 0)
	{
		pthread_create(&all_philos[count].thread, \
				NULL, create_thread_philo, &all_philos[count]);
		usleep(50);
		count -= 2;
	}
	count = -1;
	while (++count < (int)general.n_philos)
		pthread_join(all_philos[count].thread, NULL);
}
