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
			MenuAdmin();
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
	default:
		system("cls");
		cout << "\n\n               LA OPCION INGRESADA NO COINCIDE CON NINGUNA SALIDA, INTENTELO DE NUEVO";
		MenuUsuario(nombre, contraseña, departamento, empresa);
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

	}
	else
	{
		MenuUsuario(nombre, contraseña, departamento, empresa);
	}
}
void Menu::MisActivosRentados(string nombre, string contraseña, string departamento, string empresa)
{
	system("cls");
	int l;
	cout << "-------------------------------  Mis activos en renta  -------------------------------\n\n\n";
	//mostrar activos en renta, se tomaran de a lista doble 

	cout << "\n\n\n               Ingresar 1 para regresar al menu:\n               ";
	cin >> l;
	if (l==1)
	{
		MenuUsuario(nombre, contraseña,departamento, empresa);
	}
	else
	{
		MisActivosRentados(nombre, contraseña, departamento, empresa);
	}
}

void Menu::MenuAdmin()
{
	system("cls");
	int opcion;
	cout << "--------------------------  Menu Administrador  --------------------------";
	cout << "\n\n     1. Registrar Usuario";
	cout << "\n     2. Reporte Cubo Disperso";
	cout << "\n     3. Reporte activos disponibles en un departamento";
	cout << "\n     4. Reporte activos disponibles en una empresa";
	cout << "\n     5. Reporte transacciones";
	cout << "\n     6. Reporte activos de un usuario";
	cout << "\n     7. Activos rentados por un usuario";
	cout << "\n     8. Ordenar Transacciones";
	cout << "\n     9. Cerrar sesion";
	cout << "\n\n      Ingresar opcion:\n       --";
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		RegistrarUsuario();
		break;
	case 2:
		ReporteMatriz();
		break;
	case 3:
		ReporteActivosDepartamento();
		break;
	case 4:
		ReporteActivosEmpresa();
		break;
	case 5:
		ReporteTransaccion();
		break;
	case 6:
		ReporteActivosUsuario();
		break;
	case 7:
		ActivosRentadosUsuario();
		break;
	case 8:
		OrdenarTransacciones();
		break;
	case 9:
		system("cls");
		Login();
		break;
	default:
		system("cls");
		cout << "\n\n               LA OPCION INGRESADA NO COINCIDE CON NINGUNA SALIDA, INTENTELO DE NUEVO";
		MenuAdmin();
		break;
	}

}
void Menu::RegistrarUsuario()
{
	system("cls");
	string nombre, contraseña, departamento, empresa;
	char l;
	int opcion;
	cout << "-----------------------------  ADMINISTRADOR  -----------------------------";
	cout << "\n-----------------------------  Crear Usuario  -----------------------------";

	cout << "\n\n          Elija una opcion:\n          1. Crear Usuario\n          2. Regresar al menu\n";
	cin >> opcion;
	if (opcion==1)
	{
		cout << "\n\n-------Ingresar Nombre de Usuario\n--------";
		cin >> nombre;
		cout << "\n-------Ingresar Contraseña\n--------";
		cin >> contraseña;
		cout << "\n-------Ingresar Departamento\n--------";
		cin >> departamento;
		cout << "\n-------Ingresar Empresa\n--------";
		cin >> empresa;

		Matriz* m = new Matriz;
		if (m->BuscarUsuario(nombre, contraseña, departamento, empresa) != nullptr)
		{
			system("cls");
			cout << "\n\n\n         No puede existir un usuario con el mismo nombre en la misma empresa y en el mismo departamento\n\n\n   ingreselo nuevamente!";
			cout << "\n    presione cualquier tecla para continuar";
			cin >> l;
			RegistrarUsuario();
		}
		else
		{
			system("cls");
			m->Insertar(nombre, contraseña, departamento, empresa);
			cout << "\n\n        Usuario " << nombre << " agregado con exito!";

		}
	}
	else if (opcion==2)
	{
		MenuAdmin();
	}
	else
	{
		char l2;
		system("cls");
		cout << "\n\n                opcion incorrecta!\n";
		cin >> l2;

		RegistrarUsuario();
	}
}
void Menu::ReporteMatriz()
{
	char l;
	system("cls");
	cout << "\n\n--------------------------  Se creo reporte de matriz dispersa\n\n   presione cualquier tecla para volver al menu:\n   ";
	// crear reporte de matriz

	cin >> l;
	MenuAdmin();
}
void Menu::ReporteActivosDepartamento()
{
	char l;
	string departamento;
	system("cls");
	cout << "\n\n              ingresar departamento:\n              ";
	cin >> departamento;
	// crear reporte de activos por departamento

	cout << "\n\n--------------------------  Se creo reporte de activos por departamento\n\n   presione cualquier tecla para volver al menu:\n   ";
	
	cin >> l;
	MenuAdmin();
}
void Menu::ReporteActivosEmpresa()
{
	char l;
	string empresa;
	system("cls");
	cout << "\n\n              ingresar empresa:\n              ";
	cin >> empresa;
	// crear reporte de activos por empresa

	cout << "\n\n--------------------------  Se creo reporte de activos por empresa\n\n   presione cualquier tecla para volver al menu:\n   ";

	cin >> l;
	MenuAdmin();
}
void Menu::ReporteTransaccion()
{
	system("cls");
	char l;
	//crear reporte transacciones
	cout << "\n\n              Se creo el reporte de transacciones!\n\n             presione cualquier tecla para volver al menu";
	cin >> l;
	MenuAdmin();
}
void Menu::ReporteActivosUsuario()
{
	system("cls");
	char l;
	int opcion;
	string usuario;
	cout << "----------------------------------- Reporte de activos de usuario -----------------------------------";
	cout << "\n\n               1. ingresar usuario\n               2. regresar al menu\n                ";
	cin >> opcion;
	if (opcion==1)
	{
		cout << "\n\n         Ingrese el usuario al que desea ver sus activos\n";
		cin >> usuario;

		// generar reporte de activos de un usuario
		cout << "\n\n           se genero reporte de activos del usuario: "<<usuario<<" \n\n           presione cualquier tecla para volver al menu";
		cin >> l;
		MenuAdmin();
	}
	else if (opcion==2)
	{
		MenuAdmin();
	}
	else
	{
		char l;
		cout << "\n\n        la opcion selecciona no coincide con ninguna permitida";
	    cin >> l;
		MenuAdmin();

	}
}
void Menu::ActivosRentadosUsuario()
{
	system("cls");
	string Usuario;
	int opcion;
	char l;
	cout << "----------------------------- Activos rentados por usuario -----------------------------";
	cout << "\n\n               1. ingresar usuario\n               2. regresar al menu\n                ";
	cin >> opcion;
	if (opcion == 1)
	{
		cout << "\n\n         Ingrese el usuario del que desea conocer que acrivos a rentado\n";
		cin >> Usuario;

		// generar reporte de activos rentados por un usuario usuario
		cout << "\n\n           se genero reporte de activos rentados por el usuario: " << Usuario << " \n\n           presione cualquier tecla para volver al menu";
		cin >> l;
		MenuAdmin();
	}
	else if (opcion == 2)
	{
		MenuAdmin();
	}
	else
	{
		char l;
		cout << "\n\n        la opcion selecciona no coincide con ninguna permitida";
		cin >> l;
		MenuAdmin();
	}
}
void Menu::OrdenarTransacciones()
{
	int opcion;
	string orden;
	char l;

	cout << "----------------------------------- Orden de Transacciones -----------------------------------";
	cout << "\n\n               seleccione una accion:";
	cout << "\n\n               1. ordenascendete\n               2. orden desendente\n                ";
	cin >> opcion;
	if (opcion == 1)
	{
		

		// generar reporte de transacciones ascendente (immprimirla como esta)
		cout << "\n\n           se genero reporte ascendente de transacciones\n\n           presione cualquier tecla para volver al menu";
		cin >> l;
		MenuAdmin();
	}
	else if (opcion == 2)
	{
		// generar reporte de transacciones descendentes (recorrer la lista del fin al inicio)
		cout << "\n\n           se genero reporte descendente de transacciones\n\n           presione cualquier tecla para volver al menu";
		cin >> l;
		MenuAdmin();
	}
	else
	{
		char l;
		cout << "\n\n        la opcion selecciona no coincide con ninguna permitida";
		cin >> l;
		MenuAdmin();

	}
}
