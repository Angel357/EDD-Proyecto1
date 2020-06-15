#pragma once
#include <iostream>
#include <string>
using namespace std;

class NodoAl
{
public:
	string Id;
	NodoAl* Siguiente;
	NodoAl(string Id)
	{
		Siguiente = nullptr;
		this->Id = Id;
	}
};

