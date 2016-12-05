/** @file Environment.hh
    @brief Especificación de la clase Environment
*/

#ifndef ENVIRONMENT_HH
#define ENVIRONMENT_HH

#include "Expression.hh"
#include "PrimitiveOperationSpace.hh"
#include "VariableSpace.hh"
#include "OperationSpace.hh"

using namespace std;

/** @class Environment
    @brief Representa un entorno de ejecución con todas las operaciones primitivas predefinidas, así como con todas las variables y operaciones definidas por el usuario
*/

class Environment {

private:

	/* INVARIANTE
		El entorno contiene las operaciones primitivas, así como las variables y operaciones definidas por el usuario
	*/

	typedef void (*primitiveOperation)(Expression&);

	PrimitiveOperationSpace primOpSpace;
	VariableSpace varSpace;
	OperationSpace opSpace;

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar un nuevo entorno
		\pre <em>Cierto</em>
		\post Crea un objeto con mapa de operaciones primitivas 'primOpMap' del espacio de operaciones primitivas 'primOpSpace' inicializado con las operaciones primitivas, un espacio de variables 'varSpace' con mapa de variables 'varMap' vacío y un espacio de operaciones 'opSpace' con un mapa de operaciones 'opMap' vacío
	*/
	Environment();

	//_______ DESTRUCTORES

	/** @brief Destructora por defecto

		Se ejecuta automáticamente al salir de un ámbito de visibilidad
		\pre <em>Cierto</em>
		\post Libera los recursos locales del parámetro implícito al salir de un ámbito de visibilidad
	*/
	~Environment();

	//_______ MODIFICADORES

	/** @brief Modificadora por adición de variable

		\pre 'key' es un string no vacío; el mapa de variables 'varMap' del espacio de variables 'varSpace' del parámetro implícito no contiene ninguna variable con clave 'key'
		\post Se añade al mapa de variables 'varMap' del espacio de variables 'varSpace' del parámetro implícito la variable con clave 'key' y expresión 'exp'
	*/
	void add_var(string key, const Expression& exp);

	/** @brief Modificadora por adición de operación

		\pre 'key' es un string no vacío; 'key' no corresponde al nombre de ninguna de las operaciones primitivas; el mapa de operaciones 'opMap' del espacio de operaciones 'opSpace' del parámetro implícito no contiene ninguna operación con clave 'key'
		\post Se añade al mapa de operaciones 'opMap' del espacio de operaciones 'opSpace' del parámetro implícito la operación con clave 'key', parámetros 'parameters' y expresión 'exp'
	*/
	void add_op(string key, string parameters, string exp);

	/** @brief Modificadora por actualización de variable

		\pre 'key' es un string no vacío; el mapa de variables 'varMap' del espacio de variables 'varSpace' del parámetro implícito contiene una variable con clave 'key'
		\post La expresión de la variable con clave 'key' en el mapa de variables 'varMap' del espacio de variables 'varSpace' del parámetro implícito pasa a ser 'exp'
	*/
	//void update_var(string key, const Expression& exp);

	/** @brief Modificadora por actualización de operación

		\pre 'key' es un string no vacío; 'key' no corresponde al nombre de ninguna de las operaciones primitivas; el mapa de operaciones 'opMap' del espacio de operaciones 'opSpace' del parámetro implícito contiene una operación con clave 'key'
		\post Los parámetros y la expresión de la operación con clave 'key' en el mapa de operaciones 'opMap' del espacio de operaciones 'opSpace' del parámetro implícito pasan a ser 'parameters' y 'exp', respectivamente
	*/
	//void update_op(string key, string parameters, string exp);

	/** @brief Modificadora por actualización de operación

		\pre <em>Cierto</em>
		\post El espacio de variables varSpace del parámetro implícito pasa a estar vacío
	*/
	void erase_varspace();

	//_______ CONSULTORES

	/** @brief Consultora de existencia de operación primitiva

		\pre 'key' es un string no vacío
		\post Devuelve cierto si la operación de clave 'key' es una operación primitiva contenida en el mapa de operaciones 'primOpMap' del espacio de operaciones primitivas 'primOpSpace'; en otro caso, devuelve falso
	*/
	bool is_primitive(string key) const;

	/** @brief Consultora de existencia de operación

		\pre 'key' es un string no vacío
		\post Devuelve cierto si la operación de clave 'key' es una operación contenida en el mapa de operaciones 'opMap' del espacio de operaciones 'opSpace' o en el mapa de operaciones primitivas 'primOpMap' del espacio de operaciones primitivas 'primOpSpace'; en otro caso, devuelve falso
	*/
	bool is_op(string key) const;

	/** @brief Consultora de existencia

    	\pre 'key' es un string no vacío
    	\post Devuelve cierto si el string 'key' figura como clave de alguna variable u operación de algún mapa de algún espacio del parámetro implícito; en otro caso, devuelve falso
    */
	bool exists(string key) const;

	/** @brief Consultora de existencia de variable

    	\pre 'key' es un string no vacío
    	\post Devuelve cierto si la variable con clave 'key' existe en el mapa de variables 'varMap' del espacio de variables 'varSpace' del parámetro implícito; en otro caso, devuelve falso
    */
	bool exists_var(string key) const;

	/** @brief Consultora de existencia de operación

    	\pre 'key' es un string no vacío
    	\post Devuelve cierto si la operación con clave 'key' existe en el mapa de operaciones 'opMap' del espacio de operaciones 'opSpace' del parámetro implícito; en otro caso, devuelve falso
    */
	bool exists_op(string key) const;

	/** @brief Consultora de recuperación de operación primitiva

    	\pre 'key' es un string no vacío; el mapa de operaciones primitivas 'primOpMap' del espacio de operaciones primitivas 'primOpSpace' del parámetro implícito contiene una operación primitiva con clave 'key'
    	\post Devuelve la operación primitiva representada por la clave 'key'
    */
	primitiveOperation get_prim(string key);

	/** @brief Consultora de recuperación de variable

    	\pre 'key' es un string no vacío; el mapa de variables 'varMap' del espacio de variables 'varSpace' del parámetro implícito contiene una variable con clave 'key'
    	\post Devuelve la expresión representada por la variable de clave 'key'
    */
	Expression get_var(string key);

	/** @brief Consultora de recuperación de operación

    	\pre 'key' es un string no vacío; el mapa de operaciones 'opMap' del espacio de operaciones 'opSpace' del parámetro implícito contiene una operación con clave 'key'
    	\post Devuelve los parámetros y la expresión, respectivamente en forma de pair, de la operación representada por la clave 'key'
    */
	pair<string, string> get_op(string key);

	/** @brief Consultora de número de parámetros de operación

    	\pre 'key' es un string no vacío; el mapa de operaciones 'opMap' del espacio de operaciones 'opSpace' del parámetro implícito contiene una operación con clave 'key'
    	\post Devuelve el número de parámetros de la operación representada por la clave 'key'
    */
	int num_pars_op(string key);

	//_______ I/O

	/** @brief Operación de escritura de todo el entorno de variables y operaciones definidas por el usuario

		\pre <em>Cierto</em>
		\post Se ha escrito el contenido del espacio de variables 'varSpace' y del espacio de operaciones 'opSpace' por el canal estándar de salida, si lo tenían; en el caso del contenido del espacio de variables 'varSpace', si el resultado de evaluar la expresión de alguna de las variables es indefinido, se escribe "indefinido"; si alguno o ambos espacios están vacíos, no se escribe nada en relacion al/los espacio/s vacío/s por el canal estándar de salida
	*/
	void write() const;

	/** @brief Operación de escritura de una variable concreta

		\pre 'key' es un string no vacío; el mapa de variables 'varMap' del espacio de variables 'varSpace' del parámetro implícito contiene una variable con clave 'key'
		\post Se ha escrito el contenido de la variable con clave 'key' por el canal estándar de salida; en caso que el resultado de evaluar la expresión sea indefinido, se escribe "indefinido"
	*/
	void write_var(string key);

	/** @brief Operación de escritura de una operación concreta

		\pre 'key' es un string no vacío; el mapa de operaciones 'opMap' del espacio de operaciones 'opSpace' del parámetro implícito contiene una operación con clave 'key'
		\post Se ha escrito el contenido de la operación con clave 'key' por el canal estándar de salida
	*/
	void write_op(string key);

};

#endif
