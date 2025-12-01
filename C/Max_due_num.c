#include <stdio.h>    // Libreria per input/output

int main() {          // Avvio programma
    int a, b;         // Dichiarazione variabili

    printf("Inserisci due numeri: ");   // Richiesta input
    scanf("%d %d", &a, &b);             // Lettura valori

    if (a > b)                          // Controllo chi è maggiore
        printf("Il maggiore e': %d\n", a);  // Stampa del maggiore
    else
        printf("Il maggiore e': %d\n", b);  // Stampa del maggiore

    return 0;       // Fine
}
