#include <iostream>
#include <map>
#include "VariableSpace.hh"
#include "Expression.hh"

using namespace std;

//_______ CONSTRUCTORES

VariableSpace::VariableSpace() {
}

VariableSpace::VariableSpace(string key, const Expression& exp) {
	varMap[key] = exp;
}

VariableSpace::VariableSpace(const VariableSpace& varSpace) {
	varMap = varSpace.varMap;
}

//_______ DESTRUCTORES

VariableSpace::~VariableSpace() {
}

//_______ MODIFICADORES

void VariableSpace::add(string key, const Expression& exp) {
	varMap[key] = exp;
}

void VariableSpace::update(string key, const Expression& exp) {
	varMap[key] = exp;
}

//_______ CONSULTORES

bool VariableSpace::exists(string key) const {
	return varMap.find(key) != varMap.end();
}

Expression VariableSpace::get(string key) {
	return varMap[key];
}

//_______ I/O

void VariableSpace::write() const {
	cout << "Variables:" << endl;
	map<string, Expression>::const_iterator const_it = varMap.begin();
	while(const_it != varMap.end()) {
		cout << const_it->first << " ";
		const_it->second.write();
		++const_it;
	}
}

void VariableSpace::write_var(string key) {
	cout << key << " ";
	varMap[key].write();
}