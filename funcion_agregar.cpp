#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>
#include <stack>


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
}
map<std::string, Contacto> eliminar_contacto(map<std::string, Contacto> mapaContactos){
    string nombreContacto;
    
    cout << "Ingrese el nombre del contacto que desea eliminar: ";
    getline(cin,nombreContacto);
    transform(nombreContacto.begin(),nombreContacto.end(),nombreContacto.begin(),::tolower);
    cout << endl;
    
    if (mapaContactos.find(nombreContacto) != mapaContactos.end()) {
       
        string eliminacion;
        cout << "Desea eliminar definitivamente el contacto? (Y/N):";
        cin >> eliminacion;
        
        if (eliminacion == "y" || eliminacion == "Y" ){
            mapaContactos.erase(nombreContacto);
            cout<<"El contacto se eliminó correctamente"<<endl;
        }else{
            return mapaContactos;
        }
    } else {
        cout << "El elemento no pertenece a la lista de contactos" << endl<<endl;
    }
    
    return mapaContactos;

}


stack<string> Llamar_contacto(stack<string>& recientes, const map<string, Contacto>& mapaContactos) {
    long num_Contacto;

    cout << "Ingrese el numero del contacto que desea llamar: ";
    cin >> num_Contacto;
    cout << endl;

    for (const auto& par : mapaContactos) {
        const string& clave = par.first;
        const long num = par.second.numero;
        if (num == num_Contacto) {
            recientes.push(clave);
        }
    }

    return recientes;
}

void reciente(stack<string>& recientes, const map<string, Contacto>& mapaContactos) {
    
    cout<<"CONTACTOS ---- RECIENTES"<<endl;
    
    while (!recientes.empty()) {
        map<string, Contacto> reserva;
        const string& contacto_reciente = recientes.top();
        reserva[contacto_reciente] = mapaContactos.at(contacto_reciente);
        recientes.pop();
        imprimirInformacion(reserva);
    }
}

int main() {
    // Creamos el mapa de contactos
    map<std::string, Contacto> mapaContactos;
    stack<string>recientes;
    mapaContactos=add_contacto(mapaContactos);
    // Llamar a la función para imprimir la información
    Llamar_contacto(recientes,mapaContactos);
    reciente(recientes,mapaContactos);
    
    
    
    return 0;
}
