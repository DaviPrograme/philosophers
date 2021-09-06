#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philosophers
{
    unsigned int num;
    unsigned long t_born;
    unsigned long t_life;
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
    bool a_philo_died;
    unsigned int num_eat;
} general;


void error(int id_erro);
bool check_they_are_valid_numbers(char **argv);
void init_globals(int argc, char **args);
void start_meeting(void);
int	ft_atoi(const char *fr);
void *start_thread_philo(void *num_philo);
void create_philos(t_philo *philos, int num_philos);
void take_forks(t_philo *person);
void eat(t_philo *person);
void drop_forks(t_philo *person);
void _sleep(t_philo *person);
long timestamp(void);
void display(char *string, t_philo *person);
void death(t_philo *person);
void *monitor(void *person);
void free_memory(void);
void think(t_philo *person);
#endif