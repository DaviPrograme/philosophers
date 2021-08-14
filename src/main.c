#include "philo.h"

int main(int argc, char **argv)
{
    if (argc - 1 < 4 || argc - 1 > 5)
        error(1);
    if (!(check_they_are_valid_numbers(argv)))
        error(2);
    init_globals(argc, argv);
    start_meeting();
    pthread_mutex_lock(&general.is_on);
    return 0;
}