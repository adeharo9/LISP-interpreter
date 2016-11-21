OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++0x

all: main.exe

main.exe: main.o
	g++ -o main.exe main.o

main.o: main.cc Expression.hh Environment.hh PrimitiveOperationSpace.hh VariableSpace.hh OperationSpace.hh
	g++ -c main.cc $(OPTIONS)

clean:
	rm -f *~
	rm -f *.o
	rm -f *.exe
