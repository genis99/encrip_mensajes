OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o ParInt.o BinTreeIOParInt.o
	g++ -o program.exe program.o ParInt.o BinTreeIOParInt.o
	rm *.o

Cjt_rejillas.o: program.cc ParInt.hh BinTreeIOParInt.hh BinTree.hh
	g++ -c Cjt_rejillas.cc $(OPCIONS)

Rejilla.o: Rejilla.hh Rejilla.cc
	g++ -c Rejilla.cc $(OPCIONS)

Patron.o: Patron.cc BinTree.hh Patron.hh
	g++ -c Patron.cc $(OPCIONS)

clean:
	rm -vf *.o
	rm -vf *.exe
	rm -vf *.gch
