/** @file OperationSpace.hh
    @brief Especificación de la clase OperationSpace
*/

#ifndef OPERATIONSPACE_HH
#define OPERATIONSPACE_HH

#ifndef NO_DIAGRAM
#include <map>
#endif

using namespace std;

/** @class OperationSpace
    @brief Representa un espacio de operaciones definidas por el usuario en forma de mapa de variables
*/

class OperationSpace {

private:

	/* INVARIANTE
		Las operaciones no son revisadas al introducirse en el mapa de operaciones
	*/

	//________ATRIBUTOS

	/** @brief Atributo de expresion

		Atributo que contiene el número de parametros, parametros y expresión de una operación definida por el usuario.
	*/
    struct definition {
    	int n_parameters;
        string parameters;
        string exp;
    };
    
    /** @brief Atributo de OperationSpace
		
		Mapa de operaciones definidas por el usuario con 'key' nombre de operación y 'valor' la expresión definida para esta operación.
    */
    map<string, definition> opMap;

    /** @brief Método privado que cuenta la cantidad de parametros de una operación definida por el usuario

    	\pre 	<em>Cierto</em>
    	\post	Devuelve la cantidad de parametros contenidos en la variable 'parameters'
    */
    static int countVars(string parameters);

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar un nuevo espacio de operaciones
		\pre <em>Cierto</em>
		\post Crea un objeto con mapa de operaciones 'opMap' vacío
	*/
	OperationSpace();

	//_______ DESTRUCTORES

	/** @brief Destructora por defecto

		Se ejecuta automáticamente al salir de un ámbito de visibilidad
		\pre <em>Cierto</em>
		\post Libera los recursos locales del parámetro implícito al salir de un ámbito de visibilidad
	*/
	~OperationSpace();

	//_______ MODIFICADORES

	/** @brief Modificadora por establecimiento de operación

		\pre 'key' es un string no vacío; 'key' no corresponde al nombre de ninguna de las operaciones primitivas; el mapa de operaciones 'opMap' del parámetro implícito no contiene ninguna operación con clave 'key'
		\post Se añade al mapa de operaciones 'opMap' del parámetro implícito la operacion con clave 'key', parámetros 'parameters' y expresión 'exp'
	*/
	void set(string key, string parameters, string exp);

	//_______ CONSULTORES

	/** @brief Consultora de mapa vacío

    	\pre <em>Cierto</em>
    	\post Devuelve cierto si el mapa de operaciones 'opMap' está vacío
    */
	bool empty() const;

    /** @brief Consultora de existencia de operación

    	\pre 'key' es un string no vacío
    	\post Devuelve cierto si la operación con clave 'key' existe en el mapa de operaciones 'opMap' del parámetro implícito; en otro caso, devuelve falso
    */
    bool exists(string key) const;

    /** @brief Consultora de recuperación de operación

    	\pre 'key' es un string no vacío; El parámetro implícito contiene una operación con valor 'key'
    	\post Devuelve los parámetros y la expresión, respectivamente, de la operación representada por el valor 'key'
    */
    pair<string, string> get(string key);

    /** @brief Consultora de número de parámetros

    	\pre 'key' es un string no vacío; El parámetro implícito contiene una operación con valor 'key'
    	\post Devuelve el número de parámetros de la operación representada por el valor 'key'
    */
    int num_pars(string key) ;

	//_______ I/O

	/** @brief Operación de escritura de todo el espacio de operaciones

		\pre Existen operaciones definidas previamente por el usuario en OperationSpace.
		\post Se han escrito las operaciones definidas por el usuario, por el canal estándar de salida
	*/
	void write() const;

	/** @brief Operación de escritura de una operación concreta

		\pre 'key' es un string no vacío; El parámetro implícito contiene una	operación con valor 'key'
		\post Se ha escrito el contenido de la operación con valor 'key' por el canal estándar de salida
	*/
	void write_op(string key);

};

#endif
