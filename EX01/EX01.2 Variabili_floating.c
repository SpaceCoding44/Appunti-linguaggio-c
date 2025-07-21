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

/* TATTICA: Casting esplicito per evitare warning */
void ft_putnbr(int n) {
    if (n < 0) { // Gestione numeri negativi
        ft_putchar('-');
        n = -n;
    }
    if (n >= 10) { // Ricorsione per numeri multi-cifra
        ft_putnbr(n / 10);
    }
    ft_putchar(n % 10 + '0'); // Converte cifra in ASCII
}

int main() {

    // Variabile floating point (non stampabile direttamente con write)
    float temperature = 23.5;
    ft_putstr("Temperatura: ");
    // Per semplicità stampiamo solo la parte intera
    ft_putnbr((int)temperature);
    ft_putstr(".5\n");
 
    return 0;
}