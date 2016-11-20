#ifndef EXPRESSION_HH
#define EXPRESSION_HH

#include <list>
#include "tree.hh"

using namespace std;

class Expression {

private:

		bool undefined;
		bool isValue;
		bool isOp;
	    int value;
	    string op;
	    list<Expression*> lExp;

public:

	//_______ CONSTRUCTORES

	Expression();
	/* Pre: cierto*/
	/* Post: crea un objeto vacio:
				isValue=false
				isOp=false
				lExp está vacía*/

	Expression(int inValue);
	/* Pre: cierto*/
	/* Post: crea un objeto con valor igual a inValue y isValue=cierto */

	Expression(const string& inOp,const list<Expression*>& inLExp);
	/* Pre: inOp es un operador existente en el espacio de operadores
	   definidos (primitivos o no) */
	/* Post: crea un objeto con
				op igual a inOp
				lExp igual a inLExp
				isOp igual a cierto 
				isValue iguala a falso */

	Expression(const list<Expression*>& inLExp);
	/* Pre: inLExp es una lista de expresiones evaluables */
	/* Post: crea un objeto con
				lExp igual a inLExp
				isValue igual a falso
				isOp igual a falso */

	Expression(const Expression& inExp);
	/* Pre: inExp es una expresión evaluable */
	/* Post: crea un objeto copia de inExp */

	//_______ DESTRUCTORES

	~Expression();
	/* Pre: cierto */
	/* Post: se liberan los recursos asignados fuera de un ámbito de
	   visibilidad */

	//_______ CONSULTORES

	bool isValue() const;
	/* Pre: cierto */
	/* Post: retorna cierto si la expresión es un valor atómico, falso en
	   otro caso */

	bool isOp() const;
	/* Pre: cierto */
	/* Post: retorna cierto si la expresión es una operación a ser
	   evaluada, falso en otro caso */

	bool isList() const;
	/* Pre: cierto */
	/* Post: retorna cierto si la expresión es una lista de expresiones
	   (atómicas o no), falso en otro caso */

	bool empty() const;
	/* Pre: cierto*/
	/* Post: retorna cierto si la expresión está vacía, falso en otro caso*/

	//_______ MODIFICADORES

	void evaluate();
	/* Pre: cierto */
	/* Post: el parámetro implícito pasa a ser:
				· átomo si era un valor o una expresión operable. value es
				  el valor del átomo o de la expresión operable, isOp es
				  falso y lExp pasa a estar vacío
				· lista si era una lista de átomos o de expresiones
				  operables. isValue y isPp pasan a ser falso, y lExp
				  contiene los valores que representan los valores de los
				  átomos o expresiones operables anteriores */

	//_______ I/O

	void read();
	/* Pre: hay preparada en el canal estándar de entrada una expresión
			evaluable */
	/* Post: el parámetro implícito pasa a tener los atributos leídos del
			 canal estandar de entrada */

	void write() const;
	/* Pre: el parámetro implícito no está vacío */
	/* Post: escribe el valor (resultado) de la expresión representada por
	   el parámetro implícito por el canal estandar de salida  */

};

#endif
