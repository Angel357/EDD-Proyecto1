#pragma once
#include <string>
#include "Matriz.h"
#include "LCTransacciones.h"
#include <iostream>
using namespace std;
class Menu
{
public:
	Matriz* m;
	LCTransacciones* Transaccion;
	void Iniciar();
	void Login();
	//todo conforme al usuario
	void MenuUsuario(NodoM* User, string Nombre, string Contraseña, string Departamento, string Empresa);
	void AgregarActivo(NodoM* User, string Nombre, string Contraseña, string Departamento, string Empresa);
	void EliminarActivo(NodoM* User,string Nombre, string Contraseña, string Departamento, string Empresa);
	void ModificarActivo(NodoM* User,string Nombre, string Contraseña, string Departamento, string Empresa);
	void RentarActivo(NodoM* User,string Nombre, string Contraseña, string Departamento, string Empresa);
	void ActivosRentados(NodoM* User,string Nombre, string Contraseña, string Departamento, string Empresa);
	void MisActivosRentados(NodoM* User,string Nombre, string Contraseña, string Departamento, string Empresa);


	//todo conforme al administrador
	void MenuAdmin();
	void RegistrarUsuario();
	void ReporteMatriz();
	void ReporteActivosDepartamento();
	void ReporteActivosEmpresa();
	void ReporteTransaccion();
	void ReporteActivosUsuario();
	void ActivosRentadosUsuario();
	void OrdenarTransacciones();
};

