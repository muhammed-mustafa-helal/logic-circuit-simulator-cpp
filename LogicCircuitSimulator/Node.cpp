#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(){
	name = "";
	value = 0;
}

Node::Node(string n) {
	name = n;
}

Node::Node(string n, short v) {
	name = n;
	value = v;
}

void Node::setName(string n) {
	name = n;
}

void Node::setValue(short v) {
	value = v;
}

string Node::getName() {
	return name;
}

short Node::getValue() {
	return value;
}

void Node::printNode() {
	cout << name << " " << value << endl;
}