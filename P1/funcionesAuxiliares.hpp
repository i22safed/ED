/*!
  \file   	funcionesAuxiliares.hpp
  \brief  	Funciones auxiliares para el programa principal de la práctica 1
  \author 	David Sánchez Fernández
  \date  	23-02-2019
*/


#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

namespace ed
{
	/*!
		\brief   Muestra el menú del programa principal
		\return  Devuelve el número de opción elegido
	*/
	int menu();

	/*!
		\brief 	Realiza un test de todos los métodos de la clase Monomio.
		\sa		ed::Monomio::Monomio(),
				ed::Monomio::getCoeficiente(),
				ed::Monomio::getGrado(),
				ed::Monomio::setCoeficiente(),
				ed::Monomio::setGrado(),
				operator=, operator+=, operator-=, operator*=,
				operator/=, leerMonomio(), escribirMonomio()

	*/
	void testMonomio();

	/*!
		\brief 	Realiza un test de todos los métodos externos a la clase Monomio
		\sa		operator==, operator!=, operator+, operator-, operator*, operator/,
				operator>>, operator<<
	*/
	void operadoresExternosMonomios();


	/*!
		\brief 	Obtiene la grafica de un monomio
		\sa 		getValores(), getGrafica()
	*/
	void representacionGrafica();

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif
