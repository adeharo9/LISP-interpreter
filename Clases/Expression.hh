/** @file Expression.hh
    @brief Especificación de la clase Expression
*/

#ifndef EXPRESSION_HH
#define EXPRESSION_HH

#ifndef NO_DIAGRAM
#include <list>
#endif

using namespace std;

/** @class Expression
    @brief Representa una expresión, evaluable o no, mediante el resultado de evaluarla
*/

class Expression {

private:

	/* INVARIANTE
		Una expresión indefinida no está vacía;
		Una expresión vacía no está indefinida;
	*/

	bool empt;
	bool undef;
	int val;
	string op;
	list<Expression*> lExp;

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar una nueva expresión
		\pre <em>Cierto</em>
		\post Crea un objeto vacío: 'empt' igual a cierto; 'undef' igual a falso; 'val' sin inicializar; 'op' es un string vacío; 'lExp' es una lista vacía

	*/
	Expression();

	/** @brief Constructora con valor de inicialización

		\pre <em>Cierto</em>
		\post Crea un objeto con los siguientes valores: 'empt' igual a falso; 'undef' igual a falso; 'val' igual a 'value'; 'op' es un string vacío; 'lExp' es una lista vacía
	*/
	Expression(int value);

	/** @brief Constructora con operación de inicialización

		\pre 'inOperator' es un string no vacío; 'inOperator' es un operador existente en el espacio de operaciones primitivas o en el espacio de operaciones definidas por el usuario 'lExpression' es una lista no vacía de punteros a expresiones
		\post Crea un objeto con los siguientes valores: 'empt' igual a falso; 'undef' igual a falso; 'val' sin inicializar; 'op' igual a 'inOperator'; 'lExp' igual a 'lExpression'
	*/
	Expression(string inOperator, const list<Expression*>& lExpression);

	/** @brief Constructora con lista de inicialización

		\pre 'lExpression' es una lista no vacía de punteros a expresiones
		\post Crea un objeto con los siguientes valores: 'empt' igual a falso; 'undef' igual a falso; 'val' sin inicializar; 'op' es un string vacío; 'lExp' igual a 'lExpression'
	*/
	Expression(const list<Expression*>& lExpression);

	/** @brief Constructora por copia

		\pre <em>Cierto</em>
		\post Crea un objeto copia de inExp
	*/
	Expression(const Expression& inExp);

	//_______ DESTRUCTORES

	/** @brief Destructora por defecto

		Se ejecuta automáticamente al salir de un ámbito de visibilidad
		\pre <em>Cierto</em>
		\post Libera los recursos locales del parámetro implícito al salir de un ámbito de visibilidad
	*/
	~Expression();

	//_______ MODIFICADORES

	/** @brief Operación de asignación

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a ser una copia de 'inExp'
	*/
	void operator = (const Expression& inExp);

	/** @brief Operación de comparación de igualdad

		\pre <em>Cierto</em>
		\post Devuelve cierto si el parámetro implícito es igual a 'inExp'
	*/
	bool operator == (const Expression& inExp) const;

	/** @brief Operación de evaluación de expresión

		\pre El parámetro implícito no está vácío
		\post El parámetro implícito pasa a ser: valor, representado por 'val', si era una expresión evaluable; lista, representada por 'lExp', si era una lista de expresiones evaluables; indefinido, representado por 'undef' igual a cierto, si la evaluación de la expresión representada por el parámetro implícito era indefinida
	*/
	void evaluate();

	/** @brief Operación de vaciado de expresión

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a estar vacío: 'empt' igual a cierto; 'undef' igual a falso; 'val' sin inicializar; 'op' es un string vacío; 'lExp' es una lista vacía
	*/
	void clear();

	/** @brief Operación de borrado de elemetos de lista

		\pre 'lExp' no es una lista vacía
		\post Se borra el elemento apuntado por el iterador 'it' de la lista 'lExp'; devuelve un iterador al elemento siguiente al borrado
	*/
	list<Expression*>::iterator erase(list<Expression*>::iterator it);

	/** @brief Operación de vaciado de expresión

		\pre 'lExp' no es una lista vacía
		\post El parámetro implícito pasa a tener los elementos de lExpression antes del elemento apuntado por it
	*/
	void splice(list<Expression*>::iterator it, list<Expression*> lExpression);

	/** @brief Modificadora del campo undefined

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a ser undefined
	*/
	void set_undefined();

	/** @brief Modificadora de valor por asignación

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a tener valor 'value'; la lista 'lExp' del parámetro implícito pasa a estar vacía; 'op' pasa a ser un string vacío
	*/
	void set_value(int value);

	/** @brief Modificadora de lista

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a tener 'lExp' igual a 'lExpression'; 'op' pasa a ser un string vacío
	*/
	void set_list(const list<Expression*>& lExpression);

	/** @brief Modificadora de valor por adición

		\pre 'val' está inicializada a un valor concreto
		\post El parámetro implícito pasa a tener valor 'val' igual a la suma de 'val' más 'value'
	*/
	void add_value(int value);

	//_______ CONSULTORES

	/** @brief Consultora de tamaño de lista

		\pre <em>Cierto</em>
		\post Devuelve el tamaño de la lsita 'lExp'
	*/
	int size() const;

	/** @brief Consultora de estado

		\pre <em>Cierto</em>
		\post Devuelve cierto si el parámetro implícito es indefinido; en otro caso, devuelve falso
	*/
	bool undefined() const;

	/** @brief Consultora de estado

		\pre <em>Cierto</em>
		\post Devuelve cierto si el parámetro implícito está vacío; en otro caso, devuelve falso
	*/
	bool empty() const;

	/** @brief Consultora de tipo de expresión variable

		\pre El parámetro implícito no está vacío
		\post Devuelve cierto si el parámetro implícito es un valor atómico; en otro caso, devuelve falso
	*/
	bool is_value() const;

	/** @brief Consultora de tipo de expresión operación

		\pre El parámetro implícito no está vacío
		\post Devuelve cierto si el parámetro implícito es una operación a ser evaluada; en otro caso, devuelve falso
	*/
	bool is_op() const;

	/** @brief Consultora de tipo de expresión lista

		\pre El parámetro implícito no está vacío
		\post Devuelve cierto si el parámetro implícito es una lista de expresiones; en otro caso, devuelve falso
	*/
	bool is_list() const;

	/** @brief Consultora de tipo de expresión booleana

		\pre El parámetro implícito no está vacío
		\post Devuelve cierto si el parámetro implícito es una expresión booleana; en otro caso, devuelve falso
	*/
	bool is_bool() const;

	/** @brief Consultora de valor

		\pre El parámetro implícito no es undefined; el parámetro implícito no está vacío; el parámetro implícito representa un valor
		\post Devuelve el valor 'val' del parámetro implícito
	*/
	int get_value() const;

	/** @brief Consultora de operador

		\pre El parámetro implícito no es undefined; el parámetro implícito no está vacío; el parámetro implícito representa una expresión a evaluar
		\post Devuelve el operador 'op' del parámetro implícito
	*/
	string get_op() const;

	//_______ ITERADORES

	/** @brief Iterador de inicio de lista

		\pre <em>Cierto</em>
		\post Devuelve un iterador que apunta al inicio de la lista 'lExp'
	*/
	list<Expression*>::iterator begin();

	/** @brief Iterador constante de inicio de lista

		\pre <em>Cierto</em>
		\post Devuelve un const_iterator que apunta al inicio de la lista 'lExp'
	*/
	list<Expression*>::const_iterator begin() const;

	/** @brief Iterador de final de lista

		\pre <em>Cierto</em>
		\post Devuelve un iterador que apunta al final de la lista 'lExp'
	*/
	list<Expression*>::iterator end();

	/** @brief Iterador constante de final de lista

		\pre <em>Cierto</em>
		\post Devuelve un const_iterator que apunta al final de la lista 'lExp'
	*/
	list<Expression*>::const_iterator end() const;

	//_______ I/O

	/** @brief Operación de escritura de expresión

		\pre El parámetro implícito no está vacío
		\post Escribe el valor de la expresión o la lista de valores de la lista de expresiones representada/s por el parámetro implícito por el canal estandar de salida
	*/
	void write() const;

};

#endif
