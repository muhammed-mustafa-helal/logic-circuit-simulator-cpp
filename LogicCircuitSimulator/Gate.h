#pragma once
#include "Node.h"

class Gate {

protected:
	Node* in1;
	Node* in2;
	Node* out1;
public:
	Gate();
	void setIn1(Node*);
	void setIn2(Node*);
	void setOut1(Node*);
	Node* getIn1();
	Node* getIn2();
	Node* getOut1();
	virtual void calcOut() = 0;
};