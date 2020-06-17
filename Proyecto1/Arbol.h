#pragma once
#include "Nodo.h"
class Arbol
{
public:
	Nodo* Raiz;
	Nodo* Aux;
	Arbol()
	{
		Aux = nullptr;
		Raiz = nullptr;

	}
	void Insertar(string idActivo, string nombre, string descripcion, string estado);
	void Insertar2(Nodo* aux, string idActivo, string nombre, string descripcion, string estado);
	Nodo* Buscar(int numero);
	Nodo* Buscar2(Nodo* aux, int numero);
	void Eliminar(int numero);
	void Eliminar2(Nodo* aux, int numero);
	void Modificar(int numero, int nuevoNumero);
	void PreOrden(Nodo* aux);
};
