#include <iostream>
#include "Environment.hh"
#include "Expression.hh"
#include "PrimitiveOperationSpace.hh"
#include "VariableSpace.hh"
#include "OperationSpace.hh"

using namespace std;

typedef void (*primitiveOperation)(Expression&);

//_______ CONSTRUCTORES

Environment::Environment() {
}

//_______ DESTRUCTORES

Environment::~Environment() {
}

//_______ MODIFICADORES

void Environment::add_var(string key, const Expression& exp) {
	varSpace.add(key, exp);
}

void Environment::add_op(string key, string parameters, string exp) {
	opSpace.add(key, parameters, exp);
}

void Environment::update_var(string key, const Expression& exp) {
	varSpace.update(key, exp);
}

void Environment::update_op(string key, string parameters, string exp) {
	opSpace.update(key, parameters, exp);
}

//_______ CONSULTORES

bool Environment::is_primitive(string key) const {
	return primOpSpace.exists(key);
}

bool Environment::is_op(string key) const {
	return primOpSpace.exists(key) or opSpace.exists(key);
}

bool Environment::exists(string key) const {
	return primOpSpace.exists(key) or varSpace.exists(key) or opSpace.exists(key);
}

bool Environment::exists_var(string key) const {
	return varSpace.exists(key);
}

bool Environment::exists_op(string key) const {
	return opSpace.exists(key);
}

primitiveOperation Environment::get_prim(string key) {
	return primOpSpace.get(key);
}

Expression Environment::get_var(string key) {
	return varSpace.get(key);
}

pair<string, string> Environment::get_op(string key) {
	return opSpace.get(key);
}

//_______ I/O

void Environment::write() const {
	if(not varSpace.empty()) {
		varSpace.write();
	}
	if(not opSpace.empty()) {
		opSpace.write();
	}
}

void Environment::write_var(string key) {
	varSpace.write_var(key);
}

void Environment::write_op(string key) {
	opSpace.write_op(key);
}