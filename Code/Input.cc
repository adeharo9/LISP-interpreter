#include <iostream>
#include <string>
#include "Input.hh"

using namespace std;

//_______ CONSTRUCTORES

Input::Input()
{
	p = 0;
}

//_______ DESTRUCTORES

Input::~Input()
{
}

//_______ OPERADORES

string& Input::operator ++ ()
{
	return next();
}

void Input::operator --()
{
	previous();
}

string& Input::operator >> (string& str)
{
	str = next();
	return str;
}

void Input::operator << (string buff)
{
	this -> buff = buff;
}

//_______ MODIFICADORES

string& Input::next()
{
	if(buff.empty()) {
		cin >> buff;
		/* HI
			next() procesa el siguiente elemento de entrada, colocando la parte que debe ser tratada inmediatamente en 'str' y dejando el resto para su tratamiento posterior en 'buff', manteniendo el contador de paréntesis correctamente actualizado
		*/
		next();
	}
	else if(buff[0] == '(') {
		str = buff[0];
		buff.erase(0,1);
		++p;
	}
	else if(buff[0] == ')') {
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
		/* INV
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

void Input::previous()
{
	if(str == "(") {
		--p;
	}
	else if(str == ")") {
		++p;
	}
	buff = str + ' ' + buff;
	str.clear();
}

string Input::nextExpression()
{
	int aux = p;
	string auxStr = next();
	/* INV
		'auxStr' es la porción de entrada leída desde la condición inicial p = aux hasta el estado actual de 'p'
	*/
	while(p > aux) {
		auxStr += ' ' + next();
	}
	return auxStr;
}

void Input::endOfExpression()
{
	/* INV
		'p' es el número de paréntesis abiertos que quedan por cerrar en el momento de la lectura de entrada mediante el método next()
	*/
	while(p > 0) {
		next();
	}
}

int Input::countExpressions()
{
	int c = 0;
	int aux = p;
	next();
	/* INV
		'c' es la cantidad de expresiones que hay contenidas en la entrada desde p = aux hasta la iteración actual
	*/
	while(str != ")") {
		if(str != "(") {
			++c;
		}
		else {
			/* INV
				'p' es el número de paréntesis abiertos que quedan por cerrar en el momento de la lectura de entrada mediante el método next()
			*/
			do {
				next();
			} while(p > aux);
			++c;
		}
		next();
	}
	return c;
}

//_______ CONSULTORES

int Input::get_p() const
{
	return p;
}

string Input::get_buff() const
{
	return buff;
}

string Input::get_str() const
{
	return str;
}
