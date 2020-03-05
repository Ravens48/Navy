/*
** EPITECH PROJECT, 2020
** EPITECH
** File description:
** navy_game_loop
*/

#include "include/my.h"


int attack_p1(navy_t *navy, int pid, int signal_1, int signal_2)
{
    int col = -1;
    int line = -1;
    char *bn_col;
    char *bn_line;
    int x;
    size_t buffer_size = 0;

printf("line %d\n, col %d\n", line, col);
    do {
        char *buffer = NULL;
        my_putstr("attack: ");
        x = getline(&buffer, &buffer_size, stdin);
        if (x == -1) {
            printf("ici ca aurait return -1\n");
            return (-1);
        }
        col = (buffer[0]) - 'A';
        line = my_getnbr(&buffer[1]) - 1;
    } while ((col < 0 || col > 8) && (line < 0 || line > 8));
    
    printf("valeur de col = %d\n", col);
    bn_col = decimal_to_binary(col);
    bn_line = decimal_to_binary(line);
    details_choice(bn_col, pid, signal_1, signal_2);
    details_choice(bn_line, pid, signal_1, signal_2);
    return (0);
}

void details_choice(char *choice, int pid, int signal_1, int signal_2)
{   
    printf("passe dans col choice \n");
    printf("nb_col :%s\n", choice);
    for (int i = 0; choice[i] != '\0'; i++) {
        printf("combien de fois ca passe ici\n");
        if (choice[i] == '0') {        
            printf("user 1 \n");
            usleep(2000);
            kill(pid, SIGUSR1);
        }
        if (choice[i] == '1') {
            printf("user 2 \n");
            usleep(2000);
            kill(pid, SIGUSR2);
        }
        pause();
    }
}

void recup_attact_details(navy_t *navy, int pid, int signal_1)
{
    int i = 0;
    int tour = 0;

    while (i < 4 && tour < 2) {
        pause();
        printf("passe dans recup attac ou pas\n");
        //envoyer a player.pid
        usleep(2000);
        if (tour == 0)
            navy->col_details[i] = global;
        if (tour == 1)
            navy->line_details[i] = global;
        i++;
        printf("signal_c : %d\n", global);
        if (i == 4) {
            i = 0;
            tour++;
        }
        kill(pid, SIGUSR1);
    }
    navy->col_details[4] = '\0';
    navy->line_details[4] = '\0';
    printf ("colonne : %s\n ligne : %s\n", navy->col_details, navy->line_details);
}

int defense(navy_t *navy, int pid, int signal_1, int signal_2)
{
    int x = 0;
    recup_attact_details(navy, pid, signal_1);
    int col_attack = binary_to_decimal(navy->col_details);
    int line_attack = binary_to_decimal(navy->line_details);
    printf("colonne recu : %d\n ligne recue : %d\n", col_attack, line_attack);
    x = hit_or_miss(navy->map_ennemy, col_attack, line_attack);
    printf("tu recois le signal ou pas ?\n");
    if (x == 2) {
        printf("normalement on touche");
        //envoie un signal pour dire si toucher ou pas toucher
       // kill(pid, signal_1);
    }
    if (x == 1) {
        printf("normalement on touche pas");
       // kill(pid, signal_2);
    }
    return (0);
}
