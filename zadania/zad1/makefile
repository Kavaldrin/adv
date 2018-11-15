CC = g++
DEBUG = -g
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)
CPPFLAGSD = -Wall -pedantic-errors -c $(DEBUG) -std=c++14 -MMD
CPPFLAGS = -Wall -pedantic-errors $(DEBUG) -std=c++14 -MF -MM
LIBS = $(wildcard *.h)
DEPS := $(OBJS:.o=.d)
EXE = zad1


all: $(SRC) $(EXE)


$(EXE): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CPPFLAGSD) $< -o $@

clean:
	rm *.o *.d $(EXE)
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXE)
gdb:
	gdb $(EXE)
run: 
	./$(EXE)
tar:
	tar czf $(EXE).tar.gz $(SRC) $(LIBS)

-include $(DEPS)
.PHONY: clean valgrind gdb run tar
