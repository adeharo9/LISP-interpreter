#include <map>
#include "PrimitiveOperationSpace.hh"
#include "Expression.hh"

using namespace std;

//_______ MÉTODOS PRIVADOS

void PrimitiveOperationSpace::sum(Expression& exp) {
	if(exp.size() != 2) {
		exp.set_undefined();
	}
	else {
		int sum=0;
		list<Expression*>::iterator it = exp.begin();
		while(it != exp.end() and *it->is_value()) {
			sum += *it->get_value();
			++it;
		}
		if(it == exp.end()) {
			exp.set_value(sum);
		}
		else{
			exp.set_undefined();
		}
	}
}

void PrimitiveOperationSpace::neg(Expression& exp) {
	if(exp.is_value()){
		exp.set_value(-1*exp.get_value());
	}
	else{
		aux.set_undefined();
	}
}

void PrimitiveOperationSpace::cons(Expression& exp) {
	if(exp.size() != 2){
		exp.set_undefined();
	}
	else{

	}
}

void PrimitiveOperationSpace::head(Expression& exp) {
	if(exp.is_list()){
		exp = *(*exp.begin());
	}
	else{
		exp.set_undefined();
	}
}

void PrimitiveOperationSpace::tail(Expression& exp) {
	if(exp.is_list()){
		exp.erase(exp.begin());
	}
	else{
		exp.set_undefined();
	}
}

void PrimitiveOperationSpace::equal(Expression& exp) {

}

void PrimitiveOperationSpace::less(Expression& exp) {

}

void PrimitiveOperationSpace::bool_not(Expression& exp) {

}

void PrimitiveOperationSpace::bool_and(Expression& exp) {

}

void PrimitiveOperationSpace::bool_or(Expression& exp) {

}

void PrimitiveOperationSpace::cond_if(Expression& exp) {

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

primitiveOperation PrimitiveOperationSpace::retrieve(string key) const {
	return primOpMap[key];
}
