#include <iostream>
#include "Expression.hh"
#include "Environment.hh"
#include "FunctionsIO.hh"

using namespace std;

int main() {
	Environment env;
	Expression exp;
	while(read(env, exp)) {
		exp.clear();
	}
	env.write();
}
