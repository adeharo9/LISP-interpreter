#include <iostream>
#include "Environment.hh"
#include "Expression.hh"

using namespace std;

bool readExpression(Environment& env,Expression& exp){

}

int main(){
	Environment env;
	Expression exp;
	while(readExpression(env,exp)){
		if(not exp.empty()){
			exp.write();
			exp.clear();
		}
	}
	env.write_env();
}
