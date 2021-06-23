#pragma once
#include <string>
using namespace std;

class Node {
	string name;
	short value;
public:
	Node();
	Node(string n);
	Node(string n, short v);
	void setName(string n);
	void setValue(short v);
	string getName();
	short getValue();
	void printNode();
};

