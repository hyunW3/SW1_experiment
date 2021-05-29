TARGET=main
CXX=gcc
CFLAG=-Wall
OBJDIR=object
OBJECT=main.o func.o recommend.o rand.o print_session.o insert_data.o select.o
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
rand.o: rand.c
	$(CXX) $(CFLAGS) -c rand.c -lm
select.o: select.c
	$(CXX) $(CFLAGS) -c select.c -lm
print_session.o: print_session.c
	$(CXX) $(CFLAGS) -c print_session.c -lm
insert_data.o: insert_data.c
	$(CXX) $(CFLAGS) -c insert_data.c -lm
clean:
	rm -f $(OBJECT) $(TARGET)
run :
	./main