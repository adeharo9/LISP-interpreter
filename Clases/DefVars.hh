#ifndef DEFVARS_HH
#define DEFVARS_HH

#include <iostream>
#include <map>

using namespace std;

class DefVars{
private:

    map<string,int> varMem;

public:

//_______ CONSTRUCTORS

	DefVars();

	DefVars(const DefVars& inEnv);

//_______ DESTRUCTORS

	~DefVars();

//_______ MODIFICADORS

	void add(string inKey,int value);

	void update(string inKey,int );
//_______ I/O

	void write() const;

};

#endif
