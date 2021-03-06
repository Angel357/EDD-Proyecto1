#pragma once
#include "Nodo.h"
using namespace std;
class Arbol
{
public:
	Nodo* Raiz;
	Nodo* aBuscar;
	Arbol()
	{
		Raiz = nullptr;

	}

	void Insertar(string idActivo, string nombre, string descripcion, string estado);
	void Insertar2(Nodo* aux, string idActivo, string nombre, string descripcion, string estado);
	Nodo* Buscar(string idActivo);
	Nodo* Buscar2(Nodo* aux, string idActivo);
	void Eliminar(string idAcivo);
	void Eliminar2(Nodo* aux, Nodo* aux2, string idActivo);
	void Modificar(string idActivoModificar, string idActivo, string nombre, string descripcion, string estado);
	void PreOrden(Nodo* aux);
	Nodo* RetornarRaiz();

	void DesplegarActivo(Nodo* Raiz);
	void VerificarMiActivo(Nodo* Raiz);

	void Equilibrar(Nodo* padre, int rama, bool accion);
	void RSI(Nodo* nodo);
	void RSD(Nodo* nodo);
	void RDI(Nodo* nodo);
	void RDD(Nodo* nodo);

};
