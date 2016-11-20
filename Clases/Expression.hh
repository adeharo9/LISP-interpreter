#ifndef EXPRESSION_HH
#define EXPRESSION_HH

#include <list>
#include "tree.hh"

using namespace std;

class Expression {

private:

	struct definition {
		bool undefined;
		bool isVal;
		bool isOp;
	    int val;
	    string op;
	};

	tree<definition> exp;

public:

	//_______ CONSTRUCTORES

	Expression();
	/* Pre: cierto */
	/* Post: crea un objeto vacío */

	Expression(int value);
	/* Pre: cierto*/
	/* Post: crea un objeto con raíz con las siguientes propiedades:
				'undefined' igual a falso,
				'isVal' igual a cierto,
				'isOp' igual a falso,
				'val' igual a 'value',
				'op' sin inicializar */

	Expression(string operator,const list<tree<definition> >& lExp);
	/* Pre: 'operator' es un string no vacío;
			'operator' es un operador existente en el espacio de
			operaciones primitivas o en el espacio de operaciones definidas
			por el usuario */
	/* Post: crea un objeto con raíz con la siguientes propiedades:
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
				'op' igual a 'operator'
			y con el resto de elementos de sus ramas igual a los elementos
			de 'lExp' */

	Expression(const list<tree<definition> >& lExp);
	/* Pre: lExp es una lista de expresiones */
	/* Post: crea un objeto con raíz con la siguientes propiedades:
				'undefined' igual a falso,
				'isVal' igual a falso,
				'isOp' igual a falso,
				'val' sin inicializar,
				'op' sin inicializar
			 y con los elementos de sus ramas igual a los elementos de
			 'lExp' */

	Expression(const Expression& inExp);
	/* Pre: cierto */
	/* Post: crea un objeto copia de inExp */

	//_______ DESTRUCTORES

	~Expression();
	/* Pre: cierto */
	/* Post: libera los recursos locales del parámetro implícito al salir
			 de un ámbito de visibilidad */

	//_______ MODIFICADORES

	void evaluate();
	/* Pre: el parámetro implícito no está vácío */
	/* Post: el parámetro implícito pasa a ser:
				valor, representado por 'val', si era una expresión
				evaluable;
				lista, representada por las ramas de 'exp', si era una
				lista de expresiones evaluables;
				indefinido, representado por 'undefined' igual a cierto,
				si alguno de los nodos de las ramas de exp era
				indefinido */

	//_______ CONSULTORES

	bool empty() const;
	/* Pre: cierto */
	/* Post: devuelve cierto si el parámetro implícito está vacío;
			 en otro caso, devuelve falso */

	bool is_value() const;
	/* Pre: el parámetro implícito no está vacío */
	/* Post: devuelve cierto si el parámetro implícito es un valor atómico;
			 en otro caso, devuelve falso */

	bool is_op() const;
	/* Pre: el parámetro implícito no está vacío */
	/* Post: devuelve cierto si el parámetro implícito es una operación a
			 ser evaluada;
			 en otro caso, devuelve falso */

	bool is_list() const;
	/* Pre: el parámetro implícito no está vacío */
	/* Post: devuelve cierto si el parámetro implícito es una lista de
			 expresiones;
			 en otro caso, devuelve falso */

	//_______ I/O

	void read();
	/* Pre: hay preparada en el canal estándar de entrada una expresión */
	/* Post: el parámetro implícito pasa a tener los atributos leídos del
			 canal estándar de entrada */

	void write();
	/* Pre: el parámetro implícito no está vacío */
	/* Post: escribe el valor de la expresión o la lista de valores de la
			 lista de expresiones representada/s por el parámetro implícito
			 por el canal estandar de salida  */

};

#endif
