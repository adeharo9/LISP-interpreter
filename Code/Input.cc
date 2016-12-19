#include <iostream>
#include <string>
#include "Input.hh"

using namespace std;

//_______ CONSTRUCTORES

Input::Input() {
	p = 0;
}

//_______ DESTRUCTORES

Input::~Input() {
}

//_______ OPERADORES

string& Input::operator ++ () {
	return next();
}

void Input::operator --() {
	previous();
}

string& Input::operator >> (string& str) {
	str = next();
	return str;
}

void Input::operator << (string buff) {
	this -> buff = buff;
}

//_______ MODIFICADORES

string& Input::next() {
	if(buff.empty()) {
		cin >> buff;
		next();
	}
	else if(buff[0] == '(') {
		str = buff[0];
		buff.erase(0,1);
		++p;
	}
	else if(buff[0] == ')'){
		str = buff[0];
		buff.erase(0,1);
		--p;
	}
	else if(buff[0] == ' ') {
		buff.erase(0,1);
		next();
	}
	else if(buff == "****") {
		buff.swap(str);
	}
	else {
		str.clear();
		/* INVARIANTE
			'str' contiene una cadena de caracteres que va aumentando por su final
			'buff' contiene una cadena de caracteres que se va reduciendo por su inicio
		*/
		while(not buff.empty() and buff[0] != '(' and buff[0] != ')' and buff[0] != ' ') {
			str+=buff[0];
			buff.erase(0,1);
		}
	}
	return str;
}

void Input::previous() {
	if(str == "(") {
		--p;
	}
	else if(str == ")") {
		++p;
	}
	buff = str + ' ' + buff;
	str.clear();
}

string Input::nextExpression() {
	int aux = p;
	string str = next();
	/* INVARIANTE
		'str' es la porción de entrada leída desde la condición inicial p = aux hasta el estado actual de p
	*/
	while(p > aux) {
		str += ' ' + next();
	}
	return str;
}

void Input::endOfExpression() {
	/* INVARIANTE
		'p' es el número de paréntesis abiertos que quedan por cerrar en el momento de la lectura de entrada mediante el método next()
	*/
	while(p > 0) {
		next();
	}
}

//_______ CONSULTORES

int Input::get_p() const {
	return p;
}

string Input::get_buff() const {
	return buff;
}

string Input::get_str() const {
	return str;
}
