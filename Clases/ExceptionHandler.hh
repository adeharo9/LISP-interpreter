#ifndef EXCEPTIONHANDLER_HH
#define EXCEPTIONHANDLER_HH

#include <exception>

using namespace std;

class ExceptionHandler : public exception {

private:

	const char* msg;

public:

	ExceptionHandler(const char* inMsg) : exception(), msg(inMsg)
	/* Pre: cierto */
	/* Post: genera una excepción que muestra, si se proporciona, un
			 mensaje por el canal estándar de salida de errores */
	{
	}

	const char* what() const noexcept()
	/* Pre: se ha generado una excepción */
	/* Post: devuelve el motivo por el que se ha generado la excepción, si
			 se proporciona, contenido en el mensaje msg */
	{
		return msg;
	};

};

#endif
