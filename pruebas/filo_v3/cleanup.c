#include "philo.h"

void destroy_mutexes(t_table *table)
{
	if (!table) return;
	pthread_mutex_destroy(&table->write_mtx);
	pthread_mutex_destroy(&table->table_mutex);
	for (int i = 0; i < table->philos_nb; i++)
	{
		pthread_mutex_destroy(&table->philos[i]->right_fork);
		pthread_mutex_destroy(&table->philos[i]->philo_mutex);
	}
}

void cleanup(t_table *table)
{
	if (!table) return;
	destroy_mutexes(table);
	for (int i = 0; i < table->philos_nb; i++)
	{
		free(table->philos[i]);
	}
	free(table->philos);
	free(table);
}
