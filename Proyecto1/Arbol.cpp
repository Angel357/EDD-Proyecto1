#include "Arbol.h"
#include "Nodo.h"
#include <iostream>
using namespace std;

void Arbol::Insertar(string idActivo, string nombre, string descripcion, string estado)
{
	Nodo* Aux = Raiz;
	if (Aux == nullptr)
	{
		Raiz = new Nodo(idActivo, nombre, descripcion, estado);
	}
	else
	{
		Insertar2(Aux, idActivo, nombre, descripcion, estado);
	}
}
void Arbol::Insertar2(Nodo* aux, string idActivo, string nombre, string descripcion, string estado)
{
	if (aux->izquierda == nullptr&&aux->derecha == nullptr)
	{
		if (idActivo > aux->IDactivo || idActivo == aux->IDactivo)
		{
			aux->derecha = new Nodo(numero);
		}
		else
		{
			aux->izquierda = new Nodo(numero);
		}
	}
	else if (numero > aux->numero || numero == aux->numero)
	{
		if (aux->derecha != nullptr)
		{
			aux = aux->derecha;
			Insertar2(aux, numero);
		}
		else
		{
			aux->derecha = new Nodo(numero);
		}
	}
	else
	{
		if (aux->izquierda != nullptr)
		{
			aux = aux->izquierda;
			Insertar2(aux, numero);
		}
		else
		{
			aux->izquierda = new Nodo(numero);
		}
	}
}

Nodo* Arbol::Buscar(int numero)
{
	Aux = Raiz;
	if (Aux != nullptr)
	{

		if (Aux->numero == numero)
		{
			return Aux;
		}
		else
		{
			return Buscar2(Aux, numero);
		}
	}
}
Nodo* Arbol::Buscar2(Nodo* aux, int numero)
{
	if (aux->izquierda == nullptr&&aux->derecha == nullptr)
	{

	}
	else if (numero > aux->numero || numero == aux->numero)
	{
		if (aux->derecha != nullptr)
		{
			aux = aux->derecha;
			if (numero == aux->numero)
			{
				cout << "encontro " << numero;
				return aux;
			}
			Buscar2(aux, numero);
		}
		else
		{
			cout << "no se encontro " << numero;

		}
	}
	else
	{
		if (aux->izquierda != nullptr)
		{
			aux = aux->izquierda;
			if (numero == aux->numero)
			{
				cout << "encontro " << numero;
				return aux;
			}
			Buscar2(aux, numero);
		}
		else
		{
			cout << "no se encontro " << numero;

		}
	}
}

void Arbol::Eliminar(int numero)
{
	if (Buscar(numero)->izquierda == nullptr&&Buscar(numero)->derecha == nullptr)
	{
		cout << "se elimino " << numero;
		delete Buscar(numero);
	}
	else if (Aux->izquierda != nullptr&&Aux->izquierda->derecha == nullptr)
	{
		Aux->numero = Aux->izquierda->numero;
		cout << "se elimino " << numero;
		delete Aux->izquierda;
	}
	else
	{
		Eliminar2(Aux, numero);

	}
}
void Arbol::Eliminar2(Nodo* aux, int numero)
{
	Aux = aux;
	if (Aux->derecha != nullptr)
	{
		Aux = Aux->derecha;
		Eliminar2(Aux, numero);
	}
	else
	{
		Buscar(numero)->numero = Aux->numero;
		cout << Buscar(numero)->numero;
		delete Aux;
	}
}

void Arbol::Modificar(int numero, int nuevoNumero)
{
	Eliminar(numero);
	Insertar(nuevoNumero);

}

void Arbol::PreOrden(Nodo* aux)
{
	if (aux == nullptr)
	{
		return;
	}
	if (aux->numero > 0)
	{
		cout << "valor-> " << aux->numero;
	}

	PreOrden(aux->izquierda);
	PreOrden(aux->derecha);

}
