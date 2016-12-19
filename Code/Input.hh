/** @file Input.hh
    @brief Especificación de la clase Input
*/

#ifndef INPUT_HH
#define INPUT_HH

#ifndef NO_DIAGRAM
#include <string>
#endif

using namespace std;

/** @class Input
    @brief Contiene las operaciones de tratamiento de entrada necesarias para gestionar la entrada de operaciones a la calculadora
*/

class Input {

private:

	/** @brief Contador de paréntesis
		Representa la cantidad de paréntesis que se encuentran abiertos en cada instante
	*/
	int p;

	/** @brief Buffer de entrada
		Contiene la porción de texto de entrada que ha sido leída pero que no ha de ser tratada inmediatamente
	*/
	string buff;

	/** @brief Texto de tratamiento inmediato
		Contiene la porción de texto de entrada que ha sido leída y que ha de ser tratada inmediatamente
	*/
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