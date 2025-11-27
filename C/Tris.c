#include <stdio.h>

int main() {
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    int pos, mosse = 0;
    char giocatore = 'X';

    while (1) {
        // stampa del tabellone
        printf("\n %c | %c | %c\n", board[0], board[1], board[2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c\n", board[3], board[4], board[5]);
        printf("---+---+---\n");
        printf(" %c | %c | %c\n\n", board[6], board[7], board[8]);

        // input della mossa
        printf("Giocatore %c, scegli una posizione (1-9): ", giocatore);
        scanf("%d", &pos);
        pos--;

        // controllo della validità
        if (pos < 0 || pos > 8 || board[pos] == 'X' || board[pos] == 'O') {
            printf("Mossa non valida! Riprova.\n");
            continue;
        }

        // segnare la mossa
        board[pos] = giocatore;
        mosse++;

        // controllo del vincitore
        int vittoria =
            (board[0]==giocatore && board[1]==giocatore && board[2]==giocatore) ||
            (board[3]==giocatore && board[4]==giocatore && board[5]==giocatore) ||
            (board[6]==giocatore && board[7]==giocatore && board[8]==giocatore) ||
            (board[0]==giocatore && board[3]==giocatore && board[6]==giocatore) ||
            (board[1]==giocatore && board[4]==giocatore && board[7]==giocatore) ||
            (board[2]==giocatore && board[5]==giocatore && board[8]==giocatore) ||
            (board[0]==giocatore && board[4]==giocatore && board[8]==giocatore) ||
            (board[2]==giocatore && board[4]==giocatore && board[6]==giocatore);

        if (vittoria) {
            printf("\nGiocatore %c ha vinto!\n", giocatore);
            break;
        }

        if (mosse == 9) {
            printf("\nPareggio! Nessun vincitore.\n");
            break;
        }

        // cambio del giocatore
        giocatore = (giocatore == 'X') ? 'O' : 'X';
    }

    return 0;
}

