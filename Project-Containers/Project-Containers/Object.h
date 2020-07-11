#pragma once

template <typename T>
struct Object {
	T data;
	Object<T>* nextOb;
	Object<T>* prevOb;

	Object():nextOb(nullptr), prevOb(nullptr) {}

	Object(const T& data, Object<T>* nextOb, Object<T>* prevOb): data(data), nextOb(nextOb), prevOb(prevOb){}
};
