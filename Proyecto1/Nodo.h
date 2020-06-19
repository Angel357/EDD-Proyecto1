#pragma once
#include <string>
#include <iostream>
using namespace std;
class Nodo
{
public:
	Nodo* padre;
	Nodo* izquierda;
	Nodo* derecha;
	string IDactivo;
	string Nombre;
	string Descripcion;
	string Estado;
	int FE;

	Nodo(string idActivo, string nombre, string descripcion, string estado)
	{
		izquierda = nullptr;
		derecha = nullptr;
		padre = nullptr;
		IDactivo = idActivo;
		Nombre = nombre;
		Descripcion = descripcion;
		Estado = estado;
	}

};
