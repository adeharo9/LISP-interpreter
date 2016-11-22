#include <map>
#include "PrimitiveOperationSpace.hh"
#include "Expression.hh"

using namespace std;

//_______ MÉTODOS PRIVADOS

Expression PrimitiveOperationSpace::sum(const Expression& exp) {
	Expression aux(0);
	list<Expression*>::const_iterator const_it= exp.begin();
	while(const_it != exp.end() and not const_it->undefined()){
		aux.add_value(const_it->get_value());
		++const_it;
	}
	if(const_it->undefined()){
		aux.set_undefined();
	}
	return aux;
}

Expression PrimitiveOperationSpace::neg(const Expression& exp) {

}

Expression PrimitiveOperationSpace::cons(const Expression& exp) {

}

Expression PrimitiveOperationSpace::head(const Expression& exp) {

}

Expression PrimitiveOperationSpace::tail(const Expression& exp) {

}

Expression PrimitiveOperationSpace::equal(const Expression& exp) {

}

Expression PrimitiveOperationSpace::less(const Expression& exp) {

}

Expression PrimitiveOperationSpace::bool_not(const Expression& exp) {

}

Expression PrimitiveOperationSpace::bool_and(const Expression& exp) {

}

Expression PrimitiveOperationSpace::bool_or(const Expression& exp) {

}

Expression PrimitiveOperationSpace::cond_if(const Expression& exp) {

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

primitiveOperation PrimitiveOperationSpace::retrieve(string key) const {
	return primOpMap[key];
}
