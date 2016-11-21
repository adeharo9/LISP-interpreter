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
    @brief Representa un espacio de operaciones definidas por el
    usuario en forma de mapa de variables

    Todas las operaciones son de <b>coste ?</b>
*/

class OperationSpace {

private:

	/* INVARIANTE
	*/

    struct definition {
        string parameters;
        string exp;
    };
    
    map<string,definition> opMap;

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar un nuevo espacio de
		operaciones
		\pre <em>Cierto</em>
		\post Crea un objeto con mapa de operaciones 'opMap' vacío
	*/
	OperationSpace();

	/** @brief Constructora con valor de inicialización

		\pre 'key' es un string no vacío;
			'exp' es un string no vacío;
			'key' no corresponde al nombre de ninguna de las operaciones
			primitivas
		\post Crea un objeto con mapa de operaciones 'opMap' inicializado
			 con la operación de clave 'key', parámetros 'parameters' y
			 expresión 'exp'
	*/
	OperationSpace(string key, string parameters, string exp);

	/** @brief Constructora por copia

		\pre <em>Cierto</em>
		\post Crea un objeto copia de 'opSpace'
	*/
	OperationSpace(const OperationSpace& opSpace);

	//_______ DESTRUCTORES

	/** @brief Destructora por defecto

		Se ejecuta automáticamente al salir de un ámbito de visibilidad
		\pre <em>Cierto</em>
		\post Libera los recursos locales del parámetro implícito al salir
			 de un ámbito de visibilidad
	*/
	~OperationSpace();

	//_______ MODIFICADORES

	/** @brief Modificadora por adición de operación

		\pre 'key' es un string no vacío;
			'key' no corresponde al nombre de ninguna de las operaciones
			primitivas;
			el mapa de operaciones 'opMap' del parámetro implícito no
			contiene ninguna operación con clave 'key'
		\post Se añade al mapa de operaciones 'opMap' del parámetro implícito
			 la operacion con clave 'key', parámetros 'parameters' y
			 expresión 'exp'
	*/
	void add(string key, string parameters, string exp);

	/** @brief Modificadora por actualización de operación

		\pre 'key' es un string no vacío;
			'key' no corresponde al nombre de ninguna de las operaciones
			primitivas;
			el mapa de operaciones 'opMap' del parámetro implícito contiene
			una	operación con clave 'key'
		\post Los parámetros y la expresión de la operación con clave 'key'
			 en el mapa de operaciones 'opMap' del parámetro implícito pasan
			 a ser 'parameters' y 'exp', respectivamente
	*/
	void update(string key, string parameters, string exp);

	//_______ CONSULTORES

    /** @brief Consultora de existencia de operación

    	\pre 'key' es un string no vacío
    	\post Devuelve cierto si la operación con clave 'key' existe en el
    		 mapa de operaciones 'opMap' del parámetro implícito;
    		 en otro caso, devuelve falso
    */
    bool exists(string key) const;

    /** @brief Consultora de recuperación de operación

    	\pre 'key' es un string no vacío;
    		el mapa de operaciones 'opMap' del parámetro implícito contiene
			una operación con clave 'key'
    	\post Devuelve los parámetros y la expresión, respectivamente, en
    		 forma de pair, de la operación representada por la clave 'key'
    */
    pair<string,string> retrieve(string key) const;

	//_______ I/O

	/** @brief Operación de escritura de todo el mapa de operaciones

		\pre El mapa de operaciones 'opMap' del parámetro implícito no está
			vacío
		\post Se ha escrito el contenido del mapa de operaciones 'opMap' del
			 parámetro implícito por el canal estándar de salida
	*/
	void write_map() const;

	/** @brief Operación de escritura de una operación concreta

		\pre 'key' es un string no vacío;
			el mapa de operaciones 'opMap' del parámetro implícito contiene
			una	operación con clave 'key'
		\post Se ha escrito el contenido de la operación con clave 'key' por
			 el canal estándar de salida
	*/
	void write_op(string key) const;

};

#endif
