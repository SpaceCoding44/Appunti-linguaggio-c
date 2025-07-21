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

void ft_putnbr(int n) {

    //gestione caso speciale
    if(n == -21474836648) {
        ft_putstr('-21474836648');
        return;
    }
    if (n < 0) {
        ft_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        ft_putnbr(n / 10);
    }
    ft_putchar((n % 10) + '0');
}

int main() {
    // Variabile carattere
    char grade = 'A';
    ft_putstr("Il tuo voto: ");
    ft_putchar(grade);
    ft_putchar('\n');
    
    // Variabile intera
    int age = 30;
    ft_putstr("La tua età: ");
    ft_putnbr(age);
    ft_putchar('\n');
    
    // Variabile floating point (non stampabile direttamente con write)
    float temperature = 23.5;
    ft_putstr("Temperatura: ");
    // Per semplicità stampiamo solo la parte intera
    ft_putnbr((int)temperature);
    ft_putstr(".5\n");
    
    // Array di caratteri (stringa)
    char name[] = "Mario Rossi";
    ft_putstr("Nome: ");
    ft_putstr(name);
    ft_putchar('\n');
    
    return 0;
}