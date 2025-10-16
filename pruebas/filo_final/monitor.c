#include "philo.h"

static int	check_end_flags(t_rules *rules)
{
	int	end;

	pthread_mutex_lock(&rules->state_lock);
	end = rules->someone_died || rules->all_ate;
	pthread_mutex_unlock(&rules->state_lock);
	return (end);
}

static void	declare_death(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(&rules->state_lock);
	if (!rules->someone_died)
	{
		rules->someone_died = 1;
		pthread_mutex_lock(&rules->print_lock);
		printf("%lld %d died\n",
			timestamp() - rules->start_time, philo->id);
		pthread_mutex_unlock(&rules->print_lock);
	}
	pthread_mutex_unlock(&rules->state_lock);
}

static int	check_phi_stat(t_rules *rules, t_philo *philo, int *finished)
{
	long long	last;
	int			eaten;

	pthread_mutex_lock(&philo->meal_mutex);
	last = philo->last_meal;
	eaten = philo->meals_eaten;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (timestamp() - last > rules->time_die)
	{
		declare_death(rules, philo);
		return (1);
	}
	if (rules->nb_meals > 0 && eaten >= rules->nb_meals)
		(*finished)++;
	return (0);
}

static int	check_all_ate(t_rules *rules, int finished)
{
	if (rules->nb_meals > 0 && finished == rules->nb_philos)
	{
		pthread_mutex_lock(&rules->state_lock);
		rules->all_ate = 1;
		pthread_mutex_unlock(&rules->state_lock);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_rules	*rules;
	int		i;
	int		finished;

	rules = (t_rules *)arg;
	while (1)
	{
		if (check_end_flags(rules))
			break ;
		finished = 0;
		i = -1;
		while (++i < rules->nb_philos)
		{
			if (check_phi_stat(rules, &rules->philos[i], &finished))
				return (NULL);
		}
		if (check_all_ate(rules, finished))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
