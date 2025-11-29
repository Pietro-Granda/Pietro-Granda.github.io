#include <stdio.h>      // Libreria standard I/O

int main() {            // Inizio del programma
    int a, b;           // Dichiarazione di due variabili intere

    printf("Inserisci due numeri: ");   // Richiesta dei valori all'utente
    scanf("%d %d", &a, &b);             // Lettura dei due numeri

    printf("Somma = %d\n", a + b);      // Calcolo e stampa della somma
    return 0;           // Fine del programma
}
