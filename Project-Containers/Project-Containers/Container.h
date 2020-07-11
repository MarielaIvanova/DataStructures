#pragma once
#include<iostream>
//#include<vector>
//#include<string>
#include"Object.h"

template <typename T>
class Container {
public:
	Container<T>* next;
	Container<T>():next(nullptr){}

	virtual bool member(const T& x) = 0;
	virtual void print() const = 0;
	//virtual T top() = 0;
	//virtual void remove(const T& x) = 0;
};
