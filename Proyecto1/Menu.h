#pragma once
#include <string>
#include <iostream>
class Menu
{
public:
	void Iniciar();
	void Login();
	//todo conforme al usuario
	void MenuUsuario(string Nombre, string Contraseña, string Departamento, string Empresa);
	void AgregarActivo(string Nombre, string Contraseña, string Departamento, string Empresa);
	void EliminarActivo(string Nombre, string Contraseña, string Departamento, string Empresa);
	void ModificarActivo(string Nombre, string Contraseña, string Departamento, string Empresa);
	void RentarActivo(string Nombre, string Contraseña, string Departamento, string Empresa);
	void ActivosRentados(string Nombre, string Contraseña, string Departamento, string Empresa);
	void MisActivosRentados(string Nombre, string Contraseña, string Departamento, string Empresa);


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

