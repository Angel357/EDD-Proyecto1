#pragma once
#include <string>
#include"NodoLC.h"
using namespace std;

class LCTransacciones
{
public:
	NodoLC* Inicio;
	NodoLC* Fin;

	LCTransacciones()
	{
		Inicio = nullptr;
		Fin = nullptr; 
	}
	void Insertar(string IdTransaccion, string IdActivo, string UsuarioRentor, string URDepartamento,
		string UREmpresa, string Fecha, string DiasRenta);
	NodoLC Buscar(string IdTransaccion);
	void Ordenar(NodoLC* inicio);
	bool LCVacia();
};

