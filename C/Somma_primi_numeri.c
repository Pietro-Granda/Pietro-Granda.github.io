#include <stdio.h>       // Libreria I/O

int main() {             // Programma
    int N, somma = 0;    // Variabili

    printf("Inserisci N: ");   // Richiesta input
    scanf("%d", &N);           // Lettura

    for (int i = 1; i <= N; i++) // Ciclo da 1 a N
        somma += i;             // Aggiunge i alla somma

    printf("Somma = %d\n", somma);  // Stampa risultato
    return 0;               // Fine
}
