#include "Matriz.h"
#include "NodoM.h"
#include <iostream>

void Matriz::Insertar(string nombre, string contraseña, string departamento, string empresa)
{
	NodoM* Usuario=new NodoM(nombre, contraseña, departamento,empresa);
	NodoM* Empresa=BuscarEmpresa(empresa,Inicio);
	NodoM* Departamento=BuscarDepartamento(departamento,Inicio);

	if (Empresa == nullptr)
	{
		Empresa=CrearEmpresa(empresa);
	}
	if (Departamento==nullptr)
	{
		Departamento = CrearDepartamento(departamento);
	}

	//insercion de usuarios
	if (Departamento->abajo==nullptr)
	{
		Departamento->abajo = Usuario;
		Usuario->arriba = Departamento;
	}
	else if (Empresa->abajo==nullptr)
	{
		NodoM* aux = Departamento->abajo;
		while (aux->abajo!=nullptr)
		{
			aux = aux->abajo;
		}
		if (!VerificarDepartamento(departamento,aux,Usuario))
		{
			aux->siguiente = Usuario;
			Usuario->anterior = aux;
		}
	}
	else 
	{
		NodoM* aux = Departamento;
		do
		{
			aux = aux->abajo;
			if (!VerificarEmpresa(empresa,aux,Usuario))
			{
				NodoM* auxEmp = aux->anterior;
				while (auxEmp->anterior!=nullptr )
				{
					auxEmp = auxEmp->anterior;
				}
				while (auxEmp->arriba!=nullptr)
				{
					if (auxEmp->Nombre == empresa)
					{
						Usuario->abajo = aux;
						Usuario->arriba = aux->arriba;
						 
						aux->arriba->abajo = Usuario;
						aux->arriba = Usuario;
						break;
					}
					auxEmp = auxEmp->arriba;
				}
			}
		} while (aux->abajo==nullptr&&Usuario->arriba==nullptr);
		if (Usuario->arriba==nullptr&&Usuario->adelante==nullptr)
		{
			aux->abajo = Usuario;
			Usuario->arriba = aux;
		}
	}

	//insercion empresa
	if (Empresa->siguiente==nullptr)
	{
		Empresa->siguiente = Usuario;
		Usuario->anterior = Empresa;
	}
	else if (Departamento->siguiente==nullptr)
	{
		NodoM* aux = Empresa->siguiente;
		while (aux->siguiente!=nullptr)
		{
			aux = aux->siguiente;
		}
		if (!VerificarDepartamento(departamento,aux,Usuario))
		{
			aux->siguiente = Usuario;
			Usuario->anterior = aux;

		}
	}
	else
	{
		NodoM* aux = Empresa;
		do
		{
			aux = aux->siguiente;
			if (!VerificarDepartamento(departamento,aux,Usuario ))
			{
				NodoM* auxDepto = aux->arriba;
				while (auxDepto->arriba!=nullptr)
				{
					auxDepto = auxDepto->arriba; 
				}
				while (auxDepto->anterior!=nullptr)
				{
					if (auxDepto->Nombre==departamento)
					{
						Usuario->siguiente = aux;
						Usuario->anterior = aux->anterior;

						aux->anterior->siguiente = Usuario;
						aux->anterior = Usuario;
						break;
					}
					auxDepto = auxDepto->anterior;

				}
			}
		} while (aux->siguiente!=nullptr && Usuario->anterior==nullptr);

		if (Usuario->anterior == nullptr&&Usuario->adelante == nullptr)
		{
			aux->siguiente = Usuario;
			Usuario->anterior = aux;
		}
	}
	
}

NodoM* Matriz::CrearEmpresa(string empresa)
{
	NodoM* emp=new NodoM(empresa,"encabezado","","");
	NodoM* aux=Inicio;
	while (aux->abajo!=nullptr)
	{ 
		aux = aux->abajo;
	}
	aux->abajo = emp;
	emp->arriba = aux;
	return emp;
}

NodoM* Matriz::CrearDepartamento(string departamento)
{
	NodoM* depto = new NodoM(departamento,"encabezado","","");
	NodoM* aux = Inicio;
	while (aux->siguiente!=nullptr)
	{
		aux = aux->siguiente;
	}
	aux->siguiente = depto;
	depto->anterior = aux;
	return depto;

}

NodoM* Matriz::BuscarDepartamento(string departamento, NodoM* inicio)
{
	NodoM* aux = inicio;
	while (aux!=nullptr)
	{
		if (aux->Nombre == departamento)
		{
			return aux;
		}
		aux = aux->siguiente;
	}
	return nullptr; 
}
NodoM* Matriz::BuscarEmpresa(string empresa, NodoM* inicio)
{
	NodoM* aux = inicio;
	while (aux != nullptr)
	{
		if (aux->Nombre == empresa)
		{
			return aux;
		}
		aux = aux->abajo;
	}
	return nullptr;
}

bool Matriz::VerificarEmpresa(string empresa, NodoM* inicio, NodoM* usuario)
{
	NodoM* aux = inicio->anterior;
	while (aux->anterior!=nullptr)
	{
		aux = aux->anterior;
	}
	if (aux->Nombre==empresa)
	{
		while (inicio->atras!=nullptr)
		{
			inicio = inicio->atras;
		}
		inicio->atras = usuario;
		usuario->adelante = inicio;
		return true;
	}
	return false;
}
bool Matriz::VerificarDepartamento(string departamento, NodoM* inicio, NodoM* usuario)
{
	NodoM* aux = inicio->anterior;
	while (aux->anterior != nullptr)
	{
		aux = aux->anterior;
	}
	if (aux->Nombre == departamento)
	{
		while (inicio->atras != nullptr)
		{
			inicio = inicio->atras;
		}
		inicio->atras = usuario;
		usuario->adelante = inicio;
		return true;
	}
	return false;
}

NodoM* Matriz::BuscarUsuario(string nombre, string contraseña, string departamento, string empresa)
{
	NodoM* aux=Inicio;
	NodoM* aux2 = Inicio;
	while (aux!=nullptr)
	{
		while (aux2!=nullptr)
		{
			if (nombre==aux2->Nombre&&contraseña==aux2->Contraseña&&
				departamento==aux2->Departamento&&empresa==aux2->Empresa)
			{
				return aux2;
			}
			aux2 = aux2->siguiente;
		}
		aux2 = aux->abajo;
		aux = aux->abajo;
	}
	return nullptr;

}