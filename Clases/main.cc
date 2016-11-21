/**
	* @mainpage PRO2 - Práctica QT16-17: Calculadora de expresiones aritméticas
 
	Este programa constituye una calculadora de expresiones aritméticas usando un lenguaje de tipo LISP

	Se introducen las clases <em>Expression</em>, <em>Environment</em>, <em>PrimitiveOperationSpace</em>, <em>VariableSpace</em>, <em>OperationSpace</em>
*/

/** @file main.cc
    @brief Programa principal para la calculadora de expresiones aritméticas
*/

#ifndef NO_DIAGRAM
#include <iostream>
#include "FunctionsIO.hh"
#endif

#include "Environment.hh"
#include "Expression.hh"

using namespace std;

/** @brief Programa principal para la calculadora de expresiones aritméticas
*/

int main(){
	Environment env;
	Expression exp;
	while(readExpression(env,exp)){
		writeExpression(env,exp);
		exp.clear();
	}
	env.write();
}
