/*!
   \file operadoresExternosPolinomios.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "operadoresExternosPolinomios.hpp"
#include "operadoresExternosMonomios.hpp"
#include "Polinomio.hpp"


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed
{

bool operator==(ed::Polinomio const & p1, ed::Polinomio const & p2){
	
	bool valorDevuelto = true;
	ed::Monomio m1,m2;
	

	if(p1.getGrado() != p2.getGrado()){
		valorDevuelto = false; 
	}

	if(p1.getNumeroMonomios() != p2.getNumeroMonomios()){
		valorDevuelto = false; 
	
	}else{ 	// Aqui suponemos que ambos tienen el mismo numero de 
			// monomios 
		
		for(int i=0;i<p1.getNumeroMonomios();i++){
			m1 = p1.getIndice(i);
			m2 = p2.getIndice(i);

			if((std::abs(m1.getCoeficiente() - m2.getCoeficiente()) > COTA_ERROR) or (m1.getGrado() != m2.getGrado())){
				valorDevuelto = false; 
			}

		}
	}

	#ifndef NDEBUG 
		assert(valorDevuelto ==  (p1.getNumeroMonomios() == p2.getNumeroMonomios()));
	#endif

	return valorDevuelto;

}
bool operator==(ed::Polinomio const & p, ed::Monomio const & m){
	
	bool valorDevuelto = true; 
	ed::Monomio p0 = p.getIndice(0);

	if(p.getNumeroMonomios() != 1){
		valorDevuelto = false; 
	}else{

		if((std::abs(p0.getCoeficiente() - m.getCoeficiente()) > COTA_ERROR) or (p0.getGrado() != m.getGrado())){
				valorDevuelto = false; 
		}
	}
	return valorDevuelto;
}

bool operator==(ed::Monomio const & m, ed::Polinomio const & p){
	
	bool valorDevuelto = true; 
	ed::Monomio p0 = p.getIndice(0);

	if(p.getNumeroMonomios() != 1){
		valorDevuelto = false; 
	}else{

		if((std::abs(m.getCoeficiente() - p0.getCoeficiente()) > COTA_ERROR) or (m.getGrado() != p0.getGrado())){
				valorDevuelto = false; 
		}
	}
	return valorDevuelto;

}
bool operator==(ed::Polinomio const & p, double const & x){
	
	bool valorDevuelto = true; 
	ed::Monomio p0 = p.getIndice(0);

	if(p.getNumeroMonomios() != 1){
		valorDevuelto = false; 
	}else{

		if((std::abs(x - p0.getCoeficiente()) > COTA_ERROR) or (p0.getGrado() != 0)){
				valorDevuelto = false; 
		}
	}
	return valorDevuelto;

}

bool operator==(double const & x, ed::Polinomio const & p){
	
	bool valorDevuelto = true; 
	ed::Monomio p0 = p.getIndice(0);

	if(p.getNumeroMonomios() != 1){
		valorDevuelto = false; 
	}else{

		if((std::abs(p0.getCoeficiente()-x) > COTA_ERROR) or (p0.getGrado() != 0)){
				valorDevuelto = false; 
		}
	}
	return valorDevuelto;

}

////////////////////////////////////////////////////////////////////////////////////
// Operadores de desigualdad

	bool operator!=(ed::Polinomio const & p1, ed::Polinomio const & p2){
		
		bool valorDevuelto = true; 

		if((p1 == p2) == false){
			valorDevuelto = false; 
		}
		
		return valorDevuelto;
	}

	bool operator!=(ed::Polinomio const & p, ed::Monomio const & m){
		
		bool valorDevuelto = true; 

		if((p == m) == false){
			valorDevuelto = false; 
		}
		
		return valorDevuelto;
	}

	bool operator!=(ed::Monomio const & m, ed::Polinomio const & p){
		
		bool valorDevuelto = true; 

		if((m == p) == false){
			valorDevuelto = false; 
		}
		
		return valorDevuelto;
	}
	
	bool operator!=(ed::Polinomio const & p, double const & x){
		
		bool valorDevuelto = true; 

		if((p == x) == false){
			valorDevuelto = false; 
		}
		
		return valorDevuelto;
	}
	
	bool operator!=(double const & x, ed::Polinomio const & p){
		
		bool valorDevuelto = true; 

		if((x == p) == false){
			valorDevuelto = false; 
		}
		
		return valorDevuelto;
	}

// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD

//////////////////////////////////////////////////////////////////////////////////////

// Operadores unarios

ed::Polinomio & operator+(ed::Polinomio const & p){
	
	ed::Polinomio * nuevo = new ed::Polinomio(p);

	#ifndef NDEBUG 
		assert(nuevo->sonIguales(p));
	#endif

	return *nuevo;
}

ed::Polinomio & operator-(ed::Polinomio const & p){
	
	ed::Polinomio * nuevo = new ed::Polinomio();
	ed::Monomio m; 

	for(int i=0;i<p.getNumeroMonomios();i++){
		m = p.getIndice(i);
		m.setCoeficiente(m.getCoeficiente() * (-1));
		nuevo->anadirMonomio(m);
	}

	return *nuevo;
}


//////////////////////////////////////////////////////////////////////////////////////

// Operadores binarios de la suma
	ed::Polinomio & operator+(ed::Polinomio const &p1,  ed::Polinomio const &p2){
		
		ed::Polinomio res; 
		res+=p1;
		res+=p2;		
		ed::Polinomio *nuevo = new ed::Polinomio(res);
		
		return *nuevo;
	}

	ed::Polinomio & operator+(ed::Polinomio const &p,  ed::Monomio const &m){
		
		ed::Polinomio res; 
		res+=p;
		res+=m;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}

	ed::Polinomio & operator+(ed::Monomio const &m,  ed::Polinomio const &p){
		
		ed::Polinomio res; 
		res+=m;
		res+=p;
		ed::Polinomio *nuevo = new ed::Polinomio(res);
		
		return *nuevo;
	}

	ed::Polinomio & operator+(ed::Polinomio const &p,  double const &x){
		
		ed::Polinomio res; 
		res+=p;
		res+=x;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}

	ed::Polinomio & operator+(double const &x,  ed::Polinomio const &p){
		
		ed::Polinomio res; 
		res+=x;
		res+=p;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}


	////////////
	// Resta
	ed::Polinomio & operator-(ed::Polinomio const &p1,  ed::Polinomio const &p2){
		
		ed::Polinomio res; 
		res+=p1;
		res-=p2;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}

	ed::Polinomio & operator-(ed::Polinomio const &p,  ed::Monomio const &m){
		
		ed::Polinomio res; 
		res+=p;
		res-=m;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}

	ed::Polinomio & operator-(ed::Monomio const &m,  ed::Polinomio const &p){
		
		ed::Polinomio res; 
		res+=m;
		res-=p;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}

	ed::Polinomio & operator-(ed::Polinomio const &p,  double const &x){
		
		ed::Polinomio res; 
		res+=p;
		res-=x;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}

	ed::Polinomio & operator-(double const &x,  ed::Polinomio const &p){
		
		ed::Polinomio res; 
		res+=x;
		res-=p;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}
	


	//////////////////
	// Multiplicación

	ed::Polinomio & operator*(ed::Polinomio const &p1,  ed::Polinomio const &p2){
	
		ed::Polinomio res; 
		res+=p1;
		res*=p2;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}

	ed::Polinomio & operator*(ed::Polinomio const &p,  ed::Monomio const &m){
		
		ed::Polinomio res; 
		res+=p;
		res*=m;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}

	ed::Polinomio & operator*(ed::Monomio const &m,  ed::Polinomio const &p){
		
		ed::Polinomio res; 
		res+=m;
		res*=p;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}

	ed::Polinomio & operator*(ed::Polinomio const &p,  double const &x){
		
		ed::Polinomio res; 
		res+=p;
		res*=x;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}

	ed::Polinomio & operator*(double const &x,  ed::Polinomio const &p){
		
		ed::Polinomio res; 
		res+=x;
		res*=p;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}
	

	////////////
	// División

	ed::Polinomio & operator/(ed::Polinomio const &p1,  ed::Polinomio const &p2){
		
		ed::Polinomio res; 
		res+=p1;
		res/=p2;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}

	ed::Polinomio & operator/(ed::Polinomio const &p,  ed::Monomio const &m){
		
		ed::Polinomio res; 
		res+=p;
		res/=m;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}

	ed::Polinomio & operator/(ed::Monomio const &m,  ed::Polinomio const &p){
		
		ed::Polinomio res; 
		res+=m;
		res/=p;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}

	ed::Polinomio & operator/(ed::Polinomio const &p,  double const &x){
		
		ed::Polinomio res; 
		res+=p;
		res/=x;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}

	ed::Polinomio & operator/(double const &x,  ed::Polinomio const &p){
		
		ed::Polinomio res; 
		res+=x;
		res/=p;
		ed::Polinomio *nuevo = new ed::Polinomio(res);

		return *nuevo;
	}


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
