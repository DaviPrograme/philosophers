#include "philo.h"


void *create_thread_philo(void *philosopher)
{
    t_philo *philo;
    pthread_t mutex;

    philo = (t_philo *)philosopher;
    philo->t_born = timestamp();
    philo->t_life = philo->t_born + general.time_die;
    pthread_create(&mutex, NULL, monitor, philo);
    pthread_detach(mutex);
    while (philo->is_alive)
    {
        take_forks(philo);
        eat(philo);
        drop_forks(philo);
        _sleep(philo);
    }
    return NULL;
}

void create_philos(t_philo *all_philos, int num_philos)
{
    if (--num_philos < 0)
        return;
    pthread_create(&all_philos[num_philos].thread, NULL, create_thread_philo, &all_philos[num_philos]);
    pthread_detach(all_philos[num_philos].thread);
    usleep(50);
    create_philos(philos, num_philos);
}