OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++0x

all: main.exe

main.exe: main.o Expression.o Environment.o PrimitiveOperationSpace.o VariableSpace.o OperationSpace.o
	g++ -o main.exe main.o Expression.o Environment.o PrimitiveOperationSpace.o VariableSpace.o OperationSpace.o

main.o: main.cc FunctionsIO.hh Expression.hh Environment.hh PrimitiveOperationSpace.hh VariableSpace.hh OperationSpace.hh
	g++ -c main.cc $(OPTIONS)

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

clean:
	rm -f *~
	rm -f *.o
	rm -f *.exe
