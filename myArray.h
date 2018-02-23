#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
using namespace std;


template <typename T>
class MyArray;

template<class T>
ostream& operator<< (ostream& out ,  MyArray<T> & arr);

template <class T>
class MyArray
{
 
  int m_size;

  T* ptr_to_data;         

  void arrayCopy (const MyArray<T> & source);

  
public:
  
  MyArray(const int size);

  MyArray();

  MyArray(const MyArray<T>& rhs);

  ~MyArray();

	T & operator[](const int index);

	int getSize() const {return m_size;}

	void setSize(const int n);

	void clear(); 

  MyArray<T>& operator= (const MyArray<T>& rhs);  

	MyArray<T>& operator= (const T);  	
  
  void insert(const T & x, int pos);

  friend ostream& operator<< <T> (ostream& out , MyArray<T> & arr);

}; 


#include "myArray.hpp"

#endif
