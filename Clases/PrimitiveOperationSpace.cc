#include <iostream>
#include <vector>
#include <map>
#include <list>
#include "PrimitiveOperationSpace.hh"
#include "Expression.hh"

using namespace std;

typedef void (*primitiveOperation)(Expression&);

//_______ MÉTODOS PRIVADOS

void PrimitiveOperationSpace::sum(Expression& exp) {
	if(exp.is_op() and exp.size() == 2) {
		if((*exp.begin()) -> is_value() and (*exp.second()) -> is_value()) {
			exp.set_value(((*exp.begin()) -> get_value()) + ((*exp.second()) -> get_value()));
		}
		else {
			exp.set_undefined();
		}
	}
	else {
		exp.set_undefined();
	}
}

void PrimitiveOperationSpace::neg(Expression& exp) {
	if(exp.is_op() and exp.size() == 1) {
		if((*exp.begin()) -> is_value()) {
			exp.set_value(-1 * ((*exp.begin()) -> get_value()));
		}
		else {
			exp.set_undefined();
		}
	}
	else {
		exp.set_undefined();
	}
}

void PrimitiveOperationSpace::cons(Expression& exp) {
	if(exp.is_op() and exp.size() == 2) {
		if((*exp.begin()) -> is_value() and (*exp.second()) -> is_list()) {
			list<Expression*> aux;
			*(*exp.second()) >> aux;
			exp.erase(exp.second());
			exp.splice(exp.end(), aux);
			exp.set_list();
		}
		else {
			exp.set_undefined();
		}
	}
	else {
		exp.set_undefined();
	}
}

void PrimitiveOperationSpace::head(Expression& exp) {
	if(exp.is_op() and exp.size() == 1) {
		if((*exp.begin()) -> is_list() and not (*exp.begin()) -> is_empty_list()) {
			exp << *(*((*exp.begin()) -> begin()));
		}
		else {
			exp.set_undefined();
		}
	}
	else {
		exp.set_undefined();
	}
}

void PrimitiveOperationSpace::tail(Expression& exp) {
	if(exp.is_op() and exp.size() == 1) {
		if((*exp.begin()) -> is_list() and not (*exp.begin()) -> is_empty_list()) {
			if((*exp.begin()) -> erase((*exp.begin()) -> begin()) != (*exp.begin()) -> end()) {
				exp << *(*exp.begin());
			}
			else {
				exp.set_empty_list();
			}
		}
		else {
			exp.set_undefined();
		}
	}
	else {
		exp.set_undefined();
	}
}

void PrimitiveOperationSpace::equal(Expression& exp) {
	if(exp.is_op() and exp.size() == 2) {
		if(((*exp.begin()) -> is_value() and (*exp.second()) -> is_value()) or ((*exp.begin()) -> is_list() and (*exp.second()) -> is_list())){
			exp.set_value(*(*exp.begin()) == *(*exp.second()));
		}
		else {
			exp.set_undefined();
		}
	}
	else {
		exp.set_undefined();
	}
}

void PrimitiveOperationSpace::less(Expression& exp) {
	if(exp.is_op() and exp.size() == 2) {
		if(((*exp.begin()) -> is_value() and (*exp.second()) -> is_value()) or ((*exp.begin()) -> is_list() and (*exp.second()) -> is_list())){
			exp.set_value(*(*exp.begin()) < *(*exp.second()));
		}
		else {
			exp.set_undefined();
		}
	}
	else {
		exp.set_undefined();
	}
}

void PrimitiveOperationSpace::bool_not(Expression& exp) {
	if(exp.is_op() and exp.size() == 1) {
		if((*exp.begin()) -> is_bool()) {
			exp.set_value((*exp.begin()) -> get_value() == 0);
		}
		else {
			exp.set_undefined();
		}
	}
	else {
		exp.set_undefined();
	}
}

void PrimitiveOperationSpace::bool_and(Expression& exp) {
	if(exp.is_op() and exp.size() == 2) {
		if((*exp.begin()) -> is_bool() and (*exp.second()) -> is_bool()) {
			exp.set_value(((*exp.begin()) -> get_value() == 1) and ((*exp.second()) -> get_value() == 1));
		}
		else {
			exp.set_undefined();
		}
	}
	else {
		exp.set_undefined();
	}
}

void PrimitiveOperationSpace::bool_or(Expression& exp) {
	if(exp.is_op() and exp.size() == 2) {
		if((*exp.begin()) -> is_bool() and (*exp.second()) -> is_bool()) {
			exp.set_value(((*exp.begin()) -> get_value() == 1) or ((*exp.second()) -> get_value() == 1));
		}
		else {
			exp.set_undefined();
		}
	}
	else {
		exp.set_undefined();
	}
}

void PrimitiveOperationSpace::cond_if(Expression& exp) {
	if(exp.is_op() and exp.size() == 2) {
		if((*exp.begin()) -> is_bool()) {
			exp << *(*exp.second());
		}
		else {
			exp.set_undefined();
		}
	}
	else {
		exp.set_undefined();
	}
}

//_______ CONSTRUCTORES

PrimitiveOperationSpace::PrimitiveOperationSpace() {
	definition aux;

	aux.r_type = 2;
	aux.i_type = vector<uchar>(2, 2);
	aux.fun = &sum;
	primOpMap["+"] = aux;

	aux.r_type = 2;
	aux.i_type = vector<uchar>(1, 2);
	aux.fun = &neg;
	primOpMap["-"] = aux;

	aux.r_type = 4;
	aux.i_type = vector<uchar>(2);
	aux.fun = &cons;
	primOpMap["cons"] = aux;

	aux.r_type = 4;
	aux.i_type = vector<uchar>(1, 4);
	aux.fun = &head;
	primOpMap["head"] = aux;

	aux.r_type = 4;
	aux.i_type = vector<uchar>(1, 4);
	aux.fun = &tail;
	primOpMap["tail"] = aux;

	aux.r_type = 2;
	aux.i_type = vector<uchar>(2, 5);
	aux.fun = &equal;
	primOpMap["="] = aux;

	aux.r_type = 2;
	aux.i_type = vector<uchar>(2, 5);
	aux.fun = &less;
	primOpMap["<"] = aux;

	aux.r_type = 2;
	aux.i_type = vector<uchar>(1, 2);
	aux.fun = &bool_not;
	primOpMap["not"] = aux;

	aux.r_type = 2;
	aux.i_type = vector<uchar>(1, 2);
	aux.fun = &bool_and;
	primOpMap["and"] = aux;

	aux.r_type = 2;
	aux.i_type = vector<uchar>(1, 2);
	aux.fun = &bool_or;
	primOpMap["or"] = aux;

	aux.r_type = 2;
	aux.i_type = vector<uchar>(1, 2);
	aux.fun = &cond_if;
	primOpMap["if"] = aux;
}

PrimitiveOperationSpace::~PrimitiveOperationSpace() {
}

//_______ CONSULTORES

bool PrimitiveOperationSpace::exists(string key) const {
	return primOpMap.find(key) != primOpMap.end();
}

primitiveOperation PrimitiveOperationSpace::get(string key) {
	return primOpMap[key].fun;
}
