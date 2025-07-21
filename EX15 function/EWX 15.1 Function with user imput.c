#include <unistd.h>
/* TATTICA: Funzioni base per output - più leggibili e riutilizzabili */
void ft_putchar(char c) {
    write(1, &c, 1); // Scrive 1 carattere alla volta
}
/*
 * FUNZIONE VOID: Attenzione!
 * - 'void' significa "nessun ritorno", ma qui c'è un errore:
 * - Stai cercando di usare 'return' senza valore (inutile in void)
 * - Inoltre, calcoli 'result' ma non lo usi!
 */
void ft_square(int num) {
    int result = num * num;  // Calcola il quadrato
    // return;  // SBAGLIATO: void non ritorna valori (commentato per errore)
    // Se vuoi stampare il risultato:
    // ft_putnbr(result);  // (ipotizzando che esista ft_putnbr)
}

/*
 * FUNZIONE CORRETTA con ritorno int:
 * - Restituisce il quadrato del numero
 * - Nota: il tipo di ritorno è 'int', non 'void'
 */
int square(int num) {  // Rinominata per differenziarla da ft_square
    return num * num;  // Ritorna direttamente il risultato
}

int main(void) {

    // ESEMPIO DI ERRORE COMUNE:
    // int x = ft_square(2);  // SBAGLIATO: ft_square è void, non ritorna nulla!

    // Versione corretta con la funzione che ritorna int:
    int x = square(2);  // x = 4
    int y = square(3);  // y = 9

    // Se vuoi usare ft_square (void), devi modificarla per stampare:
    // ft_square(2);  // Dovrebbe stampare direttamente il risultato

    return 0;
}

/*
 * FUNZIONE CON RETURN -------------------------------------------------------------
 * - Calcola il quadrato di un numero
 * - Ritorna il risultato come 'int'
 * - TATTICA: Il tipo prima del nome (int) definisce cosa ritorna!
 */
int ft_square(int num) {
    return num * num;
}

/*
 * FUNZIONE DI STAMPA COMPLETA
 * - TATTICA: Combina calcolo e visualizzazione
 * - Usa ft_putchar per un output pulito
 */
int ft_print_square(int num) {
    // Stampa formato "[num]^2 = risultato"
    ft_putchar('[');
    ft_putnbr(num);      // Stampa il numero originale
    ft_putchar(']');
    ft_putchar('^');
    ft_putchar('2');
    ft_putchar(' ');
    ft_putchar('=');
    ft_putchar(' ');
    ft_putnbr(ft_square(num)); // Calcola e stampa il risultato
    ft_putchar('\n');
}

/*
 * FUNZIONE PER STAMPARE NUMERI (utile per debug)
 * - TATTICA: 'void' perché non ritorna nulla, solo stampa
 */
void ft_putnbr(int n) {
    if (n < 0) {
        ft_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        ft_putnbr(n / 10); // Ricorsione per numeri con più cifre
    }
    ft_putchar(n % 10 + '0'); // Converti cifra in ASCII e stampa
}

int main(void) {
    // Demo: stampa diretta con formattazione
    ft_print_square(2);  // Output: [2]^2 = 4
    ft_print_square(3);  // Output: [3]^2 = 9
    ft_print_square(5);  // Output: [5]^2 = 25

    // Demo: salvataggio risultato
    int x = ft_square(4);  // x = 16 (calcolo senza stampa)
    ft_putstr("Risultato: ");  // Aggiunto per chiarezza
    ft_putnbr(x);
    ft_putchar('\n');

    return 0;
}