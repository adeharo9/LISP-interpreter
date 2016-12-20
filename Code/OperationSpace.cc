/** @file OperationSpace.cc
    @brief Implementación de la clase OperationSpace
*/

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif

#include "OperationSpace.hh"

using namespace std;

//_______ MÉTODOS PRIVADOS

int OperationSpace::count_vars(string parameters)
{
	int c = not parameters.empty();
	/* INV
		c es el número de parámetros que hay contenidos en el string 'parameters' en el rango de posiciones [0...i]
	*/
	for(int i = 1; i < parameters.size(); ++i) {
		if(parameters[i] == ' ') {
			++c;
		}
	}
	return c;
}

//_______ CONSTRUCTORES

OperationSpace::OperationSpace()
{
}

//_______ DESTRUCTORES

OperationSpace::~OperationSpace()
{
}

//_______ MODIFICADORES

void OperationSpace::set(string key, string parameters, string exp)
{
	definition aux;
	aux.n_parameters = count_vars(parameters);
	aux.parameters = parameters;
	aux.exp = exp;
	opMap[key] = aux;
}

//_______ CONSULTORES

bool OperationSpace::empty() const
{
	return opMap.empty();
}

bool OperationSpace::exists(string key) const
{
	return opMap.find(key) != opMap.end();
}

pair<string, string> OperationSpace::get(string key)
{
	definition aux = opMap[key];
	return make_pair(aux.parameters, aux.exp);
}

int OperationSpace::num_pars(string key)
{
	return opMap[key].n_parameters;
}

//_______ I/O

void OperationSpace::write() const
{
	cout << "Operacions:" << endl;
	map<string, definition>::const_iterator c_it = opMap.begin();
	/* INV
		c_it es un iterador a un elemento del mapa de operaciones definidas por el usuario del parámetro implícito comprendido entre opMap.begin() y opMap.end()
	*/
	while(c_it != opMap.end()) {
		cout << c_it -> first << " #" << c_it -> second.n_parameters << endl;
		++c_it;
	}
}

void OperationSpace::write_op(string key)
{
	cout << key << " #" << opMap[key].n_parameters << endl;
}