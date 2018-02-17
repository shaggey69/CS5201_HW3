#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

template <typename T>   
Newton<T>::Newton()
{
}

template <typename T>   
Newton<T>::~Newton()
{
}

template <typename T>   
void Newton<T>::AddValues(const T & x, const T & y);
{
	intervalData.push_back(tuple <T,T> (x,y) );
}

template <typename T>   
 ostream& operator<< (ostream& out , const Newton<T> & n)
{

  for ( auto &i : n.intervalData)
  {
  	out << intervalData[i];
  }

  return out;
}