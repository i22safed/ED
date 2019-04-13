#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__

#include <iostream>
#include <cassert>
#include "arbolbinarioordenado.hpp"
#include "operadornodo.hpp"

using namespace std;
/*!
\brief Espacio de nombres para la asignatura Estructura de datos.
*/
namespace ed
{
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
				setInfo(info);
				setIzquierdo(NULL);
				setDerecho(NULL);

				#ifndef NDEBUG 
					assert((getIzquierdo() == NULL) || (getDerecho() == NULL));
				#endif 
			}

			NodoArbolBinario (const NodoArbolBinario &n){
				
				setInfo(n.getInfo());
				setIzquierdo(n.getIzquierdo());
				setDerecho(n.getIzquierdo());
				
				#ifndef NDEBUG // Cambiar por el operador == 
					assert((getInfo() == n.getInfo()) and 
								(getIzquierdo() == n.getIzquierdo()) and 
								(getDerecho() == n.getDerecho()));
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
				
				bool valorDevuelto = false; 
				
				if((getIzquierdo() != NULL) || (getDerecho()!=NULL)){
					valorDevuelto = true;
				}
				
				return valorDevuelto;
			}

			void recorridoPreOrden (OperadorNodo<G> &operador) const{
				
			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const{
				// TODO
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const{
				// TODO
			}

			/*!\brief Modificadores. */
			void setInfo(const G &info){
				_info = info;
			}

			void setIzquierdo(NodoArbolBinario *n){
				_izquierdo = n.getIzquierdo(); 
			}

			void setDerecho(NodoArbolBinario *n){
				_derecho = n.getDerecho();
			}

			NodoArbolBinario & operator=(const NodoArbolBinario &n){
				
				NodoArbolBinario * nodo = new NodoArbolBinario();

				setInfo(n.getInfo());
				setIzquierdo(n.getIzquierdo());
				setDerecho(n.getDerecho());
			
				return * nodo;

			}

		}; //Fin clase NodoArbolBinario

		//Implementación de la raíz
		NodoArbolBinario * _raiz; /*!<La raiz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo actual*/

	public:

		ArbolBinarioOrdenadoEnlazado (){
			// TODO
		}

		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a){
			// TODO
		}

		~ArbolBinarioOrdenadoEnlazado (){
			if (not estaVacio())
			borrarArbol();
			cout << "Destructor Usado \n";
		}

		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& a){
			// TODO
		}

		bool insertar(const G &x){
			// TODO
			return false;
		}

		void borrarArbol(){
			// TODO
		}

		bool borrar(){
			// TODO
			return false;
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const{
			// TODO
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const{
			// TODO
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const{
			// TODO
		}

		bool buscar(const G& x) const{
			// TODO
			return false;
		}

		bool estaVacio() const{
			// TODO
			return false;
		}

		G raiz() const{
			// TODO
		}

		bool existeActual() const{
			// TODO
			return false;
		}

		G actual() const{
			// TODO
		}

		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
