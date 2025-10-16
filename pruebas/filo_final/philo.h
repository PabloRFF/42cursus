#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_rules t_rules;

typedef struct s_philo
{
	int             id;
	int             meals_eaten;
	long long       last_meal;
	pthread_t       thread;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	pthread_mutex_t meal_mutex; // protege last_meal y meals_eaten
	t_rules         *rules;
}   t_philo;

typedef struct s_rules
{
	int             nb_philos;
	int             time_die;
	int             time_eat;
	int             time_sleep;
	int             nb_meals;       // opcional
	int             someone_died;
	int             all_ate;
	long long       start_time;
	pthread_mutex_t *forks;
	pthread_mutex_t print_lock;
	pthread_mutex_t state_lock; // protege someone_died y all_ate
	t_philo         *philos;
}   t_rules;

// init.c
int         init_all(t_rules *rules, int argc, char **argv);
int			ft_atoi(char *str);

// routine_utils.c
void        take_forks(t_philo *philo);
void        release_forks(t_philo *philo);
void        philo_eat(t_philo *philo);
int         check_end(t_rules *rules);

// routine.c
void		*philo_routine(void *arg);

// monitor.c
void		*monitor_routine(void *arg);

// utils.c
long long	timestamp(void);
void		ms_sleep(long long ms);
void		print_action(t_rules *rules, int id, char *msg);
int			check_args_numbers(int argc, char **argv);

// cleanup.c
void		cleanup(t_rules *rules);

#endif

