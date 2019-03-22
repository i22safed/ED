/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPPolinomio_
#define _POLINOMIO_HPPolinomio_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio
   private:

<<<<<<< HEAD
  	std::vector<Monomio> polinomio_;
=======
		std::vector<Monomio> p_;
		
>>>>>>> d350ff20da2fee9150ed513b0c8ea48d36861686

   //! \name Funciones o métodos públicos de la clase Polinomio
   public:

	//! \name Constructores de la clase Polinomio

<<<<<<< HEAD
  	inline Polinomio(){
=======
	Polinomio(){

		Monomio m; 

		m.setCoeficiente(0.0); 
		m.setGrado(0);

		#ifndef NDEBUG
			assert(esNulo());
		#endif
	}

	Polinomio(Polinomio const &p){
	
		for(int i=0; ){
			
		}
	
	}
	
	
	
>>>>>>> d350ff20da2fee9150ed513b0c8ea48d36861686

		  ed::Monomio m = ed::Monomio(0.0,0);

<<<<<<< HEAD
		  polinomio_.push_back(m);
=======
	inline bool esNulo()const{

		#ifndef NDEBUG
			assert(getNumeroMonomios() == 1);
		#endif 

		return ((this->p_[0].getCoeficiente() == 0.0) && (this->p_[0].getGrado() == 0));
	
	}

	inline int getNumeroMonomios() const {
		return this->p_.size();
	}

	


	
>>>>>>> d350ff20da2fee9150ed513b0c8ea48d36861686

		  #ifndef NDEBUG 
			assert(esNulo());
		  #endif 

	}

	inline Polinomio(Polinomio const & p){

		for(int i=0;i<p.getNumeroMonomios();i++){
			this->polinomio_[i].setCoeficiente(p.polinomio_[i].getCoeficiente());
			this->polinomio_[i].setGrado(p.polinomio_[i].getGrado());
		}

		#ifndef NDEBUG 
			//assert(esIgual polinomio_ y p);
		#endif

	}
	
	//! \name Observadores: funciones de consulta de la clase Polinomio

	inline bool esNulo() const {

		#ifndef NDEBUG
			assert(getNumeroMonomios() == 1);
		#endif

		return ((this->polinomio_[0].getCoeficiente() == 0.0) && (this->polinomio_[0].getGrado() == 0));

	}

	inline int getGrado() const {

		#ifndef NDEBUG 
			//assert(polinomioOrdenado() == true);
		#endif

		return polinomio_[0].getGrado();

	}



	inline int getNumeroMonomios() const {
		return polinomio_.size();
	}

	inline bool existeMonomio(int grado) const {

		#ifndef NDEBUG 
			assert(!esNulo());
		#endif

		bool valorDevuelto = false;

		for(int i=0;i<getNumeroMonomios();i++){
			if(polinomio_[i].getGrado() == grado){
				valorDevuelto = true;
			}
		}
		
		return valorDevuelto;

	}

	inline Monomio getMonomio(int grado) const {

		#ifndef NDEBUG 		// Precondicion → El monomio debe existir 
			assert(existeMonomio(grado));
		#endif

		ed::Monomio m = Monomio(0.0,0);

		for(int i=0;i<getNumeroMonomios();i++){

			if(polinomio_[i].getGrado() == grado){
				m = polinomio_[i];
			}
		}
	
		return m;
	
	}



	//! \name Funciones de modificación de la clase Polinomio

 	////////////////////////////////////////////////////////////////

   //! \name Operadores de la clase Polinomio

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Polinomio const &p);
	Polinomio & operator=(Monomio const &m);
	Polinomio & operator=(double const &x);

  // Operadores aritméticos y asignación

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator+=(Polinomio const &p);
	Polinomio & operator+=(Monomio const &m);
	Polinomio & operator+=(double const &x);
	
	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator-=(Polinomio const &p);
	Polinomio & operator-=(Monomio const &m);
	Polinomio & operator-=(double const &x);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator*=(Polinomio const &p);
	Polinomio & operator*=(Monomio const &m);
	Polinomio & operator*=(double const &x);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator/=(Polinomio const &p);
	Polinomio & operator/=(Monomio const &m);
	Polinomio & operator/=(double const &x);
	


  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio

	void leerPolinomio();
	void escribirPolinomio(); 


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio

	double calcularValor(double const &x);

	inline bool estaOrdenado() const{

		int max = 10000; 
		bool valorDevuelto = true; 

		for (int i=0; i<getNumeroMonomios();i++){
			if(max > polinomio_[i].getGrado()){
				max = polinomio_[i].getGrado();
			}else{
				valorDevuelto = false; 
			}
		}

		return valorDevuelto; 

	}

	inline bool sonIguales(Polinomio const &p){	// Comprueba que dos polinomios son iguales 

		bool valorDevuelto = true; 

		#ifndef NDEBUG 
			assert(getNumeroMonomios() == p.getNumeroMonomios());
		#endif 

		for(int i=0;i<getNumeroMonomios();i++){

				if((std::abs(this->polinomio_[i].getCoeficiente() - p.polinomio_[i].getCoeficiente()) > COTA_ERROR)
				or (this->polinomio_[i].getGrado() != p.polinomio_[i].getGrado())){
					valorDevuelto = false; 
				}

		}

		return valorDevuelto; 

	}

	// Incluir tambien la de ordenar vector ////////////////////



}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPPolinomio_
#endif
