#include "philo.h"
#include <string.h>

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/* sleep más responsivo: duerme en trozos y no se queda muy lejos del objetivo */
void	ms_sleep(long long ms)
{
	long long	end;

	end = timestamp() + ms;
	while (timestamp() < end)
	{
		long long rem = end - timestamp();
		if (rem > 10)
			usleep(500); /* duerme 0.5 ms cuando queda mucho */
		else
			usleep(100); /* dormimos porciones cortas al final */
	}
}

/* print_action sigue el mismo orden: state_lock -> print_lock */
void	print_action(t_rules *rules, int id, char *msg)
{
	pthread_mutex_lock(&rules->state_lock);
	/* Si ya hay muerte o fin, no imprimimos (salvo que queramos forzar) */
	if (!rules->someone_died && !rules->all_ate)
	{
		pthread_mutex_lock(&rules->print_lock);
		printf("%lld %d %s\n", timestamp() - rules->start_time, id, msg);
		pthread_mutex_unlock(&rules->print_lock);
	}
	pthread_mutex_unlock(&rules->state_lock);
}
