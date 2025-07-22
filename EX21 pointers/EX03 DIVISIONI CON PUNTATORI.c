#include <unistd.h>
// creare una funzione con prototipo  ft_div_mod(inta intb int*div int*mod)
// questa funzione calcola la divisione del parametrro a per il parametro b e ne salva il risultato 
// nel int puntato nel div e il resto in int puntato mod

#include <unistd.h>

/***********************************************
 * FT_DIV_MOD:
 * Calcola divisione e resto di a diviso b,
 * salvando i risultati nei puntatori div e mod.
 ***********************************************/
void ft_div_mod(int a, int b, int *div, int *mod)
{
    if (b != 0)  // Evitiamo la divisione per zero
    {
        *div = a / b;
        *mod = a % b;
    }
}

/***********************************************
 * FT_PUTCHAR:
 * Stampa un singolo carattere sul terminale.
 ***********************************************/
void ft_putchar(char c)
{
    write(1, &c, 1);
}

/***********************************************
 * FT_PUTSTRING:
 * Stampa una stringa completa sul terminale.
 ***********************************************/
void ft_putstring(char *string)
{
    if (string == NULL)
        return;

    while (*string != '\0')
    {
        ft_putchar(*string);
        string++;
    }
}

/***********************************************
 * FT_PUTNUMBER:
 * Stampa un numero intero sul terminale.
 ***********************************************/
void ft_putnumber(int num)
{
    if (num == -2147483648)
    {
        ft_putstring("-2147483648");
        return;
    }
    if (num < 0)
    {
        ft_putchar('-');
        num = -num;
    }

    if (num >= 10)
        ft_putnumber(num / 10);

    ft_putchar((num % 10) + '0');
}

// Esempi di utilizzo

int main(void)
{
    int a = 42;
    int b = 5;
    int risultato_div;
    int risultato_mod;
    
    ft_div_mod(a, b, &risultato_div, &risultato_mod);
    
    ft_putstring("Div: ");
    ft_putnumber(risultato_div);  // Stampa 8 (42 / 5 = 8)
    ft_putchar('\n');
    
    ft_putstring("Mod: ");
    ft_putnumber(risultato_mod);  // Stampa 2 (42 % 5 = 2)
    ft_putchar('\n');
    
    return 0;
}

/*
🧠 Key Points

    Puntatori = Mappe del Tesoro

        div e mod sono come mappe che dicono dove scrivere i risultati.

        *div e *mod sono i tesori (i valori nelle variabili originali).

    & = "Ecco dove sono!"

        &divisione dice alla funzione: "Scrivi il risultato qui!".

    Niente * = Copie inutili

        Senza *, la funzione lavora su fantasmi (copie locali), e i risultati svaniscono.
*/