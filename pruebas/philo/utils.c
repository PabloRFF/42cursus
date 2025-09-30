#include "philo.h"

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ms_sleep(long long ms)
{
	long long	start = timestamp();
	while (timestamp() - start < ms)
		usleep(500);
}

void	print_action(t_rules *rules, int id, char *msg)
{
	pthread_mutex_lock(&rules->print_lock);
	if (!rules->someone_died)
		printf("%lld %d %s\n", timestamp() - rules->start_time, id, msg);
	pthread_mutex_unlock(&rules->print_lock);
}
int	ft_atoi(const char *str)
{
	long	n = 0;
	while (*str >= '0' && *str <= '9')
		n = n * 10 + (*str++ - '0');
	return ((int)n);
}
