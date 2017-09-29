#ifndef INPUT_HH
#define INPUT_HH

#include <string>

using namespace std;

class Input {

private:

	int p;
	string buff;
	string str;

public:

//_______ CONSTRUCTORES

	Input();

//_______ DESTRUCTORES

	~Input();

//_______ OPERADORES

	string& operator ++ ();
	
	void operator -- ();

	string& operator >> (string& str);

	void operator << (string buff);

//_______ MODIFICADORES

	string& next();

	void previous();

	string nextExpression();

	void endOfExpression();

	int countExpressions();

//_______ CONSULTORES

	int get_p() const;

	string get_buff() const;

	string get_str() const;

};

#endif