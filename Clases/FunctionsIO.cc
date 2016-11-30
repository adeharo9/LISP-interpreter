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



bool readExpression(Environment& env, Expression& exp) {

	string inbuff, instr;
	bool fin = false;
	int parentesispaertura, parentesiscerrar;
	parentesispaertura = parentesiscerrar = 0;
	
	while( !fin or instr != ')'){
		cin >> instr;
		getString(inbuff, instr);

		if (instr = '('){
			parentesispaertura++;	
		} else if (instr = '('){
			parentesiscerrar++;
		} else if (instr = '****'){
			fin = true;
		} else if (isNum(instr)){
			add_value(instr); /*añade el valor a la lista de valores de la variable expresion */
		} else if (exist_var(instr)){
			add_value(get_var(instr));
		} else if (exist_op(instr)){
			set_op(instr);
		}

	}

}

void writeExpression(const Environment& env, const Expression& exp) {

}
