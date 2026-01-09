#include <iostream>   // include la libreria per input/output (std::cout, std::cin)
#include <string>     // include la libreria per usare std::string (testo)
#include <cstdlib>    // include la libreria per rand(), srand()
#include <ctime>      // include la libreria per time()

// Struttura che rappresenta un personaggio
struct Personaggio {                  // definizione della struct Personaggio
    std::string nome;                 // nome del personaggio
    int vita;                         // punti vita (HP)
    int attacco;                      // valore di attacco
    int difesa;                       // valore di difesa
    int pozioni;                      // numero di pozioni di cura
};                                    // fine definizione struct

// Funzione che mostra lo stato di un personaggio
void mostraStato(const Personaggio &p) {               // funzione che riceve un Personaggio per costante riferimento
    std::cout << "-----------------------------\n";    // stampa una linea di separazione
    std::cout << "Nome: " << p.nome << "\n";           // stampa il nome del personaggio
    std::cout << "Vita: " << p.vita << "\n";           // stampa i punti vita
    std::cout << "Attacco: " << p.attacco << "\n";     // stampa il valore di attacco
    std::cout << "Difesa: " << p.difesa << "\n";       // stampa il valore di difesa
    std::cout << "Pozioni: " << p.pozioni << "\n";     // stampa il numero di pozioni disponibili
    std::cout << "-----------------------------\n";    // stampa una linea di separazione
}                                                      // fine funzione mostraStato

// Funzione che esegue un attacco da un personaggio a un altro
void attaccare(Personaggio &attaccante, Personaggio &bersaglio) { // riceve attaccante e bersaglio per riferimento
    int variazione = std::rand() % 5;                             // genera una variazione casuale tra 0 e 4
    int dannoGrezzo = attaccante.attacco + variazione;            // calcola il danno base sommando attacco e variazione
    int dannoFinale = dannoGrezzo - bersaglio.difesa;             // sottrae la difesa del bersaglio dal danno

    if (dannoFinale < 1) {                                        // se il danno finale è minore di 1
        dannoFinale = 1;                                          // imposta il danno minimo a 1
    }                                                             // fine if

    bersaglio.vita -= dannoFinale;                                // diminuisce i punti vita del bersaglio

    std::cout << attaccante.nome << " attacca "                   // inizio del messaggio di attacco
              << bersaglio.nome << " e infligge "                 // continua il messaggio
              << dannoFinale << " danni!\n";                      // stampa il danno inflitto

    if (bersaglio.vita < 0) {                                     // se la vita del bersaglio è sotto zero
        bersaglio.vita = 0;                                       // riportiamo la vita a zero
    }                                                             // fine if
}                                                                 // fine funzione attaccare

// Funzione che usa una pozione per curare il personaggio
void usarePozione(Personaggio &p) {                               // riceve un Personaggio per riferimento
    if (p.pozioni > 0) {                                          // se il personaggio ha almeno una pozione
        int cura = 20;                                            // quantità di vita recuperata con una pozione
        p.vita += cura;                                           // aumenta i punti vita
        p.pozioni--;                                              // diminuisce il numero di pozioni

        std::cout << p.nome << " usa una pozione e recupera "     // stampa il messaggio di cura
                  << cura << " punti vita!\n";                    // continua il messaggio
        std::cout << "Pozioni rimaste: " << p.pozioni << "\n";    // mostra quante pozioni restano
    } else {                                                      // altrimenti (nessuna pozione)
        std::cout << p.nome << " non ha piu' pozioni!\n";         // messaggio: nessuna pozione disponibile
    }                                                             // fine if/else
}                                                                 // fine funzione usarePozione

int main() {                                                      // funzione principale del programma
    std::srand(static_cast<unsigned int>(std::time(nullptr)));    // inizializza il generatore di numeri casuali con il tempo attuale

    Personaggio giocatore;                                        // dichiara il personaggio controllato dal giocatore
    Personaggio nemico;                                           // dichiara il personaggio nemico

    std::cout << "=== MINI RPG DI TESTO ===\n";                   // stampa il titolo del gioco
    std::cout << "Inserisci il nome del tuo eroe: ";              // chiede all'utente il nome dell'eroe

    std::getline(std::cin, giocatore.nome);                       // legge una linea intera come nome del giocatore

    giocatore.vita = 100;                                         // imposta la vita iniziale del giocatore
    giocatore.attacco = 15;                                       // imposta l'attacco iniziale del giocatore
    giocatore.difesa = 5;                                         // imposta la difesa iniziale del giocatore
    giocatore.pozioni = 3;                                        // imposta il numero iniziale di pozioni del giocatore

    nemico.nome = "Goblin";                                       // imposta il nome del nemico
    nemico.vita = 80;                                             // imposta la vita iniziale del nemico
    nemico.attacco = 12;                                          // imposta l'attacco del nemico
    nemico.difesa = 3;                                            // imposta la difesa del nemico
    nemico.pozioni = 0;                                           // il nemico non ha pozioni

    std::cout << "\nUn " << nemico.nome                           // inizio messaggio: il nemico appare
              << " appare davanti a te!\n";                       // fine messaggio

    std::cout << "\n--- Stato iniziale dell'eroe ---\n";          // intestazione stato iniziale dell'eroe
    mostraStato(giocatore);                                       // chiama la funzione per mostrare lo stato del giocatore

    std::cout << "\n--- Stato iniziale del nemico ---\n";         // intestazione stato iniziale del nemico
    mostraStato(nemico);                                          // chiama la funzione per mostrare lo stato del nemico

    while (giocatore.vita > 0 && nemico.vita > 0) {               // ciclo principale: continua finché entrambi sono vivi
        std::cout << "\nTocca a te!\n";                           // indica che è il turno del giocatore
        std::cout << "1) Attaccare\n";                            // opzione 1: attacco
        std::cout << "2) Usare una pozione\n";                    // opzione 2: usare una pozione
        std::cout << "Scegli un'opzione: ";                       // chiede all'utente di scegliere
        int scelta;                                               // variabile che contiene la scelta dell'utente
        std::cin >> scelta;                                       // legge la scelta da tastiera

        if (scelta == 1) {                                        // se la scelta è 1
            attaccare(giocatore, nemico);                         // il giocatore attacca il nemico
        } else if (scelta == 2) {                                 // se la scelta è 2
            usarePozione(giocatore);                              // il giocatore usa una pozione
        } else {                                                  // qualsiasi altra scelta
            std::cout << "Opzione non valida! Hai perso il turno...\n"; // messaggio di errore e turno perso
        }                                                         // fine blocco if/else

        if (nemico.vita <= 0) {                                   // se il nemico è a 0 o meno punti vita
            std::cout << "\nHai sconfitto il " << nemico.nome     // stampa il messaggio di vittoria
                      << "!\n";                                   // fine messaggio
            break;                                                // esce dal ciclo while
        }                                                         // fine if

        std::cout << "\nTurno del nemico...\n";                   // indica che ora è il turno del nemico

        int chance = std::rand() % 100;                           // genera un numero casuale tra 0 e 99

        if (chance < 80) {                                        // 80% di probabilità che il nemico attacchi
            attaccare(nemico, giocatore);                         // il nemico attacca il giocatore
        } else {                                                  // altrimenti (20% dei casi)
            std::cout << nemico.nome                              // stampa il nome del nemico
                      << " ha mancato l'attacco!\n";              // messaggio: attacco mancato
        }                                                         // fine blocco if/else

        if (giocatore.vita <= 0) {                                // se i punti vita del giocatore sono 0 o meno
            std::cout << "\nSei stato sconfitto...\n";            // messaggio di sconfitta
            break;                                                // esce dal ciclo while
        }                                                         // fine if

        std::cout << "\n--- Stato dell'eroe ---\n";               // intestazione per lo stato dell'eroe
        mostraStato(giocatore);                                   // mostra lo stato aggiornato del giocatore

        std::cout << "\n--- Stato del nemico ---\n";              // intestazione per lo stato del nemico
        mostraStato(nemico);                                      // mostra lo stato aggiornato del nemico
    }                                                             // fine ciclo while

    std::cout << "\nFine della battaglia.\n";                     // messaggio di fine battaglia
    std::cout << "Grazie per aver giocato!\n";                    // messaggio di ringraziamento

    return 0;                                                     // ritorna 0: il programma è terminato correttamente
}                                                                 // fine funzione main
