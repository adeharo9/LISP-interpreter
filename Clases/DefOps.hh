#ifndef DEFOP_HH
#define DEFOP_HH

#include <iostream>
#include <map>

using namespace std;

class DefOp{
private:

    struct opDefinition{
        string vars;
        string exp;
    };
    
    map<string,opDefinition> defOpMap;

public:

DefOp();

DefOp(const DefOp& inDefOp);

~DefOp();

void add(string name,const opDefinition& inOpDefinition);

void update(string name,const opDefinition& inOpDefinition);

void write() const;

};

#endif
