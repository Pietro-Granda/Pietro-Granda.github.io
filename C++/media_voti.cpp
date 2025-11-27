#include <iostream>
using namespace std;

int main() {
    const int n = 5;
    double voti[n];
    double somma = 0;

    cout << "Inserisci 5 voti:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> voti[i];
        somma += voti[i];
    }

    double media = somma / n;

    cout << "La media è: " << media << endl;

    if (media >= 6) {
        cout << "Studente promosso!" << endl;
    } else {
        cout << "Studente bocciato!" << endl;
    }

    return 0;
}

