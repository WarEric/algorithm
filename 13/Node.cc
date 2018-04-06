/*
 * 红黑树节点相关的类成员函数和非成员函数的实现
 * 
 * by wareric@163.com
 * 2018-04-06 
 */
#include "Node.h"
using std::string;

Node::Node(int key, string color, Node *parent, Node *left, Node *right)
{
	this->key = key;
	this->parent = parent;
	this->left = left;
	this->right = right;
	this->color = color;
}

Node::Node(int key, string color)
{
	this->key = key;
	this->color = color;
	this->left = NULL;
	this->right = NULL;
}

int Node::getKey()
{
	return key;
}

string Node::getColor()
{
	return color;
}

void Node::setKey(int key)
{
	this->key = key;
}

void Node::setColor(string color)
{
	this->color = color;
}


