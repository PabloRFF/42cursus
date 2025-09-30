#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		i;
	pthread_t monitor;

	if (argc != 5 && argc != 6)
	{
		printf("Uso: %s nb_philos time_die time_eat time_sleep [nb_meals]\n", argv[0]);
		return (1);
	}
	if (!init_all(&rules, argc, argv))
		return (1);
	i = -1;
	while (++i < rules.nb_philos)
		pthread_create(&rules.philos[i].thread, NULL, philo_routine, &rules.philos[i]);
	pthread_create(&monitor, NULL, monitor_routine, &rules);
	i = -1;
	while (++i < rules.nb_philos)
		pthread_join(rules.philos[i].thread, NULL);
	pthread_join(monitor, NULL);
	cleanup(&rules);
	return (0);
}
