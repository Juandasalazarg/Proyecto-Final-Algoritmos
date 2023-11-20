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
        return "A.png";
    }
    else if(inicial=='b'){
        return "B.png";
    }
    else if(inicial=='c'){
        return "C.png";
    }
    else if(inicial=='d'){
        return "D.png";
    }
    else if(inicial=='e'){
        return "E.png";
    }
    else if(inicial=='f'){
        return "F.png";
    }
    else if(inicial=='g'){
        return "G.png";
    }
    else if(inicial=='h'){
        return "H.png";
    }
    else if(inicial=='i'){
        return "I.png";
    }
    else if(inicial=='j'){
        return "J.png";
    }
    else if(inicial=='k'){
        return "K.png";
    }
    else if(inicial=='l'){
        return "L.png";
    }
    else if(inicial=='m'){
        return "M.png";
    }
    else if(inicial=='n'){
        return "N.png";
    }
    else if(inicial=='o'){
        return "O.png";
    }
    else if(inicial=='p'){
        return "P.png";
    }
    else if(inicial=='q'){
        return "Q.png";
    }
    else if(inicial=='r'){
        return "R.png";
    }
    else if(inicial=='s'){
        return "S.png";
    }
    else if(inicial=='t'){
        return "T.png";
    }
    else if(inicial=='u'){
        return "U.png";
    }
    else if(inicial=='v'){
        return "V.png";
    }
    else if(inicial=='x'){
        return "X.png";
    }
    else if(inicial=='y'){
        return "Y.png";
    }
    else{
        return "Z.png";
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
};

map<std::string, Contacto> añadirFavorito (map<std::string, Contacto> mapaContactos, string nombreContacto){

    string favorito;

    if(nombreContacto != ""){

        transform(nombreContacto.begin(),nombreContacto.end(),nombreContacto.begin(),::tolower);

        if (mapaContactos.find(nombreContacto) != mapaContactos.end()){

            cout << "Añadir a " << nombreContacto << " a Favoritos"<<endl;
            cout << "Confirmar acción (Y/N): ";
            cin >> favorito;
            cout << endl;
            transform(favorito.begin(),favorito.end(),favorito.begin(),::tolower);

            if(favorito == "y"){
                if(!mapaContactos[nombreContacto].favorite){

                    mapaContactos[nombreContacto].favorite = true;
                    cout << "Confirmacion: " << nombreContacto << " ha sido añadido como Favorito." << endl;

                }else{
                    cout << nombreContacto << " ya está en la lista de favoritos." << endl;
                }

            }else{
                cout << "Acción cancelada." << endl;
            }

        }else{
            cout << "El contacto no pertenece a la libreta" << endl;
        }

    }else{
        cout << "ERROR" << endl;
    }
    
    return mapaContactos;
};

int main() {
    // Creamos el mapa de contactos
    map<std::string, Contacto> mapaContactos;
    mapaContactos=add_contacto(mapaContactos);
    cin.ignore();

    // Llamar a la función para imprimir la información
    imprimirInformacion(mapaContactos);

    mapaContactos = añadirFavorito(mapaContactos, "santiago");
    imprimirInformacion(mapaContactos);

    return 0;
}