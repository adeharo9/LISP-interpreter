#ifndef OPERATIONSPACE_HH
#define OPERATIONSPACE_HH

#include <map>

using namespace std;

class OperationSpace {

private:

	/* INVARIANTE
	*/

    struct definition {
        string parameters;
        string exp;
    };
    
    map<string,definition> operationMap;

public:

	//_______ CONSTRUCTORES

	OperationSpace();
	/* Pre: cierto */
	/* Post: el resultado es un mapa de operaciones vacío */

	OperationSpace(string key, string parameters, string exp);
	/* Pre: 'key' es un string no vacío;
			'exp' es un string no vacío;
			'key' no corresponde al nombre de alguna de las operaciones
			primitivas */
	/* Post: el resultado es un mapa de operaciones inicializado con la
			 operación de clave 'key', parámetros 'parameters' y expresión
			 'exp' */

	OperationSpace(const OperationSpace& inOperationSpace);
	/* Pre: cierto */
	/* Post: el resultado es un objeto copia de 'inOperationSpace' */

	//_______ DESTRUCTORES

	~OperationSpace();
	/* Pre: cierto */
	/* Post: libera los recursos locales del parámetro implícito al salir
			 de un ámbito de visibilidad */

	//_______ MODIFICADORES

	void add(string key, string parameters, string exp);
	/* Pre: 'key' es un string no vacío;
			'key' no corresponde al nombre de alguna de las operaciones
			primitivas;
			el mapa de operaciones del parámetro implícito no contiene una
			operacion con clave 'key' */
	/* Post: se añade al mapa de operaciones del parámetro implícito la
			 operacion con clave 'key', parámetros 'parameters' y expresión
			 'exp' */

	void update(string key, string parameters, string exp);
	/* Pre: 'key' es un string no vacío;
			'key' no corresponde al nombre de alguna de las operaciones
			primitivas;
			el mapa de operaciones del parámetro implícito contiene una
			operación con clave 'key' */
	/* Post: los parámetros y la expresión de la operación con clave 'key'
			 en el mapa de operaciones del parámetro implícito pasan a ser
			 'parameters' y 'exp', respectivamente */

	//_______ CONSULTORES

    bool exists(string key) const;
    /* Pre: 'key' es un string no vacío */
    /* Post: devuelve cierto si la operación con clave 'key' existe en el
    		 mapa de operaciones del parámetro implícito;
    		 en otro caso, devuelve falso */

	//_______ I/O

	void write_map() const;
	/* Pre: el mapa de operaciones del parámetro implícito no está vacío */
	/* Post: se ha escrito el contenido del mapa de operaciones del
			 parámetro implícito por el canal estándar de salida */

	void write_op(string key) const;
	/* Pre: 'key' es un string no vacío;
			el mapa de operaciones del parámetro implícito contiene una
			operación con clave 'key' */
	/* Post: se ha escrito el contenido de la operación con clave 'key' por
			 el canal estándar de salida */

};

#endif
