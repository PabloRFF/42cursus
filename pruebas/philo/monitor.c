#include "philo.h"

void    *monitor_routine(void *arg)
{
    t_rules *rules = (t_rules *)arg;
    int     i;
    int     finished;

    while (!rules->someone_died)
    {
        i = -1;
        finished = 0;
        while (++i < rules->nb_philos)
        {
            // 👀 Caso 1: alguien muere
            if (timestamp() - rules->philos[i].last_meal > rules->time_die)
            {
                print_action(rules, rules->philos[i].id, "died");
                rules->someone_died = 1;
                return (NULL);
            }
            // 👀 Caso 2: cuenta de comidas
            if (rules->nb_meals > 0 &&
                rules->philos[i].meals_eaten >= rules->nb_meals)
                finished++;
        }
        // si TODOS han comido lo suficiente → parar
        if (rules->nb_meals > 0 && finished == rules->nb_philos)
        {
            rules->someone_died = 1; // fuerza a que salgan los bucles
            return (NULL);
        }
        usleep(200);
    }
    return (NULL);
}
