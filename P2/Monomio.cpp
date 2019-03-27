/*! 
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>
#include <cmath>
#include "Monomio.hpp"

// Operadores de asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{
	this->setCoeficiente(m.getCoeficiente());
	this->setGrado(m.getGrado());

	#ifndef NDEBUG
		assert(std::abs(getCoeficiente()-m.getCoeficiente()) < COTA_ERROR);
		assert(getGrado() == m.getGrado());
	#endif

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator=(double const &x)
{
	
	this->setCoeficiente(x);
	this->setGrado(0);

	#ifndef NDEBUG
		assert(getGrado() == 0);
		assert(std::abs(getCoeficiente() - x) < COTA_ERROR);
	#endif

	// Se devuelve el objeto actual
	return *this;
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m)
{
	
	double coeficiente = getCoeficiente();
	int grado = getGrado();  
	
	#ifndef NDEBUG // Comprobamos que los monomios sean del mismo grado
		assert(getGrado() == m.getGrado());
	#endif

	this->setCoeficiente(getCoeficiente()+m.getCoeficiente());

	#ifndef NDEBUG 
		assert(
			std::abs(getCoeficiente() - (coeficiente + m.getCoeficiente())) < COTA_ERROR);
			assert(getGrado() == grado); 
	#endif 

	// Se devuelve el objeto actual
	return *this;
}


// COMPLETAR EL RESTO DE OPERADORES

ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m){


	double coeficiente = getCoeficiente();
	int grado = getGrado();  
	
	#ifndef NDEBUG // Comprobamos que los monomios sean del mismo grado
		assert(getGrado()==m.getGrado());
	#endif

	setCoeficiente(getCoeficiente()-m.getCoeficiente());

	
	#ifndef NDEBUG 
		assert(
			std::abs(getCoeficiente() - (coeficiente - m.getCoeficiente())) < COTA_ERROR);
			assert(getGrado() == grado); 
	#endif 

	return *this;

}

ed::Monomio & ed::Monomio::operator*=(ed::Monomio const &m){

	double coeficiente = getCoeficiente();
	int grado = getGrado();

	setCoeficiente(getCoeficiente() * m.getCoeficiente());
	setGrado(getGrado() + m.getGrado());

	// Postcondición 

	#ifndef NDEBUG
		assert(std::abs((coeficiente * m.getCoeficiente()) - getCoeficiente()) < COTA_ERROR);
		assert((grado + m.getGrado()) == getGrado());
	#endif 

	return *this;

}

ed::Monomio & ed::Monomio::operator/=(ed::Monomio const &m){

	double coeficiente = getCoeficiente(); 
	int grado = getGrado();

	#ifndef NDEBUG
		// Grado del monomio igual o inferior al actual 
		assert(m.getGrado() <= getGrado());
		// El coeficiente del monomio m no es 0 
		assert(m.getCoeficiente() != 0.0); 
	#endif 

	setCoeficiente(getCoeficiente() / m.getCoeficiente());
	setGrado(getGrado() - m.getGrado());

	#ifndef NDEBUG 
		assert(std::abs((coeficiente / m.getCoeficiente())-getCoeficiente()) < COTA_ERROR);
		assert((grado - m.getGrado()) == getGrado());
	
	#endif 

	return *this;

}

ed::Monomio & ed::Monomio::operator*=(double const &x){

	double coeficiente = getCoeficiente();
	int grado = getGrado();

	setCoeficiente(getCoeficiente() * x);

	#ifndef NDEBUG 
		assert(std::abs((coeficiente*x)-getCoeficiente()) < COTA_ERROR);
		assert(grado == getGrado());
	#endif 

	return *this;

}

ed::Monomio & ed::Monomio::operator/=(double const &x){

	double coeficiente = getCoeficiente();
	int grado = getGrado();

	#ifndef NDEBUG
		assert( x != 0.0);
	#endif


	setCoeficiente(getCoeficiente() / x);

	#ifndef NDEBUG 
		assert(std::abs((coeficiente/x)-getCoeficiente()) < COTA_ERROR);
		assert(grado == getGrado());
	#endif 

	return *this;

}


///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

void ed::Monomio::leerMonomio(){

	double coeficiente = 0.0; 
	int grado = 0; 

	std::cout << "\nCoeficiente → "; 
	std::cin >> coeficiente; 
	setCoeficiente(coeficiente);

	std::cout << "\nGrado → "; 
	std::cin >> grado; 

	#ifndef NDEBUG
		assert(grado >= 0);
	#endif

	setGrado(grado);

	return ; 

}

void ed::Monomio::escribirMonomio()const{

	
	/*
		▪ Si el coeficiente es 1 entonces se escribirá X^grado
		▪ Si el coeficiente es -1 entonces se escribirá -X^grado
		▪ Si el grado es 0 entonces se escribirá solo el coeficiente.
		▪ Si el grado es 1 entonces se escribirá X pero sin grado
	*/	

	if(getGrado() == 0){
		std::cout << getCoeficiente() << " "; 
	}
	if(getGrado() == 1){
		std::cout << getCoeficiente() << "x" << " ";
	}
	if(getCoeficiente() == 1 ){
		std::cout << "x^" << getGrado() << " "; 
	}
	if(getCoeficiente() == -1){
		std::cout << "-x^" << getGrado() << " "; 
	}
	if((getCoeficiente() != 1) && 
			(getCoeficiente() != -1) && 
			(getGrado() != 0) && 
			(getGrado() != 1)){
				std::cout << getCoeficiente() << "x^" <<
				getGrado() << " ";
			}

	return;

}

double ed::Monomio::calcularValor(double const &x){

	return getCoeficiente() * pow(x,getGrado());

}

///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio





// COMPLETAR

