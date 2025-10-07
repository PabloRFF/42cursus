#include "philo.h"

/* time in ms since epoch */
long long get_timestamp_ms(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL);
}

/* ms since simulation start */
long long get_now_time(t_table *table)
{
	return get_timestamp_ms() - table->start_sim;
}

/* sleep but wake periodically and exit early if simulation ended */
void philo_sleep(t_table *table, int time_ms)
{
	long long end = get_timestamp_ms() + time_ms;
	while (get_timestamp_ms() < end)
	{
		if (table->end_sim)
			break;
		usleep(100); /* 100 µs granularity */
	}
}

/* safe print: allow DIED to be printed even if end_sim true (monitor prints DIED directly) */
void write_status(const char *status, t_philo *philo)
{
	t_table *table = philo->table;
	long long ts;

	pthread_mutex_lock(&table->write_mtx);
	ts = get_now_time(table);
	if (!table->end_sim)
		printf("%lld %d %s\n", ts, philo->id, status);
	pthread_mutex_unlock(&table->write_mtx);
}

/* utility: check if all philosophers ate must_eat (not used directly here) */
int all_philos_ate(t_table *table)
{
	if (table->must_eat <= 0) return 0;
	for (int i = 0; i < table->philos_nb; i++)
	{
		pthread_mutex_lock(&table->philos[i]->philo_mutex);
		if (table->philos[i]->meals < table->must_eat)
		{
			pthread_mutex_unlock(&table->philos[i]->philo_mutex);
			return 0;
		}
		pthread_mutex_unlock(&table->philos[i]->philo_mutex);
	}
	return 1;
}

int is_simulation_end(t_table *table)
{
	return table->end_sim;
}

/* small reimplementations */
void *ft_calloc(size_t nmemb, size_t size)
{
	void *p;
	size_t total = nmemb * size;
	p = malloc(total);
	if (!p) return NULL;
	memset(p, 0, total);
	return p;
}

long ft_atol(const char *str)
{
	long r = 0;
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return r;
}

int ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i]) return (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (i < n)
		return (unsigned char)s1[i] - (unsigned char)s2[i];
	return 0;
}
