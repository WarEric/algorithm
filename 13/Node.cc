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
	this->color = NULL;
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


