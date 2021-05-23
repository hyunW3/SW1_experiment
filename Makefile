TARGET=main
CXX=gcc
CFLAG=-Wall
OBJECT=main.o func.o recommand.o
$(TARGET): $(OBJECT)
	$(CXX) $(CFLAGS) -o $(TARGET) $(OBJECT)
main.o: main.c
	$(CXX) $(CFLAGS) -c main.c
func.o: func.c
	$(CXX) $(CFLAGS) -c func.c
recommand.o: recommand.c
	$(CXX) $(CFLAGS) -c recommand.c
clean:
	rm -f $(OBJECT) $(TARGET)