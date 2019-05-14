
## Práctica 1

· Diferencias entre: 

- Tipo const & f (...) const
1.  
2. Se puede trabajar con los atributos de la clase 
pero no se puede modificar

-----------------------------------------------------

gcc -v 5.3.0

this puntero al objeto actual, debe de llevar flecha 

· Fichero de funciones auxiliares
· Para incluir integral o derivada de un monomio


#### P1 aspectos a corregir 

+ El operador de flujo de entrada no debería pedir por pantalla los datos al usuario. Se recuerda que este operador también se puede usar con ficheros.

+ La gráfica que genera podría haber mostrado los datos para valores de X con incrementos de 0.1 o menor.

+ El operador de asignación debe comprobar que el objeto actual no es igual que el objeto que se va a asignar.

+ La función leerMonomio puede ser más amigable indicando que no se puede introducir un grado negativo.

#### P3 

Caso 1. Hoja 
Caso 2. Padre con hijo izquierdo → Sube hijo al lugar de padre 
Caso 3. Padre con hijo derecho → Sube hijo al lugar de padre 
Caso 4. Hijo a izquierdas y derechas → Sube el mayor (si es izquierda) o el menor (si es derecha) del 
                                        subarbol

#### P4

· Solo se toca grafo.hpp y funciones.hpp