# TARGETS
# target : prerequisites
#  commnads

EXECUTABLE_NAME = main
CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17
LDFLAGS = -lmath

COMPILER_CALL = $(CXX) $(CXXFLAGS)

build: my_lib.o main.o
	$(COMPILER_CALL) main.o my_lib.o -o  $(EXECUTABLE_NAME)
main.o:
	$(COMPILER_CALL) main.cc -c
my_lib.o:
	$(COMPILER_CALL) my_lib.cc -c

execute:
	./main

clean:
	rm -f *.o
	rm -f main
