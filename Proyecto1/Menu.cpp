#include "Menu.h"
#include "Matriz.h"
#include "Aleatorio.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void Menu::Iniciar()
{
	int n;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@ RENTA DE ACTIVOS CAST @@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";
	cout << "1. Iniciar sesion\n\n";
	cout << "---ingresar opcion\n\n---";
	cin >> n;
	system("cls");
	if (n==1)
	{
		Login();
	}
}

void Menu::Login()
{
	system("cls");
	string nombre, contraseña, departamento, empresa;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@ RENTA DE ACTIVOS CAST @@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";
	cout << "                                  LOGIN\n\n";
	cout << "---Ingresar Usuario:\n--- ";
	cin >> nombre;
	cout << "\n";
	cout << "---Ingresar Contraseña:\n--- ";
	cin >> contraseña;
	cout << "\n";
	cout << "---Ingresar Departamento:\n--- ";
	cin >> departamento;
	cout << "\n";
	cout << "---Ingresar Empresa:\n--- ";
	cin >> empresa;
	cout << "\n";
	Matriz* m = new Matriz;
	if (m->BuscarUsuario(nombre, contraseña, departamento, empresa)!=nullptr)
	{
		if (nombre=="admin")
		{
			system("cls");
			MenuAdmin(nombre, contraseña, departamento, empresa);
		}
		else 
		{
			system("cls");
			MenuUsuario(nombre, contraseña, departamento, empresa);

		}
	}
	else
	{
		char t;
		cout << "                No se encontro el usuario en la base de datos\n";
		cout << "                Probablemente inserto mal algun campo, verifiquelos!\n";
		cout << "     nombre: " << nombre << "\n     contraseña: " << contraseña << "\n     departamento: " << departamento << "\n     empresa: " << empresa; 
		cout << "\n\n          presione cualquier tecla para continuar";
		cin >> t;
		Login();
	}
}

void Menu::MenuUsuario(string nombre,string contraseña,string departamento,string empresa)
{
	system("cls");
	int opcion;
	cout << "------------------------------  " << nombre << "  ------------------------------\n\n";
	cout << "             1. agregar un activo\n";
	cout << "             2. eliminar activo\n";
	cout << "             3. modificar activo\n";
	cout << "             4. rentar activo\n";
	cout << "             5. activos rentados\n";
	cout << "             6. mis activos rentados\n";
	cout << "             7. cerrar sesion\n\n";
	cout << "  Ingresar opcion:\n--";
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		AgregarActivo(nombre, contraseña, departamento, empresa);
		break;
	case 2:
		EliminarActivo(nombre, contraseña, departamento, empresa);
		break;
	case 3:
		ModificarActivo(nombre, contraseña, departamento, empresa);
		break;
	case 4:
		RentarActivo(nombre, contraseña, departamento, empresa);
		break;
	case 5:
		ActivosRentados(nombre, contraseña, departamento, empresa);
		break;
	case 6:
		MisActivosRentados(nombre, contraseña, departamento, empresa);

		break;
	case 7:
		system("cls");
		Login();
		break;
	}

}
void Menu::AgregarActivo(string nombre, string contraseña, string departamento, string empresa)
{
	system("cls");
	Aleatorio* al = new Aleatorio();
	string ID = al->ID,nombreActivo,descripcionActivo;
	char l;
	cout << "------------------------  Agregar activo  ------------------------\n\n";
	cout << "  Ingresar nombre:\n  "; 
	cin >> nombreActivo;
	cout << "  Ingresar descripcion:\n  ";
	cin >> descripcionActivo;

	cout << "Activo Agregado! \n\n   presione cualquier tecla para volver al menu";
	cin >> l;
	MenuUsuario(nombre,contraseña,departamento,empresa);
}
void Menu::EliminarActivo(string nombre, string contraseña, string departamento, string empresa)
{
	system("cls");
	string IDeliminar,ActibvoNombre,ActivoDescripcion;
	char l;
	cout << "----------------------  Eliminar activo  ----------------------\n\n";

	//obtencion de activos
	cout << "\n\n   ingresar ID de activo a eliminar\n  ";
	cin >> IDeliminar;
	system("cls");
	cout << "----------------------  Eliminando activo  ----------------------\n\n";
	//busqueda y descomposicion del activo
	cout << "\n\n   Activo eliminado";
	cout << "\n   ID: " << IDeliminar;
	cout << "\n   Nombre: "<<ActibvoNombre;
	cout << "\n   Descripcion: "<<ActivoDescripcion;
	cout << "\n\n         presione cualquier tecla para volver al menu!";
	cin >> l;
	//eliminar activo
	MenuUsuario(nombre, contraseña, departamento, empresa);
}
void Menu::ModificarActivo(string nombre, string contraseña, string departamento, string empresa)
{
	system("cls");
	string IDmodificar, ActibvoNombre, ActivoDescripcion;
	char l;
	cout << "----------------------  Modificar activo  ----------------------\n\n";

	//obtencion de activos
	cout << "\n\n   ingresar ID de activo a Modificar\n  ";
	cin >> IDmodificar;
	system("cls");
	cout << "----------------------  Modificando activo  ----------------------\n\n";
	//busqueda y descomposicion del activo
	cout << "\n\n   Activo Modificado";
	cout << "\n   ID: " << IDmodificar;
	cout << "\n   Nombre: " << ActibvoNombre;
	cout << "\n   Descripcion: " << ActivoDescripcion;
	cout << "\n\n         presione cualquier tecla para volver al menu!";
	cin >> l;
	//modificar activo
	MenuUsuario(nombre, contraseña, departamento, empresa);
}
void Menu::RentarActivo(string nombre, string contraseña, string departamento, string empresa)
{
	system("cls");
	int opcion;
	cout << "------------------------  Catalogo de activos  ------------------------";
	//mostrar catalogo de activos
	cout << "\n\n      1.Rentar Activo";
	cout << "\n      2. Regresar Menu";
	cout << "\n\n      ingresar opcion:\n      ";
	cin >> opcion;
	if (opcion==1)
	{
		string renta;
		int diasRenta;
		char l;
		cout << "\n      ingresar ID de activo a rentar:\n      ";
		cin >> renta;
		cout << "\n\n\n       Activo a rentar:";
		//mostrar atibutos del activo
		cout << "\n       ingrese dias a rentar\n        ";
		cin >> diasRenta;
		//modificar disponibilidad de activo
		system("cls");
		cout << "\n\n       Activo Rentado!\n\n      presione cualquier tecla para volver al menu";
		cin >> l;
		MenuUsuario(nombre, contraseña, departamento, empresa);

	}
	else
	{
		MenuUsuario(nombre, contraseña, departamento, empresa);
	}


}
void Menu::ActivosRentados(string nombre, string contraseña, string departamento, string empresa)
{
	system("cls");
	int opcion,opcionActivo;
	cout << "--------------------------------  Activos rentados  --------------------------------";
	// escanear en las transacciones los activos rentados con el nombre del usuario

	cout << "\n\n     1. Registrar devolucion";
	cout << "\n     2. Regresar al menu";
	cout << "\n\n     ingresar opcion:\n      ";
	cin >> opcion;
	if (opcion==1)
	{
		cout << "\n\n       ingresar ID de activo a devolver: \n       ";
		cin >> opcionActivo;
		//buscar activo y cambiar su estado
		//mostrar atributos de dicho activo
		//comfbgsggnsgnsry
	}
	else
	{
		MenuUsuario(nombre, contraseña, departamento, empresa);
	}
}
