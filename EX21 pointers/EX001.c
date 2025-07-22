#include <unistd.h>  // Necessario per la funzione write()

/***********************************************
 * FT_PUTCHAR:
 * Stampa un singolo carattere sul terminale.
 * 
 * Parametri:
 * - c: Il carattere da stampare.
 ***********************************************/
void ft_putchar(char c)
{
    write(1, &c, 1);  // 1 = stdout (schermo), &c = indirizzo di c, 1 = byte da scrivere
}

/***********************************************
 * FT_PUTSTRING:
 * Stampa una stringa completa sul terminale.
 * 
 * Parametri:
 * - string: Puntatore alla stringa da stampare.
 *           Se NULL, la funzione non fa nulla.
 ***********************************************/
void ft_putstring(char *string)
{
    if (string == NULL)  // Controllo esplicito per puntatore NULL
        return;

    while (*string != '\0')  // Itera fino al terminatore di stringa
    {
        ft_putchar(*string);  // Stampa il carattere corrente
        string++;             // Avanza al prossimo carattere
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
void ft_putnumber(int num)
{
    // Caso speciale: minimo valore rappresentabile
    if (num == -2147483648)
    {
        ft_putstring("-2147483648");
        return;
    }

    // Gestione dei numeri negativi
    if (num < 0)
    {
        ft_putchar('-');
        num = -num;  // Converti in positivo per elaborazione
    }

    // Chiamata ricorsiva per numeri con più cifre
    if (num >= 10)
        ft_putnumber(num / 10);

    // Conversione e stampa della cifra (aggiunge '0' per ASCII)
    ft_putchar((num % 10) + '0');
}

/***********************************************
 * FT_ULTIMATE_FT:
 * Modifica un intero attraverso 9 livelli di puntatori.
 * 
 * Parametri:
 * - nbr: Puntatore a puntatore (9 livelli) all'intero da modificare.
 *        Il valore finale verrà impostato a 42.
 ***********************************************/
void ft_ultimate_ft(int *********nbr)
{
    *********nbr = 42;  // Dereferenziazione multipla per accedere all'intero
}

/***********************************************
 * MAIN:
 * Funzione principale che dimostra l'uso di ft_ultimate_ft.
 * Crea una catena di 9 puntatori e mostra il risultato.
 ***********************************************/
int main(void)
{
    int num;                        // Variabile intera da modificare
    int *ptr1 = &num;               // Puntatore di livello 1
    int **ptr2 = &ptr1;             // Puntatore di livello 2
    int ***ptr3 = &ptr2;            // Puntatore di livello 3
    int ****ptr4 = &ptr3;           // Puntatore di livello 4
    int *****ptr5 = &ptr4;          // Puntatore di livello 5
    int ******ptr6 = &ptr5;         // Puntatore di livello 6
    int *******ptr7 = &ptr6;        // Puntatore di livello 7
    int ********ptr8 = &ptr7;       // Puntatore di livello 8
    int *********ptr9 = &ptr8;      // Puntatore di livello 9

    ft_ultimate_ft(ptr9);           // Chiamata alla funzione con 9 livelli

    // Verifica del risultato
    ft_putstring("Il valore finale è: ");
    ft_putnumber(num);
    ft_putchar('\n');

    return (0);  // Fine del programma
}