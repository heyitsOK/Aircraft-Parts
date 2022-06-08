
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;


template <typename T>
class Array {

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		void add(T);
		int getSize();
		bool isFull();

		//operator overloads
		T operator [] (int index);
		friend ostream & operator << (ostream &out, const Array<T> &a);
	private:
		int size;
		T* elements;
	
};

//overloading the << operator to print out every element
template <typename T> ostream & operator << (ostream &out, const Array<T> &a) {
	for (int i = 0; i < a.getSize(); i++) {
		out << a[i] << endl;
	}
	return out;
}

template <typename T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

template <typename T>
Array<T>::~Array(){
	delete [] elements;
}

template <typename T>
void Array<T>::add(T t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

template <typename T>
int Array<T>::getSize(){
	return size;
}

template <typename T>
bool Array<T>::isFull(){
	return size >= MAX_ARR;
}

//[] operator overload
template <typename T>
T Array<T>::operator [] (int index){
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

#endif