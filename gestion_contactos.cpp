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

contactoEmail agregarcontacto(){
    contactoEmail contactos;
    cin.ignore();
    cout << "Ingrese el nombre ";
    getline(cin,contactos.Nombres);
    cout << "Ingrese los apellidos: ";
    getline(cin, contactos.Apellidos);
    cout << "Ingrese el sexo: ";
    getline(cin, contactos.Sexo);
    cout << "Ingrese la edad de la persona: ";
    cin >> contactos.Edad;
    cin.ignore();
    cout << "Ingrese el telefono de la persona: ";
    getline(cin,contactos.Telefono);
    cout << "Ingrese el email del contacto: ";
    getline(cin,contactos.Email);
    cout << "Ingrese la nacionalidad de la persona: ";
    getline(cin, contactos.Nacionalidad);
    return contactos;
}

void agregarcontaco(contactoEmail contactos[],int &TAM, int &MAX){
    contactos[TAM] = agregarcontacto();
    TAM++;
    MAX++;
}

void eliminarcontacto(contactoEmail contactos[], int &TAM){
    bool encontrado = false;
    string buscar_email;
    cout << "Ingrese el email del contacto a eliminar: ";
    getline(cin, buscar_email);
    for (int i = 0; i < TAM; i++){
        if (contactos[i].Email == buscar_email){
            for (int j = 0; i < TAM - 1; j++){
                contactos[j] = contactos[j + 1];
            }
            TAM --; 
            encontrado = true;
            cout << "Contacto eliminado. " << endl;
        }
    }
    if (encontrado == false){
        cout << "No se encontro el contacto" << endl;
    }
}
void contactosregistrados(contactoEmail contactos[], int TAM){
    cout << "Contactos registrados: " << endl; 
    for (int i = 0; i < TAM; i++) {
        cout << " [ " << i + 1 << " ] ";
        cout << "Nombre: " << contactos[i].Nombres << endl;
        cout << "Apellido: " << contactos[i].Apellidos << endl;
        cout << "Sexo: " << contactos[i].Sexo << endl;
        cout << "Edad: " << contactos[i].Edad << endl;
        cout << "Telefono: " << contactos[i].Telefono << endl;
        cout << "Email: " << contactos[i].Email << endl;
        cout << "Nacionalidad: " << contactos[i].Nacionalidad << endl;
    }
    cout << endl;
}

void contactosexistentes(){

}
void mensajesalida(){

}

void menu(){
    int MAX = 1;
    contactoEmail contactos[MAX];
    int TAM = 0;
    int opcion;
    do {
        cout << "1. Agregar un contacto" << endl;
        cout << "2. Eliminar un contacto" << endl;
        cout << "3. Mostrar contactos registrados" << endl;
        cout << "4. Mostrar contactos existentes" << endl;
        cout << "5. Salir del programa" << endl;
        cin >> opcion;
        switch (opcion){
            case 1 :
                agregarcontaco(contactos, TAM, MAX); 
                break;
            case 2 :
                eliminarcontacto(contactos, TAM);
                break;
            case 3 : 
                contactosregistrados(contactos, TAM);
                break;
            case 4 : 
                contactosexistentes();
                break;
            case 5 :
                mensajesalida();
        }   

    } while (opcion != 5);
}
int main(){
    menu();
    return 0;
}
