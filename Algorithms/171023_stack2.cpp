#include "stdafx.h"
#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node * prev;
	Node * next;
	
	Node(int data);
	~Node();
};

Node::Node(int data) {
	this->data = data;
	this->prev = NULL;
	this->next = NULL;
}

Node::~Node() {
	cout << "Node Closed with data : " << this->data << endl;
}

class Stack {
public:
	int length;
	Node * topnode;

	Stack();
	~Stack();
	
	void push(int data);
	void pop();
	int getLength();
};

Stack::Stack() {
	this->length = 0;
	this->topnode = NULL;
}

Stack::~Stack() {
	
}

void Stack::push(int data) {
	if (this->topnode == NULL) {
		length++;
		this->topnode = new Node(data);
	}
	else {
		length++;
		Node * old = this->topnode;
		this->topnode = new Node(data);
		this->topnode->prev = old;
		
	}
	cout << "pushed " << data << endl;
}

void Stack::pop() {
	if (this->topnode == NULL) {
		cout << "Error, stack empty" << endl;
	}
	else {
		length--;
		Node * old = this->topnode;
		this->topnode = this->topnode->prev;
		delete old;
	}
}

int Stack::getLength() {
	cout << this->length << endl;
	return this->length;
}

int main() {
	Stack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.pop();
	stack.pop();
	stack.getLength();
	while (1) {
		cout << "push(1), pop(2), getlength(3)" << endl;
		int N;
		cin >> N;
		if (N == 1) {
			int M;
			cout << "give push data" << endl;
			cin >> M;
			stack.push(M);
		}
		else if (N == 2) {
			cout << "pop" << endl;
			stack.pop();
		}
		else {
			stack.getLength();
		}
	
	
	}
}
