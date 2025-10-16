#include "philo.h"

void	cleanup(t_rules *rules)
{
	int	i;

	pthread_mutex_destroy(&rules->print_lock);
	pthread_mutex_destroy(&rules->state_lock);
	i = -1;
	while (++i < rules->nb_philos)
		pthread_mutex_destroy(&rules->forks[i]);
	i = -1;
	while (++i < rules->nb_philos)
		pthread_mutex_destroy(&rules->philos[i].meal_mutex);
	free(rules->forks);
	free(rules->philos);
}
