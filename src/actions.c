#include "philo.h"

void take_forks(pthread_mutex_t *fork_left, pthread_mutex_t *fork_right)
{
    pthread_mutex_lock(fork_left);
    pthread_mutex_lock(fork_right);
}

void drop_forks(pthread_mutex_t *fork_left, pthread_mutex_t *fork_right)
{
    pthread_mutex_unlock(fork_left);
    pthread_mutex_unlock(fork_right);
}

void eat(unsigned int num, pthread_t thread, unsigned int *meals)
{
    pthread_mutex_lock(&general.display);
    printf("NUMERO: %d  PROCESSO: %lu  MEALS: %d\n", num, thread, ++meals[0]);
    pthread_mutex_unlock(&general.display);
}

void sleep(void)
{
    int x;

    x = 0;
    while (x < 100000)
        ++x;
}


