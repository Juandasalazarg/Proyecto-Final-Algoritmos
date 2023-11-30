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
    string icono;
};
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
    
};
// Definimos una función para imprimir el mapa
void imprimirInformacion(const std::map<std::string, Contacto>& mapa) {
    for (const auto& par : mapa) {
        cout << "Nombre: " << par.first << endl;
        cout << "Numero: " << par.second.numero << endl;
        cout << "Red Social: " << par.second.redSocial << endl;
        cout << "Dirección: " << par.second.direccion << endl;
        cout << "Favoritos: " << (par.second.favorite ? "Si" : "No") << endl;
        cout << "Icono " << par.second.icono << endl;
        cout << "--------------------------" << endl;
    }
    cout<<endl;
};
string icono(string nombre){
    char inicial =nombre[0];
    if(inicial=='a'){
        return "🅐";
    }
    else if(inicial=='b'){
        return "🅑";
    }
    else if(inicial=='c'){
        return "🅒";
    }
    else if(inicial=='d'){
        return "🅓";
    }
    else if(inicial=='e'){
        return "🅔";
    }
    else if(inicial=='f'){
        return "🅕";
    }
    else if(inicial=='g'){
        return "🅖";
    }
    else if(inicial=='h'){
        return "🅗";
    }
    else if(inicial=='i'){
        return "🅘";
    }
    else if(inicial=='j'){
        return "🅙";
    }
    else if(inicial=='k'){
        return "🅚";
    }
    else if(inicial=='l'){
        return "🅛";
    }
    else if(inicial=='m'){
        return "🅜";
    }
    else if(inicial=='n'){
        return "🅝";
    }
    else if(inicial=='o'){
        return "🅞";
    }
    else if(inicial=='p'){
        return "🅟";
    }
    else if(inicial=='q'){
        return "🅠";
    }
    else if(inicial=='r'){
        return "🅡";
    }
    else if(inicial=='s'){
        return "🅢";
    }
    else if(inicial=='t'){
        return "🅣";
    }
    else if(inicial=='u'){
        return "🅤";
    }
    else if(inicial=='v'){
        return "🅥";
    }
    else if(inicial=='x'){
        return "🅧";
    }
    else if(inicial=='y'){
        return "🅨";
    }
    else{
        return "🅩";
    }
}
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
    t.icono = icono(nombreContacto);

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
int main() {
    // Creamos el mapa de contactos
    map<std::string, Contacto> mapaContactos;
    mapaContactos=add_contacto(mapaContactos);
    cin.ignore();
    mapaContactos=eliminar_contacto(mapaContactos);
    cin.ignore();
    // Llamar a la función para imprimir la información
    imprimirInformacion(mapaContactos);

    return 0;
}
