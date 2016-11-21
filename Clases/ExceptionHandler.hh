/** @file ExceptionHandler.hh
    @brief Especificación de la clase ExceptionHandler
*/

#ifndef EXCEPTIONHANDLER_HH
#define EXCEPTIONHANDLER_HH

#ifndef NO_DIAGRAM
#include <exception>
#endif

using namespace std;

/** @class ExceptionHandler
    @brief Controla la generación de excepciones en caso
    de fallo de las condiciones básicas de funcionamiento
    del programa

    Todas las operaciones son de <b>coste ?</b>
*/

class ExceptionHandler : public exception {

private:

	const char* msg;

public:

	//_______ CONSTRUCTORES

	/** @brief Constructora con valor de inicialización

		\pre <em>Cierto</em>
		\post Genera una excepción que muestra, si se proporciona, un
			 mensaje por el canal estándar de salida de errores
	*/
	ExceptionHandler(const char* inMsg) : exception(), msg(inMsg) {
	}

	//_______ CONSULTORES

	/** @brief Consultor de motivo de excepción

		\pre Se ha generado una excepción
		\post Devuelve el motivo por el que se ha generado la excepción, si
			 se proporciona, contenido en el mensaje msg
	*/
	const char* what() const throw() {
		return msg;
	};

};

#endif
