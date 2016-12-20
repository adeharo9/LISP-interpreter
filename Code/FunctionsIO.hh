/** @file FunctionsIO.hh
    @brief Especificación de las operaciones de lectura/escritura de expresiones
*/

#include "Input.hh"
#include "Environment.hh"
#include "Expression.hh"

using namespace std;

/** @brief Operación para identificar un número en una cadena de strings

	\pre <em>Cierto</em>
	\post Devuelve cierto si la variable 'str' es un número, falso en caso contrario
*/
bool is_num(string str);

/** @brief Crea un espacio de variables local

	\pre 'env' es un entorno con operaciones primitivas previamente inicializadas, 'exp' una expresion no vacía y 'parameters' los paremtros a definir
	\post Crea un espacio de variables inicializado con 'parameters' como nombres de variables y los valores leídos en 'exp' como los valores de dichas variables
*/
void createLocalVarSpace(Environment& env, Expression& exp, string parameters);

/** @brief Operación de evaluación de expresión

	\pre 'env' es un entorno con operaciones primitivas previamente inicializadas; 'exp' es una expresión a evaluar
	\post Se evalua la expresion 'exp' y se retorna en la misma variable el valor resultante, el cual puede ser un valor, una lista de expresiones o indefinido.
*/
void evaluate(Environment& env, Expression& exp);

/** @brief Operación de lectura de lista de expresiones

	\pre 'env' es un entorno con operaciones primitivas previamente inicializadas; 'exp' es una expresión no vacía e 'in' contiene los caracteres a añadir en la lista
	\post	Se crea una lista de expresiones en 'exp'; si alguno de los valores a añadir es indefinidos, se modifica el valor de la expresión a indefinido
*/
void readList(Environment& env, Expression& exp, Input& in);

/** @brief Operación de lectura de operación 'if'

	\pre 'env' es un entorno con operaciones primitivas previamente inicializadas; 'exp' es una expresion inicializada con el operador 'if'; 'in' contiene una cadena de caracteres introducidas por el usuario por el canal estandar de entrada a ser introducidos como parámetros de la operación
	\post 'exp' pasa a contener el operador 'if' y los parámetros que esta operación necesita (un booleano y otro elemento que varía en función del estado de booleano). En caso que alguno de los parámetros sea indefinido, 'exp' pasa a ser indefinido
*/
void readIf(Environment& env, Expression& exp, Input& in);

/** @brief Operación de lectura de operación

	\pre 'env' es un entorno con operaciones primitivas previamente inicializadas; 'exp' es una expresion inicializada; 'in' contiene una cadena de caracteres introducidos por el usuario por el canal estandar de entrada a ser introducidos como parámetros
	\post La expresión 'exp' pasa a ser una expresión a ser evaluada en forma de operación, primitiva o no
*/
void readOp(Environment& env, Expression& exp, Input& in);

/** @brief Operación de definición de variable

	\pre 'env' es un entorno con operaciones primitivas previamente inicializadas; 'key' es el nombre de la variable a definir; 'in' contiene una cadena de caracteres introducidos por el usuario por el canal estandar de entrada a ser introducidos como parámetros
	\post Se define una nueva variable con nombre 'key' y valor extraído de la entrada mediante 'in', o se modifica una variable ya existente; dicha variable se añade al espacio de variables definidas por el usuario si su evaluación no es indefinido y no existía previamente; en caso que existiera, si su evaluación no es indefinido, se actualiza su valor; en otro caso, su valor en el espacio de variables (si existía) no se ve modificado y se imprime indefinido por el canal estándar de salida
*/
void defineVar(Environment& env, string key, Input& in);

/** @brief Operación de definición de operación

	\pre 'env' es un entorno con operaciones primitivas previamente inicializadas; 'key' es el nombre de la operacion a definir; 'parameters' es la lista de parámetros de la operación; 'in' contiene una cadena de caracteres introducidas por el usuario por el canal estandar de entrada con la información relevante a la expresión de la operación
	\post Se define una nueva operación con nombre 'key', parametros 'parameters' y como valor la cadena introducida por el canal estandar de entrada mediante 'in'; esta nueva operación se añade al espacio de operaciones definidas por el usuario sin que su expresión sea evaluada previamente
*/
void defineOp(Environment& env, string key, string parameters, Input& in);

/** @brief Operación de definición

	\pre 'env' es un entorno con operaciones primitivas previamente inicializadas; 'in' contiene una cadena con la declaración de la definición
	\post Se ha creado una varible u operación definidas por el usuario en el espacio dentro del entorno del programa correspondiente, o se ha mostrado 'indefinido' en el caso de una variable cuya evaluación sea 'indefinido'
*/
void define(Environment& env, Input& in);

/** @brief Inmersión de operación de lectura de expresiones

	\pre 'env' es un entorno con un espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas; 'exp' es una expresión vacía
	\post Se han leído los datos del canal estándar de entrada correspondientes a una expresión simple (que forma o puede formar parte de otra expresión mayor) y se han asignado a 'env' si eran una definición de una variable u operación o a 'exp' si representaban una expresión evaluable
*/
bool readExpression(Environment& env, Expression& exp, Input& in);


/** @brief Operación de lectura de expresiones

	\pre 'env' es un entorno con un espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas; 'exp' es una expresión vacía
	\post Los datos del canal estándar de entrada correspondientes una expresión completa han sido leídos y se han asignado a 'env' si eran una definición de una variable o operación o a 'exp' si representaban una expresión evaluable
*/
bool read(Environment& env, Expression& exp);
