/** @file FunctionsIO.hh
    @brief Especificación de las operaciones de lectura/escritura de expresiones
*/

#include "Input.hh"
#include "Environment.hh"
#include "Expression.hh"

using namespace std;



/** @brief Operación para identicar un número en una cadena de strings

	\pre <em>Cierto</em>
	\post Devuelve cierto si la variable 'str' es un número, falso en caso contrario.
*/
bool is_num(string str);

/** @brief Operación para identificar si los datos introducidos por el canal estandar de entrada son validos

	\pre 'env' es un entorno con variable primitivas previamente inicializadas, str es un string no vacio
	\post Devuelve true si str es un parentesis, número, operación definida, variable definida o una primitva. Falso en cualquier otro caso.
*/

bool is_valid(Environment& env, string str);

/** @brief Crea un espacio de variables local

	\pre 'env' es un entorno con variable primitivas previamente inicializadas, exp una expresion no vacia y parameters los paremtros a definir
	\post
*/
void createLocalVarSpace(Environment& env, Expression& exp, string parameters);
/** @brief Operación de separación de strings

	\pre <em>Cierto</em>
	\post 'str' es un string contenido entre espacios o paréntesis en la entrada que se ha leído
*/

/** @brief Evalua la expresion exp y retorna su valor en exp

	\pre 'env' es un entorno con variable primitivas previamente inicializadas; 'exp' es una expresión a evaluar.
	\post Se evalua la expresion 'exp' y se retorna en la misma variable el valor resultante, el cual puede ser: una lista de expresiones, un valor o indefinido.
*/
void evaluate(Environment& env, Expression& exp);

/** @brief Lee una lista de expresiones y las añade a una lista de expresiones de exp

	\pre 'env' es un entorno con variable primitivas previamente inicializadas; 'exp' es una expresión no vacia e input contiene los caracteres a añadir en la lista.
	\post	Se crea una lista de expresiones en exp, si los valores a añadir son indefinidos, se modifica el valor de la expresion a indefinido.
*/
void readList(Environment& env, Expression& exp, Input& in);

/** @brief Comprueba que una cadena de caracteres sea valida

	\pre 'env' es un entorno con variable primitivas previamente inicializadas; 'in' contiene una cadena de caracteres introducidas por el usuario por el canal estandar de entrada
	\post Devuelve cierto si in es una cadena de caracteres valida con parentesis, números, operaciones definidas, variables definidas y/o primitvas, falso en caso contrario.
*/
bool check(Environment& env, Input& in);

/** @brief Lee la operación if con sus expresiones

	\pre 'env' es un entorno con variable primitivas previamente inicializadas; exp es una expresion inicializada con el operador if, 'in' contiene una cadena de caracteres introducidas por el usuario por el canal estandar de entrada
	\post Se evalua la expresion exp y se retorna su resultado en la misma variable, su valor puede ser un valor una lista o indefinido.
*/
void readIf(Environment& env, Expression& exp, Input& in);

/** @brief Lee una operación primitiva o previamente definida por el usuario.

	\pre 'env' es un entorno con variable primitivas previamente inicializadas; exp es una expresion inicializada, 'in' contiene una cadena de caracteres introducidas por el usuario por el canal estandar de entrada
	\post Se le asigna un operador op el cual esta en la variable in, a la expresion exp.
*/
void readOp(Environment& env, Expression& exp, Input& in);

/** @brief Define una variable introducida por el canal estandar de entrada.

	\pre env es un entorno con variable primitivas previamente inicializadas; key es el nombre de la variable a definir, 'in' contiene una cadena de caracteres introducidas por el usuario por el canal estandar de entrada
	\post Se define una nueva variable con nombre 'key' y el valor esta en la expresion introducida en 'in' por el canal estandar de entrada, esta nueva variable se añade al entorno de environment. Si la evaluacion de la expresion para definir la nueva variable da indefinida, la variable quedara como indefinida.
*/
void defineVar(Environment& env, string key, Input& in);

/** @brief Define una operación introducida por el canal estandar de entrada.

	\pre env es un entorno con variable primitivas previamente inicializadas; key es el nombre de la operacion a definir, 'in' contiene una cadena de caracteres introducidas por el usuario por el canal estandar de entrada, esta cadena contiene la expresión a evaluar.
	\post Se define una nueva operación con nombre 'key', parametros 'parameters' y como valor la cadena introducida por el canal estandar de entrada 'in', esta nueva operación se añadirá al entorno de environment. No se evalua la expresión al definir la operación, solo se evaluara al utilizar la operación.
*/
void defineOp(Environment& env, string key, string parameters, Input& in);

/** @brief Interpreta si se definirá una variable u operación

	\pre 'env' es un entorno con variable primitivas previamente inicializadas; 'in' es una cadena con los valores a definir, puede ser la definicion de una variable o de una operación.
	\post Se ha creado una varible u operación. Si la expresion es correcta, si es indefinida se creara una exp con el valor indefinido.
*/
void define(Environment& env, Input& in);

/** @brief Operación de lectura de expresiones

	\pre 'env' es un entorno con un espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas; 'exp' es una expresión vacía.
	\post Se han leído los datos del canal estándar de entrada y se han asignado a 'env' si eran una definición de una variable u operación o a 'exp' si representaban una expresión evaluable
*/
bool readExpression(Environment& env, Expression& exp, Input& in);


/** @brief Operación de lectura de expresiones

	\pre 'env' es un entorno con un espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas; 'exp' es una expresión vacía
	\post Se han leído los datos del canal estándar de entrada y se han asignado a 'env' si eran una definición de una variable o operación o a 'exp' si representaban una expresión evaluable
*/
bool read(Environment& env, Expression& exp);