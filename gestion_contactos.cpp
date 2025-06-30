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

struct contactoEmail // Estructura para almacenar los datos de un contacto 
{
    string Nombres;
    string Apellidos;
    string Sexo;
    int Edad;
    string Telefono;
    string Email;
    string Nacionalidad;
};

contactoEmail agregarcontacto(){ // Funcion para agregar un contacto 
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
void agregarcontaco(contactoEmail contactos[],int &TAM){
    contactos[TAM] = agregarcontacto();
    TAM++;
}
void eliminarcontacto(contactoEmail contactos[], int &TAM){ // funcion para eliminar un contacto
    bool encontrado = false;
    cin.ignore();
    string buscar_email;
    cout << "Ingrese el email del contacto a eliminar: ";
    getline(cin, buscar_email);
    for (int i = 0; i < TAM; i++){
        if (contactos[i].Email == buscar_email){
            for (int j = i; j < TAM - 1; j++){
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
void contactosregistrados(contactoEmail contactos[], int &TAM){ // funcion para ver contactos registrados
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
string obtenerDominio(string email) { // funcion para separar contactos de acuerdo a sus dominios
    string dominio = "";
    bool copiar = false;
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') {
            copiar = true;
            continue;
        }
        if (copiar) {
            dominio += email[i];
        }
    }
    return dominio;
}
void contactosordenados(contactoEmail contactos[], int &TAM){ // funcion que ordena contactos de acuerdo a sus dominios
    if (TAM == 0) {
        cout << "No hay contactos para mostrar.\n";
        return;
    }
    cout << "\nGMAIL:\n"; // Muestra contactos de @gmail.com
    for (int i = 0; i < TAM; i++) {
        if (obtenerDominio(contactos[i].Email) == "gmail.com") {
            cout << "- " << contactos[i].Nombres << " " << contactos[i].Apellidos << " | " << contactos[i].Email << endl;
        }
    }
    cout << "\nOUTLOOK:\n";  // Muestra contactos de @outlook.com
    for (int i = 0; i < TAM; i++) {
        if (obtenerDominio(contactos[i].Email) == "outlook.com") {
            cout << "- " << contactos[i].Nombres << " " << contactos[i].Apellidos << " | " << contactos[i].Email << endl;
        }
    }
    cout << "\nYAHOO:\n"; // Muestra contactos de @yahoo.com
    for (int i = 0; i < TAM; i++) {
        if (obtenerDominio(contactos[i].Email) == "yahoo.com") {
            cout << "- " << contactos[i].Nombres << " " << contactos[i].Apellidos << " | " << contactos[i].Email << endl;
        }
    }
    cout << "\nOTROS DOMINIOS:\n"; // Muestra contactos de otros dominios
    for (int i = 0; i < TAM; i++) {
        string dominio = obtenerDominio(contactos[i].Email);
        if (dominio != "gmail.com" && dominio != "outlook.com" && dominio != "yahoo.com") {
            cout << "- " << contactos[i].Nombres << " " << contactos[i].Apellidos << " | " << contactos[i].Email << endl;
        }
    }
}
void mensajesalida(){ // funcion de mensaje de salida   
    cout << "Gracias por usar el programa. Hasta pronto.\n";
}
void menu(){
    int MAX = 100;
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
                agregarcontaco(contactos, TAM); 
                break;
            case 2 :
                eliminarcontacto(contactos, TAM);
                break;
            case 3 : 
                contactosregistrados(contactos, TAM);
                break;
            case 4 : 
                contactosordenados(contactos, TAM);
                break;
            case 5 :
                mensajesalida();
                break;
            default :
                cout << "Opcion invalida, intente nuevamente" << endl;
        }   
    } while (opcion != 5);
}
int main(){
    menu();
    return 0;
}
