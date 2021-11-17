OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

programa.exe: programa.o Cjt_mensajes.o Cjt_rejillas.o Rejilla.o
	g++ -o programa.exe programa.o Cjt_rejillas.o Rejilla.o Cjt_mensajes.o
	
programa.o: programa.cc Cjt_mensajes.hh Cjt_rejillas.hh Rejilla.hh
	g++ -c programa.cc $(OPCIONS)

Cjt_mensajes.o: Cjt_mensajes.cc Cjt_mensajes.hh
	g++ -c Cjt_mensajes.cc $(OPCIONS)	

Cjt_rejillas.o: Cjt_rejillas.cc Cjt_rejillas.hh Cjt_mensajes.hh
	g++ -c Cjt_rejillas.cc $(OPCIONS)

Rejilla.o: Rejilla.cc Rejilla.hh
	g++ -c Rejilla.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.gch
