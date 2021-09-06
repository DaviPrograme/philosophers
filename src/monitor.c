#include "philo.h"

bool check_philo_is_died(t_philo *person)
{
    if (timestamp() > (long)person->t_life)
        return (true);
    return (false);
}

void *monitor(void *person)
{
    t_philo *philo;

    philo = (t_philo *)person;
    while (philo->is_alive)
    {
        if (check_philo_is_died(philo))
        {
            death(philo);
        }
    }
    return NULL;
}
