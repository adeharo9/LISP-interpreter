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

void Expression::operator = (const Expression& inExp) {
	empt = inExp.emtp;
	undef = inExp.undef;
	val = inExp.val;
	op = inExp.op;
	lExp = inExp.lExp;
}

bool Expression::operator == (const Expression& inExp) const{
	if(this->is_value() and inExp.is_value()) {
		return this->get_value() == inExp.get_value();
	}
	else if(this->is_op() and inExp.is_op()) {
		bool aux = this->get_op() == inExp.get_op();
		list<Expression*>::const_iterator it1 = this->begin();
		list<Expression*>::const_iterator it2 = inExp->begin();
		while(aux and it1 != this->end() and it2 != inExp.end()){
			aux = *(*it2) == *(*it2);
			++it1;
			++it2;
		}
		return aux;
	}
	else if(this->is_list() and inExp.is_list()) {
		list<Expression*>::const_iterator it1 = this->begin();
		list<Expression*>::const_iterator it2 = inExp->begin();
		bool aux = *(*it2) == *(*it2);
		++it1;
		++it2;
		while(aux and it1 != this->end() and it2 != inExp.end()){
			aux = *(*it2) == *(*it2);
			++it1;
			++it2;
		}
	}
	else {
		return this->empty() and inExp.emtpy()
	}
}

void Expression::evaluate() {

}

void Expression::clear() {
	if(not empt){
		empt = true;
		undef = false;
		op.clear();
		lExp.clear();
	}
}

list<Expression*>::iterator erase(list<Expression*>::iterator it) {
	return lExp.erase(it);
}

void Expression::splice(list<Expression*>::iterator it, list<Expression*> lExpression) {
	lExp.splice(it,lExpression);
}

void Expression::set_undefined() {
	if(not undef){
		empt = false;
		undef = true;
		op.clear();
		lExp.clear();
	}
}

void Expression::set_value(int value) {
	if(not this->is_value()){
		empt = false;
		undef = false;
		op.clear();
		lExp.clear();
	}
	val = value;
}

void Expression::set_list(const list<Expression*>& lExpression) {
	if(not this->is_list()){
		empt = false;
		undef = false;
		op.clear();
	}
	lExp = lExpression;
}

void Expression::add_value(int value) {
	val += value;
}

//_______ CONSULTORES

int Expression::size() const {
	return lExp.size();
}

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