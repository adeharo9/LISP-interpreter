/** @file Input.hh
    @brief Especificación de la clase Input
*/

#ifndef INPUT_HH
#define INPUT_HH

#ifndef NO_DIAGRAM
#include <string>
#endif

using namespace std;

/** @class Input
    @brief Contiene las operaciones de tratamiento de entrada necesarias para gestionar la entrada de expresiones
*/

class Input {

private:

	/* INV
		p >= 0
	*/

	/** @brief Contador de paréntesis
		Representa la cantidad de paréntesis que se encuentran abiertos en un momento determinado de la lectura de entrada
	*/
	int p;

	/** @brief Buffer de entrada
		Contiene la porción de texto de entrada que ha sido leída pero que no ha de ser tratada inmediatamente
	*/
	string buff;

	/** @brief Texto de tratamiento inmediato
		Contiene la porción de texto de entrada que ha sido leída y que ha de ser tratada inmediatamente
	*/
	string str;

public:

//_______ CONSTRUCTORES

	/** @brief Constructora por defecto

		Se ejecuta automáticamente al declarar un nuevo espacio de variables
		\pre <em>Cierto</em>
		\post Crea un objeto vacío
		\coste Constante
	*/
	Input();

//_______ DESTRUCTORES

	/** @brief Destructora por defecto

		Se ejecuta automáticamente al salir de un ámbito de visibilidad
		\pre <em>Cierto</em>
		\post Libera los recursos locales del parámetro implícito al salir de un ámbito de visibilidad
		\coste Lineal
	*/
	~Input();

//_______ OPERADORES

	/** @brief Operación de siguiente elemento a tratar

		\pre <em>Cierto</em>
		\post Se ha actualizado el texto de tratamiento inmediato, así como el buffer de entrada y el contador de paréntesis
		\coste Generalmente lineal, aunque constante en algunos casos
	*/
	string& operator ++ ();

	/** @brief Operación de anterior elemento a tratar

		\pre <em>Cierto</em>
		\post El buffer de entrada pasa a contener el texto de tratamiento inmediato a su inicio, y el contador de paréntesis se ha actualizado convenientemente; el texto de tratamiento inmediato pasa a estar vacío
		\coste Lineal respecto al tamaño del texto a tratar de forma inmediata
	*/
	void operator -- ();

	/** @brief Operación de siguiente elemento a tratar con asignación

		\pre <em>Cierto</em>
		\post Se ha actualizado el texto de tratamiento inmediato, así como el buffer de entrada y el contador de paréntesis; 'str' es igual al texto de tratamiento inmediato
		\coste Lineal respecto al tamaño del texto a tratar de forma inmediata
	*/
	string& operator >> (string& str);

	/** @brief Operación de introducción de buffer

		\pre <em>Cierto</em>
		\post El buffer del parámetro implícito pasa a ser 'buff'
		\coste Lineal respecto al tamaño de 'buff'
	*/
	void operator << (string buff);

//_______ MODIFICADORES

	/** @brief Siguiente elemento a tratar

		\pre <em>Cierto</em>
		\post Se ha actualizado el texto de tratamiento inmediato, así como el buffer de entrada y el contador de paréntesis
		\coste Generalmente lineal, aunque constante en algunos casos
	*/
	string& next();

	/** @brief Anterior elemento a tratar 

		\pre <em>Cierto</em>
		\post El buffer de entrada pasa a contener el texto de tratamiento inmediato a su inicio, y el contador de paréntesis se ha actualizado convenientemente; el texto de tratamiento inmediato pasa a estar vacío
		\coste Lineal respecto al tamaño del texto a tratar de forma inmediata
	*/
	void previous();

	/** @brief Siguiente expresión

		\pre <em>Cierto</em>
		\post Procesa toda la entrada correspondiente a una expresión y prepara la entrada para leer lo que hay después de la misma; devuelve la expresión que acaba de procesar como un string
		\coste Cuadrático
	*/
	string nextExpression();

	/** @brief Fin de expresión

		\pre <em>Cierto</em>
		\post Ignora toda entrada situada antes del final de la expresión y prepara la entrada para leer lo que hay después de la misma
		\coste Cuadrático
	*/
	void endOfExpression();

	/** @brief Contador de expresiones

		\pre <em>Cierto</em>
		\post Devuelve el número de expresiones que hay contenidas en el buffer de entrada
		\coste Exponencial de orden 3
	*/
	int countExpressions();

//_______ CONSULTORES

	/** @brief Consultora de cantidad de paréntesis abiertos

		\pre <em>Cierto</em>
		\post Devuelve la cantidad de paréntesis que se encuentran abiertos en un momento determinado de la lectura de entrada 
		\coste Constante
	*/
	int get_p() const;

	/** @brief Consultora de buffer de entrada

		\pre <em>Cierto</em>
		\post Devuelve el contenido del buffer de entrada
		\coste Constante
	*/
	string get_buff() const;

	/** @brief Cosultora de texto de tratamiento inmediato

		\pre <em>Cierto</em>
		\post Devuelve el contenido del texto de tratamiento inmediato
		\coste Constante
	*/
	string get_str() const;

};

#endif
