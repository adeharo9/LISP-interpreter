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
    @brief Representa una expresión, evaluable o no, mediante el
    resultado de evaluarla
*/

class Expression {

private:

	/* INVARIANTE

	*/

	struct definition {
		bool undef;
		int val;
	};

	bool empt;
	definition def;
	string op;
	list<definition> lExp;

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar una nueva expresión
		\pre <em>Cierto</em>
		\post Crea un objeto vacío:
			 'empt' igual a cierto;
			 'undef' igual a falso;
			 'val' sin inicializar;
			 'op' es un string vacío;
			 'lExp' es una lista vacía

	*/
	Expression();

	/** @brief Constructora con valor de inicialización

		\pre <em>Cierto</em>
		\post Crea un objeto con las siguientes propiedades:
			 'empt' igual a falso;
			 'undef' igual a falso;
			 'val' igual a 'value';
			 'op' es un string vacío;
			 'lExp' es una lista vacía
	*/
	Expression(int value);

	/** @brief Constructora con operación de inicialización

		\pre 'inOperator' es un string no vacío;
			'inOperator' es un operador existente en el espacio de
			operaciones primitivas o en el espacio de operaciones definidas
			por el usuario
		\post Crea un objeto con la siguientes propiedades:
			 'empt' igual a falso;
			 'undef' igual a falso;
			 'val' sin inicializar;
			 'op' igual a 'inOperator';
			 'lExp' igual a 'lExpression'
	*/
	Expression(string inOperator, const list<pair<bool,int> >& lExpression);

	/** @brief Constructora con lista de inicialización

		\pre 'lExpression' es una lista con pares de booleanos representando
			valores indefinidos y enteros representando valores definidos
		\post Crea un objeto con la siguientes propiedades:
			 'empt' igual a falso;
			 'undef' igual a falso;
			 'val' sin inicializar;
			 'op' es un string vacío;
			 'lExp' igual a 'lExpression'
	*/
	Expression(const list<pair<bool,int> >& lExpression);

	/** @brief Constructora por copia

		\pre <em>Cierto</em>
		\post Crea un objeto copia de inExp
	*/
	Expression(const Expression& inExp);

	//_______ DESTRUCTORES

	/** @brief Destructora por defecto

		Se ejecuta automáticamente al salir de un ámbito de visibilidad
		\pre <em>Cierto</em>
		\post Libera los recursos locales del parámetro implícito al salir
			 de un ámbito de visibilidad
	*/
	~Expression();

	//_______ MODIFICADORES

	/** @brief Operación de evaluación de expresión

		\pre El parámetro implícito no está vácío
		\post El parámetro implícito pasa a ser:
				valor, representado por 'val', si era una expresión
				evaluable;
				lista, representada por 'lExp', si era una lista de
				expresiones evaluables;
				indefinido, representado por 'undef' igual a cierto,
				si la evaluación de la expresión representada por el 
				parámetro implícito era indefinida
	*/
	void evaluate();

	/** @brief Operación de vaciado de expresión

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a estar vacío:
			 'empt' igual a cierto;
			 'undef' igual a falso;
			 'val' sin inicializar;
			 'op' es un string vacío;
			 'lExp' es una lista vacía
	*/
	void clear();

	/** @brief Modificadora de valor

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a tener valor 'value';
			 la lista 'lExp' del parámetro implícito pasa a estar vacía;
			 'op' pasa a ser un string vacío
	*/
	void set_value(int value);

	//_______ CONSULTORES

	/** @brief Consultora de estado

		\pre <em>Cierto</em>
		\post Devuelve cierto si el parámetro implícito es indefinido;
			 en otro caso, devuelve falso
	*/
	bool undefined() const;

	/** @brief Consultora de estado

		\pre <em>Cierto</em>
		\post Devuelve cierto si el parámetro implícito está vacío;
			 en otro caso, devuelve falso
	*/
	bool empty() const;

	/** @brief Consultora de tipo de expresión variable

		\pre El parámetro implícito no está vacío
		\post Devuelve cierto si el parámetro implícito es un valor atómico;
			 en otro caso, devuelve falso
	*/
	bool is_value() const;

	/** @brief Consultora de tipo de expresión operación

		\pre El parámetro implícito no está vacío
		\post Devuelve cierto si el parámetro implícito es una operación a
			 ser evaluada;
			 en otro caso, devuelve falso
	*/
	bool is_op() const;

	/** @brief Consultora de tipo de expresión lista

		\pre El parámetro implícito no está vacío
		\post Devuelve cierto si el parámetro implícito es una lista de
			 expresiones;
			 en otro caso, devuelve falso
	*/
	bool is_list() const;

	//_______ I/O

	/** @brief Operación de escritura de expresión

		\pre El parámetro implícito no está vacío
		\post Escribe el valor de la expresión o la lista de valores de la
			 lista de expresiones representada/s por el parámetro implícito
			 por el canal estandar de salida
	*/
	void write() const;

};

#endif
