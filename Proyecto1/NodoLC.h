#pragma once
#include<string>
using namespace std;
class NodoLC
{
public:
	NodoLC* Siguiente;
	NodoLC* Anterior; 
	string IdTransaccion;
	string IdActivo;
	string UsuarioRentor;
	string URDepartamento;
	string UREmpresa;
	string Fecha;
	string DiasRenta;

	NodoLC(string IdTransaccion, string IdActivo, string UsuarioRentor, string URDepartamento,
		   string UREmpresa, string Fecha, string DiasRenta)
	{
		Siguiente = nullptr;
		Anterior = nullptr;
		this->IdTransaccion = IdTransaccion;
		this->IdActivo = IdActivo;
		this->UsuarioRentor = UsuarioRentor;
		this->URDepartamento = URDepartamento;
		this->UREmpresa = UREmpresa;
		this->Fecha = Fecha;
		this->DiasRenta = DiasRenta;
	}
};

