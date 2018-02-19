#ifndef NEWTON_H
#define NEWTON_H

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

template <typename T>
class Newton;

template<class T>
ostream& operator<< (ostream& out , const Newton<T> & n);


template <typename T>
class Newton 
{
	private:
		vector <tuple <T,T> > intervalData;
		vector <vector <T> > polyTable;

	public:

		Newton();

		~Newton();

		void AddValues(const T & x, const T & y);

		T operator[](const int placer) const;

		void calcNewton();

		friend ostream& operator<< <T> (ostream& out , const Newton<T> & n);

		T interpolantVals(const T & x) const;

};

template <typename T>
class Compare
{
	public:
		bool operator() (const tuple <T,T> lhs, const tuple <T,T> rhs) const
		{
			return (get<0>(lhs)) < (get<0>(rhs));
		}
};
#include "newton.hpp"
#endif