all: cutT2B cutB2T

cutT2B: cutrod.cc CutRod.o
	g++ -o cutT2B cutrod.cc CutRod.o
CutRod.o: CutRod.cc CutRod.h
	g++ -c CutRod.cc

cutB2T: cutrodb2t.cc CutRodB2T.o
	g++ -o cutB2T cutrodb2t.cc CutRodB2T.o
CutRodB2T.o: CutRodB2T.cc CutRodB2T.h
	g++ -c CutRodB2T.cc

.PHONY:
	clean
clean:
	rm -f cutT2B CutRod.o cutB2T CutRodB2T.o
