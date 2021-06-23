#pragma once
#include"andGate.h"
#include "orGate.h"
#include<vector>
class Simulator
{	
	vector<Node*> NA;
	vector<Gate*> GA;
public:
	Simulator();
	~Simulator();
	int getNSize();
	int getGSize();
	Node* findNode(string);
	Node* addNode(string);
	Node* findOrAddNode(string);
	void printAllNodes();
	Gate* addGate(string);
	void sim();
	void load(string);
};

