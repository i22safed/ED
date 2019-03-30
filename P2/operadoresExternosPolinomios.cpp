/*!
   \file operadoresExternosPolinomios.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "operadoresExternosPolinomios.hpp"

#include "operadoresExternosMonomios.hpp"

// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed
{

bool operator==(ed::Polinomio const & p1, ed::Polinomio const & p2){
	return false;
}
bool operator==(ed::Polinomio const & p, ed::Monomio const & m){
	return false;
}
bool operator==(ed::Monomio const & m, ed::Polinomio const & p){
	return false;
}
bool operator==(ed::Polinomio const & p, double const & x){
	return false;
}
bool operator==(double const & x, ed::Polinomio const & p){
	return false;
}

////////////////////////////////////////////////////////////////////////////////////
// Operadores de desigualdad
bool operator!=(ed::Polinomio const & p1, ed::Polinomio const & p2){
	return true;
}
bool operator!=(ed::Polinomio const & p, ed::Monomio const & m){
	return false;
}
bool operator!=(ed::Monomio const & m, ed::Polinomio const & p){
	return false;
}
bool operator!=(ed::Polinomio const & p, double const & x){
	return false;
}
bool operator!=(double const & x, ed::Polinomio const & p){
	return false;
}

// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD

//////////////////////////////////////////////////////////////////////////////////////

// Operadores unarios

// COMPLETAR
ed::Polinomio & operator+(ed::Polinomio const & p)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	ed::Polinomio *nuevo = new ed::Polinomio(p);

	// Se devuelve el resultado
	return *nuevo;
}


// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta


//////////////////////////////////////////////////////////////////////////////////////

// Operadores binarios de la suma
ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	ed::Polinomio *nuevo = new ed::Polinomio;

	// Se devuelve el resultado
	return *nuevo;
}

	// COMPLETAR LOS OTROS OPERADORES DE SUMA

	////////////
	// Resta

	// COMPLETAR


	//////////////////
	// Multiplicación

	// COMPLETAR

	////////////
	// División

	// COMPLETAR


////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, Polinomio &p){

	double coeficiente = 0;
	int grado = 0;
	ed::Monomio m;
	bool check = true;

	while(check){

		stream >> coeficiente >> grado; 

		if((coeficiente==0) or (grado < 0)){
			check = false;
		}else{
			m.setCoeficiente(coeficiente);
			m.setGrado(grado);
			p+=m;
		}
	}

	return stream;

}

// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, Polinomio &p){

	ed::Monomio m;

	for(int i=p.getGrado();i>=0;i--){
		if(p.existeMonomio(i)){
			m = p.getMonomio(i);
			std::cout << m << " ";
		}
	}	
	return stream;

}


} // Fin del espacio de nombres ed
