target test: Node.o RBTree.o
	g++ -o test test.cc Node.o RBTree.o
Node.o: Node.cc Node.h
	g++ -c Node.cc
RBTree.o: RBTree.cc RBTree.h
	g++ -c RBTree.cc
.PHONY: clean
clean:
	-rm -f test Node.o RBTree.o
