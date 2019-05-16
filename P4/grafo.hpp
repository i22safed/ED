#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>

using namespace std;

namespace ed{

	template <class G_Nodo, class G_Lado>
	class Grafo{
		private:

			G_Lado **_lados;
			G_Nodo *_nodos;

		public:

			// Contructor por defecto 
			Grafo(){};

			//Constructor parametrizado 
			Grafo(const G_Lado) 


			// destructor
			// TODO

			// funciones
			// TODO
			void borrarGrafo() {	// cabecera indicada para que compile

			}

	};
}

#endif
