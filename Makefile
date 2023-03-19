main: main.o unindent.o indent.o
	g++ -o main main.o unindent.o indent.o

main.o: main.cpp unindent.h indent.h 

unindent.o: unindent.h unindent.h

indent.o: indent.cpp indent.h

clean:
	rm -f main.o unindent.o indent.o 
