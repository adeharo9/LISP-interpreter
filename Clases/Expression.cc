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
	undefined = false;
	op = inOperator;
	lExp = lExpression;
}

Expression::Expression(const list<Expression*>& lExpression) {
	empt = false;
	undefined = false;
	lExp = lExpression;
}

Expression::Expression(const Expression& inExp) {
	empt = inExp.emtp;
	undef = inExp.undef;
	val = inExp.val;
	op = inExp.op;
	lExp = inExp.lExp;
}

//_______ DESTRUCTORES

Expression::~Expression() {
}

//_______ MODIFICADORES

void Expression::evaluate() {

}

void Expression::clear() {
	empt = true;
	undef = false;
	op.clear();
	lExp.clear();
}

void Expression::set_undefined() {
	empt = false;
	undef = true;
	op.clear();
	lExp.clear();
}

void Expression::set_value(int value) {
	empt = false;
	undef = false;
	val =value;
	op.clear();
	lExp.clear();
}

void Expression::set_list(const list<Expression*>& lExpression) {
	empt = false;
	undef = false;
	op.clear();
	lExp = lExpression;
}

void Expression::add_value(int value) {
	val += value;
}

//_______ CONSULTORES

bool Expression::undefined() const {
	return undef;
}

bool Expression::empty() const {
	return empt;
}

bool Expression::is_value() const {
	return not undef and op.size() == 0 and lExp.size() == 0;
}

bool Expression::is_op() const {
	return not undef and op.size() != 0 and lExp.size() != 0;
}

bool Expression::is_list() const {
	return not undef and op.size() == 0 and lExp.size() != 0;
}

int Expression::get_value() const {
	return val;
}

//_______ ITERADORES

list<Expression*>::iterator Expression::begin() {
	return lExp.begin();
}

list<Expression*>::const_iterator Expression::begin() const {
	return lExp.begin();
}

list<Expression*>::iterator Expression::end() {
	return lExp.end();
}

list<Expression*>::const_iterator Expression::end() const {
	return lExp.end();
}

//_______ I/O

void Expression::write() const {
	if(undef) {
		cout << "indefinit" << endl;
	}
	else if(this->is_value()) {
		cout << val << endl;
	}
	else {
		list<Expression*>::const_iterator const_it = lExp.begin();
		cout << "(" << *const_it->get_value();
		++const_it;
		while(const_it != lExp.end()) {
			cout << " " << *const_it->get_value();
			++const_it;
		}
		cout << ")";
	}
}