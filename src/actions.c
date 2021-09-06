#include "philo.h"

void take_forks(t_philo *person)
{
    pthread_mutex_lock(person->fork_left);
    display("has taken a fork", person);
    if (general.n_philos > 1)
    {
        pthread_mutex_lock(person->fork_right);
        display("has taken a fork", person);
    }
    else
        usleep(general.time_die * 1000 * 2);
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
    if (!general.a_philo_died)
        person->t_life += general.time_die;
    person->meals += 1;
}

void _sleep(t_philo *person)
{
    display("is sleeping", person);
    usleep(general.time_sleep * 1000);
}

void think(t_philo *person)
{
    display("is thinking", person);
}

void kill_all_philos(void)
{
    unsigned int x;

    x = 0;
    while (x < general.n_philos)
    {
        philos[x].is_alive = false;
        ++x;
    }
}

void death(t_philo *person)
{
    person->is_alive = false;
    pthread_mutex_lock(&general.display);
    if (!general.a_philo_died)
        printf("%lu %d died\n", timestamp() - person->t_born, person->num);
    general.a_philo_died = true;
    kill_all_philos();
    pthread_mutex_unlock(&general.display);
    // pthread_mutex_unlock(&general.is_on);
}