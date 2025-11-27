#include <iostream>
using namespace std;

struct Contatto {
    string nome;
    string telefono;
};

int main() {
    Contatto rubrica[3];

    cout << "=== Registrazione contatti ===" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Nome: ";
        cin >> rubrica[i].nome;

        cout << "Telefono: ";
        cin >> rubrica[i].telefono;

        cout << endl;
    }

    cout << "=== Contatti salvati ===" << endl;

    for (int i = 0; i < 3; i++) {
        cout << rubrica[i].nome << " - " << rubrica[i].telefono << endl;
    }

    return 0;
}

