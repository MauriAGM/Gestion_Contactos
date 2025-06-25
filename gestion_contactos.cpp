/*Crear una estructura llamada contactoEmail que tenga las siguientes características: nombres completos, sexo, edad,
teléfono, email, nacionalidad
El programa debe constar de un menú que permita:
a) Agregar un contacto
b) Eliminar un contacto
c) Mostrar listado general de contactos registrados hasta ese momento.
d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com, outlook.com,
yahoo.com, etc.)
e) Salir del programa
El programa debe mantenerse en ejecución continuamente hasta que usuario indique que desea salir del mismo.*/

#include<iostream>
using namespace std;

struct contactoEmail
{
    string Nombres;
    string Apellidos;
    string Sexo;
    int Edad;
    string Telefono;
    string Email;
    string Nacionalidad;
};

void agregarcontacto(){

}

void eliminarcontacto(){

}
void contactosregistrados(){

}
void contactosexistentes(){

}
void mensajesalida(){

}

void menu(){
    cout << "1. Agregar un contacto" << endl;
    cout << "2. Eliminar un contacto" << endl;
    cout << "3. Mostrar contactos registrados" << endl;
    cout << "4. Mostrar contactos existentes" << endl;
    cout << "5. Salir del programa" << endl;
    int opcion;
    do {
        cin >> opcion;
        switch (opcion){
            case 1 :
                agregarcontacto();
                break;
            case 2 :
                eliminarcontacto();
                break;
            case 3 : 
                contactosregistrados();
                break;
            case 4 : 
                contactosexistentes();
                break;
            case 5 :
                mensajesalida();
            default:
                cout <<  "ERROR" ;
        }

    } while (opcion != 5);
}

int main(){
    menu();
    return 0;
}
