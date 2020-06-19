#include "LCTransacciones.h"
#include "NodoLC.h"
#include <string>
#include <iostream>
using namespace std;
bool LCTransacciones::LCVacia()
{
	if (Inicio == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void LCTransacciones::Insertar(string IdTransaccion, string IdActivo,string nombreActivo, string UsuarioRentor, 
							   string URDepartamento, string UREmpresa, string DiasRenta)
{
	NodoLC* Nuevo;
	Nuevo = new NodoLC(IdTransaccion, IdActivo,nombreActivo, UsuarioRentor, URDepartamento,
		               UREmpresa, DiasRenta);
	if (LCVacia())
	{
		Nuevo->Siguiente = Nuevo;
		Nuevo->Anterior = Nuevo;
		Inicio = Nuevo;
	}
	else
	{
		Nuevo->Siguiente = Inicio;
		Nuevo->Anterior = Fin;
		Fin->Siguiente = Nuevo;
		Inicio->Anterior = Nuevo;
	}
	Fin = Nuevo;

	Ordenar(Inicio);
}

NodoLC LCTransacciones::Buscar(string IdTransaccion)
{
	if (!LCVacia())
	{
		NodoLC* aux = Inicio;
		do
		{
			if (aux->IdTransaccion == IdTransaccion)
			{
				return *aux;
			}
			aux = aux->Siguiente;
		} while (aux->Siguiente !=Inicio);
	}
}

void LCTransacciones::Ordenar(NodoLC* Inicio)
{
	NodoLC* aux2=Inicio->Siguiente;
	NodoLC* aux = Inicio;
	string DatoAux;
	while (aux->Siguiente->Siguiente!=Inicio)
	{
		while (aux2->Siguiente!=Inicio)
		{
			if (aux->IdTransaccion>aux2->IdTransaccion)
			{
				DatoAux = aux->IdTransaccion;
				aux->IdTransaccion = aux2->IdTransaccion;
				aux2->IdTransaccion = DatoAux;

			}
			aux2 = aux2->Siguiente;
		}
		aux = aux->Siguiente;
	}
}

void  LCTransacciones::TransaccionUsuario(string nombreUsuario)
{
	bool bandera=false;
	if (!LCVacia())
	{
		NodoLC* aux = Inicio;
		do
		{
			if (aux->UsuarioRentor == nombreUsuario)
			{
				bandera = true;
				cout << "\n   ID: " << aux->IdActivo << "; Nombre: " << aux->nombreActivo<<"; Tiempo de renta: "<<aux->DiasRenta<<" dias";
			}
			aux = aux->Siguiente;
		} while (aux->Siguiente != Inicio);
	}
	if (LCVacia())
	{
		cout << "No ha rentado ningun activo!";
	}

}

void LCTransacciones::MostrarTransaccionesAscendente(string prueba)
{
	if (Inicio!=nullptr)
	{
		NodoLC* aux = Inicio;
		do
		{
			if (aux)
			{
				cout << "\n ID de transaccion: " << aux->IdTransaccion << "; ID activo Rentado: " << aux->IdActivo;
				cout << " nombre de activo: " << aux->nombreActivo << " Usuario rentor: " << aux->UsuarioRentor;
				cout << " departamento: " << aux->URDepartamento << " empresa: " << aux->UREmpresa;
				cout << " dias de renta: " << aux->DiasRenta << " dias";
			}
			else
			{
				cout << "No hay transacciones que mostrar";
			}
			aux = aux->Siguiente;
		} while (aux->Siguiente != Inicio);
	}
	else
	{
		cout << "No se ha creado ninguna transaccion";
	}
	
}
void LCTransacciones::MostrarTransaccionesDescendente(string prueba)
{
	if (Inicio != nullptr)
	{
		NodoLC* aux = Fin;
		do
		{
			if (aux)
			{
				cout << "\n ID de transaccion: " << aux->IdTransaccion << "; ID activo Rentado: " << aux->IdActivo;
				cout << " nombre de activo: " << aux->nombreActivo << " Usuario rentor: " << aux->UsuarioRentor;
				cout << " departamento: " << aux->URDepartamento << " empresa: " << aux->UREmpresa;
				cout << " dias de renta: " << aux->DiasRenta << " dias";
			}
			else
			{
				cout << "\nNo hay transacciones que mostrar";
			}
			aux = aux->Anterior;
		} while (aux->Anterior != Fin);
	}
	else
	{
		cout << "\nNo se ha creado ninguna transaccion";
	}
}






