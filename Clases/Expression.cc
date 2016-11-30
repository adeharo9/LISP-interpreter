#include <iostream>
#include <list>
#include "Expression.hh"

using namespace std;

Expression::Expression() {
	empt = true;
	undef = false;
}

Expression::Expression(int value) {
	empt = false;
	undef = false;
	val = value;
}

Expression::Expression(string inOperator, const list<Expression*>& lExpression) {
	empt = false;
	undef = false;
	op = inOperator;
	lExp = lExpression;
}

Expression::Expression(const list<Expression*>& lExpression) {
	empt = false;
	undef = false;
	lExp = lExpression;
}

Expression::Expression(const Expression& inExp) {
	empt = inExp.empt;
	undef = inExp.undef;
	val = inExp.val;
	op = inExp.op;
	lExp = inExp.lExp;
}

//_______ DESTRUCTORES

Expression::~Expression() {
}

//_______ MODIFICADORES

void Expression::operator = (const Expression& inExp) {
	empt = inExp.empt;
	undef = inExp.undef;
	val = inExp.val;
	op = inExp.op;
	lExp = inExp.lExp;
}

bool Expression::operator == (const Expression& inExp) const {
	if(this->is_value() and inExp.is_value()) {
		return this->get_value() == inExp.get_value();
	}
	else if(this->is_list() and inExp.is_list()) {
		if(this->size() == inExp.size()) {
			list<Expression*>::const_iterator it1 = this->begin();
			list<Expression*>::const_iterator it2 = inExp.begin();
			bool aux = true;
			while(aux and it1 != this->end()) {
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
		return empt and inExp.empt;
	}
}

bool Expression::operator < (const Expression& inExp) const {
	if(this->is_value() and inExp.is_value()) {
		return this->get_value() < inExp.get_value();
	}
	else if(this->is_list() and inExp.is_list()) {
		if(this->size() == inExp.size() and not this->empt) {
			list<Expression*>::const_iterator it1 = this->begin();
			list<Expression*>::const_iterator it2 = inExp.begin();
			bool aux = *(*it1) < *(*it2);
			++it1;
			++it2;
			while(aux and it1 != this->end()) {
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
	if(not empt) {
		empt = true;
		undef = false;
		op.clear();
		lExp.clear();
	}
}

list<Expression*>::iterator Expression::erase(list<Expression*>::iterator it) {
	return lExp.erase(it);
}

void Expression::splice(list<Expression*>::iterator it, list<Expression*> lExpression) {
	lExp.splice(it, lExpression);
}

void Expression::set_undefined() {
	if(not undef) {
		empt = false;
		undef = true;
		op.clear();
		lExp.clear();
	}
}

void Expression::set_value(int value) {
	if(not this->is_value()) {
		empt = false;
		undef = false;
		op.clear();
		lExp.clear();
	}
	val = value;
}

void Expression::set_op(string inOperator) {
	if(not this->is_op()) {
		empt = false;
		undef = false;
		lExp.clear();
	}
	op = inOperator;
}

void Expression::set_op_list(const list<Expression*>& lExpression) {
	lExp = lExpression;
}

void Expression::set_list() {
	if(not this->is_list()) {
		empt = this->lExp.size() == 0;
		undef = false;
		op.clear();
	}
}

void Expression::set_list(const list<Expression*>& lExpression) {
	if(not this->is_list()) {
		undef = false;
		op.clear();
	}
	empt = lExpression.size() == 0;
	lExp = lExpression;
}

//_______ CONSULTORES

int Expression::size() const {
	return lExp.size();
}

bool Expression::empty() const {
	return empt;
}

bool Expression::undefined() const {
	return undef;
}

bool Expression::is_value() const {
	return not empt and not undef and op.size() == 0 and lExp.size() == 0;
}

bool Expression::is_op() const {
	return not empt and not undef and op.size() != 0 and lExp.size() != 0;
}

bool Expression::is_list() const {
	return empt or (not undef and op.size() == 0 and lExp.size() != 0);
	//return not empt and not undef and op.size() == 0 and lExp.size() != 0;
}

bool Expression::is_bool() const {
	return this->is_value() and (this->get_value() == 0 or this->get_value() == 1);
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
	if(empt) {
		cout << "()" << endl;
	}
	else if(this->is_value()) {
		cout << val << endl;
	}
	else if(this->is_list()) {
		list<Expression*>::const_iterator const_it = lExp.begin();
		cout << "(" << (*const_it)->get_value();
		++const_it;
		while(const_it != lExp.end()) {
			cout << " " << (*const_it)->get_value();
			++const_it;
		}
		cout << ")" << endl;
	}
	else {
		cout << "indefinit" << endl;
	}
}
