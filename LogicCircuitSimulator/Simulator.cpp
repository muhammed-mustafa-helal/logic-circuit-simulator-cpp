#include "Simulator.h"
#include <fstream>
using namespace std;


Simulator::~Simulator() {
	int i = 0;
	for ( i = 0; i < NA.size(); i++)
	{
		delete NA[i];
	}
	for ( i = 0; i < GA.size(); i++)
	{
		delete GA[i];
	}
}

int Simulator::getNSize() {
	return NA.size();
}

int Simulator::getGSize() {
	return GA.size();
}

Node* Simulator::findNode(string N) {
	int i;
	for ( i = 0; i < NA.size(); i++)
	{
		if (NA[i]->getName()==N)
		{
			return NA[i];
		}
	}
	return NULL;

}

Node* Simulator::addNode(string N) {
	Node*p = new Node(N);
	NA.push_back(p);
	return p;
}

Node* Simulator::findOrAddNode(string N) {
	Node* node= findNode(N);
	if (node == NULL)node = addNode(N);
	return node;
}

void Simulator::printAllNodes() {
	int i = 0;
	for ( i = 0; i < NA.size(); i++)
	{
		NA[i]->printNode();
			
	}
}

Gate* Simulator::addGate(string type) {
	/*
	* one Example that we should use a factory design pattern in.
	* instead of having to alter the logic simulator everytime we have to support 
	* a new gate, we can create a class called GatesFactory to support the new gates and let the logic simulator
	* work with all the supported gates abstractly.
	*/
	Gate* p = NULL;
	if (type == "AND")
		p = new andGate();
	else if (type == "OR")
		p = new orGate();
	GA.push_back(p);
	return p;
}

void Simulator::sim() {
	int i;
	for ( i = 0; i < GA.size(); i++)
	{
		GA[i]->calcOut();
	}
}

void Simulator::load(string fileName) {
	//open a file
	ifstream f1;
	f1.open(fileName);
	while (!f1.eof())
	{
		string s;
		f1 >> s;
		if (s == "SET")
		{
			string N; short V;
			f1 >> N >> V;
			findOrAddNode(N)->setValue(V);
		}
		else if (s == "OUT")
		{
			string N;
			f1 >> N;
			if (N == "ALL")
			{
				printAllNodes();
			}
			else
				findOrAddNode(N)->printNode();
		}
		else if (s == "SIM") {
			sim();
		}
		else {
			Gate* g = addGate(s);
			string n1, n2, n3;
			f1 >> n1 >> n2 >> n3;
			g->setIn1(findOrAddNode(n1));
			g->setIn1(findOrAddNode(n2));
			g->setIn1(findOrAddNode(n3));

		}
	}
	f1.close();
}
