#include "Gate.h"

Gate::Gate() {
	in1 = NULL;
	in2 = NULL;
	out1 = NULL;
}

void Gate::setIn1(Node*n) {
	in1 = n;
}

void Gate::setIn2(Node* n) {
	in2 = n;
}

void Gate::setOut1(Node* s) {
	out1 = s;
}

Node* Gate::getIn1() {
	return in1;
}

Node* Gate::getIn2() {
	return in2;
}

Node* Gate::getOut1() {
	return out1;
}
