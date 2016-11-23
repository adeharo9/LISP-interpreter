#include <iostream>
#include "Environment.hh"

using namespace std;

//_______ CONSTRUCTORES

Environment::Environment() {
}

//_______ DESTRUCTORES

Environment::~Environment() {
}

//_______ MODIFICADORES

void Environment::add_var(string key, const Expression& exp) {
	varSpace.add(key,exp);
}

void Environment::add_op(string key, string parameters, string exp) {
	opSpace.add(key,parameters,exp);
}

void Environment::update_var(string key, const Expression& exp) {
	varSpace.update(key,exp);
}

void Environment::update_op(string key, string parameters, string exp) {
	opSpace.update(key,parameters,exp);
}

//_______ CONSULTORES

bool Environment::is_primitive(string key) const {
	return primOpSpace.exists(key);
}

bool Environment::exists_var(string key) const {
	return varSpace.exists(key);
}

bool Environment::exists_op(string key) const {
	return opSpace.exists(key);
}

primitiveOperation Environment::retrieve_prim(string key) const {
	return primOpSpace.retrieve(key);
}

Expression Environment::retrieve_var(string key) const {
	return varSpace.retrieve(key);
}

pair<string, string> Environment::retrieve_op(string key) const {
	return opSpace.retrieve(key);
}

//_______ I/O

void Environment::write() const {
	varSpace.write();
	opSpace.write();
}

void Environment::write_var(string key) const {
	varSpace.write_var(key);
}

void Environment::write_op(string key) const {
	opSpace.write_op(key);
}