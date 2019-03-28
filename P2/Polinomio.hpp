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
#include "operadoresExternosMonomios.hpp"


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio
   private:

  	std::vector<Monomio> polinomio_;

   //! \name Funciones o métodos públicos de la clase Polinomio
   public:

	//! \name Constructores de la clase Polinomio

  	inline Polinomio(){

		  ed::Monomio m = ed::Monomio(0.0,0);

		  polinomio_.push_back(m);

		  #ifndef NDEBUG
			assert(esNulo());
		  #endif

	}

	inline Polinomio(Polinomio const & p){

		ed::Monomio m = Monomio();

		for(int i=0;i<p.getNumeroMonomios();i++){

			m = p.polinomio_[i];
			polinomio_.push_back(m);
		}

		#ifndef NDEBUG
			assert(sonIguales(p));
		#endif

	}

	//! \name Observadores: funciones de consulta de la clase Polinomio

	inline bool esNulo() const {

		ed::Monomio m = Monomio(0.0,0);

		return (polinomio_[0] == m);

	}

	inline int getGrado() {

		int max = 0;

		for(int i=0;i<getNumeroMonomios();i++){
			if(max < polinomio_[i].getGrado())
				max = polinomio_[i].getGrado();
		}

		return max;

	}

	inline int getNumeroMonomios() const {
		return polinomio_.size();
	}

	inline bool existeMonomio(int grado) const {

		/*
		#ifndef NDEBUG
			assert(getNumeroMonomios()>1);
		#endif
		*/

		bool valorDevuelto = false;

		for(int i=0;i<getNumeroMonomios();i++){
			if(this->polinomio_[i].getGrado() == grado){
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
	Polinomio & operator-=(Monomio &m); // Ya que si no existe el monomio hay que meterlo (modificarlo) negativo
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


	inline bool sonIguales(Polinomio const &p){	// Comprueba que dos polinomios son iguales

		bool valorDevuelto = true;

		if(getNumeroMonomios() != p.getNumeroMonomios()){
      valorDevuelto = false;
    }

		for(int i=0;i<getNumeroMonomios();i++){
				if(polinomio_[i] != p.polinomio_[i]){
					valorDevuelto = false;
				}
		}

		return valorDevuelto;

	}

	inline void ordenarPolinomio(){

      ed::Polinomio aux = Polinomio();
      ed::Monomio m = Monomio();
      aux.polinomio_.clear();

      // Primero quitamos posibles repetidos
      for(int i=0;i<getNumeroMonomios();i++){
          for(int j=i+1;j<getNumeroMonomios();j++){
            if(this->polinomio_[i].getGrado() == this->polinomio_[j].getGrado()){
              this->polinomio_[i].setCoeficiente(this->polinomio_[i].getCoeficiente() + this->polinomio_[j].getCoeficiente());
              this->polinomio_.erase(polinomio_.begin() + j);
            }
          }
      }

      // Ahora ordenamos en funcion del grado

      for(int x=getGrado();x>=0;x--){
        if(existeMonomio(x)){
            m = getMonomio(x);
            aux.polinomio_.push_back(m);
        }
      }

      polinomio_.clear();

      for(int y=0;y<aux.getNumeroMonomios();y++){
        polinomio_.push_back(aux.polinomio_[y]);
      }
  }


}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPPolinomio_
#endif
