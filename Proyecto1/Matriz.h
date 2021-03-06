#pragma once
#include <iostream>
#include "NodoM.h"
#include "Matriz.h"
using namespace std;

class Matriz
{ 
public :
	NodoM* Inicio;
	Matriz()
	{
		Arbol* avl = new Arbol;
		Inicio = new NodoM("admin","admin","admin","admin", avl);
	}
	void Insertar(string nombre, string contraseņa, string departamento, string empresa);
	NodoM* CrearEmpresa(string empresa);
	NodoM* CrearDepartamento(string departamento);

	NodoM* BuscarEmpresa(string empresa,NodoM* inicio);
	NodoM* BuscarDepartamento(string departamento, NodoM* inicio);

	bool VerificarEmpresa(string empresa, NodoM* inicio, NodoM* usuario);
	bool VerificarDepartamento(string departamento, NodoM* inicio, NodoM* usuario);

	NodoM* BuscarUsuario(string nombre, string contraseņa, string departamento, string empresa);
	NodoM* BuscarUsuarioUnico(string nombre);

	void ImprimirMatriz(string prueba);
};

