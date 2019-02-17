recirocal: main.o reciprocal.o
	g++ -o reciprocal main.o reciprocal.o

main.o: main.c reciprocal.hpp
	gcc -c main.c

reciprocal.o: reciprocal.cpp reciprocal.hpp
	g++ -c reciprocal.cpp

clean:
	rm -f *.o reciprocal
