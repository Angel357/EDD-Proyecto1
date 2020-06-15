#pragma once
#include <iostream>
#include "NodoM.h"
#include "Matriz.h"

class Matriz
{ 
public :
	NodoM* Inicio;
	Matriz()
	{
		Inicio = new NodoM("admin","admin","","");
	}
	void Insertar(string nombre, string contraseña, string departamento, string empresa);
	NodoM* CrearEmpresa(string empresa);
	NodoM* CrearDepartamento(string departamento);

	NodoM* BuscarEmpresa(string empresa,NodoM* inicio);
	NodoM* BuscarDepartamento(string departamento, NodoM* inicio);

	bool VerificarEmpresa(string empresa, NodoM* inicio, NodoM* usuario);
	bool VerificarDepartamento(string departamento, NodoM* inicio, NodoM* usuario);

	NodoM* BuscarUsuario(string nombre, string contraseña, string departamento, string empresa);
};

