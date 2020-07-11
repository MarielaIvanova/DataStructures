#pragma once
#include<iostream>
#include<vector>
#include"Container.h"

template <typename T>
class Queue : public Container<T>
{
	int size;
	char type;
	Object<T>* front;

public:
	Queue();
	Queue(std::vector<T> &other);
	bool member(const T& x);
	void print()const;
	void push(const T& other);
	//void remove(const T& x);
};

template <typename T>
Queue<T>::Queue() :size(0), type('Q'), front(nullptr) {}

template <typename T>
Queue<T>::Queue(std::vector<T> &other) {
	Queue();
	int i = 0;
	while (!other.empty()) {
		push(other[i]);
		other.erase(other.begin());
	}
}

template<typename T>
void Queue<T>::push(const T& x) {
	if (front == nullptr) {
		Object<T>* n = new Object<T>(x, nullptr, nullptr);
		front = n;
	}
	else {
		Object<T>* c = new Object<T>(x, nullptr, nullptr);
		Object<T>* curr = front;
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
void Queue<T>::remove(const T& x) {
	Object<T>* curr = front;
	while (curr->data == front->data) { front = curr->nextOb; }
	while (curr!=nullptr) {
		if (curr->data == x) {
			curr->prevOb->nextOb = curr->nextOb;
			size--;
		}
		curr = curr->nextOb;
	}
}*/

template <typename T>
bool Queue<T>::member(const T& x) {
	Object<T>* curr = front;
	while (curr) {
		if (curr->data == x) {
			cout << "The result of function member is True"<<endl; 
			return true; }
		else { curr = curr->nextOb; }
	}
	cout << "The result of function member is False"<<endl;
	return false;
}

template <typename T>
void Queue<T>::print()const {
	Object<T>* curr = front;
	cout << "Queue: ";
	while (curr) {
		cout << curr->data << " ";
		curr = curr->nextOb;
	}
	cout << endl;
}