#include <iostream>
#include <cstdlib> //para usar srand()

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "macros.hpp"
#include "generarpersona.hpp"

using namespace ed;

void mostrar(ArbolBinarioOrdenadoEnlazado<int> &a);
void buscar(ArbolBinarioOrdenadoEnlazado<int> &a);
void borrar(ArbolBinarioOrdenadoEnlazado<int> &a);
void borrarArbol(ArbolBinarioOrdenadoEnlazado<int> &a);

int main(){

  ArbolBinarioOrdenadoEnlazado<int> a;
  EscribirNodo<int> op;

  int secuencia[] = {10,5,1,9,7,6,8,20,15,25,22,27};

  // Generamos personas 
  for(int i=0; i < 12; i++){
    a.insertar(secuencia[i]);
  }

  int opcion = 0;
  int posicion = 0;

  do{
      // Se muestran las opciones del menú
      posicion=2;

      std::cout << CLEAR_SCREEN;

      PLACE(posicion++,0);
      std::cout << BIBLUE;
      std::cout << " Practica 3. Arboles Binarios Ordenados   ";
      std::cout << RESET;

      posicion++;
      PLACE(posicion++,5);
      std::cout << "1. Imprimir arbol\n";

      PLACE(posicion++,5);
      std::cout << "2. Buscar\n";

      PLACE(posicion++,5);
      std::cout << "3. Borrar nodo\n";

      PLACE(posicion++,5);
      std::cout << "4. Borrar arbol\n";

      posicion++;
      PLACE(posicion++,5);
      std::cout << BIRED;
      std::cout << "0. Salir \n";
      std::cout << RESET;

      posicion++;
      PLACE(posicion++,5);
      std::cout << BIYELLOW;
      std::cout << "Opción →  ";
      std::cin >> opcion;

      switch (opcion){
        case 1:
          mostrar(a);
          break;
        case 2:
          buscar(a);
          break;
        case 3:
          borrar(a);
          break;
        case 4:
          borrarArbol(a);
          break;
      }

  }while(opcion != 0);

  return 0;

}

void mostrar(ed::ArbolBinarioOrdenadoEnlazado<int> &a){

  /*
    Hace los distintos recorridos mostrando la info de 
    cada uno de los nodos 
  */
  std::cout << CLEAR_SCREEN;
  EscribirNodo<int> op;

  std::cout<<" Mostrar arbol\n\n";
  std::cout<< BIWHITE;
  
  std::cout<<"\n Recorrido ";
  std::cout<< BICYAN;
  std::cout<<"PreOrden\n\n  ";
  std::cout<< RESET;
  a.recorridoPreOrden(op);
  std::cout<<"\n";

  std::cout<<"\n Recorrido ";
  std::cout<< BIGREEN;
  std::cout<<"InOrden\n\n  ";
  std::cout<< RESET;
  a.recorridoInOrden(op);
  std::cout<<"\n";

  std::cout<<"\n Recorrido ";
  std::cout<< BIRED;
  std::cout<<"PostOrden\n\n  ";
  std::cout<< RESET;
  a.recorridoPostOrden(op);
  std::cout<<"\n";

  std::cout<< BIBLUE;
  std::cout<<"\n Pulse intro para volver al menú.";

  std::cin.get();
  std::cin.ignore();
}

void buscar(ArbolBinarioOrdenadoEnlazado<int> &a){

  /*
    La función buscar se encarga de retorna la existencia
    o no del nodo en cuestion 
  */

  int p;

  std::cout<< BIWHITE;
  std::cout<<"\n\tBuscar numero \n\n";

  std::cout<<"\tNumero a buscar → ";
  std::cin>>p;

  if(a.buscar(p)){
    std::cout << BIGREEN;
    std::cout<<"\n\tNumero encontrado\n";
    
    std::cout<< BIBLUE;
    std::cout<<"\n Pulse intro para volver al menú.";
    std::cin.get();
    std::cin.ignore();
  
  }else{
  
    std::cout << BIRED;
    std::cout<<"\n\tNumero no encontrado\n";
    std::cout<< BIBLUE;
    std::cout<<"\n Pulse intro para volver al menú.";
    std::cin.get();
    std::cin.ignore();
  
  }
}

void borrar(ArbolBinarioOrdenadoEnlazado<int> &a){

  /*
    Dejamos el puntero apuntando al nodo a borrar, para 
    despues borrarlo. Siendo necesario utilizar la función
    anterior
  */
  EscribirNodo<int> op;
  int p;

  std::cout<< BIWHITE;
  std::cout<<"\n    Borrar un nodo \n\n";
  std::cout<< RESET;

  std::cout<<"\tNumero → ";
  std::cin>>p;
  std::cout << RESET;

  if (a.buscar(p)){
      
      if (a.borrar()){
        
        std::cout << BIGREEN;
        std::cout<<"\n  Elemento borrado\n\n  ";
        a.recorridoInOrden(op);
        std::cout<< BIBLUE;
        std::cout<<"\n\n Pulse intro para volver al menú.";
        std::cin.get();
        std::cin.ignore();
        
      }
      else{
      
        std::cout << BIRED;
        std::cout<<"\tError al borrar elemento\n\n  ";
        a.recorridoInOrden(op);
        std::cout<< BIBLUE;
        std::cout<<"\n\n Pulse intro para volver al menú.";
        std::cin.get();
        std::cin.ignore();
      
      }
  }
  else{
      
      std::cout << BIRED;
      std::cout<<"\tElemento no encontrado\n\n  ";
      std::cout<< BIBLUE;
      std::cout<<"\n Pulse intro para volver al menú.";
      std::cin.get();
      std::cin.ignore();
  
  }

}

void borrarArbol(ArbolBinarioOrdenadoEnlazado<int> &a){
  
  
  EscribirNodo<int> op;

  std::cout<< BIRED;
  std::cout<<"\n    Borrar arbol\n\n";
  std::cout<< BIBLUE;
  
  /*
    Borramos el arbol, despues comprobamos si ha sido
    borrado correctamente
  */
  if (!a.estaVacio()){
    a.borrarArbol();
  }
  
  if (a.estaVacio()){
    std::cout << BIGREEN;
    std::cout<<"    Arbol borrado correctamente"<<std::endl;
    std::cout << RESET;
    std::cout<< BIBLUE;
    std::cout<<"\n Pulse intro para volver al menú.";
    std::cin.get();
    std::cin.ignore();
  
  }else{

    std::cout << BIRED;
    std::cout<<"    Error al borrar el arbol"<<std::endl;

    std::cout << BICYAN;
    a.recorridoInOrden(op);

    std::cout<< BIBLUE;
    std::cout<<"\n Pulse intro para volver al menú.";
    std::cin.get();
    std::cin.ignore();

  }

}
