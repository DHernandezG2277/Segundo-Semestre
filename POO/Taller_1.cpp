#include <iostream>
using namespace std;

bool esVocal(char c) {
    // Pasamos mayúsculas a minúsculas restando 32 si es letra A-Z
    if (c >= 'A' && c <= 'Z') {
        c = c + 32; // convertir a minúscula
    }
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main() {
    char frase[200]; // espacio para la frase (200 caracteres máx.)
    cout << "Ingrese una frase: ";
    cin.getline(frase, 200); // leer frase completa con espacios

    int totalVocales = 0;

    for (int i = 0; frase[i] != '\0'; i++) { // recorrer hasta fin de cadena
        if (esVocal(frase[i])) {
            cout << "Vocal '" << frase[i] << "' en posicion " << i << endl;
            totalVocales++;
        }
    }

    cout << "\nLa frase ingresada fue: " << frase << endl;
    cout << "Tiene " << totalVocales << " vocales en total." << endl;

    return 0;
}
