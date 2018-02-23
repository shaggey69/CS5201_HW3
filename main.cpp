#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> 
#include <fstream>
#include <cmath>

#include "myArray.h"
#include "newton.h"

using namespace std;
int main(int argc, char *argv[])
{	
	ifstream in;
	int num_of_paris = 0 ;
	vector < tuple<float,float> > dataVec;
	Newton<float> my_newton;
	float temp1 = 0 , temp2 = 0;

	if (argc < 2)
    cout << endl << "not enough inputs :(" << endl ;
  else  if (argc > 2)    
    cout << endl << "too many inputs :(" << endl ;
  else
  {
		// opening the file from command line		
		in.open(argv[1]);
		argc = 0;
		in >> num_of_paris;

		//checking if file stream was sucessful
  	if (!in) 
    	cout << endl << "invailed file :("  << endl;
		else
		{
			for (int i = 0; i < num_of_paris ; i++)
			{
				in >> temp1	;
				in >> temp2 ;
				dataVec.push_back(make_tuple(temp1,temp2));
			}
			my_newton.AddValues(dataVec);
			cout << my_newton <<endl;
			my_newton.coefficientsPrint();

			cout <<endl ;
			for (float i = 0; i < 10 ; i++)
				cout << my_newton.interpolantVals(i/10) << endl;

			cout <<endl ;

			for (float i = 0; i < 10 ; i++)
				cout << 1/(1+12*pow((i/10),2)) << endl;

		}
	}

	/*
	Newton<float> godBless;
	
	
	vector < tuple<float,float> > test;

	test.push_back(make_tuple(2,15));
	test.push_back(make_tuple(3,39));
	test.push_back(make_tuple(6,243));
	test.push_back(make_tuple(7,375));
	test.push_back(make_tuple(9,771));
	
	godBless.AddValues(test);

	cout << godBless.interpolantVals(5) << endl ; // (5) 147

	
	vector < tuple<float,float> > test;

	test.push_back(make_tuple(0,648));
	test.push_back(make_tuple(2,704));
	test.push_back(make_tuple(6,792));
	test.push_back(make_tuple(3,729));

	godBless.AddValues(test);

	cout << godBless.interpolantVals(4) << endl ; //(4) 752

	*/




	in.close();

	return 0;
}
