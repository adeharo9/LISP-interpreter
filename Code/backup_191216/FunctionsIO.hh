/** @file FunctionsIO.hh
    @brief Especificación de las operaciones de lectura/escritura de expresiones
*/

#include "Environment.hh"
#include "Expression.hh"

using namespace std;

/** @brief Operación de separación de strings

	\pre <em>Cierto</em>
	\post 'str' es un string contenido entre espacios o paréntesis en la entrada que se ha leído
*/
void getString(string& str);

/** @brief Operación de lectura de expresiones


	\pre 'env' es un entorno con un espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas; 'exp' es una expresión vacía
	\post Se han leído los datos del canal estándar de entrada y se han asignado a 'env' si eran una definición de una variable o operación o a 'exp' si representaban una expresión evaluable
*/
bool read(Environment& env, Expression& exp);

/** @brief Operación para identicar un número en una cadena de strings

	\pre <em>Cierto</em>
	\post Devuelve cierto si la variable 'str' es un número, falso en caso contrario.
*/
bool isNum(string str);

/** @brief Operación de lectura de expresiones

	\pre 'env' es un entorno con un espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas; 'exp' es una expresión vacía, buff es la expresion de entrada a tratar.
	\post Se han leído los datos del buff y se han asignado a 'env' si eran una definición de una variable o operación o a 'exp' si representaban una expresión evaluable
*/
bool readExpression(Environment& env, Expression& exp, string& inbuff);


/** @brief Operación de escritura de expresiones

	\pre 'env' es un entorno con un espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas; 'exp' es una expresión no vacía
	\post Escribe el valor de la expresión representada por 'exp' por el canal estándar de salida
*/
void writeExpression(const Expression& exp);

/** @brief 

	\pre 'env' es un entorno con un espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas; 'Ininstrn' es una cadena con los valores a definir, puede ser la definicion de una variable o de una operación.

	\post Se ha creado una expresion con una la varible u operación a crear. Si la expresion es correcta, si es indefinida se creara una exp con el valor indefinido.
*/
void define(string Ininstrn, Environment& env);

/** @brief 

	\pre 'env' es un entorno con un espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas; 'exp' es una expresión a evaluar.
	\post Se evalua la exp y se retorna en la misma variable el valor resultante.
*/
void evaluate(Expression& exp, Environment& env);