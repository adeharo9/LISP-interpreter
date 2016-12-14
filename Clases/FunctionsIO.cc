#include <iostream>
#include <string>
#include "FunctionsIO.hh"
#include "Environment.hh"
#include "Expression.hh"

using namespace std;

/*bool isNum(string str) {
	int i = 0;
	if(not str.empty() and (str[i] == '-' or (str[i] >= '0' and str[i] <= '9'))) {
			++i;
		while(i < str.size() and str[i] >= '0' and str[i] <= '9') {
			++i;
		}
	}
	return not str.empty() and i == str.size();
}
*/

bool isNum(string str) {
	string::cons_iteratior it = str.begin();
	(*it == '-') ? it++;
	while (it != str.end() and isdigit(*it)){
		it++;
	}
	return !str.empty() and *it == str.end();
}

void getString(string& buff, string& str) {
	if(buff.empty()) {
		cin >> buff;
		getString(buff, str);
	}
	else if(buff[0] == '(') {
		str = buff[0];
		buff.erase(0,1); // borrar desde la posicion 0 hasta la posicion 1 del string
	}
	else if(buff[0] == ')'){
		str = buff[0];
		buff.erase(0,1);
	}
	else if(buff[0] == ' ') {
		buff.erase(0,1);
		getString(buff, str);
	}
	else if(buff == '****') {
		buff.swap(str);
	}
	else {
		str.clear();
		while(not buff.empty() and buff[0] != '(' and buff[0] != ')' and buff[0] != ' ') {
			str+=buff[0];
			buff.erase(0,1);
		}
	}
}

bool read(Environment& env, Expression& exp){
	string inbuff, instr;

	getString(inbuff, instr);
	if(instr == "****"){
		return false;
	}
	else if(isNum(instr)){
		cout >> instr >> endl;
	}
	else{
		readExpression(env, exp, inbuff);
	}
	
}

//pre 'env' es un entorno con un espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas; 'exp' es una expresión no vacía
//post Escribe el valor de la expresión representada por 'exp' por el canal estándar de salida
bool readExpression(Environment& env, Expression& exp, String buff) {

	string instr;
	bool fin = false;
	int parentesis;
	parentesis = 0;
		


	do{
		getString(inbuff, instr);

		if (instr == '('){
			parentesis++;
			readExpression(env, exp, inbuff);
		}
		else if (instr == ')'){
			parentesis--; 
			if(parentesis < 0 ){
				//EXCEPTION --------------------------------
			}
		}
		else if (isNum(instr)){
			exp.insert(exp.end(), instr);
			 /*añade el valor numerico o el valor de una variable a la lista de valores lExp */
		}
		else if(env.exists_var(instr)){
			Expression* pExp = new Expression;
			*pExp = env.get_var(instr);
			exp.insert(exp.end() , pExp);
		}
		else if (instr == 'define'){  //verifica si existe este valor como operador, variable u otro, si no es asi lo crea con el valor
			
			define(instr);

		}
		else if (env.is_op(instr)){  // verifica que instr sea una operacion definida por el usuario o de las primitivas, en el caso de acierto terminamos de leer de forma recursiva y evaluamos.
			exp.set_op(instr);
			readExpression(env, exp, inbuff);

		}
	} while(parentesis != ')');

	evaluate(exp);

	return true;

}		

void writeExpression(const Environment& env, const Expression& exp) {
	
	if(exp.is_value()){
		cout << exp.get_value() << endl;
	}
	else if(exp.is_list()){
		cout << '(';
		list<Expression*>::const_iterator it = exp.begin(); 
		if (!exp.is_empty_list()){
			cout << (*it)->get_value();
			while( it != exp.end()){  //verificar declaracion de iterador end y const end?? cual es al que se esta llamando
				cout  << ' '; 
				cout << (*it)->get_value();
				++it;
			}
		}

		cout << ')' << endl;
	}
}

void evaluate(Expression& exp){

	
	if(env.is_primitive(exp.get_op)){
		env.get_prim(exp.get_op())(exp); //llama a la funcion primitiva con la 'key' (exp.get_op()) a esta funcion se le envia el parametro exp
	}
	else if(env.is_op(exp.get_op)) {
		env.get_op(exp.get_op())(exp); //llama a la opracion definida por el usuario con la 'key' (exp.get_op()) a esta funcion se le envia el parametro exp, retorna el resultado en la misma exp
	}
}

void define(string Ininstr){
	int parentesis, instructionBlock;
	string inbuff, instr, definition;
	parentesis = instructionBlock = 0;
	Expression exp;

	while(parentesis >= 0){
		getString(inbuff, instr)
		definition += instr + ' ';
		if(instr == '('){
			parentesis++;
		}else if(instr == ')'){
			parentesis--;
			if (parentesis == 0){
				instructionBlock++;
			}
		}
	}
	if(instructionBlock <= 1){
		// definir variable
		string variable;
		getString(definition, instr);
		variable = instr;
		readExpression(env, exp, definition) {
		env.set_var(variable, exp);

	} else {
		// definir expresion

	}
}



/*Funciones a crear ------------------------------*/

/*
 add_value
añade un avalor a una lista de valores de la clase expresion

evaluate_op
evalua la operacion con sus operandos

