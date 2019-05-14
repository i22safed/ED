#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__

#include <iostream>
#include <cassert>
#include "arbolbinarioordenado.hpp"
#include "operadornodo.hpp"
#include "macros.hpp"

using namespace std;
/*!
\brief Espacio de nombres para la asignatura Estructura de datos.
*/
namespace ed{

	/*!\brief Interfaz para definir un ArbolBinario ordenado.

	Define una interfaz para definir un ArbolBinarioOrdenado.

	\arg G define el campo de información a contener en el arbol.
	\pre G debe tener definidos los operadores < y ==.
	*/
	template<class G>
	class ArbolBinarioOrdenadoEnlazado:public ArbolBinarioOrdenado<G>{

	private:

		/*!\brief Define un nodo del arbol binario.*/
		class NodoArbolBinario{

			private:
				
				G _info;  //Valor informativo almacenado en el nodo
				NodoArbolBinario * _izquierdo;  //Puntero al hijo izquierdo
				NodoArbolBinario * _derecho;  //Puntero al hijo derecho

			public:
				
				NodoArbolBinario (const G &info){
					
					this->setInfo(info);
					_izquierdo = NULL; 
					_derecho = NULL; 

					// Se podría incluir el método esHoja()
					#ifndef NDEBUG 
						assert(this->esHoja());
					#endif 
				}

				NodoArbolBinario (const NodoArbolBinario &n){
					
					this->setInfo(n.getInfo());
					this->setIzquierdo(n.getIzquierdo());
					this->setDerecho(n.getIzquierdo());
					
					#ifndef NDEBUG // Cambiar por el operador == 
						assert((this->getInfo() == n.getInfo()) and 
									(this->getIzquierdo() == n.getIzquierdo()) and 
									(this->getDerecho() == n.getDerecho()));
					#endif  

				}

				/*!\brief Observadores.*/
				const G & getInfo() const{
					return _info;
				}

				NodoArbolBinario * getIzquierdo() const{
					return _izquierdo;
				}

				NodoArbolBinario * getDerecho() const{
					return _derecho; 
				}

				bool esHoja() const{
					
					//Comprueba que el nodo no tenga hijos
					// hijo izquierdo y derecho == NULL

					bool valorDevuelto = true; 
					
					if((this->getIzquierdo() != NULL) || (this->getDerecho()!=NULL)){
						valorDevuelto = false;
					}
					
					return valorDevuelto;
				}

				void recorridoPreOrden (OperadorNodo<G> &operador) const{

					// RAIZ → SA derecho → SA Izquierdo 
					
					operador.aplicar(this->getInfo());

					if(this->getIzquierdo() != NULL){
						this->getIzquierdo()->recorridoPreOrden(operador);
					}
					
					if(this->getDerecho() != NULL){
						this->getDerecho()->recorridoPreOrden(operador);
					}

				}

				void recorridoPostOrden (OperadorNodo<G> &operador) const{

					// SA Izquierdo → SA derecho → RAIZ 
					 
					if(this->getIzquierdo() != NULL){
						this->getIzquierdo()->recorridoPostOrden(operador);
					}
					
					if(this->getDerecho() != NULL){
						this->getDerecho()->recorridoPostOrden(operador);
					}

					operador.aplicar(this->getInfo());
				
				}

				void recorridoInOrden (OperadorNodo<G> &operador) const{
					
					// SA Izquierdo → RAIZ → SA derecho	

					if(this->getIzquierdo() != NULL){
						this->getIzquierdo()->recorridoInOrden(operador);
					}
					
					operador.aplicar(this->getInfo());

					if(this->getDerecho() != NULL){
						this->getDerecho()->recorridoInOrden(operador);
					}
				}

				/*!\brief Modificadores. */
				void setInfo(const G &info){
					this->_info = info;
				}

				void setIzquierdo(NodoArbolBinario * n){
					this->_izquierdo = n; 
				}

				void setDerecho(NodoArbolBinario * n){
					this->_derecho = n;
				}

				NodoArbolBinario & operator=(const NodoArbolBinario &n){

					// El nodo a copiar debe de ser diferente al actual
					#ifndef NDEBUG 
						assert((this->getInfo() != n.getInfo()) and 
								(this->getIzquierdo() != n.getIzquierdo()) and	
								(this->getDerecho() != n.getDerecho()));
					#endif
					
					this->setInfo(n.getInfo());
					this->setIzquierdo(n.getIzquierdo());
					this->setDerecho(n.getDerecho()); 
				
					// El nodo a copiar y el actual deben ser iguales
					// despues de la copia
					#ifndef NDEBUG 
						assert((this->getInfo() == n.getInfo()) and 
								(this->getIzquierdo() == n.getIzquierdo()) and	
								(this->getDerecho() == n.getDerecho()));
					#endif

					return this;

				}

		}; //Fin clase NodoArbolBinario

		//Implementación de la raíz
		NodoArbolBinario * _raiz; /*!<La raiz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo actual*/

	public:

		// Constructor sin parametros
		ArbolBinarioOrdenadoEnlazado (){
			
			_raiz = NULL; 			

			#ifndef NDEBUG 
				assert(this->estaVacio());
			#endif 
		}

		// Constructor de copia
		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a){
			*this = a; 
		}

		// Destructor
		~ArbolBinarioOrdenadoEnlazado (){
			if (not estaVacio())
			borrarArbol();
			cout<< BIBLUE;
			cout << "\n    Destructor Usado \n\n";
		}

		// Operador de asignación
		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& a){
			
			this->_raiz = a._raiz;
			this->_padre = a._padre;
			this->_actual = a._actual;

		}

		// Metodo para insertar en orden un nodo en el arbol
		bool insertar(const G &x){
			
			/*
				Variable de retorno para comprobar que se 
				ha insertado correctamente el nodo en el arbol
			*/
			bool insertado = false; 

			/*
				Si el arbol está vacío el nuevo nodo 
				pasará a ser la raíz y en caso contrario 
				recorrerá el arbol buscando la posición 
				correcta
			*/
			if(this->estaVacio()){
				_raiz = new NodoArbolBinario(x); 
				insertado = true; 
			}else{
				_padre = NULL; 
				_actual = _raiz; 
			}
			
			/*
				Se recorre buscanso la posición hasta que 
				insertado == true
			*/
			while(!insertado){
				
				/*
					Comprobamos si el nodo a inserar es mayor
					o menor que el actual para decidir el 
					próximo movimiento para buscar la posición
					donde insertarlo
				*/
				if(x > this->actual()){
				
					if(_actual->getDerecho() != NULL){
						_padre = _actual; 
						_actual = _actual->getDerecho(); 
					}else{
						_actual->setDerecho(new NodoArbolBinario(x));
						insertado = true;	// Posicion encontrada 
											// insertado == true
											// y fin del bucle
										
					}
				
				}else{
					
					if(_actual->getIzquierdo() != NULL){
						_padre = _actual; 
						_actual = _actual->getIzquierdo();
					}else{
						_actual->setIzquierdo(new NodoArbolBinario(x));
						insertado = true;	// Posicion encontrada 
											// insertado == true
											// y fin del bucle
					}
				}
			} 
			
			return insertado;
		}

		bool borrar(){
			
			#ifndef NDEBUG 
				assert(!this->estaVacio());
			#endif 

			bool deleted = false; 	// Variable de retorno 
									// para verificar el borrado

			/*
				Punteros auxiliares a los nodos padre y actual 
				necesarios para el borrado
			*/
			NodoArbolBinario * aux_padre; 
			NodoArbolBinario * aux_actual;
			
			aux_padre = _padre;
			aux_actual = _actual; 
			
			/*
				Se sustituye el nodo por el menor de sus mayores
				o el mayor de sus menores, desplazando uno a 
				la derecha y el resto a la izquierda 
			*/

			if(_actual->getDerecho() != NULL){
				
				_padre = _actual;
				_actual = _actual->getDerecho();

				while(_actual->getIzquierdo() != NULL){
					_padre = _actual;
					_actual = _actual->getIzquierdo();
				}

				/*
					Una vez llegados hasta el nodo a borrar 
					se intercambian los punteros para mantener
					la información 
				*/

				if(_actual->getInfo() < _padre->getInfo()){

					_padre->setIzquierdo(_actual->getDerecho());
				
				}else{
				
					aux_actual->setDerecho(_actual->getDerecho());
				
				}
				
				aux_actual->setInfo(_actual->getInfo());
				deleted = true;

				_actual = aux_actual;
				_padre = aux_padre;
			
			// Para el caso contrario, desplazar a la izquierda 
			// y el resto a la derecha ↓ 
			}else if (_actual->getIzquierdo() != NULL){
				
				_padre = _actual;
				_actual = _actual->getIzquierdo();

				while(_actual->getDerecho() != NULL){
					
					_padre = _actual;
					_actual = _actual->getDerecho();
				
				}

				if(_actual->getInfo() > _padre->getInfo()){
					
					_padre->setDerecho(_actual->getIzquierdo());
				
				}else{

					aux_actual->setIzquierdo(_actual->getIzquierdo());
				}
				
				aux_actual->setInfo(_actual->getInfo());
				deleted = true;

				_actual = aux_actual;
				_padre = aux_padre;

			}else{	// Para borrar la raiz/hoja

				if (_raiz == _actual){
					
					this->borrarArbol();
				
				}else if(_actual->getInfo() < _padre->getInfo()){
					
					_padre->setIzquierdo(NULL);

				}else{

					_padre->setDerecho(NULL);
				
				}
				
				deleted = true;
			}
			
			return deleted;
		
		}

		void borrarArbol(){

			#ifndef NDEBUG
				assert(! this->estaVacio());
			#endif

			_raiz = NULL;
			_actual = NULL;
			_padre = NULL;

			#ifndef NDEBUG
				assert(this->estaVacio());
			#endif
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const{
			_raiz->recorridoPreOrden(operador);
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const{
			_raiz->recorridoPostOrden(operador);
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const{
			_raiz->recorridoInOrden(operador);
		}

		bool buscar(const G& x) {

			/*
				Realiza el recorrido del arbol hasta que encuentra
				al nodo objetivo, en este momento match = true. 
				
				Siendo match el valor de retorno de la función
			*/

			bool match = false; 
			_padre = NULL; 
			_actual = _raiz; 


			/*
				Buscará por la izquierda o derecha en función 
				del valor de info
			*/
			while((_actual!=NULL)&&(!match)){
				if(_actual->getInfo() > x){
					if(_actual->getIzquierdo()!=NULL){
						_padre = _actual; 
						_actual = _actual->getIzquierdo();
					}else{
						_actual = NULL; 
					}
				}else if(_actual->getInfo() < x){
					if(_actual->getDerecho()!=NULL){
						_padre = _actual; 
						_actual = _actual->getDerecho();
					}else{
						_actual = NULL; 
					}

				}else{
					match = true; 
				}
			}

			if(_actual == NULL){
				_padre = NULL; 
				_actual = _raiz;
			}

			return match;
		}

		bool estaVacio() const{
			
			if (_raiz == NULL){
				return true;
			}
			return false;

		}

		G raiz() const{
			
			#ifndef NDEBUG 
				assert(!this->estaVacio());
			#endif 

			return _raiz; 
		}

		bool existeActual() const{
			
			#ifndef NDEBUG
				assert(!this->estaVacio());
			#endif 

			bool valorDevuelto = true; 

			if(_actual == NULL){
				valorDevuelto = false; 
			}

			return valorDevuelto;
		}

		G actual() const{
			
			#ifndef NDEBUG 
				assert(this->existeActual());
			#endif 

			return _actual->getInfo();
		}

		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
