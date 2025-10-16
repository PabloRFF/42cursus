#include "philo.h"

static void	apply_stagger(t_philo *philo, t_rules *rules)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	else
	{
		if (rules->nb_philos % 2 != 0 && philo->id > rules->nb_philos / 2)
			usleep(rules->time_eat * 900);
	}
}

static void	handle_single_philo(t_philo *philo, t_rules *rules)
{
	pthread_mutex_lock(philo->l_fork);
	print_action(rules, philo->id, "has taken a fork");
	ms_sleep(rules->time_die);
	print_action(rules, philo->id, "died");
	pthread_mutex_lock(&rules->state_lock);
	rules->someone_died = 1;
	pthread_mutex_unlock(&rules->state_lock);
	pthread_mutex_unlock(philo->l_fork);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *)arg;
	rules = philo->rules;
	apply_stagger(philo, rules);
	if (rules->nb_philos == 1)
	{
		handle_single_philo(philo, rules);
		return (NULL);
	}
	while (1)
	{
		if (check_end(rules))
			break ;
		philo_eat(philo);
		print_action(rules, philo->id, "is sleeping");
		ms_sleep(rules->time_sleep);
		print_action(rules, philo->id, "is thinking");
	}
	return (NULL);
}
