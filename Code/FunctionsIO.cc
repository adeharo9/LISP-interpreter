#include <iostream>
#include <string>
#include "FunctionsIO.hh"
#include "Input.hh"
#include "Environment.hh"
#include "Expression.hh"

using namespace std;

typedef list<Expression*>::const_iterator const_iter;

bool is_num(string str) {
	int i = 0;
	if(not str.empty() and (str[0] == '-' or (str[0] >= '0' and str[i] <= '9'))) {
			++i;
		while(i < str.size() and str[i] >= '0' and str[i] <= '9') {
			++i;
		}
	}
	return not str.empty() and i == str.size() and str[i-1] != '-';
}

bool is_valid(Environment& env, string str) {
	return str == "(" or str == ")" or is_num(str) or env.exists(str);
}

void createLocalVarSpace(Environment& env, Expression& exp, string parameters) {
	Input in;
	in << parameters;
	for(const_iter c_it = exp.begin(); c_it != exp.end(); ++c_it) {
		env.set_var(++in, *(*c_it));
	}
}

void evaluate(Environment& env, Expression& exp) {
	if(exp.is_op()){
		if(env.is_primitive(exp.get_op())) {
			env.get_prim(exp.get_op())(exp);
		}
		else if(env.exists_op(exp.get_op())) {
			string parameters = env.get_op(exp.get_op()).first;
			string express = env.get_op(exp.get_op()).second;
			Environment lEnv(env);
			lEnv.erase_varspace();
			if(exp.size() == env.num_pars_op(exp.get_op())){
				createLocalVarSpace(lEnv, exp, parameters);
				Input in;
				in << express;
				++in;
				exp.clear();
				readExpression(lEnv, exp, in);
			}
			else {
				exp.set_undefined();
			}
		}
	}
	else if(exp.is_list()) {
		const_iter c_it = exp.begin();
		while(c_it != exp.end() and (*c_it) -> is_value()) {
			++c_it;
		}
		if(c_it != exp.end()) {
			exp.set_undefined();
		}
	}
}

void readList(Environment& env, Expression& exp, Input& in) {
	if(in.get_str() != ")") {
		Expression* pExp;
		do {
			pExp = new Expression;
			readExpression(env, *pExp, in);
			exp.insert(exp.end(), pExp);
		} while(++in != ")" and not pExp -> undefined());
		if(pExp -> undefined()) {
			exp.set_undefined();
		}
		else {
			exp.set_list();
		}
	}
	else {
		exp.set_empty_list();
	}
}

bool check(Environment& env, Input& in) {
	while(is_valid(env, ++in) and in.get_p() > 0);
	return is_valid(env, in.get_str()) and in.get_p() == 0;
}

void readIf(Environment& env, Expression& exp, Input& in) {
	string str;
	Expression* pExp = new Expression;
	readExpression(env, *pExp, in);
	exp.insert(exp.end(), pExp);
	if(pExp -> is_bool() and ++in != ")"){
		int b = pExp -> get_value();
		if(b == 0) {
			--in;
			string aux = in.nextExpression();
			Input auxIn;
			auxIn << aux;
			if(not check(env, auxIn)) {
				exp.set_undefined();
			}
			else {
				++in;
			}
		}
		if(in.get_p() > 0 and not exp.undefined()) {
			pExp = new Expression;
			readExpression(env, *pExp, in);
			exp.insert(exp.end(), pExp);
			if(pExp -> undefined() or (b == 1 and ++in == ")")) {
				exp.set_undefined();
			}
			else if(b == 1) {
				--in;
				string aux = in.nextExpression();
				Input auxIn;
				auxIn << aux;
				if(not check(env, auxIn)) {
					exp.set_undefined();
				}
			}
			if(not exp.undefined() and  ++in != ")") {
				exp.set_undefined();
			}
		}
		else {
			exp.set_undefined();
		}
	}
	else {
		exp.set_undefined();
	}
}

void readOp(Environment& env, Expression& exp, Input& in) {
	exp.set_op(in.get_str());
	++in;
	if(exp.get_op() == "if") {
		readIf(env, exp, in);
	}
	else {
		Expression aux;
		readList(env, aux, in);
		if(aux.undefined()) {
			exp.set_undefined();
		}
		else {
			exp.swap_list(aux);
		}
	}
}

void defineVar(Environment& env, string key, Input& in) {
	Expression exp;
	readExpression(env, exp, in);
	if(not exp.undefined()) {
		env.set_var(key, exp);
		env.write_var(key);
	}
	else {
		cout << key << " " << "indefinit" << endl;
	}
}

void defineOp(Environment& env, string key, string parameters, Input& in) {
	--in;
	//string exp = ;
	env.set_op(key, parameters, in.nextExpression());
	env.write_op(key);
}

void define(Environment& env, Input& in) {
	string key = ++in;
	string aux = in.nextExpression();
	++in;
	if(in.get_p() == 0) {
		in << aux;
		++in;
		defineVar(env, key, in);
	}
	else{
		if(aux.size() < 4) {
			aux.clear();
		}
		else {
			aux.erase(0, 2);
			aux.erase(aux.size()-2, 2);
		}
		defineOp(env, key, aux, in);
	}
}

bool readExpression(Environment& env, Expression& exp, Input& in) {
	string str = in.get_str();
	if(str == "(") {
		in >> str;
		if(env.is_op(str)) {
			readOp(env, exp, in);
		}
		else if(str == "define") {
			define(env, in);
		}
		else {
			readList(env, exp, in);
		}
	}
	else if(is_num(str)){
		exp.set_value(stoi(str));
	}
	else if(env.exists_var(str)) {
		exp = env.get_var(str);
	}
	else {
		exp.set_undefined();
	}
	evaluate(env, exp);
	return str != "define";
}

bool read(Environment& env, Expression& exp){
	Input in;
	string str = ++in;
	if(str != "****" and readExpression(env, exp, in)){
		exp.write();
	}
	in.endOfExpression();
	return str != "****";
}
