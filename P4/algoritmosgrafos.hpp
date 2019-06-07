#ifndef __ALGORITMOSGRAFOS_H__
#define __ALGORITMOSGRAFOS_H__
#include <iostream>

#include "grafo.hpp"
using namespace ed;
using namespace std;

template <class G_Nodo, class G_Lado>
class AlgoritmosGrafos{

  public:

    AlgoritmosGrafos(){} // Constructor de la clase AlgoritmosGrafos 
    
    // Realizamos la matriz de distancias 
    vector<vector<G_Lado> > matrizDistancias(const Grafo<G_Nodo,G_Lado> &g){

        std::vector<std::vector<G_Lado> > matriz = g.getLados();
        
        // Ponemos la diagonal a 0 
        for (unsigned int d = 0; d < matriz.size(); ++d) {
            matriz[d][d] = 0;
        }
        // floyd algorithm
        for (unsigned int k = 0; k < matriz.size(); k++) {
            for (unsigned int i = 0; i < matriz.size(); i++) {
                for (unsigned int j = 0; j < matriz.size(); j++) {
                    // Evaluamos filas y columnas para hallar las distancias 
                    if (matriz[i][k] + matriz[k][j] < matriz[i][j]){
                        matriz[i][j] = matriz[i][k] + matriz[k][j];
                    }
                }
            }
        }

        return matriz; 

    }

    vector<vector<G_Lado> > matrizRecorridos(const Grafo<G_Nodo,G_Lado> &g){

      std::vector<std::vector<G_Lado> > matriz = g.getLados();

      // Ponemos la diagonal a 0 
      for (unsigned int d = 0; d < matriz.size(); d++) {
          matriz[d][d] = 0;
      }

      // Creamos la matriz de intermedios 
      std::vector<std::vector<G_Lado> > matrizIntermedios;
      matrizIntermedios.resize(matriz.size());
      for (unsigned int i = 0; i < matriz.size(); i++) {
          matrizIntermedios[i].resize(matriz.size());
      }

      for (unsigned int i = 0; i < matrizIntermedios.size(); i++) {
        for (unsigned int j = 0; j < matrizIntermedios[i].size(); ++j) {
          matrizIntermedios[i][j] = -1;
        }
      }

      for (unsigned int k = 0; k < matriz.size(); ++k) {
          for (unsigned int i = 0; i < matriz.size(); i++) {
              for (unsigned int j = 0; j < matriz.size(); ++j) {
                  if (matriz[i][k] + matriz[k][j] < matriz[i][j]){
                      // Evaluamos las filas y columnas de la matriz de 
                      // recorridos en funcion de la matriz de distancias
                      matriz[i][j] = matriz[i][k] + matriz[k][j];
                      matrizIntermedios[i][j] = k;
                  }
              }
          }
      }
    
      return matrizIntermedios;
    
    }


    /*
      Función para mostrar tanto la matriz de distancias como la de recorridos 
      además de las etiquetas pertenecientes a las filas y columnas 
    */
    void mostrarMatriz(const vector < vector <G_Lado> > &matrizD, vector<G_Nodo> &vectorN){
        
        for(unsigned int i=0;i<matrizD.size()+1;i++){
          for(unsigned int j=0;j<matrizD.size()+1;j++){
            
            if(i==0 and j==0){    // Etiqueta para la posicion [0][0] 
              cout << BIYELLOW; 
              cout << "\tEtiquetas";
              cout << RESET; 
            }
            if(i==0 and j!=0){    // Etiquetas para la fila  
              cout << BIBLUE; 
              cout << "\t" << vectorN[j-1];
            }
            if(i!=0 and j==0){    // Etiquetas para la columna 
              cout << BIGREEN; 
              cout << "\t" << vectorN[i-1] << "\t";
              cout << RESET;
            }
            if(i!=0 and j!=0){    // Valores de la tabla 
              cout << BIWHITE;
              cout << "\t" << matrizD[i-1][j-1]; 
              cout << RESET; 
            }

          }
          cout << endl; 
        }

    }    

    /*
      Retorna el indice de un nodo pasado como argumento
    */
    int getIndiceNodo(const Grafo<G_Nodo, G_Lado> &g,G_Nodo n)const{ 
        for (unsigned int i = 0; i < g.getNodos().size(); i++) {
            if (n == g.getNodos()[i])
                return i;
        }
        return -1;
    }

    /*
      Operación inversa a la anterior, retorna el indice perteneciente 
      al nodo pasado como argumento
    */
    G_Nodo getNodoDeIndice(const Grafo<G_Nodo, G_Lado> &g,unsigned int indice)const{
        if ( indice >= g.getNodos().size()){
          return * new G_Nodo;
        }
            

        return g.getNodos()[indice];
    }


    /*
      Funcion que comprueba si existe un nodo en la lista
    */
    bool existeNodo(G_Nodo nodo,const Grafo<G_Nodo, G_Lado> &g)const{
    		for(unsigned int i=0; i< g.getNodos().size(); i++){
    			if(nodo == g.getNodos()[i]){
    				return true;
    			}
    		}
    		return false;
    }

    /*
      Funcion que retorna la distancia entre un origen y un destino
    */
    int getDistancia(const Grafo<G_Nodo, G_Lado> &g, string origen, string destino){

      int indiceOrigen = getIndiceNodo(g,origen); 
      int indiceDestino = getIndiceNodo(g,destino); 

      vector<vector<G_Lado> > distancias = matrizDistancias(g);

      return distancias[indiceOrigen][indiceDestino];

    }

    /*
      Algoritmo de Floyd, el cual retorna un vector de nodos con la secuencia 
      de nodos a seguir desde un origen a un destino
    */
    vector <G_Nodo> floyd(const Grafo<G_Nodo, G_Lado> &g, string origen, string destino){
      
        vector <G_Nodo> camino;

        vector<vector<G_Lado> > matriz = matrizRecorridos(g);
        vector<G_Lado> filaOrigen = matriz[getIndiceNodo(g,origen)];

        bool match = false; 
        int indice = getIndiceNodo(g,destino);

        camino.push_back(destino); 

        while(!match){
          if(filaOrigen[indice] == -1){
            match = true; 
            camino.push_back(origen);
          }else{
            indice = filaOrigen[indice]; 
            camino.push_back(getNodoDeIndice(g,indice));
          }
        }

        // Mostramos la distancia entre el origen y el destino
        cout << BIWHITE << "\n    → Distancia entre nodos: " << 
                RESET << getDistancia(g,origen,destino) << " Kms"; 

        return camino; 

    }

};

#endif



