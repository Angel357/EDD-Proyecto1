//Clase Principal
#include <iostream>
#include "Aleatorio.h"
#include "Matriz.h"
#include "NodoM.h"
#include "Menu.h"
#include "Nodo.h"
using namespace std;

int main()
{
	//probando git 
	//Matriz* m = new Matriz;
	Menu* me = new Menu;
	me->Iniciar();

	/*Matriz* m = new Matriz();
	m->Insertar("pedro", "vivares", "gua","max");
	m->Insertar("pedro", "castañeda", "tec", "tel");
	m->Insertar("pedro", "calderon", "sol", "afro");
	m->Insertar("pedro", "mansilla", "pet", "res");

	NodoM* usuario=m->BuscarUsuario("pedro", "castañeda", "tec", "tel");
	
	usuario->avl->Insertar("10","pelotas","de caucho","activo");
	usuario->avl->Insertar("9", "trenes", "de caucho", "activo");
	usuario->avl->Insertar("8", "sartem", "de caucho", "activo");
	usuario->avl->Insertar("-5", "gotas", "de caucho", "activo");
	usuario->avl->Insertar("3", "gotas", "de caucho", "activo");
	usuario->avl->Insertar("95", "gotas", "de caucho", "activo");
	usuario->avl->Insertar("-2", "gotas", "de caucho", "activo");

	usuario->avl->PreOrden(usuario->avl->Raiz);
	cout << "\n\n";

	NodoM* usuario2= m->BuscarUsuario("pedro", "calderon", "sol", "afro");
	usuario2->avl->Insertar("9", "pelotas", "de caucho", "activo");
	usuario2->avl->Insertar("7", "trenes", "de caucho", "activo");
	usuario2->avl->Insertar("5", "sartem", "de caucho", "activo");
	usuario2->avl->Insertar("4", "gotas", "de caucho", "activo");
	usuario2->avl->PreOrden(usuario2->avl->Raiz);
	cout << "\n\n";
	usuario->avl->Eliminar("10");

	usuario->avl->PreOrden(usuario->avl->Raiz);
	*/

	return 0;
}
