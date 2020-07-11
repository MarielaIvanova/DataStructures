#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"Container.h"
using namespace std;


template <typename T>
class List : public Container<T> {
	Object<T>* front;
	Object<T>* back;
	char type;
	int size;

public:
	List();
	List(std::vector<T> &other);
	bool member(const T& x);
	void push(const T& x);
	//void remove(const T& x);
	//T top();
	void print()const;
	//void addEl();
};

template <typename T>
List<T>::List() :front(nullptr), back(nullptr), type('L'), size(0) {}

template<typename T>
List<T>::List(std::vector<T>& other) {
	List();
	int i = 0;
	while (!other.empty()) {
		push(other[i]);
		other.erase(other.begin());
	}
}


template<typename T>
void List<T>::push(const T& x) {
	if (front == nullptr && back == nullptr) {
		Object<T>* n = new Object<T>(x, nullptr, nullptr);
		front = n;
		back = n;
	}
	else{
		Object<T>* curr = new Object<T>(x, nullptr, nullptr);
		curr->prevOb = back;
		back->nextOb = curr;
		back = curr;		
	}
	size++;
}

/*template <typename T>
T List<T>::top() {return back->data;}

template <typename T>
void List<T>::remove(const T& x){
	Object<T>* curr = front;
	while (curr->data == front->data) { front = curr->nextOb; }
	while (curr != back){
		if (curr->data == x) {
			cout << curr->nextOb->data << "\\\\\\\\" << endl;
			cout << curr->prevOb->data << "\\\\\\\\" << endl;
			cout << curr->prevOb->nextOb->data << "\\\\\\\\" << endl;
			curr->nextOb->prevOb = curr->prevOb;
			curr->prevOb->nextOb = curr->nextOb;
			size--;
		}
		curr = curr->nextOb;
	}
	if (curr == back && curr->data == back->data) {back = curr->prevOb;}
	
}
*/

template <typename T>
bool List<T>::member(const T& x) {

	Object<T>* ob = front;
	while (ob != nullptr)
	{
		if (ob->data == x) {
			cout << "The result of function member is True"<<endl; 
			return true; }
		else { ob = ob->nextOb; }
	}
	cout << "The result of function member is False"<<endl;
	return false;
}

template <typename T>
void List<T>::print()const {
	Object<T>* ob = front;
    cout << "List: ";
	while (ob) {
		std::cout << ob->data << " ";
		ob = ob->nextOb;
	}
	cout << endl;
}