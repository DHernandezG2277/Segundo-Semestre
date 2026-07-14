#include <iostream>
#include <string>
using namespace std;

bool esVocal(char c) {
    c = tolower(c);
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main() {
    string frase;
    cout << "Ingrese una frase: ";
    getline(cin, frase);

    int totalVocales = 0;

    for (int i = 0; i < frase.length(); i++) {
        if (esVocal(frase[i])) {
            cout << "Vocal '" << frase[i] << "' en posicion " << i << endl;
            totalVocales++;
        }
    }

    cout << "\nLa frase ingresada fue: " << frase << endl;
    cout << "Tiene " << totalVocales << " vocales en total." << endl;

    return 0;
}
