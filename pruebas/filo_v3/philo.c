#include "philo.h"

/* wrapper - each philo starts and waits until threads_rdy set */
void *philo_pre_routine(void *data)
{
	t_philo *philo = (t_philo *)data;
	t_table *table = philo->table;

	/* wait until main signals start (threads_rdy) */
	while (!table->threads_rdy)
		usleep(50);

	/* initialize last_meal to start time */
	pthread_mutex_lock(&philo->philo_mutex);
	philo->last_meal = get_timestamp_ms();
	pthread_mutex_unlock(&philo->philo_mutex);

	/* run main routine */
	philo_routine(philo);
	return NULL;
}

static void take_forks_order(pthread_mutex_t *first, pthread_mutex_t *second, t_philo *philo)
{
	pthread_mutex_lock(first);
	write_status(FORK_1, philo);
	pthread_mutex_lock(second);
	write_status(FORK_2, philo);
}

static void release_forks(pthread_mutex_t *first, pthread_mutex_t *second)
{
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
}

void philo_routine(t_philo *philo)
{
	t_table *table = philo->table;
	pthread_mutex_t *first;
	pthread_mutex_t *second;

	/* decide order to avoid classical deadlock: odd pick left then right, even pick right then left */
	if (philo->id % 2 == 0)
	{
		first = philo->left_fork;
		second = &philo->right_fork;
	}
	else
	{
		first = &philo->right_fork;
		second = philo->left_fork;
	}
    

	/* stagger start to avoid starvation/death in odd philosopher count */
    if (table->philos_nb % 2 == 0)
    {
        if (philo->id % 2 == 0)
            usleep(1000); /* pares: pequeño retraso */
    }
    else
    {
        if (philo->id % 2 == 0)
            usleep(1000);
        else if (philo->id > table->philos_nb / 2)
            philo_sleep(table, table->time_eat);
    }

	/* if single philosopher special case */
	if (table->philos_nb == 1)
	{
		pthread_mutex_lock(&philo->right_fork);
		write_status(FORK_1, philo);
		philo_sleep(table, table->time_die);
		write_status(DIED, philo);
		table->end_sim = true;
		pthread_mutex_unlock(&philo->right_fork);
		return;
	}

	while (!table->end_sim)
	{
		/* take forks */
		take_forks_order(first, second, philo);

		/* update last_meal and meals under philo_mutex */
		pthread_mutex_lock(&philo->philo_mutex);
		philo->last_meal = get_timestamp_ms();
		philo->meals++;
		pthread_mutex_unlock(&philo->philo_mutex);

		/* eat */
		write_status(EATING, philo);
		philo_sleep(table, table->time_eat);

		/* release forks */
		release_forks(first, second);

		/* leave table and sleep */
		write_status(SLEEPING, philo);
		philo_sleep(table, table->time_sleep);

		/* think */
		write_status(THINKING, philo);
	}
}
