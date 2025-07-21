#include <unistd.h>

void ft_putchar(char c){
    write(1, &c, 1);
}

void ft_putchar(char *str){
    ft_putchar(*str);
    str++;
}

int main() {
    
    ft_putchar("Hello, Ilike Pizza!");
    ft_putchar("\n");
    ft_putchar("Do You Like Pizza?")
}

