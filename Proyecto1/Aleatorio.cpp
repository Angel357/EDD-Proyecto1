#include "Aleatorio.h"
#include "NodoAl.h"
#include <string>
#include <iostream>
using namespace std;

string Aleatorio::Id(string prueba)
{
	bool bandera=false;
	while (!bandera)
	{
		CrearId();
		bandera = Buscar(ID);
	}
	insertar(ID);
	return ID;
}
void Aleatorio::CrearId()
{

	char letra[26] = { 'a','b','c','d','e','f','g','h',
					   'i','j','k','l','m','n','o','p',
					   'q','r','s','t','u','v','w','x','y','z' };
	string ID;
	for (int x = 0; x < 15; x++)
	{
		switch (1 + rand() % 2)
		{
		case 1:
			ID += to_string(1 + rand() % 9);
			break;
		case 2:
			ID += letra[0 + rand() % 25];
			break;
		}
	}
	if (!Buscar(ID))
	{
		insertar(ID);
	}
}
bool Aleatorio::Buscar(string ID)
{
	NodoAl* aux = RegID;
	if (aux!=nullptr)
	{
		while (aux!=nullptr)
		{
			if (aux->Id==ID)
			{
				return false;
			}
			aux=aux->Siguiente;
		}
		this->ID = ID;
		return true;
	}
	else 
	{
		this->ID = ID;
		return true;
	}
}
void Aleatorio::insertar(string ID)
{
	NodoAl* Nuevo =new NodoAl(ID);

	if (RegID==nullptr)
	{
		RegID = Nuevo;
		RegID->Siguiente = nullptr;
	}
	else
	{	
		NodoAl* aux = RegID;

		while (aux->Siguiente!=nullptr)
		{
			aux = aux->Siguiente;
		}
		Nuevo->Siguiente = nullptr;
		aux->Siguiente = Nuevo;
	}
}


