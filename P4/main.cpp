#include <iostream>
#include <string>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros
#include <vector>
#include "grafo.hpp"
#include "algoritmosgrafos.hpp"
#include "funciones.hpp"

using namespace std;
using namespace ed;


int main()
{
	Grafo <string, int> g;
	int opcion;
	bool grafoIntroducido = false;

	do {
		opcion = menu();
		switch (opcion) {
			case 1: // Cargar grafo desde fichero
				cout << BIBLUE;
  				cout << "  Cargar grafo desde fichero \n\n";
  				cout << RESET;
				if (grafoIntroducido){
					g.borrarGrafo(); // Si hay un grafo introducido se borra.
				}

				grafoIntroducido = cargarGrafo(g);

				if (grafoIntroducido) {
					cout << BIGREEN;
					cout << "\n  Grafo cargado correctamente\n";
				}else{
					cout << BIRED;
					cout << "\n  Error al cargar del fichero\n";
				}
				cout << BIBLUE; 
				cout << "\n  Pulse intro para volver al menu.";
				cout << RESET;
				getchar();
				getchar();
				break;

			case 2: // Matriz de Recorridos
			
				cout << BIBLUE;
				cout << "  Matriz de recorridos \n\n";
				cout << RESET;
				
				if (grafoIntroducido){
					recorridos(g);
					cout << BIBLUE; 
					cout << "\n  Pulse intro para volver al menu.";
					cout << RESET;
				
				}else{

					cout << BIRED; 
					cout << "  No se ha encontrado ningun grafo\n";
					cout << RESET; 
					cout << BIBLUE; 
					cout << "\n  Pulse intro para volver al menu.";
					cout << RESET;
				}
				
				getchar();
				getchar();
				break;

			case 3: // Matriz de Distancias 

				cout << BIBLUE;
				cout << "  Matriz de distancias \n\n";
				cout << RESET;
				
				if (grafoIntroducido){
					distancias(g);
					cout << BIBLUE; 
					cout << "\n  Pulse intro para volver al menu.";
					cout << RESET;
				
				}else{

					cout << BIRED; 
					cout << "  No se ha encontrado ningun grafo\n";
					cout << RESET; 
					cout << BIBLUE; 
					cout << "\n  Pulse intro para volver al menu.";
					cout << RESET;
				}
				
				getchar();
				getchar();
				break;

			
			case 4: // Algoritmo Floyd

				cout << BIBLUE;
				cout << "  Algoritmo Floyd \n\n";
				cout << RESET;
				
				if (grafoIntroducido){
					algoritmoFloyd(g);
					cout << BIBLUE; 
					cout << "\n  Pulse intro para volver al menu.";
					cout << RESET;
				
				}else{

					cout << BIRED; 
					cout << "  No se ha encontrado ningun grafo\n";
					cout << RESET; 
					cout << BIBLUE; 
					cout << "\n  Pulse intro para volver al menu.";
					cout << RESET;
				}
				
				getchar();
				getchar();
				break;

		}
	
	} while (opcion!=0);

	return 0;
}
