#include "philo.h"

void take_forks(t_philo *person)
{
    pthread_mutex_lock(person->fork_left);
    display("has taken a fork", person);
    pthread_mutex_lock(person->fork_right);
    display("has taken a fork", person);
}

void drop_forks(t_philo *person)
{
    pthread_mutex_unlock(person->fork_left);
    pthread_mutex_unlock(person->fork_right);
}

void eat(t_philo *person)
{
    display("is eating", person);
    usleep(general.time_eat * 1000);
    person->t_life += general.time_die;
    person->meals += 1;
}

void _sleep(t_philo *person)
{
    display("is sleeping", person);
    usleep(general.time_sleep * 1000);
}

void death(t_philo *person)
{
    person->is_alive = false;
    pthread_mutex_lock(&general.display);
    printf("%lu %d died\n", timestamp() - person->t_born, person->num);
    pthread_mutex_unlock(&general.is_on);
}