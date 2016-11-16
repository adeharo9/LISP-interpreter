#ifndef ENVIRONMENT_HH
#define ENVIRONMENT_HH

#include <iostream>
#include <map>

using namespace std;

class Variables{
private:

    map<string,int> varMem;

public:

Environment();

Environment(const Environment& inEnv);

~Environment();

void add(string inKey,int value);

void update(string inKey,int );

void write() const;

};

#endif
