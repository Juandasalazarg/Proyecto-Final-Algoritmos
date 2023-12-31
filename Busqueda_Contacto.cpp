#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

// Definimos el struct que va a tener cada contacto el cual almacena sus atributos
struct Contacto {
    long numero;
    string redSocial;
    string direccion;
    bool favorite;
};

// Definimos una función para imprimir el mapa
void imprimirInformacion(const std::map<std::string, Contacto>& mapa) {
    for (const auto& par : mapa) {
        cout << "Nombre: " << par.first << endl;
        cout << "Numero: " << par.second.numero << endl;
        cout << "Red Social: " << par.second.redSocial << endl;
        cout << "Dirección: " << par.second.direccion << endl;
        cout << "Favoritos: " << (par.second.favorite ? "Si" : "No") << endl;
        cout << "--------------------------" << endl;
    }
    cout<<endl;
};

map<std::string, Contacto> add_contacto(map<std::string, Contacto> mapaContactos){
    string nombreContacto,Contactofav;
    bool favorito;
    Contacto t;

    // Pedir información al usuario
    // Nombre
    cout << "Ingrese el nombre del nuevo contacto: ";
    getline(cin,nombreContacto);
    transform(nombreContacto.begin(),nombreContacto.end(),nombreContacto.begin(),::tolower);
    cout << endl;

    // Número
    cout << "Ingrese el número de " << nombreContacto << ": ";
    cin >> t.numero;  
    cout << endl;

    // Red Social
    cout << "Ingrese una red social de " << nombreContacto << ": ";
    cin >> t.redSocial;
    cout << endl;
    
    // Dirección
    cout << "Ingrese la dirección de " << nombreContacto << ": ";
    getline(cin>>ws, t.direccion); // Lee toda la linea ingresada en la terminal con sus espacios y ws descarta espacios en blanco iniciales
    cout << endl;

    // Favoritos
    cout << "Desea Agregar a: " << nombreContacto << " como favorito? (Y/N): ";
    cin >> Contactofav;
    transform(Contactofav.begin(),Contactofav.end(),Contactofav.begin(),::tolower);
    if(Contactofav=="y"){
        t.favorite=true;
    }
    else{
        t.favorite=false;
    }
    
    cout << endl;
    
    // Insertar elementos en el mapa
    mapaContactos[nombreContacto] = t;
    return mapaContactos;
};

void buscarContactosPorNombre(const std::map<std::string, Contacto>& mapaContactos) {
    string nombreBuscado;
    cout << "Ingrese el nombre a buscar: ";
    getline(cin, nombreBuscado);

    bool encontrados = false;

    for (const auto& entrada : mapaContactos) {
        // Comparar sin distinción de mayúsculas
        string claveMinuscula = entrada.first;
        transform(claveMinuscula.begin(), claveMinuscula.end(), claveMinuscula.begin(), ::tolower);
        string nombreMinuscula = nombreBuscado;
        transform(nombreMinuscula.begin(), nombreMinuscula.end(), nombreMinuscula.begin(), ::tolower);

        if (claveMinuscula.find(nombreMinuscula) != string::npos) {
            cout << "Nombre: " << entrada.first << endl;
            cout << "Número: " << entrada.second.numero << endl;
            cout << "Red Social: " << entrada.second.redSocial << endl;
            cout << "Dirección: " << entrada.second.direccion << endl;
            cout << "Favorito: " << (entrada.second.favorite ? "Sí" : "No") << endl << endl;
            encontrados = true;
        }
    }

    if (!encontrados) {
        cout << "No se encontraron resultados para el nombre buscado." << endl;
    }
}


int main() {
    
    // Creamos el mapa de contactos
    map<string, Contacto> mapaContactos;
    mapaContactos = add_contacto(mapaContactos);
    cin.ignore();
    mapaContactos = add_contacto(mapaContactos);
    cin.ignore();
    mapaContactos = add_contacto(mapaContactos);
    cin.ignore();
    mapaContactos = add_contacto(mapaContactos);
    cin.ignore();
    // Llamar a la función para imprimir la información
    imprimirInformacion(mapaContactos);
    
    // Buscar contactos
    buscarContactosPorNombre(mapaContactos);

    return 0;
}
