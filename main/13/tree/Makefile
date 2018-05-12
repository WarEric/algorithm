CC = g++
all : TestRBTree TestBSTree

TestRBTree : TestRBT.cc RBTree.h RBTNode.h
	g++ -o TestRBTree TestRBT.cc

TestBSTree : TestBST.cc BSTree.h BSTNode.h
	g++ -o TestBSTree TestBST.cc

.PHONY:clean

clean:
	-rm -f TestRBTree TestBSTree
