#pragma once
#include <string>
#include "NodoAl.h"
#include <iostream>
using namespace std;
class Aleatorio
{
public:
	string ID;
	NodoAl* RegID;
	string Id(string prueba);
	void CrearId();
	bool Buscar(string ID);
	void insertar(string ID);
	Aleatorio()
	{
	RegID = nullptr;
	}
};

