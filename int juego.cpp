#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<int, string> Figuras;

    int cantidad_datos;
    cout << "Ingrese cuantas figuras geometricas desea agregar al mapa: ";
    cin >> cantidad_datos;

    for (int i = 1; i <= cantidad_datos; i++) {
        string dato;
        cout << "Ingrese una figura: ";
        cin >> dato;

        Figuras[i] = dato;
    }

    for (const auto& par : Figuras) {
        int clave = par.first;
        string valor = par.second;
        cout << "Clave: " << clave << ", Valor: " << valor << endl;
    }

    int clave_buscada;
    cout << "Ingrese una Clave: ";
    cin >> clave_buscada;

    if (Figuras.find(clave_buscada) != Figuras.end()) {
        cout << "El elemento esta en el mapa. Su valor asociado es: " << Figuras.find(clave_buscada)->second << endl;
    } else {
        cout << "El elemento no pertenece al mapa" << endl;
    }

    return 0;
}



