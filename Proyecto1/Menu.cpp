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
	m = new Matriz;
	Transaccion = new LCTransacciones;
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
	NodoM* User = m->BuscarUsuario(nombre, contraseña, departamento, empresa);
	if (User!=nullptr)
	{
		if (nombre=="admin")
		{
			system("cls");
			MenuAdmin();
		}
		else 
		{
			system("cls");
			MenuUsuario(User, nombre, contraseña, departamento, empresa);

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

void Menu::MenuUsuario(NodoM* User, string nombre,string contraseña,string departamento,string empresa)
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
		AgregarActivo(User, nombre, contraseña, departamento, empresa);
		break;
	case 2:
		EliminarActivo(User,nombre, contraseña, departamento, empresa);
		break;
	case 3:
		ModificarActivo(User,nombre, contraseña, departamento, empresa);
		break;
	case 4:
		RentarActivo(User,nombre, contraseña, departamento, empresa);
		break;
	case 5:
		ActivosRentados(User,nombre, contraseña, departamento, empresa);
		break;
	case 6:
		MisActivosRentados(User,nombre, contraseña, departamento, empresa);

		break;
	case 7:
		system("cls");
		Login();
		break;
	default:
		system("cls");
		cout << "\n\n               LA OPCION INGRESADA NO COINCIDE CON NINGUNA SALIDA, INTENTELO DE NUEVO";
		MenuUsuario(User,nombre, contraseña, departamento, empresa);
		break;
	}

}
void Menu::AgregarActivo(NodoM* User, string nombre, string contraseña, string departamento, string empresa)
{
	system("cls");
	Aleatorio* al = new Aleatorio();
	string ID = al->ID,nombreActivo,descripcionActivo,estado="disponible";
	char l;
	cout << "------------------------  Agregar activo  ------------------------\n\n";
	cout << "  Ingresar nombre:\n  "; 
	cin >> nombreActivo;
	cout << "  Ingresar descripcion:\n  ";
	cin >> descripcionActivo;
	//insercion de activo en usuario
	User->avl->Insertar(ID, nombreActivo,descripcionActivo,estado);
	cout << "Activo Agregado! \n\n   presione cualquier tecla para volver al menu";
	cin >> l;
	MenuUsuario(User, nombre,contraseña,departamento,empresa);
}
void Menu::EliminarActivo(NodoM* User,string nombre, string contraseña, string departamento, string empresa)
{
	system("cls");
	string IDeliminar;
	char l;
	cout << "----------------------  Eliminar activo  ----------------------\n\n";
	// mostrar activos
	User->avl->DesplegarActivo(User->avl->Raiz);
	cout << "\n\n   ingresar ID de activo a eliminar\n  ";
	cin >> IDeliminar;
	system("cls");
	cout << "----------------------  Eliminando activo  ----------------------\n\n";
	//busqueda y descomposicion del activo
	Nodo* aux=User->avl->Buscar(IDeliminar);
	cout << "\n\n   Activo eliminado";
	cout << "\n   ID: " << IDeliminar;
	cout << "\n   Nombre: "<<aux->Nombre;
	cout << "\n   Descripcion: "<<aux->Descripcion;
	User->avl->Eliminar(IDeliminar);
	cout << "\n\n         presione cualquier tecla para volver al menu!";
	cin >> l;
	//eliminar activo
	MenuUsuario(User,nombre, contraseña, departamento, empresa);
}
void Menu::ModificarActivo(NodoM* User,string nombre, string contraseña, string departamento, string empresa)
{
	system("cls");
	string IDmodificar,nuevoNombre,nuevaDescripcion;
	char l;
	cout << "----------------------  Modificar activo  ----------------------\n\n";
	User->avl->DesplegarActivo(User->avl->Raiz);
	//obtencion de activos
	cout << "\n\n   ingresar ID de activo a Modificar\n  ";
	cin >> IDmodificar;
	system("cls");
	cout << "\n    Ingrese el nuevo nombre del activo: ";
	cin >> nuevoNombre;
	cout << "\n    Ingrese la nueva descripcion del activo: ";
	cin >> nuevaDescripcion;
	system("cls");
	cout << "----------------------  Modificando activo  ----------------------\n\n";
	Nodo* aux = User->avl->Buscar(IDmodificar);
	//busqueda y descomposicion del activo
	cout << "\n\n   Activo Modificado";
	cout << "\n   ID: " << IDmodificar;
	cout << "\n   Nombre: " << aux->Nombre;
	cout << "\n   Descripcion: " << aux->Descripcion;
	
	cout << "\n\n         presione cualquier tecla para volver al menu!";
	cin >> l;
	User->avl->Modificar(IDmodificar,IDmodificar,nuevoNombre,nuevaDescripcion,aux->Estado);
	//modificar activo
	MenuUsuario(User, nombre, contraseña, departamento, empresa);
}
void Menu::RentarActivo(NodoM* User,string nombre, string contraseña, string departamento, string empresa)
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
		NodoM* aux = m->Inicio->abajo;
		NodoM* aux2 = m->Inicio->abajo->siguiente;
		Nodo* eActivo;
		while (aux != nullptr)
		{
			while (aux2 != nullptr)
			{
				if (aux2->avl->Raiz != nullptr)
				{
					aux2->avl->DesplegarActivo;
					cout << "\n";
				}
				aux = aux->siguiente;
			}
			aux2 = aux->abajo->siguiente;
			aux = aux->abajo;
		}

		string renta;
		string diasRenta;
		char l;
		cout << "\n\n      ingresar ID de activo a rentar:\n      ";
		cin >> renta;
		aux = m->Inicio->abajo;
		aux2 = m->Inicio->abajo->siguiente;
		Nodo* ActivoRentar;
		NodoM* UsuarioRentor;
		while (aux != nullptr)
		{
			while (aux2 != nullptr)
			{
				if (aux2->avl->Raiz != nullptr)
				{
				Nodo* t=aux2->avl->Buscar(renta);
					if (!t)
					{
						ActivoRentar = t;
					}
				}
				aux = aux->siguiente;
			}
			aux2 = aux->abajo->siguiente;
			aux = aux->abajo;
		}
		cout << "\n\n\n       Activo a rentar:";
		cout << "\n\n       ID= "<<ActivoRentar->IDactivo<<"; Nombre= "<<ActivoRentar->Nombre<<"; Descripcion= "<<ActivoRentar->Descripcion;

		//mostrar atibutos del activo
		cout << "\n\n       ingrese dias a rentar\n        ";
		cin >> diasRenta;
		//modificar disponibilidad de activo

		ActivoRentar->Estado = "rentado";
		//agregar transaccion
		Aleatorio* a = new Aleatorio;
		string IDTransaccion=a->ID;
		Transaccion->Insertar(IDTransaccion,ActivoRentar->IDactivo,ActivoRentar->Nombre,User->Nombre,User->Departamento,User->Empresa,diasRenta);
		system("cls");
		cout << "\n\n       Activo Rentado!\n\n      presione cualquier tecla para volver al menu";
		cin >> l;
		MenuUsuario(User,nombre, contraseña, departamento, empresa);

	}
	else
	{
		MenuUsuario(User,nombre, contraseña, departamento, empresa);
	}


}
void Menu::ActivosRentados(NodoM* User,string nombre, string contraseña, string departamento, string empresa)
{
	system("cls");
	int opcion;
	string opcionActivo;
	cout << "--------------------------------  Activos rentados  --------------------------------";
	Transaccion->TransaccionUsuario(nombre);
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
		NodoM* aux = m->Inicio->abajo;
		NodoM* aux2 = m->Inicio->abajo->siguiente;
		Nodo* activo;
		while (aux != nullptr)
		{
			while (aux2 != nullptr)
			{
				if (aux2->avl->Raiz != nullptr)
				{
					if (aux2->avl->Buscar(opcionActivo))
					{
						activo = aux2->avl->Buscar(opcionActivo);
						activo->Estado = "disponible";
					}
				}
				aux = aux->siguiente;
			}
			aux2 = aux->abajo->siguiente;
			aux = aux->abajo;
		}
		//mostrar atributos de dicho activo
		cout << "Activo devuelto: ";
		cout << "\n   ID: "<<activo->IDactivo<<"; Nombre: "<<activo->Nombre<<"; Descripcion: "<<activo->Descripcion;

		char l;
		cout << "\n\n            presione cualquier tecla para volver al menu:";
		cin >> l;
		MenuUsuario(User,nombre, contraseña,departamento,empresa);
	}
	else
	{
		MenuUsuario(User,nombre, contraseña, departamento, empresa);
	}
}
void Menu::MisActivosRentados(NodoM* User,string nombre, string contraseña, string departamento, string empresa)
{
	system("cls");
	int l;
	cout << "-------------------------------  Mis activos en renta  -------------------------------\n\n\n";
	User->avl->VerificarMiActivo(User->avl->Raiz);

	//mostrar activos en renta, se tomaran de a lista doble 

	cout << "\n\n\n               Ingresar 1 para regresar al menu:\n               ";
	cin >> l;
	if (l==1)
	{
		MenuUsuario(User,nombre, contraseña,departamento, empresa);
	}
	else
	{
		MisActivosRentados(User,nombre, contraseña, departamento, empresa);
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
	cout << "------------------------------- Matriz dispersa -------------------------------\n\n";
	m->ImprimirMatriz;
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
	NodoM* aux = m->Inicio;
	NodoM* aux2;
	while (aux != nullptr)
	{
		if (aux->Departamento==departamento)
		{
			cout << "\n Todos los activos correspondientes al departamento " << departamento << " son:\n";
			aux2 = aux->abajo;
			while (aux2!= nullptr)
			{
				if (aux2->avl->Raiz != nullptr)
				{
					cout << "Activos de: " << aux2->Nombre<<"\n";
					aux2->avl->DesplegarActivo;
					cout << "\n";
				}
				aux2 = aux2->abajo;
			}
		}
		aux = aux->siguiente;
	}

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
	NodoM* aux = m->Inicio;
	NodoM* aux2;
	while (aux != nullptr)
	{
		if (aux->Empresa == empresa)
		{
			cout << "\n Todos los activos correspondientes a la empresa " << empresa << " son:\n";
			aux2 = aux->siguiente;
			while (aux2 != nullptr)
			{
				if (aux2->avl->Raiz != nullptr)
				{
					cout << "Activos de: " << aux2->Nombre << "\n";
					aux2->avl->DesplegarActivo;
					cout << "\n";
				}
				aux2 = aux2->siguiente;
			}
		}
		aux = aux->abajo;
	}


	cout << "\n\n--------------------------  Se creo reporte de activos por empresa\n\n   presione cualquier tecla para volver al menu:\n   ";

	cin >> l;
	MenuAdmin();
}
void Menu::ReporteTransaccion()
{
	system("cls");
	char l;
	//crear reporte transacciones
	Transaccion->MostrarTransaccionesAscendente;

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
		cout << "\n\n         Ingrese el nombre del usuario del que desea ver sus activos\n";
		cin >> usuario;
		NodoM* User = m->BuscarUsuarioUnico(usuario);
		User->avl->DesplegarActivo(User->avl->Raiz);
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
		cout << "\n\n         Ingrese el nombre del usuario del que desea conocer los activos que a rentado\n";
		cin >> Usuario;
		Transaccion->TransaccionUsuario(Usuario);
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
		
		Transaccion->MostrarTransaccionesAscendente;
		// generar reporte de transacciones ascendente (immprimirla como esta)
		cout << "\n\n           se genero reporte ascendente de transacciones\n\n           presione cualquier tecla para volver al menu";
		cin >> l;
		MenuAdmin();
	}
	else if (opcion == 2)
	{
		Transaccion->MostrarTransaccionesDescendente;
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
