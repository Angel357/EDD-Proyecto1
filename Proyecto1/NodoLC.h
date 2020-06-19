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
	string DiasRenta;
	string nombreActivo;

	NodoLC(string IdTransaccion, string IdActivo, string nombreActivo, string UsuarioRentor, string URDepartamento,
		   string UREmpresa,  string DiasRenta)
	{
		Siguiente = nullptr;
		Anterior = nullptr;
		this->IdTransaccion = IdTransaccion;
		this->IdActivo = IdActivo;
		this->UsuarioRentor = UsuarioRentor;
		this->URDepartamento = URDepartamento;
		this->UREmpresa = UREmpresa;
		this->DiasRenta = DiasRenta;
		this->nombreActivo = nombreActivo;
	}
};

