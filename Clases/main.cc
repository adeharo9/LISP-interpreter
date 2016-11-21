#include <iostream>
#include "Environment.hh"
#include "Expression.hh"

using namespace std;

int main(){
	Environment env;
	Expression exp;
	while(exp.read()){
		exp.write();
		exp.clear();
	}
	env.write_env();
}
