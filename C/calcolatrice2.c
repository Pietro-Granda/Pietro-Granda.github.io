#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// Funzione per chiudere il file
void myfclose(FILE *fp) {
    if (fp != NULL) {
        fclose(fp);
    }
}

// Funzione per ottenere timestamp
void getTimestamp(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", t);
}

// Funzione per ottenere l'ultimo numero usato nel file
int leggiUltimoNumero(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) return 1;

    char riga[256];
    int ultimo = 0;

    while (fgets(riga, sizeof(riga), fp)) {
        int numero;
        if (sscanf(riga, "%d.", &numero) == 1) {
            ultimo = numero;
        }
    }

    fclose(fp);
    return ultimo + 1;
}

int main() {
    int risultato, num1, num2;
    char operazione;
    FILE *file;
    char timestamp[20];
    int contatore;

    const char *filename = "risultati.txt";
    contatore = leggiUltimoNumero(filename);

    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }

    do {
        system("cls");
        printf("Somma: +\n");
        printf("Differenza: -\n");
        printf("Moltiplicazione: *\n");
        printf("Divisione: /\n");
        printf("Radice quadrata: s\n");
        printf("0 per terminare il programma\n");
        printf("Operazione da eseguire: ");
        operazione = getchar();
        while (getchar() != '\n');

        if (operazione == '0') break;

        system("cls");
        getTimestamp(timestamp, sizeof(timestamp));

        switch (operazione) {
            case '+':
                printf("Numero 1 = ");
                scanf("%d", &num1);
                printf("Numero 2 = ");
                scanf("%d", &num2);
                risultato = num1 + num2;
                printf("Risultato = %d\n", risultato);
                fprintf(file, "%d. [%s] %d + %d = %d\n", contatore++, timestamp, num1, num2, risultato);
                break;

            case '-':
                printf("Numero 1 = ");
                scanf("%d", &num1);
                printf("Numero 2 = ");
                scanf("%d", &num2);
                risultato = num1 - num2;
                printf("Risultato = %d\n", risultato);
                fprintf(file, "%d. [%s] %d - %d = %d\n", contatore++, timestamp, num1, num2, risultato);
                break;

            case '*':
                printf("Numero 1 = ");
                scanf("%d", &num1);
                printf("Numero 2 = ");
                scanf("%d", &num2);
                risultato = num1 * num2;
                printf("Risultato = %d\n", risultato);
                fprintf(file, "%d. [%s] %d * %d = %d\n", contatore++, timestamp, num1, num2, risultato);
                break;

            case '/':
                printf("Numero 1 = ");
                scanf("%d", &num1);
                printf("Numero 2 = ");
                scanf("%d", &num2);
                if (num2 == 0) {
                    printf("Errore: divisione per zero.\n");
                    fprintf(file, "%d. [%s] %d / %d = ERRORE (divisione per zero)\n", contatore++, timestamp, num1, num2);
                } else {
                    risultato = num1 / num2;
                    printf("Risultato = %d\n", risultato);
                    fprintf(file, "%d. [%s] %d / %d = %d\n", contatore++, timestamp, num1, num2, risultato);
                }
                break;

            case 's':
                printf("Numero = ");
                scanf("%d", &num1);
                if (num1 < 0) {
                    printf("Errore: radice quadrata di numero negativo.\n");
                    fprintf(file, "%d. [%s] sqrt(%d) = ERRORE (numero negativo)\n", contatore++, timestamp, num1);
                } else {
                    risultato = (int)sqrt(num1);
                    printf("Risultato = %d\n", risultato);
                    fprintf(file, "%d. [%s] sqrt(%d) = %d\n", contatore++, timestamp, num1, risultato);
                }
                break;

            default:
                printf("Operazione non valida.\n");
                break;
        }

        while (getchar() != '\n');
        system("PAUSE");

    } while (1);

    myfclose(file);
    return 0;
}

