#include <iostream>
#include <map>
#include <string>

using namespace std;

// Definimos el struct que va a tener cada contacto el cual almacena sus atributos
struct InformacionContacto {
    string numero;
    string redSocial;
    string direccion;
};

// Definimos una función para imprimir el mapa
void imprimirInformacion(const std::map<std::string, InformacionContacto>& mapa) {
    for (const auto& par : mapa) {
        cout << "Nombre: " << par.first << endl;
        cout << "Numero: " << par.second.numero << endl;
        cout << "Red Social: " << par.second.redSocial << endl;
        cout << "Dirección: " << par.second.direccion << endl;
        cout << "--------------------------" << endl;
    }
}

int main() {
    // Creamos el mapa de contactos
    map<std::string, InformacionContacto> mapaContactos;

    // Definimos los string & long del contacto
    string nombreContacto, redContacto, direccionContacto, numeroContacto;

    // Pedir información al usuario
    // Nombre
    cout << "Ingrese el nombre del nuevo contacto: ";
    cin >> nombreContacto;
    cout << endl;

    // Número
    cout << "Ingrese el número de " << nombreContacto << ": ";
    cin >> numeroContacto;  
    cout << endl;

    // Red Social
    cout << "Ingrese una red social de " << nombreContacto << ": ";
    cin >> redContacto;
    cout << endl;
    
    // Dirección
    cout << "Ingrese la dirección de " << nombreContacto << ": ";
    getline(cin >> ws, direccionContacto); // Lee toda la linea ingresada en la terminal con sus espacios y ws descarta espacios en blanco iniciales
    cout << endl;

    // Insertar elementos en el mapa
    mapaContactos[nombreContacto] = {numeroContacto, redContacto, direccionContacto};

    // Llamar a la función para imprimir la información
    imprimirInformacion(mapaContactos);

    return 0;
}