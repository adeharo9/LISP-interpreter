#include <iostream>
#include <list>
#include "Expression.hh"

using namespace std;

//_______ METODES PRIVATS

list<Expression*> Expression::cp_exp_list(list<Expression*> lExpression) {
	list<Expression*> aux;
	Expression* pAux;
	list<Expression*>::iterator it = lExpression.begin();
	while(it != lExpression.end()){
		pAux = new Expression;
		pAux->b_undef = (*it)->b_undef;
		pAux->b_empty = (*it)->b_empty;
		pAux->b_val = (*it)->b_val;
		pAux->b_op = (*it)->b_op;
		pAux->b_list = (*it)->b_list;
		pAux->val = (*it)->val;
		pAux->op = (*it)->op;
		pAux->lExp = cp_exp_list((*it)->lExp);
		aux.insert(aux.end(), pAux);
		++it;
	}
	return aux;
}

void Expression::rm_exp_list(list<Expression*> lExpression) {
	list<Expression*>::iterator it = lExpression.begin();
	while(it != lExpression.end()) {
		rm_exp_list((*it)->lExp);
		delete *it;
		++it;
	}
}

//_______ CONSTRUCTORES

Expression::Expression() {
	b_undef = false;
	b_empty = true;
	b_val = false;
	b_op = false;
	b_list = false;
}

Expression::Expression(int value) {
	b_undef = false;
	b_empty = false;
	b_val = true;
	b_op = false;
	b_list = false;
	val = value;
}

Expression::Expression(string inOperator, const list<Expression*>& lExpression) {
	b_undef = false;
	b_empty = false;
	b_val = false;
	b_op = true;
	b_list = false;
	op = inOperator;
	lExp = cp_exp_list(lExpression);
}

Expression::Expression(const list<Expression*>& lExpression) {
	b_undef = false;
	b_empty = false;
	b_val = false;
	b_op = false;
	b_list = true;
	lExp = cp_exp_list(lExpression);
}

Expression::Expression(const Expression& inExp) {
	b_undef = inExp.b_undef;
	b_empty = inExp.b_empty;
	b_val = inExp.b_val;
	b_op = inExp.b_op;
	b_list = inExp.b_list;
	val = inExp.val;
	op = inExp.op;
	lExp = cp_exp_list(inExp.lExp);
}

//_______ DESTRUCTORES

Expression::~Expression() {
	rm_exp_list(lExp);
}

//_______ MODIFICADORES

Expression& Expression::operator = (const Expression& inExp) {
	b_undef = inExp.b_undef;
	b_empty = inExp.b_empty;
	b_val = inExp.b_val;
	b_op = inExp.b_op;
	b_list = inExp.b_list;
	val = inExp.val;
	op = inExp.op;
	if(this != &inExp) {
		rm_exp_list(lExp);
		lExp = cp_exp_list(inExp.lExp);
	}
	return *this;
}

bool Expression::operator == (const Expression& inExp) const {
	if(b_val and inExp.b_val) {
		return val == inExp.val;
	}
	else if(b_list and inExp.b_list) {
		if(lExp.size() == inExp.size()) {
			list<Expression*>::const_iterator it1 = lExp.begin();
			list<Expression*>::const_iterator it2 = inExp.lExp.begin();
			bool aux = true;
			while(aux and it1 != lExp.end()) {
				aux = *(*it1) == *(*it2);
				++it1;
				++it2;
			}
			return aux;
		}
		else {
			return false;
		}
	}
	else {
		return b_empty and inExp.b_empty;
	}
}

bool Expression::operator < (const Expression& inExp) const {
	if(b_val and inExp.b_val) {
		return val < inExp.val;
	}
	else if(b_list and inExp.b_list) {
		if(lExp.size() == inExp.size() and not b_empty) {
			list<Expression*>::const_iterator it1 = lExp.begin();
			list<Expression*>::const_iterator it2 = inExp.lExp.begin();
			bool aux = *(*it1) < *(*it2);
			++it1;
			++it2;
			while(aux and it1 != lExp.end()) {
				aux = *(*it1) < *(*it2);
				++it1;
				++it2;
			}
			return aux;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void Expression::clear() {
	if(not b_empty) {
		b_undef = false;
		b_empty = true;
		b_val = false;
		b_op = false;
		b_list = false;
	}
	op.clear();
	rm_exp_list(lExp);
	lExp.clear();
}

list<Expression*>::iterator Expression::erase(list<Expression*>::iterator it) {
	return lExp.erase(it);
}

void Expression::splice(list<Expression*>::iterator it, list<Expression*> lExpression) {
	lExp.splice(it, lExpression);
}

void Expression::set_undefined() {
	if(not b_undef) {
		b_undef = true;
		b_empty = false;
		b_val = false;
		b_op = false;
		b_list = false;
	}
}

void Expression::set_value(int value) {
	if(not b_val) {
		b_undef = false;
		b_empty = false;
		b_val = true;
		b_op = false;
		b_list = false;
	}
	val = value;
}

void Expression::set_op(string inOperator) {
	if(not b_op) {
		b_undef = false;
		b_empty = false;
		b_val = false;
		b_op = true;
		b_list = false;
	}
	op = inOperator;
}

void Expression::set_op_list(const list<Expression*>& lExpression) {
	lExp = cp_exp_list(lExpression);
}

void Expression::set_list() {
	if(not b_list) {
		b_undef = false;
		b_val = false;
		b_op = false;
		b_list = true;
	}
}

void Expression::set_list(const list<Expression*>& lExpression) {
	if(not b_list) {
		b_undef = false;
		b_empty = lExpression.size() == 0;
		b_val = false;
		b_op = false;
		b_list = true;
	}
	lExp = cp_exp_list(lExpression);
}

void Expression::set_empty_list() {
	if(not b_list) {
		b_undef = false;
		b_empty = true;
		b_val = false;
		b_op = false;
		b_list = true;
	}
}

//_______ CONSULTORES

int Expression::size() const {
	return lExp.size();
}

bool Expression::empty() const {
	return b_empty and not b_list;
}

bool Expression::undefined() const {
	return b_undef;
}

bool Expression::is_value() const {
	return b_val;
}

bool Expression::is_op() const {
	return b_op;
}

bool Expression::is_list() const {
	return b_list;
}

bool Expression::is_empty_list() const {
	return b_list and b_empty;
}

bool Expression::is_bool() const {
	return b_val and (val == 0 or val == 1);
}

int Expression::get_value() const {
	return val;
}

string Expression::get_op() const {
	return op;
}

list<Expression*> Expression::get_list() const {
	return lExp;
}

//_______ ITERADORES

list<Expression*>::iterator Expression::begin() {
	return lExp.begin();
}

list<Expression*>::const_iterator Expression::begin() const {
	return lExp.begin();
}

list<Expression*>::iterator Expression::second() {
	return ++lExp.begin();
}

list<Expression*>::const_iterator Expression::second() const {
	return ++lExp.begin();
}

list<Expression*>::iterator Expression::third() {
	return ++this->second();
}

list<Expression*>::const_iterator Expression::third() const {
	return ++this->second();
}

list<Expression*>::iterator Expression::end() {
	return lExp.end();
}

list<Expression*>::const_iterator Expression::end() const {
	return lExp.end();
}

//_______ I/O

void Expression::write() const {
	if(b_empty) {
		cout << "()" << endl;
	}
	else if(b_val) {
		cout << val << endl;
	}
	else if(b_list) {
		list<Expression*>::const_iterator const_it = lExp.begin();
		cout << "(" << (*const_it)->val;
		++const_it;
		while(const_it != lExp.end()) {
			cout << " " << (*const_it)->val;
			++const_it;
		}
		cout << ")" << endl;
	}
	else {
		cout << "indefinit" << endl;
	}
}
