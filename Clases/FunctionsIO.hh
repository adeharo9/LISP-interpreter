/** @file FunctionsIO.hh
    @brief Especificación de las operaciones de lectura/escritura
    de expresiones
*/

#ifndef NO_DIAGRAM
#include <iostream>
#endif

#include "Environment.hh"
#include "Expression.hh"

using namespace std;

/** @brief Operación de separación de strings

	\pre <em>Cierto</em>
	\post 'str' es un string contenido entre espacios o paréntesis en la
		 entrada que se ha leído
*/
void getString(string& str);

/** @brief Operación de lectura de expresiones

	\pre 'env' es un entorno con un espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas;
		'exp' es una expresión vacía
	\post Se han leído los datos del canal estándar de entrada y se han asignado a 'env' si eran una definición de una variable o operación o a 'exp' si representaban una expresión evaluable
*/
bool readExpression(Environment& env, Expression& exp);

/** @brief Operación de escritura de expresiones

	\pre 'env' es un entorno con un espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas;
		'exp' es una expresión no vacía
	\post Escribe el valor de la expresión representada por 'exp' por el canal estándar de salida
*/
void writeExpression(const Environment& env, const Expression& exp);