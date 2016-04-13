#include "Node.h"

Node::Node(uint16_t n){
	num = n;
	done = false;
	cost = MAX;
}

Node::~Node(){}

std::vector<Node *> Node::getConnectedNodes(){
	
}

bool Node::isConnectedNode(Node&){
	
}

uint16_t Node::getCost(Node *){
	
}

uint16_t Node::getNumber(){
	
}

bool Node::connectTo(Node&){
	
}

bool Node::disconnectTo(Node&){
	
}
