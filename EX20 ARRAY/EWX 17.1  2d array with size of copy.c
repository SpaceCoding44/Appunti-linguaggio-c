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
 * Stampa array 2D con gestione automatica dimensioni
 */
void ft_put2darray(void *arr, int elem_size, int rows, int cols) {
    int (*matrix)[cols] = arr;  // Cast a puntatore ad array di cols elementi
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (elem_size == sizeof(int)) {
                ft_putnbr(matrix[i][j]);
            } else if (elem_size == sizeof(char)) {
                ft_putchar(matrix[i][j]);
            }
            if (j < cols - 1) ft_putchar('\t');  // Tab come separatore
        }
        ft_putchar('\n');
    }
}

/*
 * Macro per semplificare l'uso di ft_put2darray
 * Calcola automaticamente rows, cols e elem_size
 */
#define PRINT_2D_ARRAY(arr) \
    ft_put2darray(arr, sizeof((arr)[0][0]), \
    sizeof(arr)/sizeof((arr)[0]), \
    sizeof((arr)[0])/sizeof((arr)[0][0]))

int main() {
    // Array 2D di interi
    int numbers[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    // Array 2D di caratteri
    char letters[][4] = {
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'},
        {'I', 'J', 'K', 'L'}
    };

    // Stampa con gestione automatica dimensioni
    ft_putstr("Array numerico:\n");
    PRINT_2D_ARRAY(numbers);
    
    ft_putstr("\nArray di caratteri:\n");
    PRINT_2D_ARRAY(letters);

    return 0;
}