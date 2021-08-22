#include "philo.h"

void start_meeting()
{
    pthread_mutex_init(&general.is_on, NULL);
    pthread_mutex_lock(&general.is_on);
    create_philos(philos, general.n_philos - 1);
    create_philos(philos, general.n_philos - 2);
}