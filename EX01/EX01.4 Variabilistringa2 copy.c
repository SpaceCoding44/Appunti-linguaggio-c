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
    
    char name[] = "Bro Code";
    char food[] = "pizza";

    // Stampiamo "Hello "
    ft_putstr("Hello ");
    // Stampiamo il nome
    ft_putstr(name);
    // Stampiamo newline
    ft_putchar('\n');

    // Stampiamo "Your favorite food is "
    ft_putstr("Your favorite food is ");
    // Stampiamo il cibo preferito
    ft_putstr(food);
    // Stampiamo newline
    ft_putchar('\n');

    return 0;
}



/* ESEMPIO ORIGINALE 

#include <stdio.h>

int main() {


    char name[] = "Bro Code";
    char food[] = "pizza";

    printf("Hello %s\n", name);
    printf("Your favorite food is %s\n", food);

    return 0;
}

*/