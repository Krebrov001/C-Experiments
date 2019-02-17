myprogram.out: myprogram.o mylib.o
	$(CXX) $(CFLAGS) -o $@ $^

myprogram.o: myprogram.c mylib.h
	$(CXX) $(CFLAGS) -c $<

mylib.o: mylib.c mylib.h
	$(CXX) $(CFLAGS) -c $<

clean:
	rm -f *.o *.out
