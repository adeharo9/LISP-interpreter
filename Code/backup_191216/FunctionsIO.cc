#include <iostream>
#include <string>
#include "FunctionsIO.hh"
#include "Environment.hh"
#include "Expression.hh"

using namespace std;


bool isNum(string str){
	string::const_iterator it = str.begin();
	if((*it) == '-'){
		it++;
		if(!isdigit(*it)){
			it--;
		}
	}
	while (it != str.end() and isdigit(*it)){
		it++;
	}
	return !str.empty() and it == str.end();
}

void getString(string& buff, string& str) {
	
	cout<<"buffer: "<< buff << "\ninstr: " << str << "\n" << endl;

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

bool read(Environment& env, Expression& exp){
	string inbuff, instr;
	bool result;

	getString(inbuff, instr);
	if(instr == "****"){
		result = false;
	}
	else if(isNum(instr)){
		cout << instr << endl;
		result = true;
	}
	else{
		
		inbuff.insert(0, instr);
		cout<<"antes de llamar readExpression"<<endl;
		result = readExpression(env, exp, inbuff);
		cout<<"despues de llamar readExpression"<<endl;
	}
	return result;
}

//pre 'env' es un entorno con un espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas; 'exp' es una expresión no vacía
//post Escribe el valor de la expresión representada por 'exp' por el canal estándar de salida
bool readExpression(Environment& env, Expression& exp, string& inbuff) {
	string instr;
	list<Expression*>::iterator it = exp.begin();
	cout<<"inicio del readExpression"<<endl;


	do{
		cout<<"inicio del while"<<endl;
		getString(inbuff, instr);

		if (instr == "("){
			cout<<"abrir parentesis"<<endl;
			Expression* pExp = new Expression;
			exp.insert(exp.end() , pExp);
			readExpression(env, *pExp, inbuff);
		
		}

		else if (instr == ")"){
			cout<<"cerrar parentesis"<<endl; 
			evaluate(exp, env);
			cout<<"evaluate"<<endl;
			cout<< exp.get_value() << endl;

		}

		else if (isNum(instr)){
			cout<<"es numero"<<endl;
			Expression* numExp = new Expression;
			int num = stoi(instr);
			(*numExp).set_value(num);
			exp.insert(exp.end(), numExp);  /* Insert es con iterador no con el valor directamente */
			
		}

		else if(env.exists_var(instr)){
			cout<<"exit var"<<endl;
			Expression* pExp = new Expression;
			*pExp = env.get_var(instr);
			exp.insert(exp.end() , pExp);
			
		}

		else if (instr == "define"){  //verifica si existe este valor como operador, variable u otro, si no es asi lo crea con el valor
			cout<<"define"<<endl;
			define(instr, env);
		}

		else if (env.is_op(instr)){  // verifica que instr sea una operacion definida por el usuario o de las primitivas, en el caso de acierto terminamos de leer de forma recursiva y evaluamos.
			cout<<"is operator"<<endl;
			exp.set_op(instr);
			
		}
	}while( instr!= ")");

	return true;
}		

void writeExpression(const Expression& exp) {
	
	if(exp.is_value()){
		cout << exp.get_value() << endl;
		cout<<"Imprimir valor"<<endl;
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
		cout<<"Imprimir lista"<<endl;
	}
}

void evaluate(Expression& exp, Environment& env){

	if(env.is_primitive(exp.get_op())){
		env.get_prim(exp.get_op())(exp); //llama a la funcion primitiva con la 'key' (exp.get_op()) a esta funcion se le envia el parametro exp
		cout<<"is primitive"<<endl;
	}
	else if(env.is_op(exp.get_op())) {
		pair<string, string> paramExp;
		Environment envcopy(env);
		envcopy.erase_varspace();
		paramExp = envcopy.get_op(exp.get_op()); 
		list<Expression*>::const_iterator itlist = exp.begin();
		string instr;
		

		while(!paramExp.first.empty() and itlist != exp.end()){
			getString(paramExp.first, instr);
			envcopy.set_var(instr, *(*itlist));
		}
		
		readExpression(envcopy, exp, paramExp.second);
	}
}

void define(string Ininstrn, Environment& env){
	int parentesis, instructionBlock;
	string inbuff, instr, definition;
	parentesis = instructionBlock = 0;
	Expression exp;

	while(parentesis >= 0){
		getString(Ininstrn, instr);
		definition += instr + ' ';
		if(instr == "("){
			parentesis++;
		}else if(instr == ")"){
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

		readExpression(env, exp, definition);
		
		if(!exp.undefined()){
			env.set_var(variable, exp);
		}
		cout << definition << " " << endl;

	} else {
		// definir expresion
		string operador, paremterslist;
		getString(definition, instr);
		operador = instr;
		int count = 0;

		while(instr != ")"){
			getString(definition, instr);
			paremterslist+= instr + ' ';
			count++;
		}

		cout << operador;

		if(count > 1){
			cout << "*" << count;
		}
	}
}
