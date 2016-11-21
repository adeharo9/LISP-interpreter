/** @file Expression.hh
    @brief Especificación de la clase Expression
*/

#ifndef EXPRESSION_HH
#define EXPRESSION_HH

#ifndef NO_DIAGRAM

#include <list>
#include "tree.hh"

#endif

using namespace std;

/** @class Expression
    @brief Representa una expresión, evaluable o no, mediante el
    resultado de evaluarla

    Todas las operaciones son de <b>coste ?</b>
*/

class Expression {

private:

	/*struct definition {
		bool undefined;
		bool isVal;
		bool isOp;
	    int val;
	    string op;
	};

	tree<definition> exp;*/

	struct definition {
		bool undefined;
		int val;
		string op;
	};

	list<definition> exp;

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar una nueva expresión
		\pre <em>Cierto</em>
		\post Crea un objeto vacío
	*/
	Expression();

	/** @brief Constructora con valor de inicialización

		\pre <em>Cierto</em>
		\post Crea un objeto con raíz con las siguientes propiedades:
				'undefined' igual a falso,
				'isVal' igual a cierto,
				'isOp' igual a falso,
				'val' igual a 'value',
				'op' sin inicializar
	*/
	Expression(int value);

	/** @brief Constructora con operación de inicialización

		\pre 'inOperator' es un string no vacío;
			'inOperator' es un operador existente en el espacio de
			operaciones primitivas o en el espacio de operaciones definidas
			por el usuario
		\post Crea un objeto con raíz con la siguientes propiedades:
				'undefined' igual a falso,
				'isVal' igual a falso,
				'isOp' igual a cierto,
				'val' sin inicializar,
				'op' sin inicializar
			 con el primer elemento de sus ramas con las siguientes
			 propiedades:
				'undefined' igual a falso,
				'isVal' igual a falso,
				'isOp' igual a falso,
				'val' sin inicializar,
				'op' igual a 'inOperator'
			y con el resto de elementos de sus ramas igual a los elementos
			de 'lExp'
	*/
	Expression(string inOperator, const list<definition>& lExp);

	/** @brief Constructora con lista de inicialización

		\pre 'lExp' es una lista de expresiones
		\post Crea un objeto con raíz con la siguientes propiedades:
				'undefined' igual a falso,
				'isVal' igual a falso,
				'isOp' igual a falso,
				'val' sin inicializar,
				'op' sin inicializar
			 y con los elementos de sus ramas igual a los elementos de
			 'lExp'
	*/
	Expression(const list<definition>& lExp);

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
				lista, representada por las ramas de 'exp', si era una
				lista de expresiones evaluables;
				indefinido, representado por 'undefined' igual a cierto,
				si alguno de los nodos de las ramas de exp era
				indefinido
	*/
	void evaluate();

	/** @brief Operación de vaciado de expresión

		\pre <em>Cierto</em>
		\post El parámetro implícito pasa a estar vacío
	*/
	void clear();

	//_______ CONSULTORES

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

	/** @brief Operación de lectura de expresión

		\pre Hay preparada en el canal estándar de entrada una expresión
		\post El parámetro implícito pasa a tener los atributos leídos del
			 canal estándar de entrada;
			 devuelve cierto si en el canal estándar de entrada no había
			 string "****";
			 en otro caso, devuelve falso
	*/
	bool read();

	/** @brief Operación de escritura de expresión

		\pre El parámetro implícito no está vacío
		\post Escribe el valor de la expresión o la lista de valores de la
			 lista de expresiones representada/s por el parámetro implícito
			 por el canal estandar de salida
	*/
	void write();

};

#endif
