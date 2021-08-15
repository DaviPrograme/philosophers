#include "philo.h"

void display(char *string, t_philo *person)
{
    pthread_mutex_lock(&general.display);
    if (person->is_alive)
        printf("%lu %d %s\n", timestamp() - person->t_born, person->num, string);
    pthread_mutex_unlock(&general.display);
}