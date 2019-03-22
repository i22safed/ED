/*!
   \file  grafica.cpp
	\brief Ficheros con el código para la representación grafica del Monomio
*/


//  Ficheros de cabecera
#include <iostream>
#include <string>
#include "grafica.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed
{

   void getValores(ed::Monomio m,int min, int max){

      std::ofstream salida("./monomio.dat");
      double resultado = 0.0;
      double i = 0.0;

      #ifndef NDEBUG
         assert (m.getGrado() >= 0);  // Grado mayor que 0 
         assert(max > min);      // Pre: El rango superior debe de ser mayor que el inferior
         assert(salida);         // Pre: El fichero debe de estar abierto
      #endif

      for(i=min;i<=max;i++){
         resultado = m.calcularValor(i);
         salida << i << " " << resultado << "\n";
      }

      salida.close();

      #ifndef NDEBUG
         assert(salida);        // Post el fichero debe de estar cerrado
      #endif

      return ;

   }

   void getGrafica(){

      FILE * gnuplotpipe;

      gnuplotpipe = popen("gnuplot -persist","w");

      if(gnuplotpipe){
        fprintf(gnuplotpipe, "set term postscript eps\n");
        fprintf(gnuplotpipe, "set output \"./monomio.eps\" \n");
        fprintf(gnuplotpipe, "plot \"./monomio.dat\" u 1:2 w l \n");
        fprintf(gnuplotpipe, "exit \n");
        pclose(gnuplotpipe);
      }

      return ;
   }



}
