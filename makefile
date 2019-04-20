
#Elad Motzny 204093694
#Alex Fishman 319451514

all: a.out
	 ./a.out

a.out: Document.o Editor.o main.o
	   g++ -std=c++0x Document.o Editor.o main.o

main.o: main.cpp
		g++ -std=c++0x --compile main.cpp -o main.o

Document.o: Document.cpp Document.h
		g++ -std=c++0x --compile Document.cpp -o Document.o

Editor.o: Editor.cpp Editor.h Document.h
		g++ -std=c++0x --compile Editor.cpp -o Editor.o

clean: 
		rm -f Document.o Editor.o main.o a.out