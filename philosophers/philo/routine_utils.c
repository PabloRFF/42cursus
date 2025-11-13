/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:57:04 by pablrome          #+#    #+#             */
/*   Updated: 2025/10/16 16:23:24 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	lock_and_print(pthread_mutex_t *m, t_philo *philo)
{
	pthread_mutex_lock(m);
	print_action(philo->rules, philo->id, "has taken a fork");
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		lock_and_print(philo->r_fork, philo);
		lock_and_print(philo->l_fork, philo);
	}
	else
	{
		lock_and_print(philo->l_fork, philo);
		lock_and_print(philo->r_fork, philo);
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_eat(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	take_forks(philo);
	if (check_end(rules))
	{
		release_forks(philo);
		return ;
	}
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = timestamp();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_action(rules, philo->id, "is eating");
	ms_sleep(rules->time_eat);
	release_forks(philo);
}

int	check_end(t_rules *rules)
{
	int	end;

	pthread_mutex_lock(&rules->state_lock);
	end = rules->someone_died || rules->all_ate;
	pthread_mutex_unlock(&rules->state_lock);
	return (end);
}
