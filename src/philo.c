#include "philo.h"


void *create_thread_philo(void *philosopher)
{
    t_philo *philo;

    philo = (t_philo *)philosopher;
    while (philo->is_alive)
    {
        take_forks(philo->fork_left, philo->fork_right);
        eat(philo->num, philo->thread, &philo->meals);
        drop_forks(philo->fork_left, philo->fork_right);
        sleep();
    }
    return NULL;
}

void create_philos(t_philo *all_philos, int num_philos)
{
    if (--num_philos < 0)
        return;
    pthread_create(&all_philos[num_philos].thread, NULL, create_thread_philo, &all_philos[num_philos]);
    pthread_detach(all_philos[num_philos].thread);
    create_philos(philos, num_philos);
}