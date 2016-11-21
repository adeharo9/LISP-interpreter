/** @file VariableSpace.hh
    @brief Especificación de la clase VariableSpace
*/

#ifndef VARIABLESPACE_HH
#define VARIABLESPACE_HH

#ifndef NO_DIAGRAM
#include <map>
#endif

#include "Expression.hh"

using namespace std;

/** @class VariableSpace
    @brief Representa un espacio de variables definidas por el usuario en forma de mapa de variables
*/

class VariableSpace {

private:

    /* INVARIANTE
    	Todas las expresiones que intervienen en operaciones de adición o de modificación de una variable se evalúan previamente a la ejecución de dichas operaciones

    */

    map<string, Expression> varMap;

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar un nuevo espacio de variables
		\pre <em>Cierto</em>
		\post Crea un objeto con mapa de variables 'varMap' vacío
	*/
	VariableSpace();

	/** @brief Constructora con valor de inicialización

		\pre 'key' es un string no vacío
		\post Crea un objeto con mapa de variables 'varMap' inicializado con la variable de clave 'key' y expresión 'exp'
	*/
	VariableSpace(string key, const Expression& exp);

	/** @brief Constructora por copia

		\pre <em>Cierto</em>
		\post Crea un objeto copia de 'varSpace'*/
	VariableSpace(const VariableSpace& varSpace);
	
	//_______ DESTRUCTORES

	/** @brief Destructora por defecto

		Se ejecuta automáticamente al salir de un ámbito de visibilidad
		\pre <em>Cierto</em>
		\post Libera los recursos locales del parámetro implícito al salir de un ámbito de visibilidad
	*/
	~VariableSpace();

	//_______ MODIFICADORES

	/** @brief Modificadora por adición de variable

		\pre 'key' es un string no vacío; el mapa de variables 'varMap' del parámetro implícito no contiene ninguna variable con clave 'key'
		\post Se añade al mapa de variables 'varMap' del parámetro implícito la variable con clave 'key' y expresión 'exp'
	*/
	void add(string key, const Expression& exp);

	/** @brief Modificadora por actualización de variable

		\pre 'key' es un string no vacío; el mapa de variables 'varMap' del parámetro implícito contiene una	variable con clave 'key'
		\post La expresión de la variable con clave 'key' en el mapa de variables 'varMap' del parámetro implícito pasa a ser 'exp'
	*/
	void update(string key, const Expression& exp);

	//_______ CONSULTORES

    /** @brief Consultora de existencia de variable

    	\pre 'key' es un string no vacío
    	\post Devuelve cierto si la variable con clave 'key' existe en el mapa de variables 'varMap' del parámetro implícito; en otro caso, devuelve falso
    */
    bool exists(string key) const;

    /** @brief Consultora de recuperación de variable

    	\pre 'key' es un string no vacío; el mapa de variables 'varMap' del parámetro implícito contiene una variable con clave 'key'
    	\post Devuelve la expresión representada por la variable de clave 'key'
    */
    Expression retrieve(string key) const;

	//_______ I/O

	/** @brief Operación de escritura de todo el espacio de variables

		\pre El mapa de variables 'varMap' del parámetro implícito no está vacío
		\post Se ha escrito el contenido del mapa de variables 'varMap' del parámetro implícito por el canal estándar de salida; en caso que el resultado de evaluar la expresión sea indefinido, se escribe "indefinido"
	*/
	void write() const;

	/** @brief Operación de escritura de una variable concreta

		\pre 'key' es un string no vacío; el mapa de variables 'varMap' del parámetro implícito contiene una variable con clave 'key'
		\post Se ha escrito el contenido de la variable con clave 'key' por el canal estándar de salida; en caso que el resultado de evaluar la expresión sea indefinido, se escribe "indefinido"
	*/
	void write_var(string key) const;

};

#endif
