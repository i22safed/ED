#ifndef __FUNCIONES_HPP
#define __FUNCIONES_HPP

#include <iostream>
#include <string>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros
#include <vector>
#include "grafo.hpp"
#include "algoritmosgrafos.hpp"
#include "macros.hpp"

using namespace std;
using namespace ed;

int menu(){
    
      int posicion = 0;
      int opcion;
      

      system("clear");
      
      PLACE(posicion++,0);
      cout << BIBLUE;
      cout << " Practica 4 - Grafos.Caminos y Distancias minimas\n\n" ;
      cout << RESET;
      
      cout << "  1. Cargar grafo desde fichero \n";
      cout << "  2. Matriz de Recorridos\n";
      cout << "  3. Matriz de Distancias \n";
      cout << "  4. Algoritmo de Floyd (GD y GND)\n";
      
      cout << BIRED;
      cout << "  0. Salir \n";
      cout << RESET;

      cout << "\nIntroduzca opcion → ";
      cin >> opcion;
      system ("clear");

      return opcion;
  }

  template <class G_Nodo, class G_Lado>
  bool cargarGrafo(Grafo <G_Nodo, G_Lado> &g){

      cout << "    → Se cargará el fichero de matriz: "; 
      cout << BIGREEN;
      cout << "Andalucia.txt\n";
      cout << RESET; 

      cout << "\n    → Se cargará el fichero de etiquetas: "; 
      cout << BIBLUE; 
      cout << "matrizAndalucia.txt\n\n";
      cout << RESET; 

      string ficheroMatriz = "matrizAndalucia.txt";
      string ficheroEtiquetas = "Andalucia.txt";

      // Apertura de fichero en modo lectura 
      // c_str() convierte las cadenas al formato C
      ifstream fMatriz(ficheroMatriz.c_str());
      ifstream fEtiquetas(ficheroEtiquetas.c_str());


      if (!fMatriz.is_open()){
          std::cout << "  El fichero de Matrices no está operativo" << std::endl;
          return false;
      }
      if (!fEtiquetas.is_open()){
          std::cout << "  El fichero de Nodos no está operativo" << std::endl;
          return false;
      }
      
      //Cargamos nodos//
      string buffer;
      vector <G_Nodo> aux;
      int contador = 0;

      //Lectura de los nodos 
      while(getline(fEtiquetas,buffer) && contador < 9){
        contador ++;
        aux.push_back(buffer.substr(0,buffer.size()-1));
      }
     
      //Pasamos los datos al grafo
      g.setNodos(aux);
      cout << "  Nodos cargados \n\n";
      g.mostrarNodos();
    

      //Cargamos lados  
      vector<G_Lado> fila;
      G_Lado x;
      contador = 0;

      while(getline(fMatriz, buffer) && contador<9){

        fila.clear();                                                
        while(buffer.find(' ')!=string::npos){                          // Mientras el caracter espacio no sea el final de la línea

          x = atoi(buffer.substr(0,buffer.find(' ')).c_str());          // Guardamos en x

          buffer = buffer.substr(buffer.find(' ')+1, buffer.size());    
          fila.push_back(x);                                            // Volcamos en el vector
        }
        
        x = atoi(buffer.substr(0, buffer.find('\n')).c_str());
        fila.push_back(x);
        g.setLados(fila, contador);     // Insertamos en la matriz del grafo 
        contador++;
      }
      g.mostrarMatriz();

      fEtiquetas.close();
      fMatriz.close();

      return true;
}

template <class G_Nodo, class G_Lado>
void recorridos( Grafo<G_Nodo, G_Lado> &g){

    vector <vector <G_Lado> > matrizR;  // Matriz de Recorridos 
    vector <G_Nodo> vectorN;            // Vector de Nodos 
    AlgoritmosGrafos<G_Nodo, G_Lado> a; // Objeto para realizar la matriz de Recorridos
    vectorN = g.getNodos();             // Obtenemos los nodos para despues ponerlos como etiqueta
    matrizR = a.matrizRecorridos(g);    // Obtenemos la matriz de Recorridos
    a.mostrarMatriz(matrizR,vectorN);   // Mostramos el resultado 

}

template <class G_Nodo, class G_Lado>
void distancias( Grafo<G_Nodo, G_Lado> &g){

    vector <vector <G_Lado> > matrizD;  // Matriz de Distancias
    vector <G_Nodo> vectorN;            // Vector de Nodos
    AlgoritmosGrafos<G_Nodo, G_Lado> a; // Objeto para realizar la matriz de Distancias 
    vectorN = g.getNodos();             // Obtenemos los nodos para despues ponerlos de etiqueta
    matrizD = a.matrizDistancias(g);    // Obtenemos la matriz de distancias 
    a.mostrarMatriz(matrizD,vectorN);   // Mostramos el resultado 
    

}


template <class G_Nodo, class G_Lado>
void algoritmoFloyd( Grafo<G_Nodo, G_Lado> &g){

    string origen = ""; 
    string destino = "";
    vector <G_Nodo> secuencia; 
    AlgoritmosGrafos<G_Nodo, G_Lado> a;

    // Mostramos los distintos nodos que hay 
    cout << "  Nodos disponibles: \n\n";
    g.mostrarNodos();   


    // Pedimos los nodos al usuario
    do {
        cout << "\n  Introduzca el origen → ";
        cin >> origen;

        // Comprobamos que exista el nodo
        if(!a.existeNodo(origen,g)){
            cout << BIRED;
            cout << "  \nOrigen no válido" << endl;
            cout << RESET; 
        }
    
    }while (!a.existeNodo(origen,g));

    // Se podria introducir que no se introdujera el mismo nodo como 
    // Origen y Destino, ya que la distancia es 0. No obstante se ha 
    // contemplado de que en el caso de que Origen y Destino sea el 
    // mismo nodo se devuelva la distancia de 0. 

    do {
    
        cout << "\n  Introduzca el destino → ";
        cin >> destino; 
        
        if(!a.existeNodo(destino,g)){
            cout << BIRED;
            cout << "\n  Destino no válido" << endl ;
            cout << RESET; 
        }
        
    }while (!a.existeNodo(destino,g));

    // Hallamos la secuencia de nodos de Origen a Destino
    secuencia = a.floyd(g,origen,destino);
    
    cout << "\n\n  La secuencia de nodos a seguir : \n\n    "; 

    // Mostramos la secuencia de nodos
    for(unsigned int i=secuencia.size()-1;i>0;i--){
        cout << BIWHITE << secuencia[i] << RESET << BIYELLOW << " → " << RESET ; 

    }
    cout << BIWHITE << secuencia[0] << RESET; 
    cout << "\n";

}

#endif
