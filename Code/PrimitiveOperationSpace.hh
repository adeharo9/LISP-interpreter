/** @file PrimitiveOperationSpace.hh
    @brief Especificación de la clase PrimitiveOperationSpace
*/

#ifndef PRIMITIVEOPERATIONSPACE_HH
#define PRIMITIVEOPERATIONSPACE_HH

#ifndef NO_DIAGRAM
#include <map>
#endif

#include "Expression.hh"

using namespace std;

/** @class PrimitiveOperationSpace
    @brief Espacio de almacenamiento de las operaciones primitivas predefinidas
*/

class PrimitiveOperationSpace {

private:

	/* INVARIANTE
		El tamaño del espacio de operaciones primitivas es fijo
		El espacio de operaciones primitivas no puede modificarse
	*/

	typedef void (*primitiveOperation)(Expression&);

	/** @brief Mapa de operaciones primitivas
	
		Atributo que almacena las operaciones primitivas predefinidas con su identificador como clave
	*/
	map<string, primitiveOperation> primOpMap;

	//_______ MÉTODOS PRIVADOS

	/** @brief Operación de suma

		\pre 'exp' = 'EXP'
		\post Si 'EXP' era una lista con dos punteros a dos expresiones enteras, 'exp' pasa a contener el valor de la suma de las dos expresiones enteras; en otro caso, 'exp' pasa a ser indefinido
	*/
	static void sum(Expression& exp);

	/** @brief Operación de negación

		\pre 'exp' = 'EXP'
		\post Si 'EXP' era una lista con un puntero a una expresión entera, 'exp' pasa a contener el valor de la expresión entera cambiado de signo; en otro caso, 'exp' pasa a ser indefinido
	*/
	static void neg(Expression& exp);

	/** @brief Operación de empalme de valor en lista

		\pre 'exp' = 'EXP'
		\post Si 'EXP' era una lista con un puntero a una expresión entera y un puntero a una expresión lista de expresiones enteras, 'exp' pasa a tener una lista con la expresión entera como cabeza de la lista; en otro caso, 'exp' pasa a ser indefinido
	*/
	static void cons(Expression& exp);

	/** @brief Operación de separación de primer valor de lista

		\pre 'exp' = 'EXP'
		\post Si 'EXP' era una lista no vacía de punteros a expresiones enteras, 'exp' pasa a ser el valor apuntado por el primer puntero de la lista; en otro caso, 'exp' pasa a ser indefinido
	*/
	static void head(Expression& exp);

	/** @brief Operación de eliminación de primer elemento de lista

		\pre 'exp' = 'EXP'
		\post Si 'EXP' era una lista no vacía de punteros a enteros, 'exp' pasa a tener la misma lista sin el primer elemento
	*/
	static void tail(Expression& exp);

	/** @brief Operación de comparación de igualdad

		\pre 'exp' = 'EXP'
		\post Si 'EXP' era una lista con dos punteros a dos expresiones evaluables del mismo tipo, 'exp' pasa a tener valor 1 si ambas expresiones eran iguales, y 0 si no lo eran; en otro caso, 'exp' pasa a ser indefinido
	*/
	static void equal(Expression& exp);

	/** @brief Operación de comparación de inferioridad lexicográfica exclusiva

		\pre 'exp' = 'EXP'
		\post Si 'EXP' era una lista con dos punteros a dos expresiones evaluables del mismo tipo, 'exp' pasa a tener valor 1 si la primera expresión era lexicográficamente menor que la segunda, y 0 si no lo era; en otro caso, 'exp' pasa a ser indefinido
	*/
	static void less(Expression& exp);

	/** @brief Operación booleana NOT

		\pre 'exp' = 'EXP'
		\post Si 'EXP' era un booleano, 'exp' pasa a tener el valor de 'exp' negado; en otro caso, 'exp' pasa a ser indefinido
	*/
	static void bool_not(Expression& exp);

	/** @brief Operación booleana AND

		\pre 'exp' = 'EXP'
		\post Si 'EXP' era una lista con dos punteros a dos booleanos, 'exp' pasa a tener valor 1 si ambos valores eran 1, y 0 si no lo eran; en otro caso, 'exp' pasa a ser indefinido
	*/
	static void bool_and(Expression& exp);

	/** @brief Operación booleana OR

		\pre 'exp' = 'EXP'
		\post Si 'EXP' era una lista con dos punteros a dos booleanos, 'exp' pasa a ser 0 si ambos valores eran 0, y 1 si no lo eran; en otro caso, 'exp' pasa a ser indefinido
	*/
	static void bool_or(Expression& exp);

	/** @brief Operación condicional

		\pre 'exp' = 'EXP'
		\post Si 'EXP' era una lista con un valor booleano y una expresión, 'exp' pasa a ser igual a dicha expresión; en otro caso, 'exp' es indefinido
	*/
	static void cond_if(Expression& exp);

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar un nuevo espacio de operaciones primitivas predefinidas
		\pre <em>Cierto</em>
		\post Crea un objeto inicializado con las operaciones primitivas predefinidas
	*/
	PrimitiveOperationSpace();

	//_______ DESTRUCTORES

	/** @brief Destructora por defecto

		Se ejecuta automáticamente al salir de un ámbito de visibilidad
		\pre <em>Cierto</em>
		\post Libera los recursos locales del parámetro implícito al salir  de un ámbito de visibilidad
	*/
	~PrimitiveOperationSpace();

	//_______ CONSULTORES

	/** @brief Consultora de existencia de operación primitiva

    	\pre 'key' es un string no vacío
    	\post Devuelve cierto si la operación primitiva con nombre 'key' existe entre las operaciones primitivas del parámetro implícito; en otro caso, devuelve falso
    */
	bool exists(string key) const;

	/** @brief Consultora de recuperación de operación primitiva

    	\pre 'key' es un string no vacío; el parámetro implícito contiene una operación primitiva con nombre 'key'
    	\post Devuelve la operación primitiva de nombre 'key'
    */
	primitiveOperation get(string key);

};

#endif
