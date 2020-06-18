#pragma once
#include <iostream>
#include "Arbol.h"
#include <string>
using namespace std;
class NodoM
{
public:
	NodoM* siguiente;
	NodoM* anterior;
	NodoM* abajo;
	NodoM* arriba;
	NodoM* adelante;
	NodoM* atras;

	Arbol* avl;

	string Nombre;
	string Contraseņa;
	string Departamento;
	string Empresa;
	NodoM(string Nombre, string Contraseņa, string Departamento, string Empresa, Arbol* avl)
	{
		siguiente = nullptr;
		anterior = nullptr;
		arriba = nullptr;
		abajo = nullptr;
		atras = nullptr;
		adelante = nullptr;

		this->Nombre = Nombre;
		this->Contraseņa = Contraseņa;
		this->Empresa = Empresa;
		this->Departamento = Departamento;
		this->avl = avl;
	}
};

