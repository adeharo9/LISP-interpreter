#include <iostream>
#include <list>
#include <cstddef>
#include "Expression.hh"

using namespace std;

typedef list<Expression*>::iterator iter;
typedef list<Expression*>::const_iterator const_iter;

Expression* rm_excep = NULL;

//_______ METODOS PRIVADOS

list<Expression*> Expression::cp_exp_list(const list<Expression*>& lExp)
{
	list<Expression*> aux;
	Expression* pAux;
	const_iter c_it = lExp.begin();
	/* INV
		c_it es un iterador a un elemento de la lista de expresiones del parámetro implícito comprendido entre lExp.begin() y lExp.end()
	*/
	while(c_it != lExp.end()){
		pAux = new Expression;
		pAux -> type = (*c_it) -> type;
		pAux -> val = (*c_it) -> val;
		pAux -> op = (*c_it) -> op;
		/* HI
			cp_exp_list devuelve una lista de punteros que apuntan a una copia en memoria de los objetos apuntados por la lista pasada como parámetro
		*/
		pAux -> lExp = cp_exp_list((*c_it) -> lExp);
		aux.insert(aux.end(), pAux);
		++c_it;
	}
	return aux;
}

void Expression::rm_exp_list(list<Expression*>& lExp)
{
	for (iter it = lExp.begin(); it != lExp.end(); ++it) {
		if(*it != rm_excep){
			delete *it;
		}
	}
	lExp.clear();
}

void Expression::rm_exp_list_excep(list<Expression*>& lExp, Expression& inExp)
{
		rm_excep = &inExp;
		rm_exp_list(lExp);
		rm_excep = NULL;
}

//_______ CONSTRUCTORES

Expression::Expression()
{
	type = 1;
}

Expression::Expression(const Expression& inExp)
{
	type = inExp.type;
	val = inExp.val;
	op = inExp.op;
	lExp = cp_exp_list(inExp.lExp);
}

//_______ DESTRUCTORES

Expression::~Expression()
{
	rm_exp_list(lExp);
}

//_______ OPERADORES

Expression& Expression::operator = (const Expression& inExp)
{
	if(this != &inExp) {
		type = inExp.type;
		val = inExp.val;
		op = inExp.op;
		list<Expression*> aux = cp_exp_list(inExp.lExp);
		rm_exp_list(lExp);
		lExp = aux;
	}
	return *this;
}

Expression& Expression::operator << (Expression& inExp)
{
	if(this != &inExp){
		type = inExp.type;
		val = inExp.val;
		op = inExp.op;
		rm_exp_list_excep(lExp, inExp);
		lExp = inExp.lExp;
		inExp.lExp.clear();
		inExp.clear();
		delete &inExp;
	}
	return *this;
}

Expression& Expression::operator << (list<Expression*>& lExpression)
{
	rm_exp_list(lExp);
	lExp = lExpression;
	lExpression.clear();
	return *this;
}

void Expression::operator >> (list<Expression*>& lExpression)
{
	rm_exp_list(lExpression);
	lExpression = lExp;
	lExp.clear();
}

bool Expression::operator == (const Expression& inExp) const
{
	if(type == 2 and inExp.type == 2) {
		return val == inExp.val;
	}
	else if(type == 4 and inExp.type == 4) {
		if(lExp.size() == inExp.lExp.size()) {
			const_iter c_it1 = lExp.begin();
			const_iter c_it2 = inExp.lExp.begin();
			/* INV
				c_it1 es un iterador a un elemento de la lista de expresiones del parámetro implícito comprendido entre lExp.begin() y lExp.end()
				c_it2 es un iterador a un elemento de la lista de expresiones de 'inExp' comprendido entre inExp.lExp.begin() y inExp.lExp.end()
			*/
			/* HI
				*(*c_it1) == *(*c_it2) devuelve 'true' si ambas expresiones son iguales y 'false' en otro caso
			*/
			while(c_it1 != lExp.end() and (*(*c_it1) == *(*c_it2))) {
				++c_it1;
				++c_it2;
			}
			return c_it1 == lExp.end();
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Expression::operator < (const Expression& inExp) const
{
	if(type == 2 and inExp.type == 2) {
		return val < inExp.val;
	}
	else if(type == 4 and inExp.type == 4) {
		const_iter c_it1 = lExp.begin();
		const_iter c_it2 = inExp.lExp.begin();
		/* INV
			c_it1 es un iterador a un elemento de la lista de expresiones del parámetro implícito comprendido entre lExp.begin() y lExp.end()
			c_it2 es un iterador a un elemento de la lista de expresiones de 'inExp' comprendido entre inExp.lExp.begin() y inExp.lExp.end()
		*/
		while(c_it1 != lExp.end() and c_it2 != inExp.lExp.end() and (*(*c_it1) == *(*c_it2))) {
			++c_it1;
			++c_it2;
		}
		/* HI
			*(*c_it1) < *(*c_it2)) devuelve 'true' si la expresión de la izquierda del operador es lexicográficamente menor estricta que la de la derecha del operador
		*/
		return (c_it1 == lExp.end() and c_it2 != inExp.lExp.end()) or (c_it1 != lExp.end() and c_it2!= inExp.lExp.end() and *(*c_it1) < *(*c_it2));
	}
	else {
		return false;
	}
}

//_______ MODIFICADORES

void Expression::clear()
{
	if(type != 1) {
		type = 1;
		op.clear();
		rm_exp_list(lExp);
		lExp.clear();
	}
}

void Expression::insert(iter it, Expression* pExp)
{
	lExp.insert(it, pExp);
}

iter Expression::erase(iter it)
{
	delete *it;
	return lExp.erase(it);
}

void Expression::splice(iter it, list<Expression*> lExpression)
{
	lExp.splice(it, lExpression);
}

void Expression::swap_list(Expression& inExp)
{
	lExp.swap(inExp.lExp);
}

void Expression::set_undefined()
{
	if(type != 0) {
		type = 0;
		op.clear();
		rm_exp_list(lExp);
		lExp.clear();
	}
}

void Expression::set_value(int value)
{
	if(type != 2) {
		type = 2;
		op.clear();
		rm_exp_list(lExp);
		lExp.clear();
	}
	val = value;
}

void Expression::set_op(string inOperator)
{
	if(type != 3) {
		type = 3;
	}
	rm_exp_list(lExp);
	lExp.clear();
	op = inOperator;
}

void Expression::set_list()
{
	if(type != 4) {
		type = 4;
		op.clear();
	}
}

void Expression::set_empty_list()
{
	if(type != 4 or not lExp.empty()) {
		type = 4;
		op.clear();
		rm_exp_list(lExp);
		lExp.clear();
	}
}

//_______ CONSULTORES

int Expression::size() const
{
	return lExp.size();
}

bool Expression::undefined() const
{
	return type == 0;
}

bool Expression::empty() const
{
	return type == 1;
}

bool Expression::is_value() const
{
	return type == 2;
}

bool Expression::is_op() const
{
	return type == 3;
}

bool Expression::is_list() const
{
	return type == 4;
}

bool Expression::is_empty_list() const
{
	return type == 4 and lExp.empty();
}

bool Expression::is_bool() const
{
	return type == 2 and (val == 0 or val == 1);
}

int Expression::get_value() const
{
	return val;
}

string Expression::get_op() const
{
	return op;
}

//_______ ITERADORES

iter Expression::begin()
{
	return lExp.begin();
}

const_iter Expression::begin() const
{
	return lExp.begin();
}

iter Expression::second()
{
	return ++lExp.begin();
}

const_iter Expression::second() const
{
	return ++lExp.begin();
}

iter Expression::end()
{
	return lExp.end();
}

const_iter Expression::end() const
{
	return lExp.end();
}

//_______ I/O

void Expression::write() const
{
	if(type == 2) {
		cout << val << endl;
	}
	else if(type == 4) {
		cout << "(";
		if(not lExp.empty()) {
			const_iter c_it = lExp.begin();
			cout << (*c_it) -> val;
			++c_it;
			/* INV
				c_it es un iterador a un elemento de la lista de expresiones del parámetro implícito comprendido entre lExp.begin() y lExp.end()
			*/
			while(c_it != lExp.end()) {
				cout << " " << (*c_it) -> val;
				++c_it;
			}
		}
		cout << ")" << endl;
	}
	else {
		cout << "indefinit" << endl;
	}
}
