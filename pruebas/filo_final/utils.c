#include "philo.h"
#include <string.h>

int check_args_numbers(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while(i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (argv[i][j] == '\0') // string vacio o solo signo
			return (0);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ms_sleep(long long ms)
{
	long long	end;
	long long	rem;

	end = timestamp() + ms;
	while (timestamp() < end)
	{
		rem = end - timestamp();
		if (rem > 10)
			usleep(500);
		else
			usleep(100);
	}
}

void	print_action(t_rules *rules, int id, char *msg)
{
	pthread_mutex_lock(&rules->state_lock);
	if (!rules->someone_died && !rules->all_ate)
	{
		pthread_mutex_lock(&rules->print_lock);
		printf("%lld %d %s\n", timestamp() - rules->start_time, id, msg);
		pthread_mutex_unlock(&rules->print_lock);
	}
	pthread_mutex_unlock(&rules->state_lock);
}
