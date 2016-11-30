#include <iostream>
#include <string>
#include "FunctionsIO.hh"
#include "Environment.hh"
#include "Expression.hh"

using namespace std;

bool isNum(string str) {
	int i = 0;
	if(not str.empty() and (str[i] == '-' or (str[i] >= '0' and str[i] <= '9'))) {
			++i;
		while(i < str.size() and str[i] >= '0' and str[i] <= '9') {
			++i;
		}
	}
	return not str.empty() and i == str.size();
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

}

void writeExpression(const Environment& env, const Expression& exp) {

}
