#include <unistd.h>

/*
 * 🎯 FUNZIONE PRINCIPALE - ft_rev_int_tab
 * Inverte l'ordine degli elementi in un array di interi
 * 
 * 🔍 Analisi del procedimento:
 * 1. PARTE DAGLI ESTREMI: Usa due indici che partono dagli estremi opposti
 * 2. SCAMBIO PROGRESSIVO: Ad ogni iterazione scambia gli elementi agli estremi
 * 3. CONVERGENZA AL CENTRO: Gli indici avanzano verso il centro fino a incontrarsi
 * 
 * 🧠 Logica chiave: 
 * - Con N elementi servono N/2 iterazioni
 * - L'elemento centrale (se dispari) resta al suo posto
 * 
 *  * ❓ Perché usiamo (start < end) e non (start <= end)?
 * ✅ Risposta: Con (start <= end) avremmo uno scambio superfluo 
 *    quando gli indici coincidono (elemento centrale in array dispari)
 * 
 */
void ft_rev_int_tab(int *tab, int size)
{
    int start = 0;          // 🏁 Indice sinistro (parte dall'inizio)
    int end = size - 1;     // 🏁 Indice destro (parte dalla fine)
    int temp;               // 📦 Variabile temporanea per lo scambio

    while (start < end)     // 🔄 Continua finché gli indici non si incrociano
    {
        // 🔄 Triangolazione dello scambio
        temp = tab[start];      // 1. Salva il valore di sinistra
        tab[start] = tab[end];  // 2. Sovrascrivi sinistra con destro
        tab[end] = temp;        // 3. Completa lo scambio

        start++;  // ➡️ Avanza l'indice sinistro
        end--;    // ⬅️ Retrocede l'indice destro
    }
}

/* 
 * ✨ FUNZIONI AUSILIARIE (per testing)
 */

/***********************************************
 * FT_PUTCHAR - Stampa un carattere
 * 💡 Tecnica: usa la system call write() per massima efficienza
 ***********************************************/
void ft_putchar(char c) {
    write(1, &c, 1);  // 📤 1 = stdout, &c = indirizzo del carattere, 1 = byte count
}

/***********************************************
 * FT_PUTSTRING - Stampa una stringa
 * ⚠️ Attenzione: Gestisce il caso NULL per sicurezza
 ***********************************************/
void ft_putstring(char *str) {
    if (!str) return;  // 🛡️ Controllo anti-crash
    while (*str) {     // 🔍 *str != '\0'
        ft_putchar(*str++);
    }
}

/***********************************************
 * FT_PUTNUMBER - Stampa un intero (ricorsivo)
 * 💡 Tecniche usate:
 * - Gestione speciale INT_MIN
 * - Ricorsione per stampa cifre
 * - Conversione cifra → carattere (+ '0')
 ***********************************************/

void ft_putnumber(int num) {
    if (num == -2147483648) { ft_putstring("-2147483648"); return; }
    if (num < 0) { ft_putchar('-'); num = -num; }
    if (num >= 10) ft_putnumber(num / 10);
    ft_putchar((num % 10) + '0');  // 🎯 Conversione a carattere
}

/*
 * 🧪 TEST MAIN - Dimostrazione
 */
int main(void) {
    int arr[] = {1, 2, 3, 4, 5};  // 🧩 Array di test
    int size = sizeof(arr)/sizeof(arr[0]);  // 📏 Calcolo dinamico della size

    ft_putstring("Originale: ");
    for (int i = 0; i < size; i++) {
        ft_putnumber(arr[i]);
        ft_putchar(' ');
    }
    ft_putchar('\n');

    ft_rev_int_tab(arr, size);  // 🔄 Chiamata alla funzione

    ft_putstring("Invertito: ");
    for (int i = 0; i < size; i++) {
        ft_putnumber(arr[i]);
        ft_putchar(' ');
    }
    ft_putchar('\n');

    return 0;
}

/*
 * 📚 SEZIONE RIPASSO E CONSIGLI
 * 
 * 🔹 Concetti chiave da ricordare:
 * 1. TWO-POINTER TECHNIQUE: Approccio fondamentale per problemi su array
 * 2. SWAP TRIANGOLARE: Necessità di una variabile temporanea per lo scambio
 * 3. TERMINAZIONE: Il loop deve fermarsi quando start >= end
 * 
 * 💡 Errori comuni da evitare:
 * - Dimenticare di controllare se size = 0
 * - Usare size anziché size-1 per l'indice finale
 * - Scrivere tab[end] = tab[start] invece dello scambio completo
 * 
 * 🎯 Domande per autovalutazione:
 * 
 * ❓ Cosa succede se passo un array vuoto (size=0)?
 * ✅ La funzione ritorna immediatamente grazie al controllo iniziale,
 *    evitando accessi a memoria non valida
 * 
 * ❓ Perché end = size-1 e non size?
 * ✅ Perché gli array sono 0-based in C, quindi l'ultimo elemento è size-1
 * 
 * ❓ È possibile invertire solo una parte dell'array?
 * ✅ Sì! Modificando la funzione per accettare start/end come parametri:
 *    void ft_rev_subarray(int *tab, int start, int end)
 * 
 * ❓ Come si comporta con array non modificabili (const)?
 * ✅ Causerà un errore di compilazione, per sicurezza usare:
 *    void ft_rev_int_tab(const int *tab, int size) se non deve modificare
 * 
 * ❓ Qual è l'overhead di memoria?
 * ✅ Solo 3 variabili locali (start, end, temp) → O(1) spazio
 * 
 * 🛠️ ESERCIZI CONSIGLIATI:
 * 1. Implementare ft_rev_int_tab senza variabile temp (usando XOR swap)
 * 2. Creare una versione che inverte i byte di ogni intero
 * 3. Scrivere una funzione che inverte l'ordine delle parole in una stringa
 */