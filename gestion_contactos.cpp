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

void menu(){
    int opcion;
    do {
    

    } while (opcion != 2);
}

int main(){
    menu();
    return 0;
}
