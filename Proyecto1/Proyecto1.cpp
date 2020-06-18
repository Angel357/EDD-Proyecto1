//Clase Principal
#include <iostream>
#include "Aleatorio.h"
#include "Matriz.h"
#include "NodoM.h"
//#include "Menu.h"
using namespace std;

int main()
{
	//probando git 
	/*Matriz* m = new Matriz;
	Menu* me = new Menu;
	me->Iniciar();*/

	Matriz* m = new Matriz();
	m->Insertar("pedro", "vivares", "gua","max");
	m->Insertar("pedro", "castañeda", "tec", "tel");
	m->Insertar("pedro", "calderon", "sol", "afro");
	m->Insertar("pedro", "mansilla", "pet", "res");

	NodoM* usuario=m->BuscarUsuario("pedro", "castañeda", "tec", "tel");

	usuario->avl->Insertar("aevawgrqwr","pelotas","de caucho","activo");
	usuario->avl->Insertar("auhujvawgrqwr", "trenes", "de caucho", "activo");
	usuario->avl->Insertar("rgrqwr", "sartem", "de caucho", "activo");
	usuario->avl->Insertar("jevawgrqwr", "gotas", "de caucho", "activo");

	usuario->avl->PreOrden;

	return 0;
}
