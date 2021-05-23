TARGET=main
CXX=gcc
CFLAG=-Wall
OBJDIR=object
OBJECT=main.o func.o recommand.o code.o
$(TARGET): $(OBJECT)
	$(CXX) $(CFLAGS) -o $(TARGET) $(OBJECT) -lm
	mv *.o $(OBJDIR)
main.o: main.c
	$(CXX) $(CFLAGS) -c main.c -lm
func.o: func.c
	$(CXX) $(CFLAGS) -c func.c -lm
recommand.o: recommand.c
	$(CXX) $(CFLAGS) -c recommand.c -lm
code.o: code.c
	$(CXX) $(CFLAGS) -c code.c -lm
clean:
	rm -f $(OBJECT) $(TARGET)