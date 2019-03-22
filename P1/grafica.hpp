
/*!
	\file grafica.hpp
	\brief Ficheros con los prototipos de los métodos necesarios para la representación del Monomio
*/

#ifndef _GRAFICA_HPP_
#define _GRAFICA_HPP_

// Facilita la entrada y salida
#include <iostream>
#include "Monomio.hpp"
#include <fstream>

namespace ed
{
//! \name Metodos externos para representación gráfica de un Monomio

	/*!
		\brief 		Obtiene el valor de un monomio para un rango de valores de x
		\param 		m: objeto de la clase Monomio
		\param 		min: entero que indica el valor minimo del rango
		\param 		max: entero que indica el valor superior del rango
		\pre 			El grado del Monomio debe de ser mayor que 0 
		\pre 			El valor minimo del rango no puede superar el valor máximo del rango
		\pre 			El fichero donde se van a volcar los datos debe estar abierto en modo
							escritua
		\post 		El fichero resultante debe de estar cerrado despues de la operación
							de escritura

	*/
	void getValores(ed::Monomio m,int min, int max);

	/*!
		\brief 		Obtiene mediante gnuplot la grafica del polinomio gracias a los puntos
							obtenidos en la funcion getValores()
		\pre 			El fichero Monomio.dat debe existir antes de realizar la función plot
		\post			Se deberá de haber generado el fichero resultado del plot Monomio.eps
	*/
	void getGrafica();

}  // Fin de namespace ed.

#endif // _GRAFICA_HPP_
