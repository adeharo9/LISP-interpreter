#include <iostream>
#include <map>
#include "VariableSpace.hh"
#include "Expression.hh"

using namespace std;

//_______ CONSTRUCTORES

VariableSpace::VariableSpace() {
}

VariableSpace::VariableSpace(const VariableSpace& varSpace) {
	varMap = varSpace.varMap;
}

//_______ DESTRUCTORES

VariableSpace::~VariableSpace() {
}

//_______ MODIFICADORES

void VariableSpace::clear() {
	varMap.clear();
}

void VariableSpace::set(string key, const Expression& exp) {
	varMap[key] = exp;
}

//_______ CONSULTORES

bool VariableSpace::empty() const {
	return varMap.empty();
}

bool VariableSpace::exists(string key) const {
	return varMap.find(key) != varMap.end();
}

Expression& VariableSpace::get(string key) {
	return varMap[key];
}

//_______ I/O

void VariableSpace::write() const {
	cout << "Variables:" << endl;
	map<string, Expression>::const_iterator c_it = varMap.begin();
	while(c_it != varMap.end()) {
		cout << c_it -> first << " ";
		c_it -> second.write();
		++c_it;
	}
}

void VariableSpace::write_var(string key) {
	cout << key << " ";
	varMap[key].write();
}
