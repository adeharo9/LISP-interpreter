#ifndef PRIMITIVEOPERATIONSPACE_HH
#define PRIMITIVEOPERATIONSPACE_HH

#include <map>
#include "Expression.hh"

using namespace std;

class PrimitiveOperationSpace {

private:

	/* INVARIANTE
	*/

	typedef Expression (*primitiveOperation)(const Expression&) ;

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

	PrimitiveOperationSpace();
	/* Pre: cierto */
	/* Post: el resultado es un objeto con mapa de operaciones primitivas
			 'primOpMap' inicializado con las operaciones primitivas */

	//_______ DESTRUCTORES

	~PrimitiveOperationSpace();
	/* Pre: cierto */
	/* Post: libera los recursos locales del parámetro implícito al salir
			 de un ámbito de visibilidad */

};

#endif