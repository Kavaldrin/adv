CC = g++
DEBUG = -g
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)
CPPFLAGS = -Wall -pedantic-errors -std=c++14 -MMD -MP
CPPFLAGS += $(DEBUG)
LIBS = $(wildcard *.h)
DEPS := $(OBJS:.o=.d)
EXE = zad3


all: $(SRC) $(EXE)


$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CPPFLAGS) -c $< -o $@

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
