#include <stdio.h>        // Libreria I/O

int main() {              // Avvio programma
    int n, count = 0;     // Variabili

    printf("Inserisci un numero: ");   // Richiesta input
    scanf("%d", &n);                   // Lettura

    if (n == 0) count = 1;             // Caso speciale: 0 ha 1 cifra

    while (n != 0) {       // Ciclo finché ci sono cifre
        n /= 10;           // Elimina l'ultima cifra
        count++;           // Incrementa il contatore
    }

    printf("Numero di cifre = %d\n", count);  // Stampa totale
    return 0;             // Fine programma
}
