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

static void	apply_stagger(t_philo *philo, t_rules *rules)
{
	/*
	** Estrategia de stagger:
	** - Pares: pequeño delay inicial (1 ms).
	** - Impares: si el número total de filósofos es impar,
	**   escalonamos a ~la mitad de ellos con un delay ≈ time_eat.
	**
	** Así evitamos que todos los impares intenten comer a la vez
	** y uno quede siempre fuera del ciclo.
	*/
	if (philo->id % 2 == 0)
		usleep(1000);
	else if (rules->nb_philos % 2 != 0 && philo->id > rules->nb_philos / 2)
		usleep(rules->time_eat * 900); // 90% de time_eat en µs
}

void	*philo_routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;
	t_rules	*rules = philo->rules;

	apply_stagger(philo, rules);

	if (rules->nb_philos == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		print_action(rules, philo->id, "has taken a fork");
		ms_sleep(rules->time_die);
		print_action(rules, philo->id, "died");
		pthread_mutex_lock(&rules->state_lock);
		rules->someone_died = 1;
		pthread_mutex_unlock(&rules->state_lock);
		pthread_mutex_unlock(philo->l_fork);
		return (NULL);
	}

	while (1)
	{
		pthread_mutex_lock(&rules->state_lock);
		if (rules->someone_died || rules->all_ate)
		{
			pthread_mutex_unlock(&rules->state_lock);
			break;
		}
		pthread_mutex_unlock(&rules->state_lock);

		take_forks(philo);

		pthread_mutex_lock(&philo->meal_mutex);
		philo->last_meal = timestamp();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->meal_mutex);

		print_action(rules, philo->id, "is eating");
		ms_sleep(rules->time_eat);

		release_forks(philo);

		print_action(rules, philo->id, "is sleeping");
		ms_sleep(rules->time_sleep);

		print_action(rules, philo->id, "is thinking");
	}
	return (NULL);
}
