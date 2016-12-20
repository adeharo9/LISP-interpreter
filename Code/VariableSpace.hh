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
    @brief Espacio de almacenamiento de variables definidas por el usuario
*/

class VariableSpace {

private:

    /* INV
    	No hay variables indefinidas
    	Toda variable se guarda como expresión representativa o bien de un valor entero o biend e una lista de enteros

    */

	/** @brief Mapa de variables definidas por el usuario
	
		Atributo que almacena las variables definidas por el usuario con su identificador como clave
	*/
    map<string, Expression> varMap;

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar un nuevo espacio de variables
		\pre <em>Cierto</em>
		\post Crea un objeto vacío
		\coste Constante
	*/
	VariableSpace();

	/** @brief Constructora por copia

		\pre <em>Cierto</em>
		\post Crea un objeto copia de 'varSpace'
		\coste Logaritmico
	*/
	VariableSpace(const VariableSpace& varSpace);
	
	//_______ DESTRUCTORES

	/** @brief Destructora por defecto

		Se ejecuta automáticamente al salir de un ámbito de visibilidad
		\pre <em>Cierto</em>
		\post Libera los recursos locales del parámetro implícito al salir de un ámbito de visibilidad
		\coste Lineal
	*/
	~VariableSpace();

	//_______ MODIFICADORES

	/** @brief Modificadora por eliminación de contenido

		\pre <em>Cierto</em>
		\post Elimina el contenido del parámetro implícito, que pasa a estar vacío
		\coste Lineal
	*/
	void clear();

	/** @brief Modificadora por establecimiento de variable

		\pre 'key' es un string no vacío; 'key' no corresponde al nombre de ninguna de las operaciones primitivas predefinidas ni al nombre de ninguna de las operaciones definidas por el usuario; 'exp' no es una expresión indefinida
		\post Se añade al parámetro implícito la variable con nombre 'key' y expresión 'exp', o se actualiza su expresión a 'exp' si ya existía previamente
		\coste Logaritmico
	*/
	void set(string key, const Expression& exp);

	//_______ CONSULTORES

    /** @brief Consultora de parámetro implícito vacío

    	\pre <em>Cierto</em>
    	\post Devuelve cierto si el parámetro implícito está vacío
    	\coste Constante
    */
    bool empty() const;

    /** @brief Consultora de existencia de variable

    	\pre 'key' es un string no vacío
    	\post Devuelve cierto si la variable con nombre 'key' existe en el parámetro implícito; en otro caso, devuelve falso
    	\coste Logaritmico
    */
    bool exists(string key) const;

    /** @brief Consultora de recuperación de variable

    	\pre 'key' es un string no vacío; el parámetro implícito contiene una variable con nombre 'key'
    	\post Devuelve la expresión representada por la variable de nombre 'key'
    	\coste Logaritmico
    */
    Expression& get(string key) ;

	//_______ I/O

	/** @brief Operación de escritura del espacio de variables definidas por el usuario

		\pre <em>Cierto</em>
		\post Se ha escrito el contenido del parámetro implícito por el canal estándar de salida
		\coste Lineal con respecto al tamaño del parametro implicito
	*/
	void write() const;

	/** @brief Operación de escritura de variable definida por el usuario

		\pre 'key' es un string no vacío; el parámetro implícito contiene una variable con nombre 'key'
		\post Se ha escrito el contenido de la variable con nombre 'key' por el canal estándar de salida
		\coste Logaritmico
	*/
	void write_var(string key);

};

#endif
