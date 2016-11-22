#include <iostream>
#include <map>
#include "VariableSpace.hh"
#include "Expression.hh"

using namespace std;

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
	map<string, Expression>::const_iterator const_it = varMap.find(key);
	return const_it != varMap.end();
}

Expression VariableSpace::retrieve(string key) const {
	return varMap[key];
}

//_______ I/O

void VariableSpace::write() const {
	map<string, Expression>::const_iterator const_it = varMap.begin();
	while(const_it != varMap.end()){
		cout << const_it->first << " ";
		const_it->second.write();
		++const_it;
	}
	cout<<endl;
}

void VariableSpace::write_var(string key) const {
	cout << key << " ";
	varMap[key].write();
}