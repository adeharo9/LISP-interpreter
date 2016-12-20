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
    @brief Espacio de almacenamiento de operaciones definidas por el usuario
*/

class OperationSpace {

private:

	/* INV
		Las operaciones no son revisadas al introducirse en el mapa de operaciones
	*/

	//________ATRIBUTOS

	/** @brief Atributo de definición de expresión

		Atributo que contiene el número de parámetros, los parámetros y la expresión de una operación definida por el usuario
	*/
    struct definition {
    	int n_parameters;
        string parameters;
        string exp;
    };
    
    /** @brief Mapa de operaciones definidas por el usuario
		
		Atributo que almacena las operaciones definidas por el usuario con su identificador como clave
    */
    map<string, definition> opMap;

    /** @brief Método privado de cálculo de número de parámetros

    	\pre <em>Cierto</em>
    	\post Devuelve el número de parámetros contenidos en la variable 'parameters'
    	\coste Lineal respecto al tamaño de 'parameters'
    */
    static int count_vars(string parameters);

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar un nuevo espacio de operaciones
		\pre <em>Cierto</em>
		\post Crea un objeto vacío
		\coste Constante
	*/
	OperationSpace();

	//_______ DESTRUCTORES

	/** @brief Destructora por defecto

		Se ejecuta automáticamente al salir de un ámbito de visibilidad
		\pre <em>Cierto</em>
		\post Libera los recursos locales del parámetro implícito al salir de un ámbito de visibilidad
		\coste Lineal respecto al tamaño del parámetro implícito
	*/
	~OperationSpace();

	//_______ MODIFICADORES

	/** @brief Modificadora por establecimiento de operación

		\pre 'key' es un string no vacío; 'key' no corresponde al nombre de ninguna de las operaciones primitivas ni al nombre de ninguna de las variables definidas por el usuario
		\post Se añade al parámetro implícito la operacion con nombre 'key', parámetros 'parameters' y expresión 'exp', o se actualizan sus parámetros a 'parameters' y su expresión a 'exp' si ya existía previamente
		\coste Lineal respecto al tamaño de 'parameters'
	*/
	void set(string key, string parameters, string exp);

	//_______ CONSULTORES

	/** @brief Consultora de parámetro implícito vacío

    	\pre <em>Cierto</em>
    	\post Devuelve cierto si el parámetro implícito está vacío
    	\coste Constante
    */
	bool empty() const;

    /** @brief Consultora de existencia de operación

    	\pre 'key' es un string no vacío
    	\post Devuelve cierto si la operación con nombre 'key' existe en el parámetro implícito; en otro caso, devuelve falso
    	\coste Logarítmico respecto al tamaño del parámetro implícito respecto al tamaño del parámetro implícito
    */
    bool exists(string key) const;

    /** @brief Consultora de recuperación de operación

    	\pre 'key' es un string no vacío; el parámetro implícito contiene una operación con valor 'key'
    	\post Devuelve los parámetros y la expresión, respectivamente contenidos en forma de pair, de la operación de nombre 'key'
    	\coste Logarítmico respecto al tamaño del parámetro implícito
    */
    pair<string, string> get(string key);

    /** @brief Consultora de número de parámetros

    	\pre 'key' es un string no vacío; el parámetro implícito contiene una operación de nombre'key'
    	\post Devuelve el número de parámetros de la operación de nombre 'key'
    	\coste Logarítmico respecto al tamaño del parámetro implícito
    */
    int num_pars(string key) ;

	//_______ I/O

	/** @brief Operación de escritura del espacio de operaciones definidas por el usuario

		\pre <em>Cierto</em>
		\post Se han escrito las operaciones definidas por el usuario por el canal estándar de salida
		\coste Lineal respecto al tamaño del parámetro implícito
	*/
	void write() const;

	/** @brief Operación de escritura de operación definida por el usuario

		\pre 'key' es un string no vacío; el parámetro implícito contiene una operación de nombre 'key'
		\post Se ha escrito el contenido de la operación de nombre 'key' por el canal estándar de salida
		\coste Logarítmico respecto al tamaño del parámetro implícito
	*/
	void write_op(string key);

};

#endif
