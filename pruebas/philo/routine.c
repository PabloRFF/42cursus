#include "philo.h"

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_action(philo->rules, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_action(philo->rules, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_action(philo->rules, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_action(philo->rules, philo->id, "has taken a fork");
	}
}

static void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;
	t_rules	*rules = philo->rules;

	if (philo->id % 2 == 0) // 🔑 Evita que todos arranquen a la vez
		usleep(3500);

	while (!rules->someone_died)
	{
		take_forks(philo);

		print_action(rules, philo->id, "is eating");
		philo->last_meal = timestamp();
		ms_sleep(rules->time_eat);
		philo->meals_eaten++;

		release_forks(philo);

		print_action(rules, philo->id, "is sleeping");
		ms_sleep(rules->time_sleep);

		print_action(rules, philo->id, "is thinking");
	}
	return (NULL);
}
