#include <map>
#include <list>
#include "PrimitiveOperationSpace.hh"
#include "Expression.hh"

using namespace std;

typedef void (*primitiveOperation)(Expression&);

//_______ MÉTODOS PRIVADOS

void PrimitiveOperationSpace::sum(Expression& exp) {
	if(exp.is_op() and exp.size() == 2) {
		if((*exp.begin())->is_value() and (*exp.second())->is_value()) {
			exp.set_value(((*exp.begin())->get_value()) + ((*exp.second())->get_value()));
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
		if((*exp.begin())->is_value()) {
			exp.set_value(-1 * ((*exp.begin())->get_value()));
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
		if((*exp.begin())->is_value() and (*exp.second())->is_list()) {
			list<Expression*> aux = (*exp.second())->get_list();
			exp.splice(exp.second(),aux);
			exp.erase(--exp.end());
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
		if((*exp.begin())->is_list()) {
			exp = *(*((*exp.begin())->begin()));
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
		if((*exp.begin())->is_list()) {
			(*exp.begin())->erase((*exp.begin())->begin());
			exp = *(*exp.begin());
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
		if((*exp.begin())->undefined() or (*exp.second())->undefined()) {
			exp.set_undefined();
		}
		else {
			exp.set_value(*(*exp.begin()) == *(*exp.second()));
		}
	}
	else {
		exp.set_undefined();
	}
}

void PrimitiveOperationSpace::less(Expression& exp) {
	if(exp.is_op() and exp.size() == 2) {
		if((*exp.begin())->undefined() or (*exp.second())->undefined()) {
			exp.set_undefined();
		}
		else {
			exp.set_value(*(*exp.begin()) < *(*exp.second()));
		}
	}
	else {
		exp.set_undefined();
	}
}

void PrimitiveOperationSpace::bool_not(Expression& exp) {
	if(exp.is_op() and exp.size() == 1) {
		if((*exp.begin())->is_bool()) {
			exp.set_value((*exp.begin())->get_value() == 0);
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
		if((*exp.begin())->is_bool() and (*exp.second())->is_bool()) {
			exp.set_value(((*exp.begin())->get_value() == 1) and ((*exp.second())->get_value() == 1));
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
		if((*exp.begin())->is_bool() and (*exp.second())->is_bool()) {
			exp.set_value(((*exp.begin())->get_value() == 1) or ((*exp.second())->get_value() == 1));
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
	if(exp.is_op() and exp.size() == 3) {
		if((*exp.begin())->is_bool()) {
			if((*exp.begin())->get_value() == 1) {
				exp = *(*exp.second());
			}
			else {
				exp = *(*exp.third());
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

//_______ CONSTRUCTORES

PrimitiveOperationSpace::PrimitiveOperationSpace() {
	primOpMap["+"] = &sum;
	primOpMap["-"] = &neg;
	primOpMap["cons"] = &cons;
	primOpMap["head"] = &head;
	primOpMap["tail"] = &tail;
	primOpMap["="] = &equal;
	primOpMap["<"] = &less;
	primOpMap["not"] = &bool_not;
	primOpMap["and"] = &bool_and;
	primOpMap["or"] = &bool_or;
	primOpMap["if"] = &cond_if;
}

PrimitiveOperationSpace::~PrimitiveOperationSpace() {
}

//_______ CONSULTORES

bool PrimitiveOperationSpace::exists(string key) const {
	return primOpMap.find(key) != primOpMap.end();
}

primitiveOperation PrimitiveOperationSpace::get(string key) {
	return primOpMap[key];
}
