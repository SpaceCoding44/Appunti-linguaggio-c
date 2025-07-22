#include <unistd.h>

/*
 * 🎯 FUNZIONE PRINCIPALE:
 * void ft_string(char *strig)    creare una funzione che stamnpi una riga di caratteri
 * 
 * 📌 Parametri:
 * - strig: puntatore alla stringa da stampare
 * 
 * ⚠️ Attenzione:
 * - La funzione non restituisce alcun valore (void)
 * - Gestisce il caso di puntatore NULL
 */
void ft_string(char *strig)
{
    if (strig == NULL)
        return;
        
    while (*strig != '\0')
    {
        write(1, strig, 1);
        strig++;
    }
}

/*
 * ✍️ FUNZIONI AUSILIARIE PER LA VISUALIZZAZIONE
 * (Non richieste nell'esercizio ma utili per testing)
 */

/***********************************************
 * FT_PUTCHAR:
 * Stampa un singolo carattere sul terminale.
 ***********************************************/
void ft_putchar(char c)
{
    write(1, &c, 1);  // 📤 Scrive 1 byte sullo standard output
}

/***********************************************
 * FT_PUTSTRING:
 * Stampa una stringa completa sul terminale.
 ***********************************************/
void ft_putstring(char *string)
{
    if (string == NULL)
        return;                 // 🛡️ Controllo input nullo

    while (*string != '\0')     // 🔄 Scorre tutta la stringa
    {
        ft_putchar(*string);
        string++;               // ➡️ Avanza al prossimo carattere
    }
}

/***********************************************
 * FT_PUTNUMBER:
 * Stampa un numero intero sul terminale.
 * 
 *  💡 Gestisce:
 * - Numero minimo (-2147483648)
 * - Numeri negativi
 * - Casi base ricorsione
 ***********************************************/
void ft_putnumber(int num)
{
    // Caso speciale: numero minimo su 32 bit
    if (num == -2147483648)
    {
        ft_putstring("-2147483648");
        return;
    }
    
    // Gestione numeri negativi
    if (num < 0)
    {
        ft_putchar('-');  // Stampa il segno
        num = -num;       // Rendilo positivo
    }

    // Caso ricorsivo: numeri con più di una cifra
    if (num >= 10)
        ft_putnumber(num / 10); // ▶️ Chiamata ricorsiva

    // Caso base: stampa l'ultima cifra
    ft_putchar((num % 10) + '0');        
    // 🔢 Converti cifra in carattere
}

/*
 *  TEST MAIN
 * Dimostrazione funzionamento / 
 */
int main(void)
{
    ft_string("Hello, World!\n");
    return 0;
}