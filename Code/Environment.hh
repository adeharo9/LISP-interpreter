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
		El entorno contiene las operaciones primitivas, las variables y las operaciones definidas por el usuario
		Las operaciones primitivas no son modificables
	*/

	typedef void (*primitiveOperation)(Expression&);

	//_______ ATRIBUTOS


	/** @brief Espacio de operaciones primitivas
		Atributo que almacena las operaciones primitivas predefinidas
	*/
	PrimitiveOperationSpace primOpSpace;

	/** @brief Espacio de variables definidas por el usuario
		Atributo que almacena las variables definidas por el usuario en tiempo de ejecución
	*/
	VariableSpace varSpace;

	/** @brief Espacio de operaciones definidas por el usuario
		Atributo que almacena las operaciones definidas por el usuario en tiempo de ejecución
	*/
	OperationSpace opSpace;

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar un nuevo entorno
		\pre <em>Cierto</em>
		\post Crea un objeto con espacio de operaciones primitivas inicializado con las operaciones primitivas predefinidas, un espacio de variables vacío y un espacio de operaciones vacío
	*/
	Environment();

	/** @brief Constructora por copia

		\pre <em>Cierto</em>
		\post Crea un objeto copia de 'env'
	*/
	Environment(const Environment& env);

	//_______ DESTRUCTORES

	/** @brief Destructora por defecto

		Se ejecuta automáticamente al salir de un ámbito de visibilidad
		\pre <em>Cierto</em>
		\post Libera los recursos locales del parámetro implícito al salir de un ámbito de visibilidad
	*/
	~Environment();

	//_______ MODIFICADORES

	/** @brief Modificadora por establecimiento de variable

		\pre 'key' es un string no vacío
		\post Se añade al espacio de variables del parámetro implícito la variable con nombre 'key' y expresión 'exp', o se actualiza su expresión a 'exp' si ya existía previamente
	*/
	void set_var(string key, const Expression& exp);

	/** @brief Modificadora por establecimiento de operación

		\pre 'key' es un string no vacío; 'key' no corresponde al nombre de ninguna de las operaciones primitivas predefinidas
		\post Se añade al espacio de operaciones del parámetro implícito la operación con nombre 'key', parámetros 'parameters' y expresión 'exp', o se actualizan sus parámetros a 'parameters' y su expresión a 'exp' si ya existía previamente
	*/
	void set_op(string key, string parameters, string exp);

	/** @brief Modificadora por eliminación de espacio de variables

		\pre <em>Cierto</em>
		\post El espacio de variables definidas por el usuario del parámetro implícito pasa a estar vacío
	*/
	void erase_varspace();

	//_______ CONSULTORES

	/** @brief Consultora de existencia de operación primitiva

		\pre 'key' es un string no vacío
		\post Devuelve cierto si la operación de nombre 'key' es una operación primitiva contenida en el espacio de operaciones primitivas; en otro caso, devuelve falso
	*/
	bool is_primitive(string key) const;

	/** @brief Consultora de existencia de operación

		\pre 'key' es un string no vacío
		\post Devuelve cierto si la operación de nombre 'key' es una operación contenida en el espacio de operaciones primitivas o en el espacio de operaciones definidas por el usuario; en otro caso, devuelve falso
	*/
	bool is_op(string key) const;

	/** @brief Consultora de existencia

    	\pre 'key' es un string no vacío
    	\post Devuelve cierto si el string 'key' es el nombre de alguna variable u operación de algún espacio (de operaciones primitivas, variables definidas por el usuario u operaciones definidas por el usuario) del parámetro implícito; en otro caso, devuelve falso
    */
	bool exists(string key) const;

	/** @brief Consultora de existencia de variable

    	\pre 'key' es un string no vacío
    	\post Devuelve cierto si la variable con nombre 'key' existe en el espacio de variables del parámetro implícito; en otro caso, devuelve falso
    */
	bool exists_var(string key) const;

	/** @brief Consultora de existencia de operación

    	\pre 'key' es un string no vacío
    	\post Devuelve cierto si la operación con nombre 'key' existe en el espacio de operaciones del parámetro implícito; en otro caso, devuelve falso
    */
	bool exists_op(string key) const;

	/** @brief Consultora de recuperación de operación primitiva

    	\pre 'key' es un string no vacío; el espacio de operaciones primitivas del parámetro implícito contiene una operación primitiva con nombre 'key'
    	\post Devuelve la operación primitiva de nombre 'key'
    */
	primitiveOperation get_prim(string key);

	/** @brief Consultora de recuperación de variable

    	\pre 'key' es un string no vacío; el espacio de variables del parámetro implícito contiene una variable con nombre 'key'
    	\post Devuelve un alias de la expresión representada por la variable de nombre 'key'
    */
	Expression& get_var(string key);

	/** @brief Consultora de recuperación de operación

    	\pre 'key' es un string no vacío; el espacio de operaciones del parámetro implícito contiene una operación con nombre 'key'
    	\post Devuelve los parámetros y la expresión, respectivamente en forma de pair, de la operación de nombre 'key'
    */
	pair<string, string> get_op(string key);

	/** @brief Consultora de número de parámetros de operación

    	\pre 'key' es un string no vacío; el espacio de operaciones del parámetro implícito contiene una operación con nombre 'key'
    	\post Devuelve el número de parámetros de entrada de la operación de nombre 'key'
    */
	int num_pars_op(string key);

	//_______ I/O

	/** @brief Operación de escritura del entorno de variables y operaciones definidas por el usuario

		\pre <em>Cierto</em>
		\post Se ha escrito el contenido del espacio de variables y del espacio de operaciones por el canal estándar de salida, si lo tenían; en el caso del contenido del espacio de variables, si el resultado de evaluar la expresión de alguna de las variables es indefinido, se escribe "indefinido"
	*/
	void write() const;

	/** @brief Operación de escritura de variable definida por el usuario

		\pre 'key' es un string no vacío; el espacio de variables del parámetro implícito contiene una variable de nombre 'key'
		\post Se ha escrito el contenido de la variable de nombre 'key' por el canal estándar de salida; en caso que el resultado de evaluar la expresión sea indefinido, se escribe "indefinido"
	*/
	void write_var(string key);

	/** @brief Operación de escritura de operación definida por el usuario

		\pre 'key' es un string no vacío; el espacio de operaciones del parámetro implícito contiene una operación de nombre 'key'
		\post Se ha escrito el contenido de la operación de nombre 'key' por el canal estándar de salida
	*/
	void write_op(string key);

};

#endif
