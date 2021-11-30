OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Cjt_mensajes.o Cjt_rejillas.o Rejilla.o Cjt_patrones.o Patron.o
	g++ -o program.exe program.o Cjt_rejillas.o Rejilla.o Cjt_mensajes.o
	
program.o: program.cc Cjt_mensajes.hh Cjt_rejillas.hh Rejilla.hh
	g++ -c program.cc $(OPCIONS)

Cjt_mensajes.o: Cjt_mensajes.cc Cjt_mensajes.hh
	g++ -c Cjt_mensajes.cc $(OPCIONS)	

Cjt_rejillas.o: Cjt_rejillas.cc Cjt_rejillas.hh Cjt_mensajes.hh
	g++ -c Cjt_rejillas.cc $(OPCIONS)

Rejilla.o: Rejilla.cc Rejilla.hh
	g++ -c Rejilla.cc $(OPCIONS)

Cjt_patrones.o: Cjt_patrones.cc Cjt_patrones.hh
	g++ -c Cjt_patrones.cc $(OPCIONS)

Patron.o: Patron.cc Patron.hh BinTree.hh
	g++ -c Patron.cc $(OPCIONS)

tar: Rejilla.cc Rejilla.hh Cjt_rejillas.cc Cjt_rejillas.hh Cjt_mensajes.cc Cjt_mensajes.hh program.cc Patron.hh Patron.cc Cjt_patrones.hh Cjt_patrones.cc BinTree.hh html.zip Makefile
	tar -cvf practica.tar Rejilla.cc Rejilla.hh Cjt_rejillas.cc Cjt_rejillas.hh Cjt_mensajes.cc Cjt_mensajes.hh program.cc Patron.hh Patron.cc Cjt_patrones.hh Cjt_patrones.cc BinTree.hh html.zip Makefile

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.gch
