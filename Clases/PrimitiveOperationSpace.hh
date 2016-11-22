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
    @brief Representa un espacio de operaciones primitivas predefinidas en forma de mapa de operaciones
*/

class PrimitiveOperationSpace {

private:

	/* INVARIANTE
		El espacio de operaciones primitivas no puede modificarse una vez ha sido creado
	*/

	typedef Expression (*primitiveOperation)(const Expression&);

	map<string, primitiveOperation> primOpMap;

	//_______ MÉTODOS PRIVADOS

	static Expression sum(const Expression& exp);
	/* Pre: 'exp' es una lista con dos punteros a dos expresiones enteras */
	/* Post: devuelve el valor de la suma de las dos expresiones enteras o undefined si alguno de los valores era undefined */

	static Expression neg(const Expression& exp);
	/* Pre: 'exp' es una lista con un puntero a una expresión entera */
	/* Post: devuelve el valor de la expresión entera cambiado de signo o undefined si el valor era undefined */

	static Expression cons(const Expression& exp);
	/* Pre: 'exp' es una expresión entera y una lista con punteros a expresiones enteras */
	/* Post: devuelve una lista con la expresión entera como cabeza de la lista */

	static Expression head(const Expression& exp);
	/* Pre: 'exp' es una lista no vacía de punteros a expresiones enteras */
	/* Post: devuelve el valor del primer puntero de la lista o undefined si era undefined */

	static Expression tail(const Expression& exp);
	/* Pre: 'exp' es una lista no vacía de punteros a enteros */
	/* Post: devuelve la lista sin el primer elemento */

	static Expression equal(const Expression& exp);
	/* Pre: 'exp' es una lista con dos punteros a dos expresiones evaluables del mismo tipo */
	/* Post: devuelve 1 si ambas expresiones son iguales; en otro caso, devuelve 0 */

	static Expression less(const Expression& exp);
	/* Pre: 'exp' es una lista con dos punteros a dos expresiones evaluables del mismo tipo */
	/* Post: devuelve 1 si ambas expresiones son iguales; en otro caso, devuelve 0 */

	static Expression bool_not(const Expression& exp);
	/* Pre: 'exp' es un booleano */
	/* Post: devuelve el valor de 'exp' negado */

	static Expression bool_and(const Expression& exp);
	/* Pre: 'exp' es una lista con dos punteros a dos booleanos */
	/* Post: devuelve 1 si ambos valores son 1;  en otro caso, devuelve 0 */

	static Expression bool_or(const Expression& exp);
	/* Pre: 'exp' es una lista con dos punteros a dos booleanos */
	/* Post: devuelve 0 si ambos valores son 0;  en otro caso, devuelve 1 */

	static Expression cond_if(const Expression& exp);
	/* Pre: 'exp' es un valor booleano y una lista con dos punteros a dos expresiones evaluables */
	/* Post: devuelve el resultado de evaluar la primera expresión  si el booleano era 1;  en otro caso, devuelve el resultado de evaluar la  segunda expresión */

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar un nuevo espacio de operaciones primitivas predefinidas
		\pre <em>Cierto</em>
		\post Crea un objeto con mapa de operaciones primitivas 'primOpMap'  inicializado con las operaciones primitivas
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

	/** @brief Consultora de recuperación de operación primitiva

    	\pre 'key' es un string no vacío; el mapa de operaciones primitivas 'primOpMap' del parámetro implícito contiene una operación primitiva con clave 'key'
    	\post Devuelve la operación primitiva representada por la clave 'key'
    */
	primitiveOperation retrieve(string key) const;

};

#endif