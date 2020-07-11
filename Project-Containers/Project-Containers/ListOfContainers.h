#pragma once
#include "Container.h"

template<typename T>
class ListOfContainers {
public:
	Container<T>* front;

	ListOfContainers();
	void add(Container<T>* other);
	void print()const;
	void searchEl(const T& x)const;
};

template <typename T>
ListOfContainers<T>::ListOfContainers():front(nullptr){}

template <typename T>
void ListOfContainers<T>::add(Container<T>* other) {
	
	if (this->front == nullptr) { this->front = other; }
	else {
		Container<T>* curr = this->front;
		while (curr->next != nullptr) { curr = curr->next; }
		curr->next = other;
	}
}

template <typename T>
void ListOfContainers<T>::print() const
{
	Container<T>* curr = front;
	cout << "All containers in the list:"<<endl;
	while (curr != nullptr)
	{
		cout << "*";
		curr->print();
		curr = curr->next;
	}
	cout << endl;
}

template <typename T>
void ListOfContainers<T>::searchEl(const T& x)const{
	if (front == nullptr){
		cout << "The element " << x << " is not found in the list of containers"<<endl;
		return;
	}
	Container<T>* curr = front;
	while (curr != nullptr)
	{
		if (curr->member(x)) {
			cout << "The element " << x << " is found in the list of containers"<<endl;
			return;
		}
		curr = curr->next;
	}
	cout << "The element " << x << " is not found in the list of containers"<<endl;
	return;
}