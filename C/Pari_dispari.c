#include <stdio.h>      // Libreria standard I/O

int main() {            // Funzione principale
    int n;              // Variabile per il numero

    printf("Inserisci un numero: ");   // Richiesta input
    scanf("%d", &n);                   // Lettura del numero

    if (n % 2 == 0)                    // Controllo se il numero è divisibile per 2
        printf("Il numero e' pari.\n");   // Messaggio se pari
    else                               
        printf("Il numero e' dispari.\n"); // Messaggio se dispari

    return 0;           // Fine programma
}
