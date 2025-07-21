#include <unistd.h>

    // variable = A reusable container for a value.
    // Behaves as if it were the value it contains.


void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putstr(char *str) {
    while (*str) {
        ft_putchar(*str);
        str++;
    }
}


int main() {

    // Array di caratteri (stringa)
    char name[] = "Mario Rossi";
    ft_putstr("Nome: ");
    ft_putstr(name);
    ft_putchar('\n');
    
    return 0;
}

