/*!
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed
{
	// Operadores de igualdad

	// COMPLETAR

	bool operator==(ed::Monomio const &m1, ed::Monomio const &m2){
		
		
		bool valorDevuelto = ((std::abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR)
		and (m1.getGrado() == m2.getGrado()));
		
		#ifndef NDEBUG 
			assert(valorDevuelto == ((std::abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR)
			and (m1.getGrado() == m2.getGrado())));
		#endif 
	
		return valorDevuelto;

	}

	bool operator==(ed::Monomio const &m, double const &x){
		
		bool valorDevuelto = ((std::abs( m.getCoeficiente() - x )<COTA_ERROR)
		and (m.getGrado() == 0)); 

		#ifndef NDEBUG 
			assert( valorDevuelto == ((std::abs( m.getCoeficiente() - x )<COTA_ERROR)
					and (m.getGrado() == 0)) );
		#endif

		return valorDevuelto;

	}

	bool operator==(double const &x, ed::Monomio const &m){

		bool valorDevuelto = ((std::abs( x - m.getCoeficiente())<COTA_ERROR)
		and (m.getGrado() == 0)); 

		#ifndef NDEBUG 
			assert( valorDevuelto == ((std::abs( x - m.getCoeficiente())<COTA_ERROR)
					and (m.getGrado() == 0)) );
		#endif

		return valorDevuelto;

	}


	// Operadores de desigualdad

	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2){

		bool valorDevuelto = not(m1==m2); 

		#ifndef NDEBUG 
			assert(valorDevuelto == not(m1==m2));
		#endif 
		
		return valorDevuelto;
	}

	bool operator!=(double const &x, ed::Monomio const &m){

		bool valorDevuelto = not(x==m);

		#ifndef NDEBUG 
			assert(valorDevuelto == not(x==m));
		#endif 

		return valorDevuelto;
	}

	bool operator!=(ed::Monomio const &m, double const &x){

		bool valorDevuelto = not(m==x);

		#ifndef NDEBUG 
			assert(valorDevuelto == not(m==x));
		#endif 

		return valorDevuelto;
	}
	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos

	ed::Monomio & operator+(ed::Monomio const & m){

		// Se crea un nuevo objeto
		ed::Monomio * nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m.getCoeficiente());
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG 
			assert((nuevo->getCoeficiente() == m.getCoeficiente()) and (nuevo->getGrado() == m.getGrado()));
		#endif 

		// Se devuelve el resultado
		return * nuevo;
	}

	ed::Monomio & operator-(ed::Monomio const & m){

		// Se crea un nuevo objeto
		ed::Monomio * nuevo = new ed::Monomio();

		nuevo->setCoeficiente(-1 * m.getCoeficiente());
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG 
			assert((nuevo->getCoeficiente() == (-1 * m.getCoeficiente())) and (nuevo->getGrado() == m.getGrado()));
		#endif 

		// Se devuelve el resultado
		return * nuevo;
	}

	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+(ed::Monomio const &m1, ed::Monomio const &m2){
		
		
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		#ifndef NDEBUG 
			assert( m1.getGrado() == m2.getGrado());
		#endif
	
		nuevo->setCoeficiente(m1.getCoeficiente() + m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado());


		#ifndef NDEBUG 
			assert(std::abs(nuevo->getCoeficiente()-m1.getCoeficiente()-m2.getCoeficiente()) < COTA_ERROR);
			assert((nuevo->getGrado() == m1.getGrado()) and (nuevo->getGrado() == m2.getGrado()));
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	////////////
	// Resta

	ed::Monomio & operator-(ed::Monomio const &m1,ed::Monomio const &m2){

		ed::Monomio * nuevo = new ed::Monomio();

		#ifndef NDEBUG 
			assert(m1.getGrado() == m2.getGrado());
		#endif 

		nuevo->setCoeficiente( m1.getCoeficiente() - m2.getCoeficiente() );
		nuevo->setGrado(m1.getGrado());

		#ifndef NDEBUG 
			assert( nuevo->getGrado() == m1.getGrado() );
			assert(std::abs(nuevo->getCoeficiente()-(m1.getCoeficiente()-m2.getCoeficiente())) < COTA_ERROR);
		#endif 

		return *nuevo;

	}

	//////////////////
	// Multiplicación

	ed::Monomio & operator*(ed::Monomio const &m1, ed::Monomio const &m2){

		ed::Monomio * nuevo = new ed::Monomio();
		
		nuevo->setCoeficiente(m1.getCoeficiente() * m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado() + m2.getGrado());		

		#ifndef NDEBUG 
			assert(nuevo->getGrado() == (m1.getGrado() + m2.getGrado()));
			assert( std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() * m2.getCoeficiente())) < COTA_ERROR);
		#endif 

		return * nuevo; 

	}

	ed::Monomio & operator*( ed::Monomio const &m, double x){

		ed::Monomio * nuevo = new ed::Monomio();		

		nuevo->setCoeficiente(m.getCoeficiente() * x);
		nuevo->setGrado(m.getGrado());


		#ifndef NDEBUG
			assert(nuevo->getGrado() == m.getGrado());
			assert(std::abs(nuevo->getCoeficiente() - (m.getCoeficiente() * x)) < COTA_ERROR);
		#endif 

		return *nuevo;

	}

	ed::Monomio & operator*(double x, ed::Monomio const &m){

		ed::Monomio * nuevo = new ed::Monomio();		

		nuevo->setCoeficiente(x * m.getCoeficiente());
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG
			assert(nuevo->getGrado() == m.getGrado());
			assert(std::abs(nuevo->getCoeficiente() - (x * m.getCoeficiente())) < COTA_ERROR);
		#endif 

		return *nuevo;

	}

	////////////
	// División

	ed::Monomio & operator/(ed::Monomio const &m1, ed::Monomio const &m2){
		
		ed::Monomio * nuevo = new ed::Monomio();

		#ifndef NDEBUG 
			assert(m1.getGrado() >= m2.getGrado());
			assert(m2.getCoeficiente() != 0.0);
		#endif

		nuevo->setCoeficiente(m1.getCoeficiente() / m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado() - m2.getGrado());

		#ifndef NDEBUG 
			assert(nuevo->getGrado() == (m1.getGrado() - m2.getGrado()));
			assert(std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() / m2.getCoeficiente())) < COTA_ERROR);
		#endif

		return *nuevo;
	}

	ed::Monomio & operator/(ed::Monomio const &m, double x){
		
		ed::Monomio * nuevo = new ed::Monomio(); 

		#ifndef NDEBUG 
			assert( x != 0); 
		#endif

		nuevo->setCoeficiente(m.getCoeficiente()/x);
		nuevo->setGrado(m.getGrado());

		#ifndef NDEBUG 
			assert(nuevo->getGrado() == m.getGrado());
			assert(std::abs(nuevo->getCoeficiente() - (m.getCoeficiente()/x)) < COTA_ERROR);
		#endif 

		return * nuevo; 
	
	}

	ed::Monomio & operator/(double x, ed::Monomio const &m){
	
		ed::Monomio * nuevo = new ed::Monomio(); 

		#ifndef NDEBUG 
			assert((m.getGrado() == 0) and (m.getCoeficiente() != 0.0));
		#endif

		nuevo->setCoeficiente(x/m.getCoeficiente());
		nuevo->setGrado(m.getGrado());


		#ifndef NDEBUG 
			assert(nuevo->getGrado() == 0);
			assert(std::abs(nuevo->getCoeficiente()-(x/m.getCoeficiente())) < COTA_ERROR);
		#endif

		return * nuevo; 
	
	}

	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m){
		// COMPLETAR

		double coeficiente = 0.0; 
		int grado = 0; 

		std::cout << "Introduzca los valores para Coeficiente y Grado: ";
		stream >> coeficiente >> grado;
	
		m.setCoeficiente(coeficiente);
		m.setGrado(grado);

   		// Se devuelve el flujo de entrada
		return stream;
	}

	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m){
		
		stream << m.getCoeficiente() << " " << m.getGrado();		

		// Se devuelve el flujo de salida
		return stream;
	}

}  // namespace ed
