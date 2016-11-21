/**
	* @mainpage PRO2 - Práctica QT16-17: Calculadora de expresiones aritméticas
 
	Este programa constituye una calculadora de expresiones aritméticas usando un lenguaje de tipo LISP

	Se introducen las clases <em>Environment</em>, <em>Expression.hh</em>,
	<em>PrimitiveOperationSpace</em>, <em>VariableSpace</em>,
	<em>OperationSpace</em> y <em>Expression</em>
*/

/** @file main.cc
    @brief Programa principal para la calculadora de expresiones aritméticas
*/

#include <iostream>
#include "Environment.hh"
#include "Expression.hh"

#ifndef NO_DIAGRAM

#include "FunctionsIO.hh"

#endif

using namespace std;

/** @brief Programa principal para la calculadora de expresiones aritméticas
*/

int main(){
	Environment env;
	Expression exp;
	while(readExpression(env,exp)){
		writeExpression(env,exp);
	}
	env.write_env();
}
