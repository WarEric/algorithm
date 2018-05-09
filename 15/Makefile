all: cutT2B

cutT2B: cutrod.cc CutRod.o
	g++ -o cutT2B cutrod.cc CutRod.o
CutRod.o: CutRod.cc CutRod.h
	g++ -c CutRod.cc

.PHONY:
	clean
clean:
	rm -f cutT2B CutRod.o
