#include <iostream>
#include <map>
#include "OperationSpace.hh"

using namespace std;

//_______ MÉTODOS PRIVADOS

//(define abs (x) (x))
//(abs 1)
//CURIOSO, ESTÁ MAL

int OperationSpace::countVars(string parameters) {
	int c = not parameters.empty();
	for(int i = 1; i < parameters.size(); ++i) {
		if(parameters[i] == ' ') {
			++c;
		}
	}
	return c;
}

//_______ CONSTRUCTORES

OperationSpace::OperationSpace() {
}

//_______ DESTRUCTORES

OperationSpace::~OperationSpace() {
}

//_______ MODIFICADORES

void OperationSpace::set(string key, string parameters, string exp) {
	definition aux;
	aux.n_parameters = countVars(parameters);
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
	return opMap[key].n_parameters;
}

//_______ I/O

void OperationSpace::write() const {
	cout << "Operacions:" << endl;
	map<string, definition>::const_iterator const_it = opMap.begin();
	while(const_it != opMap.end()) {
		cout << const_it -> first << " #" << const_it -> second.n_parameters << endl;
		++const_it;
	}
}

void OperationSpace::write_op(string key) {
	cout << key << " #" << opMap[key].n_parameters << endl;
}