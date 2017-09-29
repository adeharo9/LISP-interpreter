OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

all: program.exe clean_o

program.exe: program.o Input.o FunctionsIO.o Expression.o Environment.o PrimitiveOperationSpace.o VariableSpace.o OperationSpace.o
	g++ -o program.exe program.o Input.o FunctionsIO.o Expression.o Environment.o PrimitiveOperationSpace.o VariableSpace.o OperationSpace.o

program.o: program.cc FunctionsIO.hh Expression.hh Environment.hh
	g++ -c program.cc $(OPTIONS)

Input.o: Input.cc Input.hh
	g++ -c Input.cc $(OPTIONS)

FunctionsIO.o: FunctionsIO.cc FunctionsIO.hh Environment.hh Expression.hh Input.hh
	g++ -c FunctionsIO.cc $(OPTIONS)

Expression.o: Expression.cc Expression.hh
	g++ -c Expression.cc $(OPTIONS)

Environment.o: Environment.cc Environment.hh Expression.hh PrimitiveOperationSpace.hh VariableSpace.hh OperationSpace.hh 
	g++ -c Environment.cc $(OPTIONS)

PrimitiveOperationSpace.o: PrimitiveOperationSpace.cc PrimitiveOperationSpace.hh Expression.hh
	g++ -c PrimitiveOperationSpace.cc $(OPTIONS)

VariableSpace.o: VariableSpace.cc VariableSpace.hh Expression.hh
	g++ -c VariableSpace.cc $(OPTIONS)

OperationSpace.o: OperationSpace.cc OperationSpace.hh
	g++ -c OperationSpace.cc $(OPTIONS)

practica.tar: Makefile program.cc Input.hh Input.cc FunctionsIO.hh FunctionsIO.cc Expression.hh Expression.cc Environment.hh Environment.cc PrimitiveOperationSpace.hh PrimitiveOperationSpace.cc VariableSpace.hh VariableSpace.cc OperationSpace.hh OperationSpace.cc

	tar -cvf practica.tar Makefile program.cc Input.hh Input.cc FunctionsIO.hh FunctionsIO.cc Expression.hh Expression.cc Environment.hh Environment.cc PrimitiveOperationSpace.hh PrimitiveOperationSpace.cc VariableSpace.hh VariableSpace.cc OperationSpace.hh OperationSpace.cc

clean:
	rm -f *~
	rm -f *.o
	rm -f *.exe
	rm -f practica.tar

clean_o:
	rm -f *~
	rm -f *.o
