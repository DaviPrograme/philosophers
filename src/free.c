#include "philo.h"

void free_memory(void)
{
    free(philos);
    free(general.forks);
}