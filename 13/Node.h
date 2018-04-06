#ifndef NODE_H
#define NODE_H
#include<string>

class Node{
	friend bool operator==(const Node &n1, const Node &n2);
	friend bool operator!=(const Node &n1, const Node &n2);
	public:
		Node(int key, std::string color, Node *parent, Node *left, Node *right);
		Node(int key, std::string color);
		~Node(){};
		int getKey();
		std::string getColor();
		void setKey(int key);
		void setColor(std::string color);
		Node *parent, *left, *right;
	private:
		int key;
		std::string color;
};

inline
bool operator==(const Node &n1, const Node &n2)
{
	if(n1.key != n2.key) return false;
	if(n1.color != n2.color) return false;
	return true;
}

inline
bool operator!=(const Node &n1, const Node &n2)
{
	return !(n1 == n2);
}
#endif
