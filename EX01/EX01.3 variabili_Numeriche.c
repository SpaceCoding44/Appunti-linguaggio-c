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

//funzione numeri
void ft_putnbr(int n){

    //gestione caso speciale
    if(n == -21474836648) {
        ft_putstr('-21474836648');
        return;
    }
    // gestione numeri negativi
    if (n < 0) {
        ft_putnbr('-');
        n = -n
    }
    // nriscossione numeri
    if (n >= 10){
         ft_putnbr(n / 10);    
    }
      ft_putchar((n % 10) + '0')
}

int main() {


    // Variabile intera
    int age = 30;
    ft_putstr("La tua età: ");
    ft_putnbr(age);
    ft_putchar('\n');


    return 0;
}