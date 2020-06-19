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
	int rama;
	bool Accion = true;
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
			rama = 0;
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
			rama = 0;
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
		return nullptr;
	}
	else
	{
		Buscar2(aux, idActivo);
		Nodo* nuevo = aBuscar;
		return nuevo;
	}
}
Nodo* Arbol::Buscar2(Nodo* aux, string idActivo)
{
	
		if (aux == nullptr)
		{
			return nullptr;
		}
		if (idActivo == aux->IDactivo)
		{
			aBuscar = aux;
		}

		Buscar2(aux->izquierda, idActivo);
		Buscar2(aux->derecha, idActivo);
	
}

void Arbol::Eliminar(string idActivo)
{
	Nodo* aux2 = Buscar(idActivo);
	if (aux2->izquierda == nullptr&&aux2->derecha == nullptr)
	{
		if (aux2->Nombre==Raiz->Nombre)
		{
			Raiz = nullptr;
		}
		else
		{
			if (aux2->IDactivo > aux2->padre->IDactivo)

			{

				aux2->padre->derecha = nullptr;
			}
			else
			{
				aux2->padre->izquierda = nullptr;
			}
		}
		
	}
	else if (aux2->izquierda != nullptr&& aux2->izquierda->derecha == nullptr)
	{
		aux2->IDactivo = aux2->izquierda->IDactivo;
		aux2->Nombre = aux2->izquierda->Nombre;
		aux2->Descripcion = aux2->izquierda->Descripcion;
		aux2->Estado = aux2->izquierda->Estado;
		if (aux2->izquierda->izquierda!=nullptr)
		{
			aux2->izquierda->izquierda->padre = aux2;
			aux2->izquierda=aux2->izquierda->izquierda;
			int rama = 0;
			bool Accion = false;
			Equilibrar(aux2->padre->padre, rama, Accion);
		}
		else
		{

			aux2->izquierda = nullptr;// el nodo como tal no se elimina solo deja de formar parte del arbol
			int rama = 0;
			bool Accion = false;
			if (aux2->padre!=nullptr)
			{
				Equilibrar(aux2->padre->padre, rama, Accion);
			}
		}
	}
	else
	{
		Eliminar2(aux2,aux2->izquierda->derecha, idActivo);
	}
}
void Arbol::Eliminar2(Nodo* aux, Nodo* aux2, string idActivo)
{
	Nodo* Aux2 = aux;
	Nodo* Aux = aux2;
	if (Aux->derecha != nullptr)
	{
		Aux = Aux->derecha;
		Eliminar2(Aux2,Aux, idActivo);
	}
	else
	{
		Aux2->IDactivo = Aux->IDactivo;
		Aux2->Nombre = Aux->Nombre;
		Aux2->Descripcion = Aux->Descripcion;
		Aux2->Estado = Aux->Estado;
		Aux->padre->derecha = nullptr;
		Aux->padre = nullptr;
		int rama = 1;
		bool Accion = false;
		if (aux2->padre != nullptr)
		{
			Equilibrar(aux2->padre->padre, rama, Accion);
		}
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
		PreOrden(aux->izquierda);
		PreOrden(aux->derecha);
	}


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
				RDI(padre);
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
	Nodo* Padre = nodo->padre;
	Nodo* p = nodo;
	Nodo* q = p->izquierda;
	Nodo* b = q->izquierda;

	if (Padre)
	{
		if (Padre->derecha==p)
		{
			Padre->derecha = q;
		}
		else
		{
			Padre->izquierda = q;
		}
	}
	else
	{
		Raiz = q;
	}

	p->izquierda = b;
	q->derecha = p;

	p->padre = q;
	if (b)
	{
		b->padre = p;
	}
	q->padre = Padre;

	p->FE = 0;
	q->FE = 0;
}
void Arbol::RDI(Nodo* nodo)
{
	Nodo* padre = nodo->padre;
	Nodo* p = nodo;
	Nodo* q = p->derecha;
	Nodo* r = q->izquierda;
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

	p->derecha = b;
	q->izquierda = c;
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
		p->FE = 1;
		q->FE = 0;
		break;
	case 0:
		p->FE = 0;
		q->FE = 0;
		break;
	case 1:
		p->FE = 0;
		q->FE = -1;
		break;
	}
	r->FE = 0;

}

Nodo* Arbol::RetornarRaiz()
{
	return Raiz;
}

void::Arbol::DesplegarActivo(Nodo* Raiz)
{
	Nodo* aux = Raiz;
	if (aux == nullptr)
	{
		return;
	}
	else
	{
		if (aux->Estado == "disponible")
		{
			cout << "\n--ID= " << aux->IDactivo << "; Nombre: " << aux->Nombre;
		}
		DesplegarActivo(aux->izquierda);
		DesplegarActivo(aux->derecha);
	}
}

void::Arbol::VerificarMiActivo(Nodo* Raiz)
{
	Nodo* aux = Raiz;
	if (aux == nullptr)
	{
		return;
	}
	else
	{
		if (aux->Estado == "rentado")
		{
			cout << "\n--ID= " << aux->IDactivo << "; Nombre: " << aux->Nombre;
		}
		VerificarMiActivo(aux->izquierda);
		VerificarMiActivo(aux->derecha);
	}
}




