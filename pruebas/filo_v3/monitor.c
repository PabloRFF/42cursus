#include "philo.h"

void *monitoring(void *data)
{
	t_table *table = (t_table *)data;
	int i;

	while (!table->end_sim)
	{
		for (i = 0; i < table->philos_nb; i++)
		{
			t_philo *p = table->philos[i];
			pthread_mutex_lock(&p->philo_mutex);
			long long last = p->last_meal;
			pthread_mutex_unlock(&p->philo_mutex);

			/* check death */
			if (get_timestamp_ms() - last > table->time_die)
			{
				/* set end_sim and print died with write_mtx locked to avoid prints after */
				pthread_mutex_lock(&table->write_mtx);
				table->end_sim = true;
				printf("%lld %d %s\n", get_now_time(table), p->id, DIED);
				pthread_mutex_unlock(&table->write_mtx);
				return NULL;
			}
		}

		/* if must_eat defined, check if all ate enough */
		if (table->must_eat > 0)
		{
			int all = 1;
			for (i = 0; i < table->philos_nb; i++)
			{
				pthread_mutex_lock(&table->philos[i]->philo_mutex);
				if (table->philos[i]->meals < table->must_eat)
					all = 0;
				pthread_mutex_unlock(&table->philos[i]->philo_mutex);
				if (!all) break;
			}
			if (all)
			{
				table->end_sim = true;
				return NULL;
			}
		}
		usleep(100); /* check frequently */
	}
	return NULL;
}
