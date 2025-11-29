#include <stdio.h>        // Libreria per I/O

int main() {              // Programma
    int n;                // Variabile per il numero

    printf("Inserisci un numero: ");   // Richiesta input
    scanf("%d", &n);                   // Lettura numero

    for (int i = 1; i <= 10; i++)      // Ciclo da 1 a 10
        printf("%d x %d = %d\n", n, i, n * i);  // Stampa riga della tabellina

    return 0;            // Fine
}
