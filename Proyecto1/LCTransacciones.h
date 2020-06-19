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
	void Insertar(string IdTransaccion, string IdActivo,string nombreActivo, string UsuarioRentor, string URDepartamento,
		string UREmpresa, string DiasRenta);
	NodoLC Buscar(string IdTransaccion);
	void Ordenar(NodoLC* inicio);
	bool LCVacia();
	void TransaccionUsuario(string nombreUsuario);
	void MostrarTransaccionesAscendente(string prueba);
	void MostrarTransaccionesDescendente(string prueba);
};

