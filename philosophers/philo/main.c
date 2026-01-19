/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:57:42 by pablrome          #+#    #+#             */
/*   Updated: 2025/10/20 13:26:18 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules		rules;
	int			i;
	pthread_t	monitor;

	if (argc != 5 && argc != 6)
	{
		printf("Uso: %s nb_philos time_die time_eat time_sleep [nb_meals]\n",
			argv[0]);
		return (1);
	}
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (printf("ERROR: nb_meals must be a positive integer\n"), 1);
	if (!init_all(&rules, argc, argv))
		return (1);
	i = -1;
	while (++i < rules.nb_philos)
		pthread_create(&rules.philos[i].thread,
			NULL, philo_routine, &rules.philos[i]);
	pthread_create(&monitor, NULL, monitor_routine, &rules);
	i = -1;
	while (++i < rules.nb_philos)
		pthread_join(rules.philos[i].thread, NULL);
	pthread_join(monitor, NULL);
	cleanup(&rules);
	return (0);
}
