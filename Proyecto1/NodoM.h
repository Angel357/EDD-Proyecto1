#pragma once
#include <iostream>
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
	string Nombre;
	string Contraseña;
	string Departamento;
	string Empresa;
	NodoM(string Nombre, string Contraseña, string Departamento, string Empresa)
	{
		siguiente = nullptr;
		anterior = nullptr;
		arriba = nullptr;
		abajo = nullptr;
		atras = nullptr;
		adelante = nullptr;

		this->Nombre = Nombre;
		this->Contraseña = Contraseña;
		this->Empresa = Empresa;
		this->Departamento = Departamento;
	}
};

