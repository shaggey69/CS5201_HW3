#include <iostream>
#include <cmath>
#include <vector>
#include <typeinfo>

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
void Newton<T>::AddValues(const T & x, const T & y)
{
	intervalData.push_back(tuple <T,T> (x,y) );
	return;
}

template <typename T>   
T Newton<T>::operator[](const int placer) const
{
	for ( auto &i : intervalData)
		if (get<0>(i) == placer )
			return get<1>(i);
	return 0;
}

template <typename T>   
void Newton<T>::makeTable()
{
	vector<T> xValues;
	vector<T> yValues;
	for ( auto &i : intervalData)
	{
		xValues.push_back(get<0>(i)) ;
		yValues.push_back(get<1>(i)) ;
	}
	polyTable.push_back(yValues);

	int size = xValues.size();	

	for (int j = 1 ; j < size ; j++)
	{
		vector<T> temp;
		for (int z = 0; z < j ; z++)
			temp.push_back(0);

		for (int k = j ; k < size ; k++)
		{


			T o1,o2,o3,o4;
			o1 = xValues[k];
			o2 = xValues[k-j];
			o3 = polyTable[j-1][k];
			o4 = polyTable[j-1][k-1];

//cout << "made it?..." << endl ;
			T denominator = (o1) - (o2) ;
			T numerator = (o3) -(o4) ;
			temp.push_back(numerator/denominator);
		}

		polyTable.push_back(temp);
	}
	
	for (int t1 = 0 ; t1 < size ; t1++)
	{
		for (int t2 = 0 ; t2 < size ; t2++)
				cout << polyTable[t2][t1] << " " ;
		cout << endl ;
	}

	

	return;
}


template <typename T>   
 ostream& operator<< (ostream& out , const Newton<T> & n)
{
  for ( auto &i : n.intervalData)
  	out << get<0>(i) << " " << get<1>(i) << endl;
  return out;
}

