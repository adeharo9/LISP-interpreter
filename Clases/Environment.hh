#ifndef ENVIRONMENT_HH
#define ENVIRONMENT_HH

#include "PrimitiveOperationSpace.hh"
#include "VariableSpace.hh"
#include "OperationSpace.hh"

class Environment {
private:

	/* INVARIANTE
	*/

	PrimitiveOperationSpace primOpSpace;
	VariableSpace varSpace;
	OperationSpace opSpace;

public:

	//_______ CONSTRUCTORES

	Environment();
	/* Pre: cierto */
	/* Post: el resultado es un mapa de operaciones primitivas del espacio
			 de operaciones primitivas 'primOpSpace' inicializado con las
			 operaciones primitivas, un espacio de variables 'varSpace'
			 vacío y un espacio de operaciones 'opSpace' vacío */

	//_______ DESTRUCTORES

	~Environment();
	/* Pre: cierto */
	/* Post: libera los recursos locales del parámetro implícito al salir
			 de un ámbito de visibilidad */

	//_______ MODIFICADORES

	void add_var(string key, const Expression& exp);
	/* Pre: 'key' es un string no vacío;
			el mapa de variables del espacio de variables 'varSpace' del
			parámetro implícito no contiene una	variable con clave 'key' */
	/* Post: se añade al mapa de variables del espacio de variables
			 'varSpace' del parámetro implícito la variable con clave
			 'key' y expresión 'exp' */

	void add_op(string key, string parameters, string exp);
	/* Pre: 'key' es un string no vacío;
			'key' no corresponde al nombre de alguna de las operaciones
			primitivas;
			el mapa de operaciones del espacio de operaciones 'opSpace' del
			parámetro implícito no contiene una operacion con clave	'key' */
	/* Post: se añade al mapa de operaciones del espacio de operaciones
			 'opSpace' del parámetro implícito la operacion con clave
			 'key', parámetros 'parameters' y expresión 'exp' */

	void update_var(string key, const Expression& exp);
	/* Pre: 'key' es un string no vacío;
			el mapa de variables del espacio de variables 'varSpace' del
			parámetro implícito contiene una variable con clave 'key' */
	/* Post: la expresión de la variable con clave 'key' en el mapa de
			 variables del espacio de variables 'varSpace' del parámetro
			 implícito pasa a ser 'exp' */

	void update_op(string key string parameters, string exp);
	/* Pre: 'key' es un string no vacío;
			'key' no corresponde al nombre de alguna de las operaciones
			primitivas;
			el mapa de operaciones del espacio de operaciones 'opSpace' del
			parámetro implícito contiene una operación con clave 'key' */
	/* Post: los parámetros y la expresión de la operación con clave 'key'
			 en el mapa de operaciones del espacio de operaciones 'opSpace'
			 del parámetro implícito pasan a ser 'parameters' y 'exp',
			 respectivamente */

	//_______ CONSULTORES

	bool is_primitive(string key) const;
	/* Pre: 'key' es un string no vacío */
	/* Post: devuelve cierto si la operación de clave 'key' es una
			 operación primitiva contenida en el mapa de operaciones del
			 espacio de operaciones primitivas 'primOpSpace';
			 en otro caso, devuelve falso */

	bool exists_var(string key) const;
    /* Pre: 'key' es un string no vacío */
    /* Post: devuelve cierto si la variable con clave 'key' existe en el
    		 mapa de variables del espacio de variables 'varSpace' del
    		 parámetro implícito;
    		 en otro caso, devuelve falso */

	bool exists_op(string key) const;
    /* Pre: 'key' es un string no vacío */
    /* Post: devuelve cierto si la operación con clave 'key' existe en el
    		 mapa de operaciones del espacio de operaciones 'opSpace' del
    		 parámetro implícito;
    		 en otro caso, devuelve falso */

	//_______ I/O

	void write_env();
	/* Pre: cierto */
	/* Post: se ha escrito el contenido del espacio de variables 'varSpace'
			 y del espacio de operaciones 'opSpace' por el canal estándar
			 de salida, si lo tenían;
			 en el caso del contenido del espacio de variables 'varSpace',
			 si el resultado de evaluar la expresión de la variable es
			 indefinido, se escribe "indefinido";
			 si alguno o ambos espacios están vacíos, no se escribe nada
			 en relacion al/los espacio/s vacío/s por el canal estándar de
			 salida */

	void write_var(string key);
	/* Pre: 'key' es un string no vacío;
			el mapa de variables del espacio de variables 'varSpace' del
			parámetro implícito contiene una variable con clave 'key' */
	/* Post: se ha escrito el contenido de la variable con clave 'key' por
			 el canal estándar de salida;
			 en caso que el resultado de evaluar la expresión sea
			 indefinido, se escribe "indefinido" */

	void write_op(string key);
	/* Pre: 'key' es un string no vacío;
			el mapa de operaciones del espacio de operaciones 'opSpace' del
			parámetro implícito contiene una operación con clave 'key' */
	/* Post: se ha escrito el contenido de la operación con clave 'key' por
			 el canal estándar de salida */

};

#endif
