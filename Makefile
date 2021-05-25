TARGET=main
CXX=gcc
CFLAG=-Wall
OBJDIR=object
OBJECT=main.o func.o recommend.o code.o
$(TARGET): $(OBJECT)
	$(CXX) $(CFLAGS) -o $(TARGET) $(OBJECT) -lm
	mv *.o $(OBJDIR)
	./main
main.o: main.c
	$(CXX) $(CFLAGS) -c main.c -lm
func.o: func.c
	$(CXX) $(CFLAGS) -c func.c -lm
recommend.o: recommend.c
	$(CXX) $(CFLAGS) -c recommend.c -lm
code.o: code.c
	$(CXX) $(CFLAGS) -c code.c -lm
clean:
	rm -f $(OBJECT) $(TARGET)
run :
	./main