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

/*
 * Stampa un array 2D di interi
 * rows: numero di righe
 * cols: numero di colonne
 */
void ft_put2darray(int rows, int cols, int arr[rows][cols]) {
    int i = 0;
    while (i < rows) {
        int j = 0;
        while (j < cols) {
            ft_putnbr(arr[i][j]);
            if (j < cols - 1)
                ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

/*
Come funzionano i due cicli:

    Ciclo Esterno (while (i < rows)):

        Controlla le righe (dalla prima all'ultima).
        Per ogni riga, il ciclo interno stampa tutti i suoi elementi.
        Alla fine di ogni riga, va a capo con ft_putchar('\n').

    Ciclo Interno (while (j < cols)):

        Scorre le colonne (elementi della riga corrente).
        Stampa il valore con ft_putnbr(arr[i][j]).
        Aggiunge uno spazio dopo ogni elemento, tranne dopo l'ultimo (if (j < cols - 1)).
*/

int main() {
    /*
     * ARRAY 2D: Un array i cui elementi sono altri array
     * Sintassi: tipo nome_array[righe][colonne]
     * Accesso: nome_array[indice_riga][indice_colonna]
     */
    
    // Inizializzazione con dimensioni esplicitate
    int numbers1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Inizializzazione con dimensioni dedotte
    int numbers2[][4] = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120}
    };
    
    // Stampa array 3x3
    ft_putstr("Array 3x3:\n");
    ft_put2darray(3, 3, numbers1);
    ft_putchar('\n');
    
    // Stampa array 3x4
    ft_putstr("Array 3x4:\n");
    ft_put2darray(3, 4, numbers2);
    
    // Accesso diretto agli elementi
    ft_putstr("\nElementi specifici:\n");
    ft_putstr("numbers1[0][0] = ");
    ft_putnbr(numbers1[0][0]);
    ft_putchar('\n');
    
    ft_putstr("numbers2[2][3] = ");
    ft_putnbr(numbers2[2][3]);
    ft_putchar('\n');
    
    return 0;
}