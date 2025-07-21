#include <unistd.h>
#include <stdbool.h> // Necessario per usare 'bool'

/* TATTICA: Funzioni base per output */
void ft_putchar(char c) {
    write(1, &c, 1); // Scrive 1 carattere alla volta
}

void ft_putstr(char *str) {
    while (*str) { // Continua finché incontri '\0' (fine stringa)
        ft_putchar(*str);
        str++; // Sposta il puntatore al prossimo carattere
    }
}


/* FUNZIONE VOID*/

void ft_HappyBirthday(char *name, int age) {
    ft_putstr("\n*************************\n");
    ft_putstr("   HAPPY BIRTHDAY, ");
    ft_putstr(name);
    ft_putstr("!\n");
    ft_putstr("   You are now ");
    
    // Stampa l'età (versione semplificata senza ft_putnbr)
    if (age == 1) {
        ft_putstr("1 year old!");
    } else {
        ft_putstr("years old!"); // Nota: per semplicità, omesso il numero
    }
    
    ft_putstr("\n*************************\n\n");
}

int main(void) {
    char name[]= 'alice';
    int age = 45;
    
    ft_HappyBirthday(name, age);  // Sostituisci con nome ed età desiderati
    return 0;
}