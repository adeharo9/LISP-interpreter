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
		buff.erase(0,1);
	}
	else if(buff[0] == ')'){
		str = buff[0];
		buff.erase(0,1);
	}
	else if(buff[0] == ' ') {
		buff.erase(0,1);
		getString(buff, str);
	}
	else if(buff == "****") {
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


//pre 'env' es un entorno con un espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas; 'exp' es una expresión no vacía
//post Escribe el valor de la expresión representada por 'exp' por el canal estándar de salida
bool readExpression(Environment& env, Expression& exp) {

	string inbuff, instr;
	bool fin = false;
	int parentesis;
	parentesis = 0;
	
	do{
		cin >> instr;
		getString(inbuff, instr);

		if (instr = '('){
			parentesis++;	
		}
		else if (instr = ')'){
			parentesis--; 

			if(parentesis < 0 ){
				//EXCEPTION --------------------------------
			}

		}
		else if (instr = '****'){
			fin = true;
			return false;
		}
		else if (isNum(instr) or env.exists_var(instr)){
			(isNum(instr)) ? exp.add_value(instr); : exp.add_value(env.get_var(instr));
			 /*añade el valor numerico o el valor de una variable a la lista de valores lExp */
		}
		else if (!env.exists(instr)){  //verifica si existe este valor como operador, variable u otro, si no es asi lo crea con el valor
			
			is_new_var = true;   // necesito un booleano para saber si se hico la definicion de una variable, para utilizarla a la hora de imprimir
			readExpression(env, inbuff);						
			env.add_var(instr, exp);

		}
		else if (env.is_op(instr)){  // verifica que instr sea una operacion definida por el usuario o de las primitivas, en el caso de acierto terminamos de leer de forma recursiva y evaluamos.
			exp.set_op(instr);
			readExpression(env, inbuff);

		}
	} while(parentesis != ')');

	evaluate(exp);

	return true;

}		

void writeExpression(const Environment& env, const Expression& exp) {

	if (){

	}
	else if(exp.is_value()){
		cout << exp.get_value();
	}
	else if(exp.is_list()){
		cout << '(';
		while( it != exp.end()){  //verificar declaracion de iterador end y const end?? cual es al que se esta llamando
			cout << (*it).get_value() << ' ' ;
			++it;
		}
		cout << ')' << endl;
		
	}
	else if(exp.is_bool()){
		
	}
	else if(exp.undefined()){
		
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


/*Funciones a crear ------------------------------*/

/*
 add_value
añade un avalor a una lista de valores de la clase expresion

evaluate_op
evalua la operacion con sus operandos
