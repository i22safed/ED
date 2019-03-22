/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"

// Operadores de asignación

// COMPLETAR


/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(Polinomio const &p)
{
	
	#ifndef NDEBUG 
		assert(!sonIguales(p));
	#endif
	
	
	for(int i=0;i<p.getNumeroMonomios();i++){
			this->polinomio_[i].setCoeficiente(p.polinomio_[i].getCoeficiente());
			this->polinomio_[i].setGrado(p.polinomio_[i].getGrado());
	}

	#ifndef NDEBUG 
		assert(sonIguales(p));
	#endif

	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{
	
	this->polinomio_[0].setCoeficiente(m.getCoeficiente());
	this->polinomio_[0].setGrado(m.getGrado());

	#ifndef NDEBUG 
		assert((getNumeroMonomios() == 1) and ( 
			(std::abs(this->polinomio_[0].getCoeficiente() - m.getCoeficiente()) < COTA_ERROR) 
			and (this->polinomio_[0].getGrado() == m.getGrado())));
	#endif 

	return *this; // Se devuelve el objeto actual
}


ed::Polinomio & ed::Polinomio::operator=(double const &x)
{

	ed::Monomio m = Monomio();
	m.setCoeficiente(x);
	m.setGrado(0);

	polinomio_.push_back(m);

	#ifndef NDEBUG 
		assert((getNumeroMonomios() == 1) and ( 
			(std::abs(this->polinomio_[getNumeroMonomios()-1].getCoeficiente() - x) < COTA_ERROR) and 
			(this->polinomio_[getNumeroMonomios()-1].getGrado() == 0) ));
	#endif 

	return *this; // Se devuelve el objeto actual
}

//////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator+=(Polinomio const &p)
{
	
	for(int i=0;i<p.getNumeroMonomios();i++){ 	// Recorremos el polinomio pasado como parámetro 
												// y comprobamos que el monomio existe en el polinomio 
												// actual: 
												// 		- Si existe, hacemos la siguiente operacion 
												// 			p_[i] = p_[i] + p[i]
												// 		- Si no existe, hacemos la siguiente operacion 
												// 			m = Monomio()
												// 			m.grado = p[i].grado
												// 			m.coeficiente = p[i].coeficiente
												// 			p_.push_back(m)

		if(existeMonomio(p.polinomio_[i].getGrado())){

			for(int j=0;j<getNumeroMonomios();j++){

				if(this->polinomio_[j].getGrado() == p.polinomio_[i].getGrado()){

					this->polinomio_[j].setCoeficiente(this->polinomio_[j].getCoeficiente() + p.polinomio_[i].getCoeficiente());

				}
			}
		}

		if(!existeMonomio(p.polinomio_[i].getGrado())){
			ed::Monomio m = Monomio();
			m = p.getMonomio(p.polinomio_[i].getGrado());
			this->polinomio_.push_back(m);
		}
	}

	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator+=(ed::Monomio const &m)
{
	
	if(existeMonomio(m.getGrado())){
		for(int i=0;i<getNumeroMonomios();i++){

			if(polinomio_[i].getGrado() == m.getGrado()){
				polinomio_[i].setCoeficiente( polinomio_[i].getCoeficiente() + m.getCoeficiente() );
			}
		}
	
	}else{
	
		polinomio_.push_back(m);
	
	}

	

	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator+=(double const &x)
{
	// COMPLETAR

	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Polinomio const &p)
{
	// COMPLETAR

	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Monomio const &m)
{
	// COMPLETAR
	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator-=(double const &x)
{
	// COMPLETAR

	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Polinomio const &p)
{
	// COMPLETAR

	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Monomio const &m)
{
	// COMPLETAR
	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator*=(double const &x)
{
	// COMPLETAR

	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Polinomio const &p)
{
	// COMPLETAR

	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Monomio const &m)
{
	// COMPLETAR
	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator/=(double const &x)
{
	// COMPLETAR

	return *this; // Se devuelve el objeto actual
}

// COMPLETAR EL RESTO DE OPERADORES



///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

void ed::Polinomio::leerPolinomio(){

}

void ed::Polinomio::escribirPolinomio(){
	
}


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

double ed::Polinomio::calcularValor(double const &c){

	double valorDevuelto = 0.0; 

	return valorDevuelto; 
}
