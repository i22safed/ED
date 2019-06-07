#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "macros.hpp"

using namespace std;

namespace ed
{

	template <class G_Nodo, class G_Lado>
	class Grafo
	{
	private:

		vector <G_Nodo> nodos_;
		vector <vector <G_Lado> > lados_;

	public:

		// CONSTRUCTORES

		//Constructor que crea un grafo vacío
		Grafo()
		{

		};	

		//Constructor que crea un grafo a partir del tamaño del fichero
		Grafo(int n)
		{

			this->nodos_ = new vector <G_Nodo> [n];//?//
			this->lados_ = new vector <vector <G_Lado> > [n];

			int i;
			for (i=0;i<n;i++){
				this->lados_[i] = new vector <vector <G_Lado> > [n];
			}
			//this->cargarGrafo(rta_nodos_, rutalados_);
		}

		//Constructor de copia que crea un grafo a partir de otro grafo
		Grafo(const Grafo<G_Nodo, G_Lado> &g){
        	this->lados_=g.lados_;
        	this->nodos_=g.nodos_;
        }

    	//DESTRUCTOR
		~Grafo(){
			this->borrarGrafo();
		};


		// FUNCIONES
		
		//Funcion que limpia el grafo//
		void borrarGrafo(){
			this->lados_.clear();
			this->nodos_.clear();
		}

		//Funcion que devuelve los lados del vector//
		vector<vector <G_Lado> > getLados() const{
			return this->lados_;
		}

		//Funcion que devuelve los nodos del vector//
		vector<G_Nodo> getNodos() const{
			return this->nodos_;
		} 


		//Función que asigna un grafo a otro.
		const Grafo & operator=(const Grafo<G_Nodo, G_Lado> &gAux){
        	if (this == &gAux){
            	return *new Grafo<G_Nodo, G_Lado>;
        	}
        
        	this->nodos_=gAux._odos_;
        	this->lados_=gAux.lados_;

       		return *this;
    	}

    	//Funcion que introduce el vector de nodos
    	void setNodos(const vector <G_Nodo> &v){
    		for(unsigned int i=0;i<v.size();i++){
    			this->nodos_.push_back(v[i]);
			}
    	}

		// Funcion que muestra los nodos disponibles 
		void mostrarNodos(){
  			for (unsigned int i = 0; i < this->nodos_.size(); i++){
  					cout << BIWHITE;
    				cout << "    → "<< this->nodos_[i] << std::endl;
					cout << RESET;
  			}
		}

		// Modificador de los lados 
    	void setLados(const vector<G_Lado> &v, const int i){
    		this->lados_.push_back(v);
    	}

		// Muestra la matriz de la clase Grafo.hpp
    	void mostrarMatriz(){

    		cout << std::endl << "  Matriz del grafo \n" << std::endl;
    		for(unsigned int i = 0; i < this->lados_.size(); i++){
    			cout << "\t";
				for(unsigned int j =0; j < this->lados_.size(); j++){
    				cout << BIWHITE;
    				cout << this->lados_[i][j] << "\t";
					cout << RESET;
    			}
    			cout << std::endl;
    		}	
    	}
    	
		// Carga un grafo desde fichero 
		bool cargarGrafo(Grafo <G_Nodo, G_Lado> &g);

	};
}

#endif
