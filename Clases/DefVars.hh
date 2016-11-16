#ifndef DEFVARS_HH
#define DEFVARS_HH

#include <iostream>
#include <map>

using namespace std;

	class DefVars{
private:

	struct variable{
		int value;
		bool undefine;
	};

	

    map<string,variable> varMem;

public:

	//_______ CONSTRUCTORS

	DefVars();
	/* Pre: cierto */
	/* Post: el resultado es un mapa vacio  */

	DefVars(string var, variable inValue);
	/* Pre: cierto */
	/* Post: el resultado es una variable "var" con el valor "inValue"; si 
		"inValue.undefine" == true, inValue.value = 0 */


	DefVars(const DefVars& inVars);
	/* Pre: cierto */
	/* Post: el resultado es una copia del mapa inVars */
	
	//_______ DESTRUCTORS

	~DefVars();

	//_______ MODIFICADORS

	void add(string inKey,int value);
	/* Pre: el mapa del parametro implicito no tiene una
		variable con la key "inKey" */
	/* Post: se añade al mapa del parametro implicito
		la key "inKey" con valor "value" */

	void update(string inKey,int value);
	/* Pre: el mapa del parametro implicito contiene una variable
		con la key "inKey" */
	/* Post: el valor del mapa del parametro implicito con la key
		"inKey" pasa a ser "value" */

	//_______ I/O

	void write() const;
	/* Pre: cierto */
	/* Post: se han escrito los valores del mapa del parametro implicito por
		el canal estanadar de salid; en el caso de que el resultado de evaluar
		la expresion sea indefinida, se escribira "indefinida" */

	};

#endif
