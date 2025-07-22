#include <unistd.h>

/*
 * 🎯 FUNZIONE PRINCIPALE:
 * ft_ultimate_div_mod - Calcola divisione e resto modificando direttamente i puntatori
 * 
 * 📌 Parametri:
 * - int *a: puntatore al dividendo (diventerà il risultato della divisione)
 * - int *b: puntatore al divisore (diventerà il resto)
 * 
 * ⚠️ Attenzione:
 * - Gestisce il caso di divisione per zero
 * - Modifica direttamente le variabili originali
 */
void ft_ultimate_div_mod(int *a, int *b)
{
    // 🛡️ Doppio controllo di sicurezza
    if (b != NULL && *b != 0)  // 1. Verifica che il puntatore esista 2. Verifica che non sia divisione per zero
    {
        int temp_div = *a / *b;  // 📊 Calcola la divisione
        int temp_mod = *a % *b;  // 🔍 Calcola il resto
        
        *a = temp_div;  // ✏️ Sovrascrive il valore originale con il risultato
        *b = temp_mod;  // ✏️ Sovrascrive il valore originale con il resto
    }
    // else {
    //   Se vuoi gestire esplicitamente l'errore:
    //   write(1, "Errore: divisione per zero!\n", 27);
    // }
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
 * Dimostrazione funzionamento con caso 42 / 5
 */
int main(void)
{
    int a = 42;  // 🎲 Dividendo originale
    int b = 5;   // 🎲 Divisore originale
    
    // 🖨️ Stampa valori iniziali
    ft_putstring("Valori iniziali:\n");
    ft_putstring("a = ");
    ft_putnumber(a);
    ft_putstring("\nb = ");
    ft_putnumber(b);
    ft_putstring("\n\n");
    
    // 🔄 Chiamata alla funzione (passaggio per riferimento)
    ft_ultimate_div_mod(&a, &b);
    
    // 🖨️ Stampa risultati
    
    ft_putstring("Dopo ft_ultimate_div_mod:\n");
    ft_putstring("a (divisione) = ");
    ft_putnumber(a);
    ft_putstring("\nb (resto) = ");
    ft_putnumber(b);
    ft_putstring("\n");
    
    return 0;
}

/*
 * 🧠 KEY POINTS - SPIEGAZIONE FINALE
 * 
 * 1. PUNTATORI = MODIFICA DIRETTA
 *    - Usando *a e *b modifichiamo le variabili originali
 *    - Senza puntatori lavoreremmo su copie locali
 * 
 * 2. & OPERATOR = "DOVE VIVONO LE VARIABILI"
 *    - &a nell'main dice: "Ecco l'indirizzo della variabile a"
 * 
 * 3. SICUREZZA
 *    - Controlliamo b != NULL per evitare segmentation fault
 *    - Controlliamo *b != 0 per evitare divisione per zero
 * 
 * 4. TEMPORANEE
 *    - temp_div e temp_mod evitano sovrascritture premature
 *      (senza di esse, dopo *a = *a / *b, il % darebbe un risultato sbagliato)
 */