#include <iostream>
#include <vector>
#include "Object.h"
#include "Stack.h"
#include "Queue.h"
#include "List.h"
#include "Container.h"
#include "ListOfContainers.h"

int main()
{
	/// TESTS
	std::vector<int> v1 = { 7, 5, 16, 8 };
	std::vector<int> v2 = { 6, 4, 15, 7 };
	std::vector<int> v3 = { 9, 6, 17, 9 };


	Container<int>* s = new Stack<int>(v1);
	s->print();

	Container<int>* q = new Queue<int>(v2);
	q->print();
	
	Container<int>* l = new List<int>(v3);
	l->print();
	l->member(6);
	//l->remove(6);

	ListOfContainers<int>* lc = new ListOfContainers<int>();
	lc->add(s);
	lc->add(q);
	lc->add(l);
	
	lc->searchEl(7);
	lc->searchEl(122);

	lc->print();
	system("pause");
	return 0;
}
