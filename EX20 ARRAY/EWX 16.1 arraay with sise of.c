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
 * Stampa un array di interi conoscendone la dimensione
 */
void ft_putarray_int(int *arr, size_t size) {
    size_t i = 0;
    while (i < size) {
        ft_putnbr(arr[i]);
        if (i < size - 1)
            ft_putchar(' ');
        i++;
    }
}

/*
 * Stampa un array di caratteri conoscendone la dimensione
 */
void ft_putarray_char(char *arr, size_t size) {
    size_t i = 0;
    while (i < size) {
        ft_putchar(arr[i]);
        if (i < size - 1)
            ft_putchar(' ');
        i++;
    }
}

int main() {
    // Array di interi
    int numbers[] = {10, 20, 30, 40, 50};
    size_t numbers_size = sizeof(numbers) / sizeof(numbers[0]);
    
    // Array di caratteri
    char grades[] = {'A', 'B', 'C', 'D', 'F'};
    size_t grades_size = sizeof(grades) / sizeof(grades[0]);
    
    // Stringa (array con terminatore nullo)
    char name[] = "Bro Code";
    size_t name_size = sizeof(name) - 1; // -1 per escludere il '\0'

    // Stampa array di numeri
    ft_putstr("Array numbers: ");
    ft_putarray_int(numbers, numbers_size);
    ft_putchar('\n');

    // Stampa array di caratteri
    ft_putstr("Array grades: ");
    ft_putarray_char(grades, grades_size);
    ft_putchar('\n');
    
    // Stampa stringa
    ft_putstr("String name: ");
    ft_putstr(name);
    ft_putchar('\n');

    // Stampa stringa come array
    ft_putstr("String as array: ");
    ft_putarray_char(name, name_size);
    ft_putchar('\n');

    return 0;
}