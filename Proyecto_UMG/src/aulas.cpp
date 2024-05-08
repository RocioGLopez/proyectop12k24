//Creado por Rocio Guisell Lopez espinoza 9959-23-740
#include "aulas.h"// Incluye el archivo de encabezado para las definiciones de la clase AulasCRUD.

#include <fstream>// Incluye las funciones para trabajar con archivos.
#include <iostream>// Incluye las funciones de entrada y salida estándar.
#include<stdlib.h>// Incluye funciones para el manejo de memoria dinámica, control de procesos y conversiones de cadena.
#include<cstdlib>// Incluye funciones para el control de procesos y conversiones de cadena.
#include<conio.h>// Incluye funciones para el manejo de la consola.
#include<iomanip>// Incluye funciones para formatear la salida.
using namespace std;// Se utiliza el espacio de nombres estandar.
//Definicion de la funcioón que realiza las operaciones CRUD
void AulasCRUD::CrudAula()
{
    int opcion;
    do
    {

	system("cls");//limpia pantalla
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t|     SISTEMA DE GESTION UMG - Aulas       |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Aula"<<endl;
	cout<<"\t\t\t 2. Modificar Aula"<<endl;
	cout<<"\t\t\t 3. Borrar Aula"<<endl;
	cout<<"\t\t\t 4. Desplegar Aula"<<endl;
	cout<<"\t\t\t 5. Regresar Menu Anterior"<<endl;
    cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\t |   Opcion a escoger:[1|2|3|4|5|]           |"<<endl;
	cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>opcion;


     switch(opcion)
    {
	case 1:
        IngresarAula();
		break;
    case 2:
        ModificarAula();
		break;
    case 3:
        BorrarAula();
		break;
    case 4:
        DesplegarAula();
		break;
    case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(opcion!= 5);

}
//funcion para ingresar una nueva aula
void AulasCRUD::IngresarAula() {

   system("cls"); //limpia pantalla
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Aula--------------------------------------------"<<endl;
    aulas aula;
    cout << "Ingrese el codigo del aula: ";
    cin >> aula.codigo;
    cin.ignore();//ignora el caracter de nueva linea en el buffer de entrada.

    cout << "Ingrese el nombre del aula: ";
    cin.getline(aula.nombre, 50);

    cout << "Ingrese la estatus de la aula: ";
    cin.getline(aula.estatus, 50);

    ofstream archivo("aulas.dat", ios::binary | ios::app);//Abre el archivo en modo de escritura binaria, con la opción de agregar al final.
    archivo.write(reinterpret_cast<const char*>(&aula), sizeof(aulas));// Escribe la estructura aula en el archivo.
    archivo.close();// Cierra el archivo.


    cout << "aula agregada exitosamente!" << endl;
}
//funcion para modificar una aula existente.
void AulasCRUD::ModificarAula() {
    int codigo;
    cout << "Ingrese el codigo de la aula a modificar: ";
    cin >> codigo;

    fstream archivo("aulas.dat", ios::binary | ios::in | ios::out);//abre el archivo en modo
    if (!archivo) {
        cout << "No hay aulas registradas." << endl;
        return;
    }

    aulas aula;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        if (aula.codigo == codigo) {
            cout << "Ingrese el nuevo nombre de la aula: ";
            cin.ignore();
            cin.getline(aula.nombre, 50);

            cout << "Ingrese el nuevo estatus de la aula: ";
            cin.getline(aula.estatus, 50);

            archivo.seekp(-static_cast<int>(sizeof(aulas)), ios::cur);// Mueve el puntero de escritura a la posición anterior.
            archivo.write(reinterpret_cast<const char*>(&aula), sizeof(aulas));// Escribe la estructura aula modificada en el archivo.


            encontrada = true;
            break;
        }
    }

    archivo.close();

    if (!encontrada) {
        cout << "No se encontró la aula con el codigo ingresado." << endl;
    } else {
        cout << "aula modificada exitosamente!" << endl;
    }

}
//funcion para eliminar una aula.
void AulasCRUD::BorrarAula() {
    int codigo;
    cout << "Ingrese el codigo de la aula a eliminar: ";
    cin >> codigo;

    ifstream archivo("aulas.dat", ios::binary);// Abre el archivo en modo lectura binaria.
    if (!archivo) {
        cout << "No hay aulas registradas." << endl;

    }

    ofstream archivoTmp("aulas_tmp.dat", ios::binary);// abre un archivo temporal en modo escritura binaria
    aulas aula;
    bool eliminada = false;
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        if (aula.codigo != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&aula), sizeof(aulas));// Escribe la aula en el archivo temporal si no coincide con el código proporcionado.
        } else {
            eliminada = true;
        }
    }

    archivo.close();
    archivoTmp.close();

    remove("aulas.dat");//elimina el archivo original
    rename("aulas_tmp.dat", "aulas.dat");//renombra el archivo remporal al original.

    if (eliminada) {
        cout << "aula eliminada exitosamente!" << endl;

    } else {
        cout << "No se encontró la aula con el codigo ingresado." << endl;
    }

}
//funcion para mostrar todas las aulas registradas.
void AulasCRUD::DesplegarAula() {
    system("cls");// limpia la pantalla
    cout<<"-----------------Despliegue de aulas registradas---------------------"<<endl;
    ifstream archivo("aulas.dat", ios::binary);
    if (!archivo) {
        cout << "No hay aulas registradas." << endl;
        return;
    }

    aulas aula;
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        cout << "Codigo: " << aula.codigo << endl;
        cout << "Nombre: " << aula.nombre << endl;
        cout << "Estatus: " << aula.estatus << endl;
        cout << "-----------------------------" << endl;
    }

    archivo.close();

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}



