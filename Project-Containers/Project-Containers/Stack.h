#pragma once
#include<iostream>
#include<vector>
#include"Container.h"
using namespace std;

template <typename T>
class Stack : public Container<T>
{
	int size;
	char type;
	Object<T>* top;

public:
	Stack();
	Stack(std::vector<T>& other);
	bool member(const T& x);
	void print()const;
	void push(const T& x);
	//void remove(const T& x);
};

template <typename T>
Stack<T>::Stack():size(0),type('S'),top(nullptr){}

template <typename T>
Stack<T>::Stack(std::vector<T> &other) {
	Stack();
	int i = 0;
	while (!other.empty()) {
		push(other[i]);
		other.erase(other.begin());
	}
}

template<typename T>
void Stack<T>::push(const T& x) {
	if (top == nullptr) {
		Object<T>* n = new Object<T>(x, nullptr, nullptr);
		top = n;
	}
	else {
		Object<T>* c = new Object<T>(x, nullptr, nullptr);
		Object<T>* curr = top;
		while (curr->nextOb != nullptr)
		{
			curr = curr->nextOb;
		}
		curr->nextOb = c;
		c->prevOb = curr;
	}
	size++;
}

/*template <typename T>
void Stack<T>::remove(const T& x) {
	Object<T>* curr = top;
	if (curr->data == top->data) {top= curr->nextOb; }
	while (curr != nullptr) {
		if (curr->data == x) {
			curr->prevOb->nextOb = curr->nextOb;
			size--;
		}
		curr = curr->nextOb;
	}
}*/

template <typename T>
bool Stack<T>::member(const T& x) {
	Object<T>* curr = top;
	while (curr) {
		if (curr->data == x) { 
			cout << "The result of function member is True"<<endl;
			return true; }
		else {curr = curr->nextOb; }
	}
	cout << "The result of function member is False"<<endl;
	return false;
}

template <typename T>
void Stack<T>::print()const {
	Object<T>* curr = top;
	cout << "Stack: ";
	while (curr->nextOb) {
		curr=curr->nextOb;
	}
	while (curr) {
		cout << curr->data<<" ";
		curr = curr->prevOb;
	}
	cout << endl;
}