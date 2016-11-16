#ifndef EXPRESSION_HH
#define EXPRESSION_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
#endif

using namespace std;

/** @class Expression
    @brief Representa una expresión evaluable con atributos: valor, operando y lista de expresiones

    Todas las operaciones son de <b>coste (?)</b>
*/

class Expression{
private:

    int value;
    string op;
    list<Expression*> lExp;

public:

//_______ CONSTRUCTORS

/** @brief Creadora por defecto. 

    Se ejecuta automáticamente al declarar una expresión.
    \pre <em>cierto</em>
    \post El resultado es una prenda sin valor, sin operando
*/   

Expression();
/* Pre*/

Expression(int inValue);

Expression(const string& inOp,const list<Expression*>& inLExp);

Expression(const list<Expression*>& inLExp);

Expression(const Expression& inExp);

//_______ DESTRUCTORS

~Expression();

//_______ MODIFICADORS

void evaluate();

//_______ I/O

void read();

void write() const;

};

#endif
