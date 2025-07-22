#include <unistd.h>

/*
 * 🎯 FUNZIONE PRINCIPALE - ft_sort_int_tab
 * Ordina un array di interi in ordine crescente usando Bubble Sort
 * 
 * 📌 Parametri:
 *   - tab: puntatore all'array da ordinare
 *   - size: numero di elementi nell'array
 * 
 * 🔍 Algoritmo scelto:
 *   - Bubble Sort per semplicità didattica
 *   - Complessità: O(n²) nel caso peggiore
 *   - Spazio: O(1) (ordinamento in-place)
 */


 void ft_sort_int_tab(int *tab, int size)
{
    int i;    // Contatore passate principali
    int j;    // Contatore confronti interni
    int temp; // Variabile temporanea per lo scambio

    // 🛑 CASI BASE: array vuoto o con 1 elemento è già ordinato
    if (size <= 1)
        return;

    // 🔁 LOOP ESTERNO (controlla il numero di passate necessarie)
    // - Servono al massimo (size-1) passate per ordinare
    // - Ogni passata "fissa" un elemento nella posizione corretta
    i = 0;
    while (i < size - 1)
    {
        // 🔄 LOOP INTERNO (confronta elementi adiacenti)
        // - Scorre l'array fino alla porzione non ancora ordinata
        // - (size - i - 1) perché:
        //   • "-i": ignora gli ultimi i elementi già ordinati
        //   • "-1": evita di confrontare l'ultimo col successivo (fuori array)
        j = 0;
        while (j < size - i - 1)
        {
            // 📊 CONFRONTO: controlla se gli elementi sono in ordine sbagliato
            if (tab[j] > tab[j + 1])
            {
                // 🔄 SWAP: scambia gli elementi con la tecnica "a tre variabili"
                temp = tab[j];       // 1. Salva il valore corrente in temp
                tab[j] = tab[j + 1]; // 2. Sovrascrive col valore successivo
                tab[j + 1] = temp;   // 3. Completa lo scambio
                
                // 🎯 Dopo questo blocco:
                // tab[j] ora contiene il valore più piccolo
                // tab[j+1] contiene il valore più grande
            }
            j++; // ➡️ Avanza al prossimo confronto
        }
        i++; // 🚀 Incrementa il contatore delle passate completate
        
        // 💡 Dopo ogni passata:
        // - L'elemento più grande "affonda" in fondo all'array
        // - La porzione non ordinata si riduce di 1 elemento
    }
}

/*
 * ✨ FUNZIONI AUSILIARIE (identiche all'esercizio precedente)
 */

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putstring(char *str) {
    if (!str) return;
    while (*str) {
        ft_putchar(*str++);
    }
}

void ft_putnumber(int num) {
    if (num == -2147483648) {
        ft_putstring("-2147483648");
        return;
    }
    if (num < 0) {
        ft_putchar('-');
        num = -num;
    }
    if (num >= 10)
        ft_putnumber(num / 10);
    ft_putchar((num % 10) + '0');
}

/*
 * 🧪 TEST MAIN con casi significativi
 */
int main(void) {
    // 🎯 Array di test
    int test1[] = {4, 2, 9, 1, 5};  // Caso generico
    int test2[] = {1, 2, 3, 4, 5};   // Già ordinato
    int test3[] = {5, 4, 3, 2, 1};   // Inverso
    int test4[] = {42};              // Singolo elemento
    int test5[5] = {0};              // Tutti zero

    int *tests[] = {test1, test2, test3, test4, test5};
    int sizes[] = {5, 5, 5, 1, 5};

    for (int i = 0; i < 5; i++) {
        ft_putstring("Test ");
        ft_putnumber(i+1);
        ft_putstring(" - Prima: ");

        // Stampa array non ordinato
        for (int j = 0; j < sizes[i]; j++) {
            ft_putnumber(tests[i][j]);
            ft_putchar(' ');
        }

        ft_sort_int_tab(tests[i], sizes[i]);

        ft_putstring(" Dopo: ");
        // Stampa array ordinato
        for (int j = 0; j < sizes[i]; j++) {
            ft_putnumber(tests[i][j]);
            ft_putchar(' ');
        }
        ft_putchar('\n');
    }

    return 0;
}

/*
 * 📚 SEZIONE RIPASSO E APPROFONDIMENTI
 * 
 * 🔹 Domande Frequenti:
 * 
 * ❓ Perché usare Bubble Sort invece di algoritmi più efficienti?
 * ✅ Risposta:
 *    - Semplice da implementare e comprendere
 *    - Adeguato per array piccoli (fino a ~1000 elementi)
 *    - Per array grandi considerare QuickSort o MergeSort
 * 
 * ❓ Come ottimizzare Bubble Sort?
 * ✅ Tecniche avanzate:
 *    1. Aggiungere flag per rilevare se l'array è già ordinato
 *    2. Alternare direzioni (Cocktail Shaker Sort)
 *    3. Memorizzare l'ultimo scambio per ridurre i confronti
 * 
 * ❓ Cosa cambia nell'ordinamento decrescente?
 * ✅ Basta invertire il confronto:
 *    if (tab[j] < tab[j + 1]) invece di >
 * 
 * ❓ Come gestire array con duplicati?
 * ✅ L'algoritmo funziona già correttamente, mantiene l'ordine relativo
 *    (Bubble Sort è stabile)
 * 
 * 🛠️ Esercizi Consigliati:
 * 1. Implementare una versione ricorsiva
 * 2. Aggiungere un parametro per scegliere ordine crescente/decrescente
 * 3. Creare una funzione generica che ordina qualsiasi tipo di dato
 * 4. Implementare QuickSort e confrontare le performance
 * 
 * 💡 Errori Comuni:
 * - Confondere i limiti dei loop (j < size - i - 1)
 * - Dimenticare lo scambio quando gli elementi sono uguali
 * - Accesso fuori dai bound (es. tab[j+1] con j=size-1)
 */