#include <unistd.h>

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

/***********************************************
 * FT_STRLENGHT:
 * Calcola la lunghezza di una stringa.
 ***********************************************/
int ft_strlenght(char *stri)
{
    int length = 0;
    
    if (stri == NULL)
        return 0;
        
    while (*stri != '\0')
    {
        length++;
        stri++;
    }
    
    return length;
}

/***********************************************
 * MAIN:
 * Testa la funzione ft_strlenght con vari casi.
 ***********************************************/
int main(void)
{
    char *str1 = "Hello, World!";
    char *str2 = "";
    char *str3 = NULL;
    char str4[] = {'H', 'i', '\0'};
    
    // Test 1: Stringa normale
    ft_putstring("Lunghezza di \"");
    ft_putstring(str1);
    ft_putstring("\": ");
    ft_putnumber(ft_strlenght(str1));
    ft_putchar('\n');
    
    // Test 2: Stringa vuota
    ft_putstring("Lunghezza di \"\" (stringa vuota): ");
    ft_putnumber(ft_strlenght(str2));
    ft_putchar('\n');
    
    // Test 3: Puntatore NULL
    ft_putstring("Lunghezza di NULL: ");
    ft_putnumber(ft_strlenght(str3));
    ft_putchar('\n');
    
    // Test 4: Array di caratteri con terminatore
    ft_putstring("Lunghezza di \"Hi\": ");
    ft_putnumber(ft_strlenght(str4));
    ft_putchar('\n');
    
    return 0;
}