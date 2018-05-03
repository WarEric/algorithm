CC = g++
all : TestOSTree

TestOSTree : TestOST.cc OSTree.h OSTNode.h
	g++ -o TestOSTree TestOST.cc

.PHONY:clean

clean:
	-rm -f TestOSTree
