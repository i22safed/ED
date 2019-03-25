/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>
#include "Polinomio.hpp"

// Operadores de asignación

/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(Polinomio const &p){
	
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


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m){
	
	polinomio_.push_back(m);

	#ifndef NDEBUG 
		assert((getNumeroMonomios() == 1) and (this->polinomio_[getNumeroMonomios()-1] == m));
	#endif 

	return *this; // Se devuelve el objeto actual
}


ed::Polinomio & ed::Polinomio::operator=(double const &x){

	ed::Monomio m = Monomio();
	m.setCoeficiente(x);
	m.setGrado(0);

	polinomio_.push_back(m);

	#ifndef NDEBUG 
		assert((getNumeroMonomios() == 1) and ( 
			(std::abs(this->polinomio_[0].getCoeficiente() - x) < COTA_ERROR) and 
			(this->polinomio_[0].getGrado() == 0) ));
	#endif 

	return *this; // Se devuelve el objeto actual
}

//////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator+=(Polinomio const &p){
	
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

			// AQUI HABRÍA QUE ORDENAR EL POLINOMIO

		}
	}

	return *this; // Se devuelve el objeto actual

}

ed::Polinomio & ed::Polinomio::operator+=(ed::Monomio const &m){
	
	if(existeMonomio(m.getGrado())){
		for(int i=0;i<getNumeroMonomios();i++){

			if(polinomio_[i].getGrado() == m.getGrado()){
				this->polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() + m.getCoeficiente() );
			}
		}
	
	}else{
		this->polinomio_.push_back(m);

		// AQUI HABRÍA QUE ORDENAR EL POLINOMIO

	}

	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator+=(double const &x){

	if(existeMonomio(0)){
		
		for(int i=0;i<getNumeroMonomios();i++){
			if(polinomio_[i].getGrado() == 0){
				polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() + x);
			}
		}
	
	}else{
	
		ed::Monomio m = Monomio();
		m.setGrado(0);
		m.setCoeficiente(x);
		this->polinomio_.push_back(m);
	
	}

	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Polinomio const &p){
	
		for(int i=0;i<p.getNumeroMonomios();i++){ 

		if(existeMonomio(p.polinomio_[i].getGrado())){

			for(int j=0;j<getNumeroMonomios();j++){

				if(this->polinomio_[j].getGrado() == p.polinomio_[i].getGrado()){

					this->polinomio_[j].setCoeficiente(this->polinomio_[j].getCoeficiente() - p.polinomio_[i].getCoeficiente());

				}
			}
		}

		if(!existeMonomio(p.polinomio_[i].getGrado())){
			ed::Monomio m = Monomio();
			m = p.getMonomio(p.polinomio_[i].getGrado());
			m.setCoeficiente(m.getCoeficiente() * (-1));
			this->polinomio_.push_back(m);
		}
	}

	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Monomio &m){
	
	if(existeMonomio(m.getGrado())){
	
		for(int i=0;i<getNumeroMonomios();i++){

			if(polinomio_[i].getGrado() == m.getGrado()){
				this->polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() - m.getCoeficiente() );
			}
		}
	
	}else{
		m.setCoeficiente(m.getCoeficiente() * (-1));
		this->polinomio_.push_back(m);
	}

	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator-=(double const &x){
	
		if(existeMonomio(0)){
		
		for(int i=0;i<getNumeroMonomios();i++){
			if(polinomio_[i].getGrado() == 0){
				polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() - x);
			}
		}
	
	}else{
	
		ed::Monomio m = Monomio();
		m.setGrado(0);
		m.setCoeficiente((-1) * x);
		this->polinomio_.push_back(m);
	
	}
	
	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Polinomio const &p){
	
	for(int i=0;i<p.getNumeroMonomios();i++){

		for(int j=0;j<getNumeroMonomios();j++){

			polinomio_[j].setCoeficiente( p.polinomio_[i].getCoeficiente() * polinomio_[j].getCoeficiente());
			polinomio_[j].setGrado( p.polinomio_[i].getGrado() + polinomio_[j].getGrado() );

		}
	}

	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Monomio const &m){
	
	for(int i=0;i<getNumeroMonomios();i++){

		polinomio_[i].setCoeficiente( m.getCoeficiente() * polinomio_[i].getCoeficiente());
		polinomio_[i].setGrado( m.getGrado() + polinomio_[i].getGrado() );

	}

	return *this; // Se devuelve el objeto actual

}

ed::Polinomio & ed::Polinomio::operator*=(double const &x){
	
	for(int i=0;i<getNumeroMonomios();i++){		
		polinomio_[i].setCoeficiente(x * polinomio_[i].getCoeficiente());	
	}
	
	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Polinomio const &p){
	
	#ifndef NDEBUG 
		assert(polinomio_[0].getGrado() >= p.polinomio_[0].getGrado());
		assert(!p.esNulo());
	#endif
	
	ed::Polinomio cociente = Polinomio();
	ed::Polinomio resultado = Polinomio(); 
	ed::Monomio termino = Monomio();

	while(termino.getGrado()>= resultado.polinomio_[0].getGrado()){

		


		polinomio_.clear();

	}
	


	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Monomio const &m){
	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator/=(double const &x){
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

double ed::Polinomio::calcularValor(double const &x){

	double valorDevuelto = 0.0; 

	for(int i=0;i<getNumeroMonomios();i++){
		valorDevuelto = valorDevuelto + pow(x,polinomio_[i].getGrado()) * polinomio_[i].getCoeficiente();
	}

	return valorDevuelto; 
}
