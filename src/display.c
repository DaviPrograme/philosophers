/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display(char *string, t_philo *person)
{
	pthread_mutex_lock(&g_eneral.display);
	if (person->is_alive && !g_eneral.a_philo_died)
		printf("%lu %d %s\n", timestamp() - person->t_born, person->num, string);
	pthread_mutex_unlock(&g_eneral.display);
}
