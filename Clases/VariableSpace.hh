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

    map<string, Expression> varMap;

public:

	//_______ CONSTRUCTORES

	VariableSpace();
	/* Pre: cierto */
	/* Post: crea un objeto con mapa de variables 'varMap'
			 vacío */

	VariableSpace(string key, const Expression& exp);
	/* Pre: 'key' es un string no vacío */
	/* Post: crea un objeto con mapa de variables 'varMap' inicializado
			 con la variable de clave 'key' y expresión 'exp' */

	VariableSpace(const VariableSpace& varSpace);
	/* Pre: cierto */
	/* Post: crea un objeto copia de 'varSpace' */
	
	//_______ DESTRUCTORES

	~VariableSpace();
	/* Pre: cierto */
	/* Post: libera los recursos locales del parámetro implícito al salir
			 de un ámbito de visibilidad */

	//_______ MODIFICADORES

	void add(string key, const Expression& exp);
	/* Pre: 'key' es un string no vacío;
			el mapa de variables 'varMap' del parámetro implícito no
			contiene ninguna variable con clave 'key' */
	/* Post: se añade al mapa de variables 'varMap' del parámetro
			 implícito la variable con clave 'key' y expresión 'exp' */

	void update(string key, const Expression& exp);
	/* Pre: 'key' es un string no vacío;
			el mapa de variables 'varMap' del parámetro implícito contiene
			una	variable con clave 'key' */
	/* Post: la expresión de la variable con clave 'key' en el mapa de
			 variables 'varMap' del parámetro implícito pasa a ser 'exp' */

	//_______ CONSULTORES

    bool exists(string key) const;
    /* Pre: 'key' es un string no vacío */
    /* Post: devuelve cierto si la variable con clave 'key' existe en el
    		 mapa de variables 'varMap' del parámetro implícito;
    		 en otro caso, devuelve falso */

	//_______ I/O

	void write_map() const;
	/* Pre: el mapa de variables 'varMap' del parámetro implícito no está
			vacío */
	/* Post: se ha escrito el contenido del mapa de variables 'varMap' del
			 parámetro implícito por el canal estándar de salida;
			 en caso que el resultado de evaluar la expresión sea
			 indefinido, se escribe "indefinido" */

	void write_var(string key) const;
	/* Pre: 'key' es un string no vacío;
			el mapa de variables 'varMap' del parámetro implícito contiene
			una variable con clave 'key' */
	/* Post: se ha escrito el contenido de la variable con clave 'key' por
			 el canal estándar de salida;
			 en caso que el resultado de evaluar la expresión sea
			 indefinido, se escribe "indefinido" */

};

#endif
