#include "philo.h"

int	init_all(t_rules *rules, int argc, char **argv)
{
	int	i;

	rules->nb_philos = ft_atoi(argv[1]);
	rules->time_die = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	rules->nb_meals = (argc == 6) ? ft_atoi(argv[5]) : -1;
	rules->someone_died = 0;
	rules->start_time = timestamp();
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philos);
	rules->philos = malloc(sizeof(t_philo) * rules->nb_philos);
	if (!rules->forks || !rules->philos)
		return (0);
	pthread_mutex_init(&rules->print_lock, NULL);
	i = -1;
	while (++i < rules->nb_philos)
		pthread_mutex_init(&rules->forks[i], NULL);
	i = -1;
	while (++i < rules->nb_philos)
	{
		rules->philos[i].id = i + 1;
		rules->philos[i].meals_eaten = 0;
		rules->philos[i].last_meal = rules->start_time;
		rules->philos[i].l_fork = &rules->forks[i];
		rules->philos[i].r_fork = &rules->forks[(i + 1) % rules->nb_philos];
		rules->philos[i].rules = rules;
	}
	return (1);
}
