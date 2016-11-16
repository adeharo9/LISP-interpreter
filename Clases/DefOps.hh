#ifndef DEFOP_HH
#define DEFOP_HH

#include <iostream>
#include <map>

using namespace std;

class DefOp{
private:

    struct opDefinition{
        string parameters;
        string exp;
    };
    
    map<string,opDefinition> defOpMap;

public:

	//_______ CONSTRUCTORS

	DefOp();
	/* Pre: Cierto */
	/* Post: Se crea una objeto de clase DefOp vacio*/

	DefOp(string name, string parameters, string exp);
	/* Pre: Name, parameters, exp != Null.  "name" no puede ser uno de los nombres de las operaciones primitivas,
		primitivas  */
	/* Post: Crea una nueva operacion con el nombre "name", con los paremetros "parameters"
		y que tiene como codigo la expresion evaluable "exp". Si el valor "name" ya esxiste
		se reemplazará si la "exp" != indefinido  */

	//_______ DESTRUCTORS

	~DefOp();

	//_______ MODIFICADORS

	void add(string name,const opDefinition& inOpDefinition);
	/* Pre: El parametro implicito no tiene la operacion "name" */
	/* Post: Se añade a la lista defOpMap la operacion "name" con parametros
		y expresion "inOpDefinition"  */

	void update(string name,const opDefinition& inOpDefinition);
	/* Pre: El parametro implicito existe y tiene una expresion opDefinition */
	/* Post: La nueva opDefinition de "name" pasa a ser "inOpDefinition" */

	//_______ I/O

	void write() const;
	/* Pre: cierto */
	/* Post: Se ha escrito los atributos del parametro implicito al canal
		estandar de salida; si no tiene "opDefinition" se escribe "indefinido" */

	};

#endif
