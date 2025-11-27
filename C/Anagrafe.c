#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // numero massimo di persone salvabili

// Tipo enumerato per il genere
typedef enum {
    MASCHIO,
    FEMMINA
} Genere;

// Struttura persona
typedef struct {
    char nome[30];
    char cognome[30];
    char codiceFiscale[20];
    char luogoNascita[30];
    char dataNascita[11];  // formato gg/mm/aaaa
    Genere genere;
} Persona;

// PROTOTIPI DELLE FUNZIONI
void caricaDaFile(Persona v[], int *n);
void salvaSuFile(Persona v[], int n);
void inserisciPersona(Persona v[], int *n);
void mostraPersone(Persona v[], int n);
int cercaPersona(Persona v[], int n, const char *codiceFiscale);
void modificaPersona(Persona v[], int n);
void eliminaPersona(Persona v[], int *n);
void stampaPersona(Persona p);
void pulisciInput(void);

// FUNZIONE PRINCIPALE
int main() {
    Persona elenco[MAX];
    int n = 0;
    int scelta;

    // Carica dati da file
    caricaDaFile(elenco, &n);

    do {
        printf("\n===== MENU ANAGRAFE =====\n");
        printf("1. Inserisci persona\n");
        printf("2. Visualizza elenco\n");
        printf("3. Modifica persona\n");
        printf("4. Elimina persona\n");
        printf("5. Salva su file\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        pulisciInput();

        switch (scelta) {
            case 1:
                inserisciPersona(elenco, &n);
                break;
            case 2:
                mostraPersone(elenco, n);
                break;
            case 3:
                modificaPersona(elenco, n);
                break;
            case 4:
                eliminaPersona(elenco, &n);
                break;
            case 5:
                salvaSuFile(elenco, n);
                break;
            case 0:
                salvaSuFile(elenco, n);
                printf("\nDati salvati. Uscita...\n");
                break;
            default:
                printf("Scelta non valida!\n");
        }
    } while (scelta != 0);

    return 0;
}

// Inserimento di una nuova persona
void inserisciPersona(Persona v[], int *n) {
    if (*n >= MAX) {
        printf("Archivio pieno!\n");
        return;
    }

    Persona p;

    printf("Nome: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';

    printf("Cognome: ");
    fgets(p.cognome, sizeof(p.cognome), stdin);
    p.cognome[strcspn(p.cognome, "\n")] = '\0';

    printf("Codice fiscale: ");
    fgets(p.codiceFiscale, sizeof(p.codiceFiscale), stdin);
    p.codiceFiscale[strcspn(p.codiceFiscale, "\n")] = '\0';

    printf("Luogo di nascita: ");
    fgets(p.luogoNascita, sizeof(p.luogoNascita), stdin);
    p.luogoNascita[strcspn(p.luogoNascita, "\n")] = '\0';

    printf("Data di nascita (gg/mm/aaaa): ");
    fgets(p.dataNascita, sizeof(p.dataNascita), stdin);
    p.dataNascita[strcspn(p.dataNascita, "\n")] = '\0';

    printf("Genere (M/F): ");
    char g;
    scanf(" %c", &g);
    pulisciInput();
    p.genere = (g == 'M' || g == 'm') ? MASCHIO : FEMMINA;

    v[*n] = p;
    (*n)++;

    printf("Persona aggiunta con successo!\n");
}

// Visualizza tutte le persone
void mostraPersone(Persona v[], int n) {
	int i = 0;
    if (n == 0) {
        printf("Nessuna persona registrata.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("\nPersona #%d:\n", i + 1);
        stampaPersona(v[i]);
    }
}

// Stampa singola persona
void stampaPersona(Persona p) {
    printf("Nome: %s\n", p.nome);
    printf("Cognome: %s\n", p.cognome);
    printf("Codice fiscale: %s\n", p.codiceFiscale);
    printf("Luogo di nascita: %s\n", p.luogoNascita);
    printf("Data di nascita: %s\n", p.dataNascita);
    printf("Genere: %s\n", (p.genere == MASCHIO) ? "Maschio" : "Femmina");
}

// Cerca una persona per codice fiscale
int cercaPersona(Persona v[], int n, const char *codiceFiscale) {
	int i = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(v[i].codiceFiscale, codiceFiscale) == 0)
            return i;
    }
    return -1;
}

// Modifica una persona
void modificaPersona(Persona v[], int n) {
    char cf[20];
    printf("Inserisci il codice fiscale della persona da modificare: ");
    fgets(cf, sizeof(cf), stdin);
    cf[strcspn(cf, "\n")] = '\0';

    int i = cercaPersona(v, n, cf);
    if (i == -1) {
        printf("Persona non trovata.\n");
        return;
    }

    printf("\nDati attuali:\n");
    stampaPersona(v[i]);

    printf("\n--- Inserisci nuovi dati ---\n");
    inserisciPersona(&v[i], &i);  // riusa la funzione di inserimento per sovrascrivere

    printf("Dati modificati con successo!\n");
}

// Elimina una persona
void eliminaPersona(Persona v[], int *n) {
	int i, j;
    char cf[20];
    printf("Inserisci il codice fiscale della persona da eliminare: ");
    fgets(cf, sizeof(cf), stdin);
    cf[strcspn(cf, "\n")] = '\0';

    i = cercaPersona(v, *n, cf);
    if (i == -1) {
        printf("Persona non trovata.\n");
        return;
    }

    for (j = i; j < *n - 1; j++)
        v[j] = v[j + 1];

    (*n)--;
    printf("Persona eliminata con successo!\n");
}

// Carica i dati da file
void caricaDaFile(Persona v[], int *n) {
    FILE *fp = fopen("anagrafe.txt", "r");
    if (!fp) return; // se il file non esiste, ignora

    while (fscanf(fp, "%29[^;];%29[^;];%19[^;];%29[^;];%10[^;];%d\n",
                  v[*n].nome, v[*n].cognome, v[*n].codiceFiscale,
                  v[*n].luogoNascita, v[*n].dataNascita, (int*)&v[*n].genere) == 6) {
        (*n)++;
    }

    fclose(fp);
    printf("Dati caricati da file (%d persone)\n", *n);
}

// Salva i dati su file
void salvaSuFile(Persona v[], int n) {
	int i;
    FILE *fp = fopen("anagrafe.txt", "w");
    if (!fp) {
        printf("Errore nell'apertura del file!\n");
        return;
    }

    for (i = 0; i < n; i++) {
        fprintf(fp, "%s;%s;%s;%s;%s;%d\n",
                v[i].nome, v[i].cognome, v[i].codiceFiscale,
                v[i].luogoNascita, v[i].dataNascita, v[i].genere);
    }

    fclose(fp);
    printf("Dati salvati correttamente su file.\n");
}

// Pulisce il buffer tastiera
void pulisciInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

