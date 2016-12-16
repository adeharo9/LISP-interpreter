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

	typedef list<Expression*>::iterator iter;
	typedef list<Expression*>::const_iterator const_iter;

	/* INVARIANTE
		Una expresión indefinida no está vacía;
		Una expresión vacía no está indefinida;
	*/

	//_______ ATRIBUTOS

	bool b_undef;
	bool b_empty;
	bool b_val;
	bool b_op;
	bool b_list;
	int val;
	string op;
	list<Expression*> lExp;

	//_______ MÉTODOS PRIVADOS

	/** @brief Método privado de copia de lista de expresiones

		\pre <em>Cierto</em>
		\post Devuelve una lista de punteros que apuntan a una copia de los objetos contenidos por 'lExp', es decir, devuelve una lista conteniendo una copia del contenido de la lista 'lExp'

	*/
	static list<Expression*> cp_exp_list(const list<Expression*>& lExp);

	/** @brief Método privado de borrado de lista de expresiones

		\pre <em>Cierto</em>
		\post Elimina todos los elementos apuntados por la lista 'lExp' y libera la memoria ocupada por ellos
	*/
	static void rm_exp_list(list<Expression*>& lExp);

	/** @brief Método privado de borrado de lista de expresiones

		\pre <em>Cierto</em>
		\post Elimina todos los elementos apuntados por la lista 'lExpression' a excepción del elemento 'inExp' y todos los que dependen de él (si forma parte de 'lExp' o de alguno de los elementos apuntados por los elementos de 'lExp'), y libera la memoria ocupada por ellos
	*/
	static void rm_exp_list_excep(list<Expression*>& lExp, Expression& inExp);

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar una nueva expresión
		\pre <em>Cierto</em>
		\post Crea un objeto vacío: 'b_undef' igual a falso; 'b_empty' igual a cierto; 'b_val' igual a falso; 'b_op' igual a falso; 'b_list' igual a falso; 'val' sin inicializar; 'op' es un string vacío; 'lExp' es una lista vacía

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
		\post El parámetro implícito pasa a ser una copia de 'inExp'
	*/
	Expression& operator = (const Expression& inExp);

	/** @brief Operación de asignación por transferencia

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a tener todos los elementos de 'inExp' mediante transferencia (sin reubicación de datos en memoria); 'inExp' pasa a estar vacío
	*/
	Expression& operator << (Expression& inExp);

	/** @brief Operación de asignación de lista de expresiones por transferencia

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a tener la lista de expresiones de 'lExpression' mediante transferencia (sin reubicación de datos en memoria); 'lExpression' pasa a estar vacía
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
		\post El parámetro implícito pasa a estar vacío: 'b_undef' igual a falso; 'b_empty' igual a cierto; 'b_val' igual a falso; 'b_op' igual a falso; 'b_list' igual a falso; 'val' sin inicializar; 'op' es un string vacío; 'lExp' es una lista vacía
	*/
	void clear();

	/** @brief Operación de inserción de elemetos de lista

		\pre 'it' es un iterador a 'lExp', pero no a su inicio; 'pExp' es un puntero a una expresión existente en memoria
		\post Se inserta el puntero 'pExp' en la posición precedente al iterador 'it' en 'lExp'
	*/
	void insert(iter it, Expression* pExp);

	/** @brief Operación de borrado de elemetos de lista

		\pre 'lExp' no es una lista vacía
		\post Se borra el elemento apuntado por el iterador 'it' de la lista 'lExp'; devuelve un iterador al elemento siguiente al borrado
	*/
	iter erase(iter it);

	/** @brief Operación de empalmado de listas

		\pre 'it' es un iterador a 'lExp', pero no a su inicio
		\post 'lExp' pasa a tener los elementos de 'lExpression' antes del elemento apuntado por 'it'
	*/
	void splice(iter it, list<Expression*> lExpression);

	/** @brief Operación de cambio de listas

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a tener la lista de expresiones de 'inExp'; 'inExp' pasa a tener la lista de expresiones del parámetro implícito
	*/
	void swap_list(Expression& inExp);

	/** @brief Operación de asignación de lista de expresiones por transferencia

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a tener la lista de expresiones de 'inExp' mediante transferencia (sin reubicación de datos en memoria); 'inExp' pasa a tener una lista de expresiones vacía
	*/
	void move_list(Expression& inExp);

	/** @brief Modificadora del campo undefined

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a ser undefined, si aun no lo era: 'b_undef' igual a cierto; 'b_empty' igual a falso; 'b_val' igual a falso; 'b_op' igual a falso; 'b_list' igual a falso; 'op' es un string vacío; 'lExp' es una lista vacía
	*/
	void set_undefined();

	/** @brief Modificadora de valor por asignación

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a tener valor 'value' y pasa a ser un valor, si aun no lo era: 'b_undef' igual a falso; 'b_empty' igual a falso; 'b_val' igual a cierto; 'b_op' igual a falso; 'b_list' igual a falso; 'op' es un string vacío; 'lExp' es una lista vacía
	*/
	void set_value(int value);

	/** @brief Modificadora de operador

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a tener operador 'op' y pasa a ser una operación, si aun no lo era: 'b_undef' igual a falso; 'b_empty' igual a falso; 'b_val' igual a falso; 'b_op' igual a cierto; 'b_list' igual a falso; 'op' es un string vacío; 'lExp' es una lista vacía a la espera de ser inicializada mediante algún otro método
	*/
	void set_op(string op);

	/** @brief Modificadora de lista

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a ser una lista, si aun no lo era: 'b_undef' igual a falso; 'b_empty' igual a 'lExp.empty()'; 'b_val' igual a falso; 'b_op' igual a falso; 'b_list' igual a cierto; 'op' es un string vacío
	*/
	void set_list();

	/** @brief Modificadora de lista

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a ser una lista vacía, si aun no lo era: 'b_undef' igual a falso; 'b_empty' igual a cierto; 'b_val' igual a falso; 'b_op' igual a falso; 'b_list' igual a cierto; 'op' es un string vacío; 'lExp' es una lista vacía
	*/
	void set_empty_list();

	//_______ CONSULTORES

	/** @brief Consultora de tamaño de lista

		\pre <em>Cierto</em>
		\post Devuelve el tamaño de la lista de expresiones 'lExp'
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

		\pre El parámetro implícito representa un valor ('b_val' es cierto y 'val' ha sido inicializado con un valor)
		\post Devuelve el valor 'val' del parámetro implícito
	*/
	int get_value() const;

	/** @brief Consultora de operador

		\pre El parámetro implícito representa una expresión a evaluar ('b_op' es cierto y 'op' ha sido inicializado con un operador)
		\post Devuelve el operador 'op' del parámetro implícito
	*/
	string get_op() const;

	void whatis() const;


	//_______ ITERADORES

	/** @brief Iterador de inicio de lista

		\pre <em>Cierto</em>
		\post Devuelve un iterador que apunta al inicio de la lista de expresiones 'lExp'
	*/
	iter begin();

	/** @brief Iterador constante de inicio de lista

		\pre <em>Cierto</em>
		\post Devuelve un const_iterator que apunta al inicio de la lista de expresiones 'lExp'
	*/
	const_iter begin() const;

	/** @brief Iterador de segundo elemento de lista

		\pre <em>Cierto</em>
		\post Devuelve un iterador que apunta al segundo elemento de la lista de expresiones 'lExp'
	*/
	iter second();

	/** @brief Iterador constante de segundo elemento de lista

		\pre <em>Cierto</em>
		\post Devuelve un const_iterator que apunta al segundo elemento de la lista de expresiones 'lExp'
	*/
	const_iter second() const;

	/** @brief Iterador de final de lista

		\pre <em>Cierto</em>
		\post Devuelve un iterador que apunta al final de la lista de expresiones 'lExp'
	*/
	iter end();

	/** @brief Iterador constante de final de lista

		\pre <em>Cierto</em>
		\post Devuelve un const_iterator que apunta al final de la lista de expresiones 'lExp'
	*/
	const_iter end() const;


	//_______ I/O

	/** @brief Operación de escritura de expresión

		\pre <em>Cierto</em>
		\post Escribe el valor de la expresión o la lista de valores de la lista de expresiones representada/s por el parámetro implícito por el canal estandar de salida; en caso que el parámetro implícito no represente ninguno de los tipos permitidos, escribe "indefinit"
	*/
	void write() const;

};

#endif
