#include "Arbol.h"
#include "Nodo.h"
#include <iostream>
using namespace std;

void Arbol::Insertar(string idActivo, string nombre, string descripcion, string estado)
{
	Accion = true;
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
	int rama;
	if (aux->izquierda == nullptr&&aux->derecha == nullptr)
	{
		if (idActivo > aux->IDactivo || idActivo == aux->IDactivo)
		{
			aux->derecha = new Nodo(idActivo, nombre, descripcion, estado);
			aux->derecha->padre = aux;
			rama = 1;
			Equilibrar(aux, rama, Accion);
		}
		else
		{
			aux->izquierda = new Nodo(idActivo, nombre, descripcion, estado);
			aux->izquierda->padre = aux;
			rama = 1;
			Equilibrar(aux, rama, Accion);
		}
	}
	else if (idActivo > aux->IDactivo || idActivo == aux->IDactivo)
	{
		if (aux->derecha != nullptr)
		{
			aux = aux->derecha;
			Insertar2(aux, idActivo, nombre, descripcion, estado);
		}
		else
		{
			aux->derecha = new Nodo(idActivo, nombre, descripcion, estado);
			aux->derecha->padre = aux;
			rama = 1;
			Equilibrar(aux, rama, Accion);
		}
	}
	else
	{
		if (aux->izquierda != nullptr)
		{
			aux = aux->izquierda;
			Insertar2(aux, idActivo, nombre, descripcion, estado);
		}
		else
		{
			aux->izquierda = new Nodo(idActivo, nombre, descripcion, estado);
			aux->izquierda->padre = aux;
			rama = 1;
			Equilibrar(aux, rama, Accion);
		}
	}
}

Nodo* Arbol::Buscar(string idActivo)
{
	Nodo* aux = Raiz;
	if (aux == nullptr)
	{
		cout << "No hay ningun activo registrado";
		return;
	}
	else
	{
		return Buscar2(aux, idActivo);
	}
}
Nodo* Arbol::Buscar2(Nodo* aux, string idActivo)
{
	if (aux == nullptr)
	{
		return;
	}
	if (idActivo == aux->IDactivo)
	{
		return aux;
	}

	PreOrden(aux->izquierda);
	PreOrden(aux->derecha);
}

void Arbol::Eliminar(string idActivo)
{
	Nodo* aux = Buscar(idActivo);
	if (aux->izquierda == nullptr&&aux->derecha == nullptr)
	{
		aux = nullptr;
	}
	else if (aux->padre->izquierda != nullptr&&aux->padre->izquierda->derecha == nullptr)
	{
		aux->IDactivo = aux->izquierda->IDactivo;
		aux->Nombre = aux->izquierda->Nombre;
		aux->Descripcion = aux->izquierda->Descripcion;
		aux->Estado = aux->izquierda->Estado;

		aux->padre->izquierda = nullptr;// el nodo como tal no se elimina solo deja de formar parte del arbol
		int rama = 0;
		Accion = false;
		Equilibrar(aux->padre->padre,rama,Accion);
	}
	else
	{
		Eliminar2(aux, idActivo);
	}
}
void Arbol::Eliminar2(Nodo* aux, string idActivo)
{
	Nodo* Aux = aux;
	if (Aux->derecha != nullptr)
	{
		Aux = Aux->derecha;
		Eliminar2(Aux, idActivo);
	}
	else
	{
		aux->IDactivo = Aux->IDactivo;
		aux->Nombre = Aux->Nombre;
		aux->Descripcion = Aux->Descripcion;
		aux->Estado = Aux->Estado;
		Aux->padre->derecha = nullptr;
		int rama = 1;
		Accion = false;
		Equilibrar(aux->padre->padre, rama, Accion);
	}
}

void Arbol::Modificar(string idActivoModificar, string idActivo, string nombre, string descripcion, string estado)
{
	Eliminar(idActivoModificar);
	Insertar(idActivo, nombre, descripcion, estado);

}

void Arbol::PreOrden(Nodo* aux)
{
	if (aux == nullptr)
	{
		return;
	}
	else
	{
		cout << aux->IDactivo<<"\n";
	}

	PreOrden(aux->izquierda);
	PreOrden(aux->derecha);

}

void Arbol::Equilibrar(Nodo* padre, int rama, bool accion)
{
	bool salir = false;

	while (padre &&!salir)
	{
		if (accion)
		{
			if (rama==0)
			{
				padre->FE--;
			}
			else
			{
				padre->FE++;
			}
		}
		else
		{
			if (rama == 0)
			{
				padre->FE++;
			}
			else
			{
				padre->FE--;
			}
		}

		if (padre->FE==0)
		{
			salir = true;
		}
		else if (padre->FE==-2)
		{
			if (padre->izquierda->FE==1)
			{
				RDD(padre);
			}
			else
			{
				RSD(padre);
			}
			salir = true;
		}
		else if (padre->FE==2)
		{
			if (padre->derecha->FE==-1)
			{
				RDT(padre);
			}
			else
			{
				RSI(padre);
			}
			salir = true;
		}
		if (padre->padre)
		{
			if (padre->padre->derecha==padre)
			{
				rama = 1;
			}
			else
			{
				rama = 0;
			}
		}
		padre = padre->padre;
	}
}
void Arbol::RSI(Nodo* nodo)
{
	Nodo* padre = nodo->padre;
	Nodo* p = nodo;
	Nodo* q = p->derecha;
	Nodo* b = q->izquierda;

	if (padre)
	{
		if (padre->derecha == p)
		{
			padre->derecha = q;
		}
		else
		{
			padre->izquierda = q;
		}
	}
	else
	{
		Raiz = q;
	}

	p->derecha = b;
	q->izquierda = p;

	p->padre = q;
	if (b)
	{
		b->padre = p;
	}
	q->padre = padre;

	p->FE=0;
	q->FE=0;
}
void Arbol::RSD(Nodo* nodo)
{
	Nodo* padre = nodo->padre;
	Nodo* p = nodo;
	Nodo* q = p->izquierda;
	Nodo* b = q->izquierda;

	if (padre)
	{
		if (padre->derecha==p)
		{
			padre->derecha = q;
		}
		else
		{
			padre->izquierda = q;
		}
	}
	else
	{
		Raiz = q;
	}

	p->derecha = b;
	q->izquierda = p;

	p->padre = q;
	if (b)
	{
		b->padre = p;
	}
	q->padre = padre;

	p->FE = 0;
	q->FE = 0;
}
void Arbol::RDI(Nodo* nodo)
{
	Nodo* padre = nodo->padre;
	Nodo* p = nodo;
	Nodo* q = p->izquierda;
	Nodo* r = q->derecha;
	Nodo* b = r->izquierda;
	Nodo* c = r->derecha;


	if (padre)
	{
		if (padre->derecha==nodo)
		{
			padre->derecha = r;
		}
		else
		{
			padre->izquierda = r;
		}
	}
	else
	{
		Raiz = r;
	}

	q->derecha = b;
	p->izquierda = c;
	r->izquierda = p;
	r->derecha = q;

	r->padre = padre;
	p->padre = q->padre = r;
	if (b)
	{
		b->padre = p;
	}
	if (c)
	{
		c->padre = q;
	}

	switch (r->FE)
	{
	case -1:
		p->FE = 0;
		q->FE = 1;
		break;
	case 0:
		p->FE = 0;
		q->FE = 0;
		break;
	case 1:
		p->FE = -1;
		q->FE = 0;
		break;
	}
	r->FE = 0;



}
void Arbol::RDD(Nodo* nodo)
{
	Nodo* padre = nodo->padre;
	Nodo* p = nodo;
	Nodo* q = p->izquierda;
	Nodo* r = q->derecha;
	Nodo* b = r->izquierda;
	Nodo* c = r->derecha;


	if (padre)
	{
		if (padre->derecha == nodo)
		{
			padre->derecha = r;
		}
		else
		{
			padre->izquierda = r;
		}
	}
	else
	{
		Raiz = r;
	}

	q->derecha = b;
	p->izquierda = c;
	r->izquierda = q;
	r->derecha = p;

	r->padre = padre;
	p->padre = q->padre = r;
	if (b)
	{
		b->padre = q;
	}
	if (c)
	{
		c->padre = p;
	}

	switch (r->FE)
	{
	case -1:
		p->FE = 0;
		q->FE = 1;
		break;
	case 0:
		p->FE = 0;
		q->FE = 0;
		break;
	case 1:
		p->FE = -1;
		q->FE = 0;
		break;
	}
	r->FE = 0;

}

Nodo* Arbol::RetornarRaiz()
{
	return Raiz;
}




