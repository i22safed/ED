#include <iostream>
#include <cstdlib> //para usar srand()

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "macros.hpp"
#include "generarpersona.hpp"

using namespace ed;

int main(){

  ArbolBinarioOrdenadoEnlazado<Persona> a;
  Persona p;
  EscribirNodo<Persona> op;

  int n = 0;  // Numero de personas a generar 

  // Limpia la terminal completamente
  std::cout << BIBLUE;
  std::cout<< "\n Numero de persona a generar → ";
  std::cin >> n;
  std::cout << RESET;

  // Generamos personas 
  for(int i=0; i < n; i++){
    a.insertar(generarDatosPersonales());
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
      std::cout << "3. Borrar persona\n";

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

void mostrar(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a){

  /*
    Hace los distintos recorridos mostrando la info de 
    cada uno de los nodos 
  */
  std::cout << CLEAR_SCREEN;
  EscribirNodo<Persona> op;

  std::cout<<" Mostrar arbol\n\n";
  std::cout<< BIWHITE;
  
  std::cout<<" Recorrido ";
  std::cout<< BICYAN;
  std::cout<<"PreOrden\n\n  ";
  std::cout<< RESET;
  a.recorridoPreOrden(op);
  std::cout<<"\n";

  std::cout<<" Recorrido ";
  std::cout<< BIGREEN;
  std::cout<<"InOrden\n\n  ";
  std::cout<< RESET;
  a.recorridoInOrden(op);
  std::cout<<"\n";

  std::cout<<" Recorrido ";
  std::cout<< BIRED;
  std::cout<<"PostOrden\n\n  ";
  std::cout<< RESET;
  a.recorridoPostOrden(op);
  std::cout<<"\n";

  std::cout<< BIBLUE;
  std::cout<<" Pulse intro para volver al menú.";

  std::cin.get();
  std::cin.ignore();
}

void buscar(ArbolBinarioOrdenadoEnlazado<Persona> &a){

  /*
    La función buscar se encarga de retorna la existencia
    o no del nodo en cuestion 
  */

  Persona p;

  std::cout<< BIWHITE;
  std::cout<<"\n\tBuscar persona \n\n";

  std::cout<<"\tPersona a buscar → \n";
  std::cin>>p;

  if(a.buscar(p)){
    std::cout << BIGREEN;
    std::cout<<"\n\tPersona encontrada\n";
    
    std::cout<< BIBLUE;
    std::cout<<"\n Pulse intro para volver al menú.";
    std::cin.get();
    std::cin.ignore();
  
  }else{
  
    std::cout << BIRED;
    std::cout<<"\n\tPersona no encontrada\n";
    std::cout<< BIBLUE;
    std::cout<<"\n Pulse intro para volver al menú.";
    std::cin.get();
    std::cin.ignore();
  
  }
}

void borrar(ArbolBinarioOrdenadoEnlazado<Persona> &a){

  /*
    Dejamos el puntero apuntando al nodo a borrar, para 
    despues borrarlo. Siendo necesario utilizar la función
    anterior
  */
  EscribirNodo<Persona> op;
  Persona p;

  std::cout<< BIWHITE;
  std::cout<<"\n    Borrar un nodo \n\n";
  std::cout<< RESET;

  std::cout<<"\tDatos personales → \n";
  std::cin>>p;
  std::cout << RESET;

  if (a.buscar(p)){
      
      if (a.borrar()){
        
        std::cout << BIGREEN;
        std::cout<<"\n  Elemento borrado\n\n  ";
        a.recorridoInOrden(op);
        std::cout<< BIBLUE;
        std::cout<<"\n Pulse intro para volver al menú.";
        std::cin.get();
        std::cin.ignore();
        
      }
      else{
      
        std::cout << BIRED;
        std::cout<<"\tError al borrar elemento\n\n  ";
        a.recorridoInOrden(op);
        std::cout<< BIBLUE;
        std::cout<<"\n Pulse intro para volver al menú.";
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

void borrarArbol(ArbolBinarioOrdenadoEnlazado<Persona> &a){
  
  
  EscribirNodo<Persona> op;

  std::cout<< BIRED;
  std::cout<<"\n    Borrar arbol\n\n";
  std::cout<< BIBLUE;
  
  /*
    Borramos el arbol, despues comprobamos si ha sido
    borrado correctamente
  */
  if(!a.estaVacio()){
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
