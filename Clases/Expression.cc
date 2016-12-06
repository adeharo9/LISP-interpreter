#include <iostream>
#include <list>
#include "Expression.hh"

using namespace std;

Expression* rm_excep = NULL;

//_______ METODES PRIVATS

list<Expression*> Expression::cp_exp_list(const list<Expression*>& lExp) {
	list<Expression*> aux;
	Expression* pAux;
	list<Expression*>::const_iterator const_it = lExp.begin();
	while(const_it != lExp.end()){
		pAux = new Expression;
		pAux->b_undef = (*const_it)->b_undef;
		pAux->b_empty = (*const_it)->b_empty;
		pAux->b_val = (*const_it)->b_val;
		pAux->b_op = (*const_it)->b_op;
		pAux->b_list = (*const_it)->b_list;
		pAux->val = (*const_it)->val;
		pAux->op = (*const_it)->op;
		pAux->lExp = cp_exp_list((*const_it)->lExp);
		aux.insert(aux.end(), pAux);
		++const_it;
	}
	return aux;
}

void Expression::rm_exp_list(list<Expression*>& lExp) {
	list<Expression*>::iterator it = lExp.begin();
	while(it != lExp.end()) {
		if(*it != rm_excep){
			delete *it;
		}
		++it;
	}
}

void Expression::rm_exp_list_excep(list<Expression*>& lExp, Expression& inExp) {
		rm_excep = &inExp;
		rm_exp_list(lExp);
		rm_excep = NULL;
}

//_______ CONSTRUCTORES

Expression::Expression() {
	b_undef = false;
	b_empty = true;
	b_val = false;
	b_op = false;
	b_list = false;
}

/*Expression::Expression(int value) {
	b_undef = false;
	b_empty = false;
	b_val = true;
	b_op = false;
	b_list = false;
	val = value;
}*/

/*Expression::Expression(string inOperator, const list<Expression*>& lExpression) {
	b_undef = false;
	b_empty = false;
	b_val = false;
	b_op = true;
	b_list = false;
	op = inOperator;
	lExp = cp_exp_list(lExpression);
}*/

/*Expression::Expression(const list<Expression*>& lExpression) {
	b_undef = false;
	b_empty = false;
	b_val = false;
	b_op = false;
	b_list = true;
	lExp = cp_exp_list(lExpression);
}*/

/*Expression::Expression(const Expression& inExp) {
	b_undef = inExp.b_undef;
	b_empty = inExp.b_empty;
	b_val = inExp.b_val;
	b_op = inExp.b_op;
	b_list = inExp.b_list;
	val = inExp.val;
	op = inExp.op;
	lExp = cp_exp_list(inExp.lExp);
}*/

//_______ DESTRUCTORES

Expression::~Expression() {
	rm_exp_list(lExp);
}

//_______ MODIFICADORES

Expression& Expression::operator = ( Expression& inExp) {
	if(this != &inExp) {
		b_undef = inExp.b_undef;
		b_empty = inExp.b_empty;
		b_val = inExp.b_val;
		b_op = inExp.b_op;
		b_list = inExp.b_list;
		val = inExp.val;
		op = inExp.op;
		list<Expression*> aux = cp_exp_list(inExp.lExp);
		rm_exp_list(lExp);
		lExp = aux;
	}
	cout << "Hola: ";
	this->write();
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

/*void Expression::assign_ncp(Expression& inExp) {
	b_undef = inExp.b_undef;
	b_empty = inExp.b_empty;
	b_val = inExp.b_val;
	b_op = inExp.b_op;
	b_list = inExp.b_list;
	val = inExp.val;
	op = inExp.op;
	lExp = inExp.lExp;
}*/

void Expression::clear() {
	if(not (b_empty and not b_list)) {
		b_undef = false;
		b_empty = true;
		b_val = false;
		b_op = false;
		b_list = false;
		op.clear();
		rm_exp_list(lExp);
		lExp.clear();
	}
}

list<Expression*>::iterator Expression::erase(list<Expression*>::iterator it) {
	return lExp.erase(it);
}

void Expression::splice(list<Expression*>::iterator it, list<Expression*> lExpression) {
	lExp.splice(it, lExpression);
}

/*void Expression::swap_list(list<Expression*>& lExpression) {
	list<Expression*> aux = lExp;
	lExp = lExpression;
	lExpression = aux;
}*/

void Expression::swap_list(Expression& inExp) {
	list<Expression*> aux = lExp;
	lExp = inExp.lExp;
	inExp.lExp = aux;
}

/*void Expression::swap(Expression& inExp) {
	if(this != &inExp){
		bool b_aux = b_undef;
		b_undef = inExp.b_undef;
		inExp.b_undef = b_aux;

		b_aux = b_empty;
		b_empty = inExp.b_empty;
		inExp.b_empty = b_aux;

		b_aux = b_val;
		b_val = inExp.b_val;
		inExp.b_val = b_aux;

		b_aux = b_op;
		b_op = inExp.b_op;
		inExp.b_op = b_aux;

		b_aux = b_list;
		b_list = inExp.b_list;
		inExp.b_list = b_aux;

		int i_aux = val;
		val = inExp.val;
		inExp.val = i_aux;

		string s_aux = op;
		op = inExp.op;
		inExp.op = s_aux;

		list<Expression*> l_aux = lExp;
		lExp = inExp.lExp;
		inExp.lExp = l_aux;
	}
}*/

/*void Expression::move(Expression& inExp) {
	if(this != &inExp){
		b_undef = inExp.b_undef;
		b_empty = inExp.b_empty;
		b_val = inExp.b_val;
		b_op = inExp.b_op;
		b_list = inExp.b_list;
		val = inExp.val;
		op = inExp.op;
		rm_exp_list_excep(lExp, inExp);
		lExp = inExp.lExp;
		inExp.lExp.clear();
		//inExp.~Expression();
		inExp.clear();
	}
}*/

Expression& Expression::operator << (Expression& inExp) {
	if(this != &inExp){
		b_undef = inExp.b_undef;
		b_empty = inExp.b_empty;
		b_val = inExp.b_val;
		b_op = inExp.b_op;
		b_list = inExp.b_list;
		val = inExp.val;
		op = inExp.op;
		rm_exp_list_excep(lExp, inExp);
		lExp = inExp.lExp;
		inExp.lExp.clear();
		//inExp.~Expression();
		inExp.clear();
	}
	return *this;
}

/*void Expression::move_list(list<Expression*>& lExpression) {
	rm_exp_list(lExp);
	lExp = lExpression;
	lExpression.clear();
}*/

Expression& Expression::operator << (list<Expression*>& lExpression) {
	rm_exp_list(lExp);
	lExp = lExpression;
	lExpression.clear();
	return *this;
}

void Expression::operator >> (list<Expression*>& lExpression) {
	rm_exp_list(lExpression);
	lExpression = lExp;
	lExp.clear();
	
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

/*void Expression::set_op_list(const list<Expression*>& lExpression) {
	lExp = cp_exp_list(lExpression);
}*/

void Expression::set_list() {
	if(not b_list) {
		b_undef = false;
		b_empty = lExp.size() == 0;
		b_val = false;
		b_op = false;
		b_list = true;
	}
}

/*void Expression::set_list(const list<Expression*>& lExpression) {
	if(not b_list) {
		b_undef = false;
		b_empty = lExpression.size() == 0;
		b_val = false;
		b_op = false;
		b_list = true;
	}
	lExp = cp_exp_list(lExpression);
}*/

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
	return cp_exp_list(lExp);
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
	if(b_list and b_empty) {
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
