#include <iostream>
using namespace std;

int main() {
    int numero;

    cout << "Inserisci un numero: ";
    cin >> numero;

    if (numero % 2 == 0) {
        cout << "Il numero è pari." << endl;
    } else {
        cout << "Il numero è dispari." << endl;
    }

    return 0;
}

