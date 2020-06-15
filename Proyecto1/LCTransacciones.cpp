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
void LCTransacciones::Insertar(string IdTransaccion, string IdActivo, string UsuarioRentor, 
							   string URDepartamento, string UREmpresa, string Fecha, 
							   string DiasRenta)
{
	NodoLC* Nuevo;
	Nuevo = new NodoLC(IdTransaccion, IdActivo, UsuarioRentor, URDepartamento,
		               UREmpresa, Fecha, DiasRenta);
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
	if (LCVacia())
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



