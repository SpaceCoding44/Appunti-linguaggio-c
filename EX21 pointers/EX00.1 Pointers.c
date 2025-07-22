#include <unistd.h>

// Craree una funzione che abbia come parametro un puntatore ed ad int ed imposti il valore a 42

// Funzione che stampa un singolo carattere
void    pt_putchar(char c)
{
    write(1, &c, 1);  // Stampa il carattere 'c' sullo standard output (1)
}

// Funzione ricorsiva che stampa un numero intero
void    print_number(int n)
{
    // Gestione dei numeri negativi
    if (n < 0)
    {
        pt_putchar('-');  // Stampa il segno meno
        n = -n;           // Converte il numero in positivo
    }
    // Caso base: se il numero ha più di una cifra
    if (n >= 10)
    {
        print_number(n / 10);  // Chiamata ricorsiva per le cifre più significative
    }
    pt_putchar('0' + (n % 10));  // Stampa l'ultima cifra
}

// Funzione che imposta a 42 il valore puntato da ptr
void    set_to_42(int *ptr)
{
    // Controllo per evitare di dereferenziare un puntatore NULL
    if (ptr != NULL)
    {
        *ptr = 42;  // Assegna 42 alla variabile puntata
    }
}

int main(void)
{
    int num;                // Dichiarazione di una variabile intera
    set_to_42(&num);        // Chiamata alla funzione con l'indirizzo di 'num'
    print_number(num);      // Stampa il valore di 'num' (dovrebbe essere 42)
    pt_putchar('\n');       // Stampa un newline per migliorare la leggibilità
    return (0);             // Termina il programma con successo
}
