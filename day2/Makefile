CXX=clang++
CXXFLAGS=-std=c++11
PROGRAM1=part1
PROGRAM2= part2

default: $(PROGRAM1) $(PROGRAM2)

run: default
	cat input.data | ./part1
	cat input.data | ./part2

$(PROGRAM1): part1.cpp
$(PROGRAM2): part2.cpp

clean:
	rm -rf $(PROGRAM1) $(PROGRAM2) *.o
