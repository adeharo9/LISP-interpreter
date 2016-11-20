#ifndef VARIABLESPACE_HH
#define VARIABLESPACE_HH

#include <map>
#include "Expression.hh";

using namespace std;

class VariableSpace {
private:

    /* INVARIANTE
    	- Todas las expresiones que intervienen en operaciones de adición o
    	  de modificación de una variable se evalúan previamente a la
    	  ejecución de dichas operaciones

    */

    map<string, Expression> variableMap;

public:

	//_______ CONSTRUCTORES

	VariableSpace();
	/* Pre: cierto */
	/* Post: el resultado es un mapa de variables vacío */

	VariableSpace(string key, const Expression& exp);
	/* Pre: 'key' es un string no vacío */
	/* Post: el resultado es un mapa de variables inicializado con la
			 variable de clave 'key' y expresión 'exp' */

	VariableSpace(const VariableSpace& inVariableSpace);
	/* Pre: cierto */
	/* Post: el resultado es un objeto copia de inVariableSpace */
	
	//_______ DESTRUCTORES

	~VariableSpace();
	/* Pre: cierto */
	/* Post: libera los recursos locales del parámetro implícito al salir
			 de un ámbito de visibilidad */

	//_______ MODIFICADORES

	void add(string key, const Expression& exp);
	/* Pre: 'key es un string no vacío;
			el mapa de variables del parámetro implícito no contiene una
			variable con clave 'key */
	/* Post: se añade al mapa de variables del parámetro implícito la 
			 variable con clave 'key' y expresión 'exp' */

	void update(string key, const Expression& exp);
	/* Pre: 'key' es un string no vacío;
			el mapa de variables del parámetro implícito contiene una
			variable con clave 'key' */
	/* Post: la expresión de la variable con clave 'key' en el mapa de
			 variables del parámetro implícito pasa a ser 'exp' */

	//_______ CONSULTORES

    bool exists(string key) const;
    /* Pre: 'key' es un string no vacío*/
    /* Post: devuelve cierto si la variable con clave 'key' existe en el
    		 mapa de variables del parámetro implícito;
    		 en otro caso, devuelve falso */

	//_______ I/O

	void write_map() const;
	/* Pre: el mapa de variables del parámetro implícito no está vacío */
	/* Post: se ha escrito el contenido del mapa de variables del parámetro
			 implícito por el canal estándar de salida; en caso que el
			 resultado de evaluar la expresión sea indefinido, se escribe
			 "indefinido" */

	void write_var(string key) const;
	/* Pre: 'key' es un string no vacío;
			el mapa de variables del parámetro implícito contiene una
			variable con clave 'key' */
	/* Post: se ha escrito el contenido de la variable con clave 'key' por
			 el canal estándar de salida; en caso que el resultado de
			 evaluar la expresión sea indefinido, se escribe "indefinido" */

	};

#endif
