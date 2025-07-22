#include <unistd.h>  // Necessario per la funzione write()

/***********************************************
 * FT_PUTCHAR:
 * Stampa un singolo carattere sul terminale.
 * 
 * Parametri:
 * - c: Il carattere da stampare.
 ***********************************************/
void ft_putChar(char c)
{
    write(1, &c, 1);  // 1 = stdout (schermo), &c = indirizzo di c, 1 = numero di byte da scrivere
}

/***********************************************
 * FT_PUTSTRING:
 * Stampa una stringa completa sul terminale.
 * 
 * Parametri:
 * - string: Puntatore alla stringa da stampare.
 *           Se NULL, la funzione non fa nulla.
 ***********************************************/

void ft_putString(char *string)
{
    if (!string)  // Controllo se il puntatore è NULL (evita segmentation fault)
        return;

    while (*string)  // Continua finché non incontra '\0' (fine stringa)
    {
        ft_putChar(*string);  // Stampa il carattere corrente
        string++;             // Sposta il puntatore al prossimo carattere
    }
}

/***********************************************
 * FT_PUTNUMBER:
 * Stampa un numero intero sul terminale.
 * Gestisce numeri negativi e multipli cifre.
 * 
 * Parametri:
 * - num: Il numero intero da stampare.
 ***********************************************/

void ft_putNumber(int num)
{
    // Gestione numeri negativi
    if (num < 0)
    {
        ft_putChar('-');  // Stampa il segno meno
        num = -num;       // Converti in positivo per elaborazione
    }

    // Stampa ricorsiva per numeri con più cifre
    if (num >= 10)
    {
        ft_putNumber(num / 10);  // Stampa le cifre più significative prima
    }

    // Stampa l'ultima cifra (o l'unica cifra per numeri < 10)
    ft_putChar((num % 10) + '0');  // Converti cifra in carattere ASCII
}

/***********************************************
 * PRINT_AGE:
 * Stampa un messaggio con l'età.
 * 
 * Parametri:
 * - pAge: Puntatore all'intero contenente l'età.
 ***********************************************/
void printAge(int *pAge)
{
    ft_putString("You are ");  // Stampa testo fisso
    ft_putNumber(*pAge);       // Dereferenzia pAge e stampa il valore
    ft_putString(" years old\n");  // Stampa resto del messaggio
}

/***********************************************
 * MAIN:
 * Punto di ingresso del programma.
 * Dimostra l'uso di puntatori e stampa personalizzata.
 ***********************************************/

int main()
{
    int age = 21;      // Variabile intera
    int *pAge = &age;  // Puntatore che memorizza l'indirizzo di age

    printAge(pAge);    // Chiama la funzione con il puntatore

    return 0;          // Termina il programma
}