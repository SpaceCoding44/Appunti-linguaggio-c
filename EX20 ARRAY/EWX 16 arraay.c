#include <unistd.h>

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putstr(char *str) {
    while (*str) {
        ft_putchar(*str);
        str++;
    }
}

void ft_putnbr(int nb) {
    if (nb == -2147483648) {
        ft_putstr("-2147483648");
        return;
    }
    
    if (nb < 0) {
        ft_putchar('-');
        nb = -nb;
    }
    
    if (nb >= 10) {
        ft_putnbr(nb / 10);
    }
    ft_putchar((nb % 10) + '0');
}

int main() {
    /*
     * ARRAY: Collezione di elementi dello stesso tipo
     * - Dimensione fissa
     * - Accesso tramite indice (partendo da 0)
     */
    
    // Array di interi con inizializzazione
    int numbers[] = {10, 20, 30, 40, 50};
    
    // Array di caratteri (non è una stringa perché manca il terminatore nullo)
    char grades[] = {'A', 'B', 'C', 'D', 'F'};
    
    // Stringa (array di char con terminatore nullo '\0' automatico)
    char name[] = "Bro Code";
    
    // Stampa array di numeri
    ft_putstr("Array numbers: ");
    int i = 0;
    while (i < 5) {  // Corretto: l'array numbers ha 5 elementi, non 6
        ft_putnbr(numbers[i]);
        if (i < 4) ft_putchar(' ');
        i++;
    }
    ft_putchar('\n');

    // Stampa l'array grades usando while
    ft_putstr("Stampa array grades: ");
    i = 0;  // Reset dell'indice
    while (i < 5) {
        ft_putchar(grades[i]);
        if (i < 4)
            ft_putchar(' ');
        i++;
    }
    ft_putchar('\n');
    
    // Stampa la stringa name
    ft_putstr("Stampa stringa name: ");
    ft_putstr(name);
    ft_putchar('\n');

    return 0;
}