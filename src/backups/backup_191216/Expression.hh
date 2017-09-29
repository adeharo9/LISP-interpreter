/** @file Expression.hh
    @brief Especificación de la clase Expression
*/

#ifndef EXPRESSION_HH
#define EXPRESSION_HH

#ifndef NO_DIAGRAM
#include <list>
#include <string>
#endif

using namespace std;

/** @class Expression
    @brief Representa una expresión, evaluable o no, mediante el resultado de evaluarla
*/

class Expression {

private:

	/* INV

		Una expresión puede ser indefinida, vacía, un entero, una operación a ser evaluada o una lista de expresiones

		0 <= type <= 4
			0 --> undefined
			1 --> empty
			2 --> val
			3 --> op
			4 --> list

		Si type == 0
			op.size() == 0
			lExp.size() == 0;
		si type == 1
			op.size() == 0
			lExp.size() == 0;
		si type == 2
			op.size() == 0
			lExp.size() == 0;
		si type == 3
			op.size() != 0
			lExp.size() != 0;
		si type == 4
			op.size() == 0
			lExp.size() != 0

		Las expresiones apuntadas por los elementos de 'lExp' no tienen ningún otro puntero asociado aparte del contenido en la lista 'lExp'

	*/

	//_______ ATRIBUTOS

	/** @brief Atributo de tipo de expresión

		Atributo que codifica el tipo de expresión según la correspondencia: 0 -> indefinido; 1 -> vacío; 2 -> valor; 3 -> operación a ser evaluada; 4 ->lista de expresiones
	*/
	unsigned char type;

	/** @brief Atributo de valor

		Atributo que contiene el valor entero de una expresión atómica o resultado de una operación que se evalua a un entero
	*/
	int val;

	/** @brief Atributo de operador

		Atributo que contiene el operador de una operación a ser evaluada
	*/
	string op;

	/** @brief Atributo de lista de expresiones

		Atributo que contiene una lista de punteros a expresiones en caso que la expresión sea una operación (miembros de la operación) o una lista de expresiones
	*/
	list<Expression*> lExp;

	//_______ MÉTODOS PRIVADOS

	/** @brief Método privado de copia de lista de expresiones

		\pre <em>Cierto</em>
		\post Devuelve una lista de punteros que apuntan a una copia en memoria de los objetos apuntados por 'lExp', es decir, devuelve una lista conteniendo una copia del contenido de la lista 'lExp'

	*/
	static list<Expression*> cp_exp_list(const list<Expression*>& lExp);

	/** @brief Método privado de borrado de lista de expresiones

		\pre <em>Cierto</em>
		\post Elimina todos los elementos apuntados por la lista 'lExp' y libera la memoria ocupada por ellos
	*/
	static void rm_exp_list(list<Expression*>& lExp);

	/** @brief Método privado de borrado de lista de expresiones con excepción

		\pre <em>Cierto</em>
		\post Elimina todos los elementos apuntados por la lista 'lExpression' a excepción del elemento 'inExp' y todos los que dependen de él (si forma parte de 'lExp' o de alguno de los elementos apuntados por los elementos de 'lExp'), y libera la memoria ocupada por ellos
	*/
	static void rm_exp_list_excep(list<Expression*>& lExp, Expression& inExp);

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar una nueva expresión
		\pre <em>Cierto</em>
		\post Crea un objeto vacío
	*/
	Expression();

	/** @brief Constructora por copia

		\pre <em>Cierto</em>
		\post Crea un objeto copia de 'inExp'
	*/
	Expression(const Expression& inExp);

	//_______ DESTRUCTORES

	/** @brief Destructora por defecto

		Se ejecuta automáticamente al salir de un ámbito de visibilidad
		\pre <em>Cierto</em>
		\post Libera los recursos locales del parámetro implícito al salir de un ámbito de visibilidad
	*/
	~Expression();

	//_______ OPERADORES

	/** @brief Operación de asignación por copia

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a ser una copia de 'inExp'. Retorna un alias al parámetro implícito
	*/
	Expression& operator = (const Expression& inExp);

	/** @brief Operación de asignación por transferencia

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a tener todos los elementos de 'inExp' mediante transferencia (sin reubicación de datos en memoria); 'inExp' pasa a dejar de existir en memoria. Retorna un alias al parámetro implícito
	*/
	Expression& operator << (Expression& inExp);

	/** @brief Operación de asignación de lista de expresiones por transferencia

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a tener la lista de expresiones de 'lExpression' mediante transferencia (sin reubicación de datos en memoria); 'lExpression' pasa a estar vacía. Retorna un alias al parámetro implícito
	*/
	Expression& operator << (list<Expression*>& lExpression);

	/** @brief Operación de asignación de lista de expresiones por transferencia

		\pre <em>Cierto</em>
		\post La lista 'lExpression' pasa a tener la lista de expresiones del parámetro implícito mediante transferencia (sin reubicación de datos en memoria); la lista del parámetro implícito pasa a estar vacía
	*/
	void operator >> (list<Expression*>& lExpression);

	/** @brief Operación de comparación de igualdad

		\pre <em>Cierto</em>
		\post Si el parámetro implícito y 'inExp' son valores, devuelve cierto si son iguales; si ambos son listas de expresiones, devuelve cierto si los elementos de las respectivas posiciones de ambas listas son iguales; en otro caso, devuelve falso
	*/
	bool operator == (const Expression& inExp) const;

	/** @brief Operación de comparación lexicográfica de inferioridad exclusiva

		\pre <em>Cierto</em>
		\post Devuelve cierto si el parámetro implícito es lexicográficamente menor exclusivo que 'inExp'
	*/
	bool operator < (const Expression& inExp) const;

	//_______ MODIFICADORES

	/** @brief Operación de vaciado de expresión

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a estar vacío
	*/
	void clear();

	/** @brief Operación de inserción de elemetos de lista

		\pre 'it' es un iterador a la lista de expresiones del parámetro implícito; 'pExp' es un puntero a una expresión existente en memoria
		\post Se inserta el puntero 'pExp' en la posición precedente al iterador 'it' en la lista de expresiones del parámetro implícito
	*/
	void insert(list<Expression*>::iterator it, Expression* pExp);

	/** @brief Operación de borrado de elemetos de lista

		\pre la lista de expresiones del parámetro implícito no es una lista vacía
		\post Se borra el elemento apuntado por el iterador 'it' de la lista de expresiones del parámetro implícito; devuelve un iterador al elemento siguiente al borrado
	*/
	list<Expression*>::iterator erase(list<Expression*>::iterator it);

	/** @brief Operación de empalmado de listas

		\pre 'it' es un iterador a la lista de expresiones del parámetro implícito
		\post la lista de expresiones del parámetro implícito pasa a tener los elementos de 'lExpression' antes del elemento apuntado por 'it'
	*/
	void splice(list<Expression*>::iterator it, list<Expression*> lExpression);

	/** @brief Operación de cambio de listas

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a tener la lista de expresiones de 'inExp'; 'inExp' pasa a tener la lista de expresiones del parámetro implícito
	*/
	void swap_list(Expression& inExp);

	/** @brief Modificadora a expresión indefinida

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a ser indefinido, si aun no lo era
	*/
	void set_undefined();

	/** @brief Modificadora de valor por asignación

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a tener valor 'value' y pasa a ser un valor, si aun no lo era
	*/
	void set_value(int value);

	/** @brief Modificadora de operador

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a tener operador 'op' y pasa a ser una operación, si aun no lo era; la lista de expresiones del parámetro implícito es una lista vacía a la espera de ser inicializada mediante algún otro método
	*/
	void set_op(string op);

	/** @brief Modificadora de lista

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a ser una lista, si aun no lo era
	*/
	void set_list();

	/** @brief Modificadora de lista vacía

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a ser una lista vacía, si aun no lo era
	*/
	void set_empty_list();

	//_______ CONSULTORES

	/** @brief Consultora de tamaño de lista

		\pre <em>Cierto</em>
		\post Devuelve el tamaño de la lista de expresiones del parámetro implícito
	*/
	int size() const;

	/** @brief Consultora de estado

		\pre <em>Cierto</em>
		\post Devuelve cierto si el parámetro implícito es indefinido; en otro caso, devuelve falso
	*/
	bool undefined() const;

	/** @brief Consultora de estado

		\pre <em>Cierto</em>
		\post Devuelve cierto si el parámetro implícito es vacío; en otro caso, devuelve falso
	*/
	bool empty() const;

	/** @brief Consultora de tipo de expresión variable

		\pre <em>Cierto</em>
		\post Devuelve cierto si el parámetro implícito es un valor; en otro caso, devuelve falso
	*/
	bool is_value() const;

	/** @brief Consultora de tipo de expresión operación

		\pre <em>Cierto</em>
		\post Devuelve cierto si el parámetro implícito es una operación a ser evaluada; en otro caso, devuelve falso
	*/
	bool is_op() const;

	/** @brief Consultora de tipo de expresión lista

		\pre <em>Cierto</em>
		\post Devuelve cierto si el parámetro implícito es una lista de expresiones o una lista vacía; en otro caso, devuelve falso
	*/
	bool is_list() const;

	/** @brief Consultora de tipo de expresión lista vacía

		\pre <em>Cierto</em>
		\post Devuelve cierto si el parámetro implícito es una lista de expresiones vacía; en otro caso, devuelve falso
	*/
	bool is_empty_list() const;

	/** @brief Consultora de tipo de expresión booleana

		\pre <em>Cierto</em>
		\post Devuelve cierto si el parámetro implícito es una expresión booleana; en otro caso, devuelve falso
	*/
	bool is_bool() const;

	/** @brief Consultora de valor

		\pre El parámetro implícito representa un valor
		\post Devuelve el valor del parámetro implícito
	*/
	int get_value() const;

	/** @brief Consultora de operador

		\pre El parámetro implícito representa una operación a evaluar
		\post Devuelve el operador del parámetro implícito
	*/
	string get_op() const;

	//_______ ITERADORES

	/** @brief Iterador de inicio de lista

		\pre <em>Cierto</em>
		\post Devuelve un iterador que apunta al inicio de la lista de expresiones del parámetro implícito
	*/
	list<Expression*>::iterator begin();

	/** @brief Iterador constante de inicio de lista

		\pre <em>Cierto</em>
		\post Devuelve un const_iterator que apunta al inicio de la lista de expresiones del parámetro implícito
	*/
	list<Expression*>::const_iterator begin() const;

	/** @brief Iterador de segundo elemento de lista

		\pre La lista de expresiones del parámetro implícito no está vacía
		\post Devuelve un iterador que apunta al segundo elemento de la lista de expresiones del parámetro implícito
	*/
	list<Expression*>::iterator second();

	/** @brief Iterador constante de segundo elemento de lista

		\pre La lista de expresiones del parámetro implícito no está vacía
		\post Devuelve un const_iterator que apunta al segundo elemento de la lista de expresiones del parámetro implícito
	*/
	list<Expression*>::const_iterator second() const;

	/** @brief Iterador de final de lista

		\pre <em>Cierto</em>
		\post Devuelve un iterador que apunta al final de la lista de expresiones del parámetro implícito
	*/
	list<Expression*>::iterator end();

	/** @brief Iterador constante de final de lista

		\pre <em>Cierto</em>
		\post Devuelve un const_iterator que apunta al final de la lista de expresiones del parámetro implícito
	*/
	list<Expression*>::const_iterator end() const;


	//_______ I/O

	/** @brief Operación de escritura de expresión

		\pre <em>Cierto</em>
		\post Escribe el valor de la expresión o la lista de valores de la lista de expresiones representada/s por el parámetro implícito por el canal estandar de salida; en caso que el parámetro implícito no represente ninguno de los tipos permitidos, escribe "indefinit"
	*/
	void write() const;

};

#endif
