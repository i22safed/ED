/*! 
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$ 
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	private:

		double coeficiente_; 
		int grado_; 


	//! \name Funciones o métodos públicos de la clase Monomio
	public:

	//! \name Constructores de la clase Monomio
	/*! 
		\brief 		Constructor parametrizado que crea un Monomio a partir del Coeficiente y del Grado 
		\attention 	Función sobrecargada
		\note 		Función inline 
		\warning 	Los parámetros tienen valores por defecto
		\param 		coeficiente: número real que representa el coeficiente del Monomio
		\param 		grado: número entero que representa el grado del monomio 
		\pre 		El grado del monomio debe de ser mayor o igual que 0
		\post 		El coeficiente se ha asignado de manera correcta (coeficiente == getCoeficiente())
		\post 		El grado se ha asignado de manera correcta (grado == getGrado())
		\note 		El coeficiente se ha obtenido mediante la resta de coeficiente y 
					y getCoeficiente() y comparado con la cota de error (COTA_ERROR) al 
					tratarse de numeros reales, sin	embargo para el grado se ha utilizado 
		 			el operador de igualdad (==) ya que son de tipo entero. En ambas 
					postcondiciones se han incluido un ejemplo simplificado de las mismas  
		\sa			setCoeficiente(), setGrado()
	
	*/
	inline Monomio(double coeficiente=0.0 ,int grado=0){

		#ifndef NDEBUG 
			assert(grado>=0); 
		#endif 

		this->setCoeficiente(coeficiente);
		this->setGrado(grado); 

		#ifndef NDEBUG 
			assert(std::abs(this->getCoeficiente() - coeficiente) < COTA_ERROR);
			assert(getGrado() == grado);
		#endif 

	}


	/*! 
		\brief 		Constructor de copia que crea un Monomio a partir de otro pasado como argumento 
		\attention 	Función sobrecargada
		\note 		Función inline 
		\warning 	Se requiere que las funciones de acceso getCoeficiente y getGrado tengan el modificador const
		\param 		m: Monomio
		\post 		El coeficiente se ha asignado de manera correcta (coeficiente == getCoeficiente())
		\post 		El grado se ha asignado de manera correcta (grado == getGrado())
		\note 		El coeficiente se ha obtenido mediante la resta de coeficiente y 
					y getCoeficiente() y comparado con la cota de error (COTA_ERROR) al 
					tratarse de numeros reales, sin	embargo para el grado se ha utilizado 
		 			el operador de igualdad (==) ya que son de tipo entero. En ambas 
					postcondiciones se han incluido un ejemplo simplificado de las mismas  
		\sa			setCoeficiente(), setGrado()
	
	*/
	inline Monomio(ed::Monomio const &m){

		this->setCoeficiente(m.getCoeficiente());
		this->setGrado(m.getGrado());

		#ifndef NDEBUG
			assert(std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
			assert(this->getGrado() == m.getGrado());
		#endif

	}
	
	//! \name Observadores: funciones de consulta de la clase Monomio

	/*!
		\brief 		Función que devuelve el coeficiente del Monomio
		\warning 	Se utiliza el modificador const en la definición de la 
					función para poder definir el constructor de copia entre 
					otros métodos de la clase
		\note 		Función inline 
		\return 	Coeficiente del Monomio actual
		\pre		Ninguna 
		\post		Ninguna 
		\sa 		getGrado()

	*/

	inline double getCoeficiente()const{
		return coeficiente_;
	}
	


	/*!
		\brief 		Función que devuelve el grado del Monomio
		\warning 	Se utiliza el modificador const en la definición de la 
					función para poder definir el constructor de copia entre 
					otros métodos de la clase
		\note 		Función inline 
		\return 	Grado del Monomio actual
		\pre		Ninguna 
		\post		Ninguna 
		\sa 		getCoeficiente()
		
	*/
	inline int getGrado()const{
		return grado_;
	}

	//! \name Funciones de modificación de la clase Monomio

	/*!
		\brief 		Función que asigna un valor "x" al coeficiente del Monomio 
		\note 		Función inline 
		\param		x: nuevo valor del coeficiente del Monomio (tipo double, referencia constante)
		\pre		Ninguna
		\post 		El coeficiente asignado es igual al parametro "x" (coeficiente_ == x)
		\note 		Se utiliza la cota de error (COTA_ERROR) para controlar la precisión a 
					a la hora de la asignación de los números reales
		\sa 		setGrado()
	*/
	inline void setCoeficiente(double const &x){

		coeficiente_ = x; 

		#ifndef NDEBUG 
			assert(std::abs(getCoeficiente() - x) < COTA_ERROR);
		#endif

	}

	/*!
		\brief 		Función que asigna un valor "n" al grado del Monomio 
		\note 		Función inline 
		\param		n: nuevo valor del grado del Monomio de tipo integer pasado como referencia constante
		\pre		El numero entero "n"
		\post 		El grado asignado es igual al parametro "n" (grado_ == n)
		\sa 		setCoeficiente()
	*/
	inline void setGrado(int const &n){
		
		#ifndef NDEBUG 
			assert(n >= 0);
		#endif
		
		grado_ = n;

		#ifndef NDEBUG 
			assert(getGrado()==n);
		#endif

	}

	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio

	// Operadores de asignación

		/*!
			\brief		Operador de asignación =(m): devuelve el monomio actual que ha sido modificado
						con los atributos del Monomio "m"
			\attention 	Se sobrecarga el operador de asignación "="
			\warning 	Se requiere que las funciones de acceso getCoeficiente()
						y getGrado() tengan el modificador const
			\param		m: objeto de tipo Monomio pasado como referencia constante
			\pre		Ninguna 
			\post		El coeficiente del Monomio es igual al coeficiente del Monomio "m" (getCoeficiente() == m.getCoeficiente())
			\post		El grado del monomio es igual al grado del Monomio "m" (getGrado() == m.getGrado())
			\note		En la asignación del coeficiente se utiliza la cota de error (COTA_ERROR) para controlar la precisión a 
						a la hora de la asignación de los números reales
			\sa			setCoeficiente(), setGrado(), getCoeficiente(), getGrado()
		*/
		Monomio & operator=(Monomio const &m);		// Hecho

		/*!
			\brief 		Operador de asignación =(x): devuelve el Monomio actual que ha sido modificado para que su grado sea 0 
						y su coeficiente sea el número real "x"
			\attention 	Se sobrecarga el operador de asignación "="
			\warning 	Se requiere que las funciones de acceso getCoeficiente() y getGrado() tengan 
						el modificador const
			\param		x: variable de tipo double que representa un número real, pasado por referencia 
			\pre		Ninguna 
			\post		El grado del Monomio es igual a 0 (getGrado() == 0)
			\post		El coeficiente del Monomio es igual al número real "x"  
			\note		En la asignación del coeficiente se utiliza la cota de error (COTA_ERROR) para controlar la precisión a 
						a la hora de la asignación de los números reales
			\sa			setCoeficiente(), setGrado(), getCoeficiente(), getGrado()
		*/
		Monomio & operator=(double const &x);		// Hecho

		/*!
			\brief		Operador de asignación +=(m): modifica el Monomio actual sumandole otro de igual grado 
			\attention	Se sobrecarga el operador combinado "+=" 
			\warning 	Se requiere que las funciones de acceso getCoeficiente() y getGrado() tengan 
						el modificador const
			\param		m: objeto de la clase Monomio pasado como referencia constante
			\pre		El monomio "m" tiene el mismo grado que el monomio actual (getGrado() == m.getGrado())
			\post		El coeficiente del Monomio actual se ha incrementado con el 
						coeficiente del Monomio "m" (getCoeficiente == old.getCoeficiente + m.getCoeficiente)
			\post		El grado del Monomio no se ha modificado (old.getGrado() == getGrado)
			\note		En la asignación del coeficiente se utiliza la cota de error (COTA_ERROR) para controlar la precisión a 
						a la hora de la asignación de los números reales
			\return 	Retorna el puntero al objeto actual 
			\sa			getCoeficiente(),setCoeficiente(),getGrado() 
		*/
		Monomio & operator+=(Monomio const &m);		// Hecho

		/*!
			\brief		Operador de asignación -=(m): Modifica el Monomio actual restandole otro de igual grado 
			\attention	Se sobrecarga el operador combinado "-=" 
			\warning 	Se requiere que las funciones de acceso getCoeficiente() y getGrado() tengan 
						el modificador const
			\param		m: objeto de la clase Monomio pasado como referencia constante
			\pre		El monomio "m" tiene el mismo grado que el monomio actual (getGrado() == m.getGrado())
			\post		El coeficiente del Monomio actual se ha decrementado con el 
						coeficiente del Monomio "m" (getCoeficiente == (old.getCoeficiente - m.getCoeficiente))
			\post		El grado del Monomio no se ha modificado (old.getGrado() == getGrado)
			\note		En la asignación del coeficiente se utiliza la cota de error (COTA_ERROR) para controlar la precisión a 
						a la hora de la asignación de los números reales
			\return 	Retorna el puntero al objeto actual 
			\sa			getCoeficiente(),setCoeficiente(),getGrado() 
		*/
		Monomio & operator-=(Monomio const &m);		// Hecho

		/*!
			\brief		Operador de asignación *=(m): modifica el Monomio multiplicado por otro de igual grado 
			\attention	Se sobrecarga el operador combinado "*=" 
			\warning 	Se requiere que las funciones getCoeficiente() y getGrado() tengan el modificador const
			\param		m: objeto de la clase Monomio pasado como referencia constante
			\pre		Ninguna
			\post		El coeficiente del Monomio actual se ha multiplicado por el coeficiente del Monomio "m" ((getCoeficiente() == (old.getCoeficiente() * m.getCoeficiente()))
			\post		El grado del Monomio actual se ha incrementado con el grado del Monomio "m" (getGrado() == old.getGrado() + m.getGrado())
			\note		En la asignación del coeficiente se utiliza la cota de error (COTA_ERROR) para controlar la precisión a 
						a la hora de la asignación de los números reales
			\return 	Retorna el puntero al objeto actual 
			\sa			getCoeficiente(), getGrado(), getCoeficiente(), getGrado()
		*/
		Monomio & operator*=(Monomio const &m);		// Hecho		
		
		/*!
			\brief		Operador de asignación /=(m): modifica el Monomio dividiéndolo por otro Monomio 
			\attention	Se sobrecarga el operador combinado "/="
			\warning 	Se requiere que las funciones de acceso getCoeficiente() y getGrado() tengan el modificador const
			\param		m: objeto de la clase Monomio pasado como referencia constante
			\pre		El grado del Monomio "m" es igual o inferior al grado del Monomio actual (m.getGrado() <= getGrado())
			\pre		El coeficiente del Monomio "m" no es 0.0 (m.getGrado() != 0.0)
			\post		El coeficiente del Monomio actual se ha dividido por el coeficiente del Monomio "m" (getCoeficiente() == (old.getCoeficiente() / m.getCoeficiente()))
			\post		El grado del Monomio actual se ha decrementado con el grado del Monomio "m" (getGrado == (old.getGrado() - m.getGrado()))
			\note		En la asignación del coeficiente se utiliza la cota de error (COTA_ERROR) para controlar la precisión a 
						a la hora de la asignación de los números reales
			\sa			getCoeficiente(), getGrado(), getCoeficiente(), getGrado()
		*/
		Monomio & operator/=(Monomio const &m);		// Hecho
		
		/*!
			\brief		Operador de asignación *=(x): modifica el Monomio multiplicándolo por un número real 
			\attention	Se sobrecarga el operador combinado "*="
			\warning 	Se requiere que las funciones de acceso getCoeficiente() y getGrado() tengan el modificador const
			\param		x: variable de tipo double que representa un número real, pasado por referencia  	
			\pre		Ninguna
			\post		El coeficiente del Monomio actual se ha multiplicado por el número real "x" (getCoeficiente() == (old.getCoeficiente() * getCoeficiente()))
			\post		El grado del Monomio actual no ha sido modificado (getGrado == old.getGrado())
			\note		En la asignación del coeficiente se utiliza la cota de error (COTA_ERROR) para controlar la precisión a 
						a la hora de la asignación de los números reales
			\sa			getCoeficiente(), getGrado(), getCoeficiente(), getGrado()
		*/
		Monomio & operator*=(double const &x);		// Hecho
		
		/*!
			\brief		Operador de asignación /=(x): modifica el Monomio multiplicándolo por un número real 
			\attention	Se sobrecarga el operador combinado /=
			\warning 	Se requiere que las funciones de acceso getCoeficiente() y getGrado() tengan el modificador const
			\param		x: variable de tipo double que representa un número real, pasado por referencia  	
			\pre		La variable "x" no es 0.0 (x != 0.0)
			\post		El coeficiente del Monomio actual se ha dividido por el número real "x"(getCoeficiente() )
			\post		El grado del del Monomio actual no ha sido modificado (old.getGrado() == getGrado())
			\note		En la asignación del coeficiente se utiliza la cota de error (COTA_ERROR) para controlar la precisión a 
						a la hora de la asignación de los números reales
			\sa			getGrado(), getCoeficiente(), setCoeficiente()
		*/
		Monomio & operator/=(double const &x);		// Hecho



	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

	/*!
		\brief		Lee desde teclado los valores de coeficiente y grado de forma secuencial 
		\warning 	El usuario debe de introducir dichos numeros
		\pre		Ninguna 
		\post		El grado del Monomio es mayor o igual que 0 
		\sa 		setCoeficiente(), setGrado()
	*/
	void leerMonomio();


	/*!
		\brief		Escribe por pantalla los atributos del Monomio con el formato coeficienteX^grado
		\warning 	Método constante para evitar la modificación del Monomio actual 
		\note		Dependiendo de los valores del coeficiente y el grado, se adoptará un determinado 
					formato: 
						- Si coeficiente == 1 	-> 	X^Grado
						- Si coeficiente == -1 	-> 	-X^Grado
						- Si grado == 0 		-> 	Coeficiente 
						- Si grado == 1			-> 	CoeficienteX
		\pre 		Ninguna 
		\post		Ninguna
	
	*/
	void escribirMonomio() const; 

	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Monomio


	/*! 
		\brief		Calcula el valor del Monomio para un determinado valor de "x"
		\param 		x: numero real pasado como referencia constante, que representa
					el valor de "x" en el Monomio 
		\pre		Ninguna
		\post 		Ninguna
		\note 		Uso de la librería matemática cmath, necesaria para la 
					potencia de la variable "x" y el grado (pow(x,getGrado())) 
		\return 	Valor del Monomio para el valor de "x" pasado 
		\sa 		getCoeficiente(), getGrado()
		
	
	*/
	double calcularValor(double const &x);

};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
