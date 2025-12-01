#include <stdio.h>        // Libreria standard

int main() {              // Funzione principale
    float celsius, fahrenheit;  // Variabili per temperatura

    printf("Inserisci la temperatura in Celsius: ");  // Richiesta input
    scanf("%f", &celsius);                            // Lettura valore

    fahrenheit = celsius * 9 / 5 + 32;                // Formula conversione

    printf("In Fahrenheit = %.2f\n", fahrenheit);     // Stampa risultato
    return 0;              // Fine programma
}
