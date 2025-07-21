#include <unistd.h>
#include <stdbool.h> // Necessario per usare 'bool'

/* TATTICA: Funzioni base per output */
void ft_putchar(char c) {
    write(1, &c, 1); // Scrive 1 carattere alla volta
}

void ft_putstr(char *str) {
    while (*str) { // Continua finché incontri '\0' (fine stringa)
        ft_putchar(*str);
        str++; // Sposta il puntatore al prossimo carattere
    }
}

/* TATTICA: && richiede TUTTE le condizioni vere */
void ft_temperature_Display(int temp) {
    if(temp > 0 && temp < 39) { // OK solo se 0 < temp < 39
        ft_putstr("Temperatura e buona!");
    }
    else if(temp >= 40) { // Controllo aggiuntivo
        ft_putstr("Temperatura e bollente!");
    }
    else { // Default: cattura tutti gli altri casi (<=0 o ==39)
        ft_putstr("Temperatura e fredda!");     
    }
}

/* TATTICA: || richiede UNA sola condizione vera */
void ft_temperature_Display2(int temp) {
    if(temp < 0 || temp >= 39) { // Basta temp<0 OPPURE temp>=39
        ft_putstr("Temperatura e BAD!");
    }
    else { // Altrimenti (0 <= temp < 39)
        ft_putstr("Temperatura e GOOD!");     
    }
}

/* TATTICA: bool è un interruttore (true/false) */
void ft_weather_Display(bool issunny) {
    if(issunny) { // Equivale a (issunny == true)
        ft_putstr("sunny!");
    }
    else { // Se issunny è false
        ft_putstr("not sunny");     
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

int main(void) {
    float temperature = 23.5;

    /* TATTICA: Casting float->int per stampare solo la parte intera */
    ft_putstr("Temperatura: ");
    ft_putnbr((int)temperature); // (int) tronca i decimali

    /* Esempi di chiamate con commenti tattici */
    ft_putchar('\n');
    ft_temperature_Display(25);   // &&: mostra "buona" (25 è 0<25<39)
    ft_putchar('\n');
    ft_temperature_Display2(25);  // ||: mostra "GOOD" (25 non è <0 né >=39)
    ft_putchar('\n');
    ft_weather_Display(true);     // bool: mostra "sunny!" (true è come "ON")
    
    return 0;
}