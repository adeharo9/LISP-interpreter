#include <iostream>
#include <map>
#include "OperationSpace.hh"

using namespace std;

//_______ MÉTODOS PRIVADOS

int OperationSpace::countVars(string parameters) {
	if(parameters.empty()) {
		return 0;
	}
	else {
		int c = 1;
		int i = 0;
		while(i < parameters.size()) {
			if(parameters[i] == ' ') {
				++c;
			}
			++i;
		}
		return c;
	}
}

//_______ CONSTRUCTORES

OperationSpace::OperationSpace() {
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

//_______ CONSULTORES

bool OperationSpace::empty() const {
	return opMap.empty();
}

bool OperationSpace::exists(string key) const {
	return opMap.find(key) != opMap.end();
}

pair<string, string> OperationSpace::get(string key) {
	definition aux = opMap[key];
	return make_pair(aux.parameters, aux.exp);
}

int OperationSpace::num_pars(string key) {
	return countVars(opMap[key].parameters);
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