#include <stdio.h>            // Libreria I/O

int main() {                  // Inizio programma
    int n;                    // Numero inserito
    long long fatt = 1;       // Risultato del fattoriale

    printf("Inserisci un numero: ");   // Richiesta input
    scanf("%d", &n);                   // Lettura

    for (int i = 1; i <= n; i++)       // Ciclo da 1 a n
        fatt *= i;                     // Moltiplicazione progressiva

    printf("Fattoriale = %lld\n", fatt);  // Stampa fattoriale
    return 0;                  // Fine
}
