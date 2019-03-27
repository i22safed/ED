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
		assert(getGrado() >= p.polinomio_[0].getGrado());
		assert(!p.esNulo());
	#endif
	
	ed::Polinomio * cociente = new Polinomio();		// Polinomio a retornar 
	ed::Polinomio resultado = Polinomio(); 			// Resultado intermedio para restarlo al dividendo
	ed::Monomio termino = Monomio();				// Variable auxiliar
	int i=0; 

	while((getGrado() >= p.getGrado()) or getNumeroMonomios() == 0){

		cociente->polinomio_[i] = this->polinomio_[0] / p.polinomio_[0];  

		for(int j=0;j<p.getNumeroMonomios();j++){

			termino = cociente->polinomio_[i] * p.polinomio_[j];		// Cociente[i] * Divisor  
			termino.setCoeficiente(termino.getCoeficiente() * (-1));	// Cambio de signo 
			resultado.polinomio_.push_back(termino);					// Añadimos a resultado el termino 
			
		}

		// Dividendo = dividendo + resultado

		for(int k=0;k<resultado.getNumeroMonomios();k++){ 					// Realizamos la suma de Dividendo +( - resultado )

			if(existeMonomio(resultado.polinomio_[k].getGrado())){	// Si existe en el polinomio actual el grado del monomio del 
																	// Polinomio secundario (resultado)

				for(int j=0;j<getNumeroMonomios();j++){				// Recorremos el principal viendo cual es 

					if(this->polinomio_[j].getGrado() == resultado.polinomio_[k].getGrado()){

						this->polinomio_[j].setCoeficiente(this->polinomio_[j].getCoeficiente() + resultado.polinomio_[k].getCoeficiente());

					}
				}
			}

			if(!existeMonomio(resultado.polinomio_[k].getGrado())){
				ed::Monomio m = Monomio();
				m = resultado.getMonomio(resultado.polinomio_[k].getGrado());
				this->polinomio_.push_back(m);
			}
		}

		// Borramos el primer elemento ya que es necesario en el proceso de división 
		// en el resto de los monomios, si tenemos algún elemento con coeficiente 0 
		// tambien deberemos eliminarlo

		for(int x=0;x<getNumeroMonomios();x++){
			if(polinomio_[x].getCoeficiente() == 0){
				polinomio_.erase(polinomio_.begin() + x); // Todo polinomio cuyo coeficiente sea 0 	
			}
		}

		i++; // incrementamos el indice para meter en el cociente el siguiente termino

		// Aqui terminaría la primera iteración 

	}
	
	return * cociente; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Monomio const &m){

	
	#ifndef NDEBUG 
		assert(m.getGrado() <= getGrado());
	#endif 

	ed::Polinomio * cociente = new Polinomio();		// Polinomio a retornar 
	ed::Polinomio resultado = Polinomio(); 			// Resultado intermedio para restarlo al dividendo
	ed::Monomio termino = Monomio();				// Variable auxiliar
	int i=0; 

	while((getGrado() >= m.getGrado()) or getNumeroMonomios() == 0){
		
		cociente->polinomio_[i] = this->polinomio_[0] / m;  

		termino = cociente->polinomio_[i] * m;	// Cociente[i] * Divisor  
		termino.setCoeficiente(termino.getCoeficiente() * (-1));	// Cambio de signo 
		resultado.polinomio_.push_back(termino);
		
		
		for(int k=0;k<resultado.getNumeroMonomios();k++){ 					// Realizamos la suma de Dividendo +( - resultado )

			if(existeMonomio(resultado.polinomio_[k].getGrado())){	// Si existe en el polinomio actual el grado del monomio del 
																	// Polinomio secundario (resultado)

				for(int j=0;j<getNumeroMonomios();j++){				// Recorremos el principal viendo cual es 

					if(this->polinomio_[j].getGrado() == resultado.polinomio_[k].getGrado()){

						this->polinomio_[j].setCoeficiente(this->polinomio_[j].getCoeficiente() + resultado.polinomio_[k].getCoeficiente());

					}
				}
			}

			if(!existeMonomio(resultado.polinomio_[k].getGrado())){
				ed::Monomio m = Monomio();
				m = resultado.getMonomio(resultado.polinomio_[k].getGrado());
				this->polinomio_.push_back(m);
			}
		}

		for(int x=0;x<getNumeroMonomios();x++){
			if(polinomio_[x].getCoeficiente() == 0){
				polinomio_.erase(polinomio_.begin() + x); // Todo polinomio cuyo coeficiente sea 0 	
			}
		}
		
		i++; 
	
	}
	
	return *this; // Se devuelve el objeto actual
}

ed::Polinomio & ed::Polinomio::operator/=(double const &x){
	
	for(int i=0;i<getNumeroMonomios();i++){
		polinomio_[i].setCoeficiente(polinomio_[i].getCoeficiente()/x);
	}

	return *this; // Se devuelve el objeto actual
}

// COMPLETAR EL RESTO DE OPERADORES



///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

void ed::Polinomio::leerPolinomio(){

	bool check = true; 
	double coeficiente;
	int grado;
	ed::Monomio m = Monomio(0.0,0); 

	this->polinomio_.clear(); 	// Limpiamos el vector ya que 
								// contiene el Monomio (0,0) del
								// constructor 

	std::cout << "\nPara salir introduzca en coeficiente 0 o grado negativo\n";

	while(check){

		std::cout << "\nCoeficiente: ";  
		std::cin >> coeficiente; 

		std::cout << "Grado: ";
		std::cin >> grado;

		if((coeficiente == 0) or (grado < 0)){
			check=false;
		}else{
			m.setCoeficiente(coeficiente);
			m.setGrado(grado);
			this->polinomio_.push_back(m);
		}
	}
}

void ed::Polinomio::escribirPolinomio(){

	for(int i=0;i<getNumeroMonomios();i++){
		polinomio_[i].escribirMonomio(); 
	}

	std::cout << "\n";

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
