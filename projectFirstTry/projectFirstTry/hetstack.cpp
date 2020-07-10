#include<iostream>
#include<cassert>
using namespace std;

#include <stack>
#include <queue>
#include <list>

class object {
public:
	virtual void print() = 0;
	virtual int length() = 0;
	virtual bool member() = 0;
};

typedef list<object*> listObj;
template <typename T>
stack<T> Tstack;
template <typename T>
queue<T> Tqueue;
//typedef queue<T> Tqueue;
template <typename T>
list<T> Tlist;
//typedef list<T> Tlist;


class polyList : public listObj, public object {
public: 
	void print();
	int length();
	bool member();
};

void polyList::print()
{
	polyList ps(*this);//копира хетерогенния лист в листа ps

	object *x;
	while (!ps.empty()) {
		ps.pop_back;
		x->print(); //разрешава се динамично
	}
	cout << endl;
}

int polyList::length() {
	polyList ps(*this);
	int num = 0;
	object *x;
	while (!ps.empty())
	{
		//func pop za list
		ps.pop_front(x);
		cout << x->length() << " ";
		num++;
	}
}

template <typename T>
class newStack : public Tstack, public object {
public:
	void print();
	int length();
	bool member();
};

template<typename T>
void newStack<T>::print() {
	Tlist::print();
}

template<typename T>
int newStack<T>::length() {
	return Tlist::length();
}

template <typename T>
class newList: public Tlist, public object {
	void print();
	int length();
};

template<typename T>
void newList<T>::print() {
	Tlist temp(*this);
	temp.print();
}

template<typename T>
int newList<T>::length() {
	Tlist temp(*this);
	temp.length();
}

template <typename T>
class newQueue : public Tqueue, public object {
	void print();
	int length();
};

template<typename T>
void newQueue<T>::print() {
	Tqueue temp(*this);
	temp.print();
}

template<typename T>
int newQueue<T>::length() {
	Tqueue temp(*this);
	temp.length();
}

int main() {
	return 0;
}