all: cut1

cut1: cutrod.cc CutRod.o
	g++ -o cut1 cutrod.cc CutRod.o
CutRod.o: CutRod.cc CutRod.h
	g++ -c CutRod.cc

.PHONY:
	clean
clean:
	rm cut1 CutRod.o
