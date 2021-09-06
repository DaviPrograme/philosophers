/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_philo_is_died(t_philo *person)
{
	if (timestamp() > (long)person->t_life)
		return (true);
	return (false);
}

void	*monitor(void *person)
{
	t_philo	*philo;

	philo = (t_philo *)person;
	while (philo->is_alive)
	{
		if (check_philo_is_died(philo))
			death(philo);
	}
	return (NULL);
}
