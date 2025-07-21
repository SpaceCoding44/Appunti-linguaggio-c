#include <unistd.h>



// Definizione:   una funzione che accetta un parametro di tipo e non restituisce alcun valore ( void )

void ft_putchar(char c) {
    write(1, &c, 1);
}

// Main - La funzione main è il punto di ingresso del programma e restituisce un int (di solito 0 per indicare successo).

int main() {
    char letter = 'A';       // Variabile carattere
    ft_putchar(letter);      // Stampa 'A'
    ft_putchar('\n');        // Nuova riga
    
    return 0;
}


/*

2. Chiamate di Sistema (System Calls) LINK man  : https://man7.org/linux/man-pages/man2/syscalls.2.html

· Approfondisci come funzionano i file descriptor e le system call in Unix/
Linux.


3. Guide e Tutorial

System Call in Generale

· Linux System Calls Explained (Breve guida) -----------------

LinuxHint - System Calls
Spiega cosa sono le system call e come funzionano a livello di kernel.


. File Descriptor in Unix/Linux ----------------------------------
-> GeeksforGeeks - File Descriptors
Spiega i file descriptor e le syscall correlate ( open ,

Approfondimento su write()

· Tutorial con esempi -------------------------------------------
-> Write System Call in C
Mostra come usare write() con diversi file descriptor.

· Differenza tra write e printf ---------------------------------

-> StackOverflow - write vs printf

Spiega perché write è a basso livello mentre printf è buffered.

*/