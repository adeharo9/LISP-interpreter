#include <iostream>
#include <map>
#include "OperationSpace.hh"

using namespace std;

//_______ MÉTODOS PRIVADOS

int OperationSpace::countVars(string parameters) {
	// ACABAR
	int c = 0;
	
	return c;
}

//_______ CONSTRUCTORES

OperationSpace::OperationSpace() {
}

OperationSpace::OperationSpace(string key, string parameters, string exp) {
	definition aux;
	aux.parameters = parameters;
	aux.exp = exp;
	opMap[key] = aux;
}

OperationSpace::OperationSpace(const OperationSpace& opSpace) {
	opMap = opSpace.opMap;
}

//_______ DESTRUCTORES

OperationSpace::~OperationSpace() {
}

//_______ MODIFICADORES

void OperationSpace::add(string key, string parameters, string exp) {
	definition aux;
	aux.parameters = parameters;
	aux.exp = exp;
	opMap[key] = aux;
}

void OperationSpace::update(string key, string parameters, string exp) {
	definition aux;
	aux.parameters = parameters;
	aux.exp = exp;
	opMap[key] = aux;
}

//_______ CONSULTORES

bool OperationSpace::exists(string key) const {
	return opMap.find(key) != opMap.end();
}

pair<string, string> OperationSpace::get(string key) {
	definition aux = opMap[key];
	return make_pair(aux.parameters, aux.exp);
}

//_______ I/O

void OperationSpace::write() const {
	cout << "Operacions:" << endl;
	map<string, definition>::const_iterator const_it = opMap.begin();
	while(const_it != opMap.end()) {
		cout << const_it->first << " #" << countVars(const_it->second.parameters) << endl;
		++const_it;
	}
}

void OperationSpace::write_op(string key) {
	cout << key << " #" << countVars(opMap[key].parameters) << endl;
}