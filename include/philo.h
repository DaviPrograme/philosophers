#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_philosophers
{
    unsigned int num;
    unsigned long time_die;
    unsigned long time_sleep;
    unsigned int meals;
    pthread_mutex_t *fork_left;
    pthread_mutex_t *fork_right;
    pthread_t thread;
    bool is_alive;
} t_philo;

t_philo *philos;

struct s_general_infos
{
    pthread_mutex_t is_on;
    pthread_mutex_t *forks;
    pthread_mutex_t display;
    unsigned int n_philos;
    unsigned long int time_die;
    unsigned long int time_eat;
    unsigned long int time_sleep;
    bool opt_eat;
    unsigned int num_eat;
} general;


void error(int id_erro);
bool check_they_are_valid_numbers(char **argv);
void init_globals(int argc, char **args);
void start_meeting(void);
int	ft_atoi(const char *fr);
void *start_thread_philo(void *num_philo);
void create_philos(t_philo *philos, int num_philos);
void take_forks(pthread_mutex_t *fork_left, pthread_mutex_t *fork_right);
void eat(unsigned int num, pthread_t thread, unsigned int *meals);
void drop_forks(pthread_mutex_t *fork_left, pthread_mutex_t *fork_right);
void sleep(void);
#endif