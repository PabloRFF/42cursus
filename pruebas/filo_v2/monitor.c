#include "philo.h"

void	*monitor_routine(void *arg)
{
	t_rules	*rules = (t_rules *)arg;
	int		i;
	int		finished;

	while (1)
	{
		/* comprobar flags globales rápido */
		pthread_mutex_lock(&rules->state_lock);
		if (rules->someone_died || rules->all_ate)
		{
			pthread_mutex_unlock(&rules->state_lock);
			break;
		}
		pthread_mutex_unlock(&rules->state_lock);

		finished = 0;
		i = -1;
		while (++i < rules->nb_philos)
		{
			/* leer last_meal y meals_eaten bajo meal_mutex */
			pthread_mutex_lock(&rules->philos[i].meal_mutex);
			long long last = rules->philos[i].last_meal;
			int eaten = rules->philos[i].meals_eaten;
			pthread_mutex_unlock(&rules->philos[i].meal_mutex);

			/* si ha pasado el tiempo de vida -> declarar muerte */
			if (timestamp() - last > rules->time_die)
			{
				/* bloqueamos en el mismo orden que print_action: state_lock -> print_lock */
				pthread_mutex_lock(&rules->state_lock);
				if (!rules->someone_died) /* doble comprobación para evitar prints duplicados */
				{
					rules->someone_died = 1;
					pthread_mutex_lock(&rules->print_lock);
					printf("%lld %d died\n", timestamp() - rules->start_time, rules->philos[i].id);
					pthread_mutex_unlock(&rules->print_lock);
				}
				pthread_mutex_unlock(&rules->state_lock);
				return (NULL);
			}
			if (rules->nb_meals > 0 && eaten >= rules->nb_meals)
				finished++;
		}
		/* si todos comieron el mínimo */
		if (rules->nb_meals > 0 && finished == rules->nb_philos)
		{
			pthread_mutex_lock(&rules->state_lock);
			rules->all_ate = 1;
			pthread_mutex_unlock(&rules->state_lock);
			return (NULL);
		}
		/* chequear con alta frecuencia para tests justos */
		usleep(100); /* 100 µs */
	}
	return (NULL);
}
