/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:57:51 by pablrome          #+#    #+#             */
/*   Updated: 2025/10/16 15:57:52 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

static int	init_rules_values(t_rules *rules, int argc, char **argv)
{
	rules->nb_philos = ft_atoi(argv[1]);
	rules->time_die = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules->nb_meals = ft_atoi(argv[5]);
	else
		rules->nb_meals = -1;
	rules->someone_died = 0;
	rules->all_ate = 0;
	rules->start_time = timestamp();
	return (1);
}

static int	init_mutexes(t_rules *rules)
{
	int	i;

	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philos);
	rules->philos = malloc(sizeof(t_philo) * rules->nb_philos);
	if (!rules->forks || !rules->philos)
		return (0);
	pthread_mutex_init(&rules->print_lock, NULL);
	pthread_mutex_init(&rules->state_lock, NULL);
	i = -1;
	while (++i < rules->nb_philos)
		pthread_mutex_init(&rules->forks[i], NULL);
	return (1);
}

static void	init_philos(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philos)
	{
		rules->philos[i].id = i + 1;
		rules->philos[i].meals_eaten = 0;
		rules->philos[i].last_meal = rules->start_time;
		pthread_mutex_init(&rules->philos[i].meal_mutex, NULL);
		rules->philos[i].l_fork = &rules->forks[i];
		rules->philos[i].r_fork = &rules->forks[(i + 1) % rules->nb_philos];
		rules->philos[i].rules = rules;
	}
}

int	init_all(t_rules *rules, int argc, char **argv)
{
	if (!check_args_numbers(argc, argv))
	{
		printf("ERROR: Todos los argumentos deben ser enteros positivos\n");
		return (0);
	}
	if (!init_rules_values(rules, argc, argv))
		return (0);
	if (!init_mutexes(rules))
		return (0);
	init_philos(rules);
	return (1);
}
