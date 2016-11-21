/** @file PrimitiveOperationSpace.hh
    @brief Especificación de la clase PrimitiveOperationSpace
*/

#ifndef PRIMITIVEOPERATIONSPACE_HH
#define PRIMITIVEOPERATIONSPACE_HH

#ifndef NO_DIAGRAM

#include <map>
#include "Expression.hh"

#endif

using namespace std;

/** @class PrimitiveOperationSpace
    @brief Representa un espacio de operaciones primitivas predefinidas
    en forma de mapa de operaciones

    Todas las operaciones son de <b>coste ?</b>
*/

class PrimitiveOperationSpace {

private:

	/* INVARIANTE
	*/

	typedef Expression (*primitiveOperation)(const Expression&);

	map<string,primitiveOperation> primOpMap;

	//_______ MÉTODOS PRIVADOS

	static Expression sum(const Expression& exp);
	/* Pre: */
	/* Post: */

	static Expression neg(const Expression& exp);
	/* Pre: */
	/* Post: */

	static Expression cons(const Expression& exp);
	/* Pre: */
	/* Post: */

	static Expression head(const Expression& exp);
	/* Pre: */
	/* Post: */

	static Expression tail(const Expression& exp);
	/* Pre: */
	/* Post: */

	static Expression equal(const Expression& exp);
	/* Pre: */
	/* Post: */

	static Expression less(const Expression& exp);
	/* Pre: */
	/* Post: */

	static Expression bool_not(const Expression& exp);
	/* Pre: */
	/* Post: */

	static Expression bool_and(const Expression& exp);
	/* Pre: */
	/* Post: */

	static Expression bool_or(const Expression& exp);
	/* Pre: */
	/* Post: */

	static Expression cond_if(const Expression& exp);
	/* Pre: */
	/* Post: */

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar un nuevo espacio de
		operaciones primitivas predefinidas
		\pre <em>Cierto</em>
		\post Crea un objeto con mapa de operaciones primitivas 'primOpMap'
			 inicializado con las operaciones primitivas
	*/
	PrimitiveOperationSpace();

	//_______ DESTRUCTORES

	/** @brief Destructora por defecto

		Se ejecuta automáticamente al salir de un ámbito de visibilidad
		\pre <em>Cierto</em>
		\post Libera los recursos locales del parámetro implícito al salir
			 de un ámbito de visibilidad
	*/
	~PrimitiveOperationSpace();

	//_______ CONSULTORES

	/** @brief Consultora de recuperación de operación primitiva

    	\pre 'key' es un string no vacío;
    		el mapa de operaciones primitivas 'primOpMap' del parámetro
    		implícito contiene una operación primitiva con clave 'key'
    	\post Devuelve la operación primitiva representada por la clave
    		 'key'
    */
	primitiveOperation retrieve(string key) const;

};

#endif