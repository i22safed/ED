/*!
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad

		bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);


	/*!
		\brief 		Operador de igualdad: comprueba si un Monomio "m" es igual a un número real (m==x).
					Para determinar sin son iguales, es necesario que el grado del Monomio es igual a 
					0 y el coeficiente sea igual al valor "x" 
		\attention	Se sobrecarga el operador de igualdad "==".
		\param 		m: objeto de la clase Monomio pasado como referencia constante
		\param 		x: numero real, pasado como referencia constante
		\pre 		Ninguna 
		\post 		El valor devuelto (bool valorDevuelto) debe ser el resultado lógico de 
					de las comparaciones de los coeficientes y el grado ((m.getCoeficiente() == x)
					and (m.getGrado() ==  0))
		\note 		Para mejorar la precisión a la hora de comparar los coeficientes se ha utilizado 
					la cota de error (COTA_ERROR) mediante la expresion (|valor1 - valor2| < COTA_ERROR)
		\return 	El valor de retorno es un booleano (bool valorDevuelto) que contiene el resultado 
					de la expresión lógica de comparación. Devolviendo TRUE si son iguales 
					y FALSE en caso contrario.
		\sa 		ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	
	*/
	bool operator==(ed::Monomio const &m, double const &x);
	
	/*!
		\brief 		Operador de igualdad: comprueba si un numero real "x" es igual a un Monomio (x==m).
					Para determinar sin son iguales, es necesario que el grado del Monomio es igual a 
					0 y el coeficiente sea igual al valor "x" 
		\attention	Se sobrecarga el operador de igualdad "==".
		\param 		x: numero real, pasado como referencia constante
		\param 		m: objeto de la clase Monomio pasado como referencia constante
		\pre 		Ninguna 
		\post 		El valor devuelto (bool valorDevuelto) debe ser el resultado lógico de 
					de las comparaciones de los coeficientes y el grado ((x == m.getCoeficiente())
					and (m.getGrado() ==  0))
		\note 		Para mejorar la precisión a la hora de comparar los coeficientes se ha utilizado 
					la cota de error (COTA_ERROR) mediante la expresion (|valor1 - valor2| < COTA_ERROR)
		\return 	El valor de retorno es un booleano (bool valorDevuelto) que contiene el resultado 
					de la expresión lógica de comparación. Devolviendo TRUE si son iguales 
					y FALSE en caso contrario.
		\sa 		ed::Monomio::getCoeficiente(), ed::Monomio::getGrado()
	
	*/
	bool operator==(double const &x, ed::Monomio const &m);

	//! \name Operadores de desigualdad 

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN

	
	/*!
		\brief 		Operador de desigualdad: compara si dos Monomios son distintos (m1 != m2)
		\note 		La operación de desigualdad se realiza mediante el resultado de la igualdad 
					(==), es decir, si el resultado del operador de igualdad para dos Monomios 
					retorno FALSE implica que dichos Monomio NO son iguales retornando por 
					consecuencia TRUE para el operador de desigualdad (!=)
		\attention 	Se sobrecarga el operador de desigualdad "!="
		\param 		m1: objeto de la clase Monomio pasado como referencia constante
		\param 		m2: objeto de la clase Monomio pasado como referencia constante
		\pre 		Ninguna
		\post		El valor devuelto (bool valorDevuelto) debe ser igual a la negacion del resultado 
					de la expresión m1==m2 (valorDevuelto == not(m1==m2))
		\note 		Para mejorar la precisión a la hora de comparar los coeficientes se ha utilizado 
					la cota de error (COTA_ERROR) mediante la expresion (|valor1 - valor2| < COTA_ERROR)
		\return 	El valor de retorno es un booleano (bool valorDevuelto) que contiene el resultado 
					de la expresión lógica de comparación. Devolviendo TRUE si son distintos 
					y FALSE en caso contrario.
		\sa			operator ==
		
	*/
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);


	/*!
		\brief		Operador de desigualdad: compara si un numero real "x" es distinto 
					de un Monomio "m" (x!=m)
		\note 		La operación de desigualdad se realiza mediante el resultado de la igualdad 
					(==), es decir, si el resultado del operador de igualdad para dos Monomios 
					retorno FALSE implica que dichos Monomio NO son iguales retornando por 
					consecuencia TRUE para el operador de desigualdad (!=)
		\attention 	Se sobrecarga el operador de desigualdad "!="
		\param 		x: numero real, pasado como referencia constante
		\param 		m: objeto de la clase Monomio pasado como referencia constante
		\pre 		Ninguna 
		\post 		El valor devuelto (bool valorDevuelto) debe ser el resultado lógico de 
					de las comparaciones de los coeficientes y el grado ((x != m.getCoeficiente())
					and (m.getGrado() !=  0))
		\return 	El valor de retorno es un booleano (bool valorDevuelto) que contiene el resultado 
					de la expresión lógica de comparación. Devolviendo TRUE si son distintos 
					y FALSE en caso contrario.
		\sa			operator ==
		
	*/
	bool operator!=(double const &x, ed::Monomio const &m);



	/*!
		\brief		Operador de desigualdad: compara si un Monomio "m" es distinto 
					de un numero real "x" (m!=x)
		\note 		La operación de desigualdad se realiza mediante el resultado de la igualdad 
					(==), es decir, si el resultado del operador de igualdad para dos Monomios 
					retorno FALSE implica que dichos Monomio NO son iguales retornando por 
					consecuencia TRUE para el operador de desigualdad (!=)
		\attention 	Se sobrecarga el operador de desigualdad "!="
		\param 		m: objeto de la clase Monomio pasado como referencia constante
		\param 		x: numero real, pasado como referencia constante
		\pre 		Ninguna 
		\post 		El valor devuelto (bool valorDevuelto) debe ser el resultado lógico de 
					de las comparaciones de los coeficientes y el grado ((x != m.getCoeficiente())
					and (m.getGrado() !=  0))
		\return 	El valor de retorno es un booleano (bool valorDevuelto) que contiene el resultado 
					de la expresión lógica de comparación. Devolviendo TRUE si son distintos 
					y FALSE en caso contrario.
		\sa			operator ==
		
	*/
	bool operator!=(ed::Monomio const &m, double const &x);

	//! \name Operadores unarios prefijos

	/*! 
		\brief 		Operador signo +: devuelve un monomio "m" con el mismo grado y 
					coeficiente 
		\note 		Se reserva dinamicamente memoria para un objeto de tipo Monomio
					(ed::Monomio * nuevo = new ed::Monomio()), el cual se retornará 
					una vez asignado los valores de coeficiente y grado 
		\attention 	Se sobrecarga el operador unario "+"
		\param 		m: objeto de la clase Monomio pasado como referencia constante
		\pre		Ninguna
		\post 		El Monomio devuelto posee el mismo coeficiente y grado que el
					que el Monomio "m", para ello comprobamos que 
					nuevo -> getGrado() == m.getGrado() y 
					nuevo -> getCoeficiente() == -m.getCoeficiente()
		\return 	El valor de retorno es un objeto de tipo Monomio con el mismo
					grado y coeficiente del Monomio "m"
		\sa			ed::Monomio::setCoeficiente(), ed::Monomio::setGrado(), 
					ed::Monomio::getCoeficiente(), ed::Monomio::getGrado(),   
	
	*/

	ed::Monomio & operator+(ed::Monomio const & m);

	/*! 
		\brief 		Operador signo -: devuelve un monomio "m" con el mismo grado y el  
					coeficiente opuesto ( m -> -m )
		\note 		Se reserva dinamicamente memoria para un objeto de tipo Monomio
					(ed::Monomio * nuevo = new ed::Monomio()), el cual se retornará 
					una vez asignado los valores de coeficiente y grado 
		\attention 	Se sobrecarga el operador unario "-"
		\param 		m: objeto de la clase Monomio pasado como referencia constante
		\pre		Ninguna
		\post 		El Monomio devuelto posee el mismo grado que el Monomio "m" pero 
					el coeficiente opuesto, para ello comprobamos que 
					nuevo -> getGrado() == m.getGrado() y 
					nuevo -> getCoeficiente() == -m.getCoeficiente()
		\return 	El valor de retorno es un objeto de tipo Monomio con el mismo
					grado y coeficiente del Monomio "m"
		\sa			ed::Monomio::setCoeficiente(), ed::Monomio::setGrado(), 
					ed::Monomio::getCoeficiente(), ed::Monomio::getGrado(),   
	
	*/
	ed::Monomio & operator-(ed::Monomio const & m);

	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma 

	/*! 
		\brief 		Operado suma +: devuelve un objeto de tipo Monomio cuyo resultado 
					es la suma de los Monomios "m1" y "m2"
		\note 		Se reserva dinamicamente memoria para un objeto de tipo Monomio
					(ed::Monomio * nuevo = new ed::Monomio()), el cual se retornará 
					una vez asignado los valores de coeficiente y grado 
		\attention	Se sobrecarga el operador "+"
		\param 		m1: objeto de la clase Monomio pasado como referencia constante
		\param 		m2: objeto de la clase Monomio pasado como referencia constante
		\pre 		Los monomios "m1" y "m2" deben de poseer el mismo grado (m1.getGrado() == m2.getGrado())
		\post 		El monomio devuelto posee el mismo grado que "m1" y "m2"
		\post 		El monomio devuelto posee como coeficiente la suma de los coeficiente 
					de "m1" y "m2" (nuevo->getCoeficiente == (m1.getCoeficiente() + m2.getCoeficiente()))
		\note 		Para mejorar la precisión a la hora de asignar los coeficientes se ha utilizado 
					la cota de error (COTA_ERROR) mediante la expresion (|valor1 - valor2| < COTA_ERROR)
		\return 	Objeto de tipo Monomio con el resultado de la suma de m1+m2
		\sa			getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/
	 ed::Monomio & operator+(ed::Monomio const &m1, ed::Monomio const &m2);

	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta 
	
	/*! 
		\brief 		Operador resta -: devuelve un objeto de tipo Monomio cuyo resultado 
					es la resta de los Monomios "m1" y "m2"
		\note 		Se reserva dinamicamente memoria para un objeto de tipo Monomio
					(ed::Monomio * nuevo = new ed::Monomio()), el cual se retornará 
					una vez asignado los valores de coeficiente y grado 
		\attention	Se sobrecarga el operador "-"
		\param 		m1: objeto de la clase Monomio pasado como referencia constante
		\param 		m2: objeto de la clase Monomio pasado como referencia constante
		\pre 		Los monomios "m1" y "m2" deben de poseer el mismo grado (m1.getGrado() == m2.getGrado())
		\post 		El monomio devuelto posee el mismo grado que "m1" y "m2"
		\post 		El monomio devuelto posee como coeficiente la resta de los coeficiente 
					de "m1" y "m2" (nuevo->getCoeficiente == (m1.getCoeficiente() - m2.getCoeficiente()))
		\note 		Para mejorar la precisión a la hora de asignar los coeficientes se ha utilizado 
					la cota de error (COTA_ERROR) mediante la expresion (|valor1 - valor2| < COTA_ERROR)
		\return 	Objeto de tipo Monomio con el resultado de la resta de m1-m2
		\sa			getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/
	ed::Monomio & operator-(ed::Monomio const &m1, ed::Monomio const &m2);

	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación 

	/*! 
		\brief 		Operador producto *: devuelve un objeto de tipo Monomio cuyo resultado
					es el producto de los Monomios "m1" y "m2" (m1*m2)
		\note 		Se reserva dinamicamente memoria para un objeto de tipo Monomio
					(ed::Monomio * nuevo = new ed::Monomio()), el cual se retornará 
					una vez asignado los valores de coeficiente y grado 
		\attention	Se sobrecarga el operador "*"
		\param 		m1: objeto de la clase Monomio pasado como referencia constante
		\param 		m2: objeto de la clase Monomio pasado como referencia constante
		\pre 		Ninguna 
		\post		El Monomio devuelto tiene como grado la suma de los grado de "m1" y "m2"
					(nuevo->getGrado() == (m1.getGrado() + m2.getGrado()))
		\post 		El Monomio devuelto tiene como coeficiente el producto de los coeficientes
					de los Monomios "m1" y "m2" 
					(nuevo->getCoeficiente() == (m1.getCoeficiente() * m2.getCoeficiente())) 
		\note 		Para mejorar la precisión a la hora de asignar los coeficientes se ha utilizado 
					la cota de error (COTA_ERROR) mediante la expresion (|valor1 - valor2| < COTA_ERROR)
		\return 	Objeto de tipo Monomio con el resultado del producto de los Monomios "m1" y "m2"
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/
	ed::Monomio & operator*(ed::Monomio const &m1, ed::Monomio const &m2);


	/*! 
		\brief 		Operador producto *: devuelve un objeto de tipo Monomio cuyo valor 
					es el resultado del producto de un Monomio "m" por un número real "x" (m==x)
		\note 		Se reserva dinamicamente memoria para un objeto de tipo Monomio
					(ed::Monomio * nuevo = new ed::Monomio()), el cual se retornará 
					una vez asignado los valores de coeficiente y grado 
		\attention 	Se sobrecarga el operador "*"
		\param 		m: objeto de la clase Monomio pasado como referencia constante
		\param 		x: numero real, pasado como referencia constante
		\pre		Ninguna 
		\post		El Monomio devuelto tiene el mismo grado que el Monomio "m" (nuevo->getGrado() == m.getGrado())
		\post 		El Monomio devuelto posee como coeficiente el producto del coeficiente de "m" por el 
					número real "x" (nuevo->getCoeficiente() == (m.getCoeficiente() * x)) 
		\return 	Objeto de tipo Monomio con el resultado del producto del Monomio "m" por el número real "x"
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/
	ed::Monomio & operator*( ed::Monomio const &m, double x);



	/*! 
		\brief 		Operador producto *: devuelve un objeto de tipo Monomio cuyo valor 
					es el resultado del producto de un número real "x" por un Monomio "m" (x==m)
		\note 		Se reserva dinamicamente memoria para un objeto de tipo Monomio
					(ed::Monomio * nuevo = new ed::Monomio()), el cual se retornará 
					una vez asignado los valores de coeficiente y grado 
		\attention 	Se sobrecarga el operador "*"
		\param 		x: numero real, pasado como referencia constante
		\param 		m: objeto de la clase Monomio pasado como referencia constante
		\pre		Ninguna 
		\post		El Monomio devuelto tiene el mismo grado que el Monomio "m" (nuevo->getGrado() == m.getGrado())
		\post 		El Monomio devuelto posee como coeficiente el producto del coeficiente de "m" por el 
					número real "x" (nuevo->getCoeficiente() == (m.getCoeficiente() * x)) 
		\return 	Objeto de tipo Monomio con el resultado del producto del Monomio "m" por el número real "x"
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/
	ed::Monomio & operator*(double x, ed::Monomio const &m);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división 

	/*! 
		\brief 		Operador producto /: devuelve un objeto de tipo Monomio cuyo resultado
					es la división de los Monomios "m1" y "m2" (m1/m2)
		\note 		Se reserva dinamicamente memoria para un objeto de tipo Monomio
					(ed::Monomio * nuevo = new ed::Monomio()), el cual se retornará 
					una vez asignado los valores de coeficiente y grado 
		\attention	Se sobrecarga el operador "/"
		\param 		m1: objeto de la clase Monomio pasado como referencia constante
		\param 		m2: objeto de la clase Monomio pasado como referencia constante
		\pre 		El grado del Monomio "m1" es mayor o igual que el grado de "m2" (m1.getGrado() >= m2.getGrado())
		\pre 		El coeficiente del Monomio "m2" es distinto de 0.0 (m2.getCoeficiente() != 0.0)
		\post		El Monomio devuelto tiene como grado la resta de los grado de "m1" y "m2"
					(nuevo->getGrado() == (m1.getGrado() + m2.getGrado()))
		\post 		El Monomio devuelto tiene como coeficiente la división de los coeficientes
					de los Monomios "m1" y "m2" 
					(nuevo->getCoeficiente() == (m1.getCoeficiente() / m2.getCoeficiente())) 
		\note 		Para mejorar la precisión a la hora de asignar los coeficientes se ha utilizado 
					la cota de error (COTA_ERROR) mediante la expresion (|valor1 - valor2| < COTA_ERROR)
		\return 	Objeto de tipo Monomio con el resultado de la división de los Monomios "m1" y "m2"
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/
	ed::Monomio & operator/(ed::Monomio const &m1, ed::Monomio const &m2);


	/*! 
		\brief 		Operador division /: devuelve un objeto de tipo Monomio cuyo valor 
					es el resultado de la division de un Monomio "m" por un número real "x" (m/x)
		\note 		Se reserva dinamicamente memoria para un objeto de tipo Monomio
					(ed::Monomio * nuevo = new ed::Monomio()), el cual se retornará 
					una vez asignado los valores de coeficiente y grado
		\attention 	Se sobrecarga el operador "/"
		\param 		m: objeto de la clase Monomio pasado como referencia constante
		\param 		x: numero real, pasado como referencia constante
		\pre		El número "x" es distinto de 0.0 (x	!= 0)
		\post		El Monomio devuelto tiene el mismo grado que el Monomio "m" (nuevo->getGrado() == m.getGrado())
		\post 		El Monomio devuelto posee como coeficiente la división del coeficiente de "m" entre el 
					número real "x" (nuevo->getCoeficiente() == (m.getCoeficiente() / x)) 
		\return 	Objeto de tipo Monomio con el resultado de la division del Monomio "m" por el número real "x"
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/
	ed::Monomio & operator/(ed::Monomio const &m, double x);


	/*! 
		\brief 		Operador division /: devuelve un objeto de tipo Monomio cuyo valor 
					es el resultado de la division de un número real "x" por un Monomio "m" (x/m)
		\note 		Se reserva dinamicamente memoria para un objeto de tipo Monomio
					(ed::Monomio * nuevo = new ed::Monomio()), el cual se retornará 
					una vez asignado los valores de coeficiente y grado
		\attention 	Se sobrecarga el operador "/"
		\param 		x: numero real, pasado como referencia constante
		\param 		m: objeto de la clase Monomio pasado como referencia constante
		\pre		El grado del Monomio es 0 y su coeficiente es distinto de 0.0 ((getGrado() == 0) and (getCoeficiente() != 0.0)) 
		\post		El Monomio devuelto tiene el grado igual a 0 (nuevo->getGrado() == 0)
		\post 		El Monomio devuelto posee como coeficiente la división del  entre el número real "x" 
					coeficiente de "m" (nuevo->getCoeficiente() == (x / m.getCoeficiente())) 
		\return 	Objeto de tipo Monomio con el resultado de la division del Monomio "m" por el número real "x"
		\sa 		getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
	*/
	ed::Monomio & operator/(double x, ed::Monomio const &m);

	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida 

	/*! 
		\brief 		Sobrecarga del operador de flujo de entrada de lectura ">>". 
					Lee el coeficiente y el grado del Monomio separado por un espacio
		\param		stream: flujo de entrada 
		\param 		m: objeto de tipo Monomio pasado como referencia
		\pre 		Ninguna 
		\post		Ninguna
		\sa 		operator<<
	
	*/
	istream &operator>>(istream &stream, ed::Monomio &m);

	/*! 
		\brief 		Sobrecarga del operador de flujo de salida o escritua "<<". 
					Escribe el coeficiente y el grado del Monomio separado por un espacio
		\param		stream: flujo de salida 
		\param 		m: objeto de tipo Monomio pasado como referencia
		\pre 		Ninguna 
		\post		Ninguna
		\sa 		operator>>
	
	*/
	ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_
