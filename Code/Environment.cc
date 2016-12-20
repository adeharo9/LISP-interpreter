/** @file Environment.cc
    @brief Implementación de la clase Environment
*/

#include "Environment.hh"
#include "Expression.hh"
#include "PrimitiveOperationSpace.hh"
#include "VariableSpace.hh"
#include "OperationSpace.hh"

using namespace std;

typedef void (*primitiveOperation)(Expression&);

//_______ CONSTRUCTORES

Environment::Environment()
{
}

Environment::Environment(const Environment& env)
{
	primOpSpace = env.primOpSpace;
	varSpace = env.varSpace;
	opSpace = env.opSpace;
}

//_______ DESTRUCTORES

Environment::~Environment()
{
}

//_______ MODIFICADORES

void Environment::set_var(string key, const Expression& exp)
{
	varSpace.set(key, exp);
}

void Environment::set_op(string key, string parameters, string exp)
{
	opSpace.set(key, parameters, exp);
}

void Environment::erase_varspace()
{
	varSpace.clear();
}

//_______ CONSULTORES

bool Environment::is_primitive(string key) const
{
	return primOpSpace.exists(key);
}

bool Environment::is_op(string key) const
{
	return primOpSpace.exists(key) or opSpace.exists(key);
}

bool Environment::exists(string key) const
{
	return primOpSpace.exists(key) or varSpace.exists(key) or opSpace.exists(key);
}

bool Environment::exists_var(string key) const
{
	return varSpace.exists(key);
}

bool Environment::exists_op(string key) const
{
	return opSpace.exists(key);
}

primitiveOperation Environment::get_prim(string key)
{
	return primOpSpace.get(key);
}

Expression& Environment::get_var(string key)
{
	return varSpace.get(key);
}

pair<string, string> Environment::get_op(string key)
{
	return opSpace.get(key);
}

int Environment::num_pars_op(string key)
{
	return opSpace.num_pars(key);
}

//_______ I/O

void Environment::write() const
{
	varSpace.write();
	opSpace.write();
}

void Environment::write_var(string key)
{
	varSpace.write_var(key);
}

void Environment::write_op(string key)
{
	opSpace.write_op(key);
}
