CC = g++
all : TestOSTree TestITVTree

TestOSTree : TestOST.cc OSTree.h OSTNode.h
	g++ -o TestOSTree TestOST.cc
TestITVTree : TestITV.cc ITVTree.h ITVNode.h
	g++ -o TestITVTree TestITV.cc

.PHONY:clean

clean:
	-rm -f TestOSTree TestITVTree
