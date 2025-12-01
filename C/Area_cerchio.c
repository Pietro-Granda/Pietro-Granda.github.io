#include <stdio.h>       // Libreria I/O

int main() {             // Inizio programma
    float r;             // Variabile per il raggio
    const float PI = 3.14;  // Definizione della costante π

    printf("Inserisci il raggio: ");   // Richiesta del raggio
    scanf("%f", &r);                   // Lettura raggio

    float area = PI * r * r;           // Calcolo dell'area

    printf("Area del cerchio = %.2f\n", area);  // Stampa del risultato
    return 0;              // Fine del programma
}
