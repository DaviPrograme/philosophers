#include "philo.h"

void init_philos(int num_philos)
{
    philos = (t_philo *)malloc(sizeof(t_philo) * num_philos);
    if (!philos)
        error(4);
    while (--num_philos >= 0)
    {
        philos[num_philos].num = num_philos + 1;
        philos[num_philos].is_alive = true;
        philos[num_philos].t_born = 0;
        philos[num_philos].t_life = 0;
        philos[num_philos].meals = 0;
        philos[num_philos].fork_left = &general.forks[num_philos];
        philos[num_philos].fork_right = &general.forks[(num_philos + 1) % general.n_philos];
    }
}

void init_general_infos(char **args, int count_args)
{
    unsigned int count_philos;

    general.n_philos = atoi(args[1]);
    general.time_die = atoi(args[2]);
    general.time_eat = atoi(args[3]);
    general.time_sleep = atoi(args[4]);
    general.a_philo_died = false;
    general.opt_eat = false;
    general.num_eat = 0;
    if (count_args == 5)
    {
        general.opt_eat = true;
        general.num_eat = atoi(args[5]);
    }
    general.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * general.n_philos);
    if (!general.forks)
        error(3);
    count_philos = -1;
    while (++count_philos < general.n_philos)
        pthread_mutex_init(&general.forks[count_philos], NULL);
    pthread_mutex_init(&general.display, NULL);
}

void init_globals(int argc, char **args)
{
    init_general_infos(args, argc - 1);
    init_philos(general.n_philos);
}
