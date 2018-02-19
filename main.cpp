#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> 
#include "newton.h"


using namespace std;
int main()
{	

	Newton<float> test;
	/*
	test.AddValues(2,15);
	test.AddValues(3,39);
	test.AddValues(6,243);
	test.AddValues(7,375);
	test.AddValues(9,771);
	*/
	//cout << test << endl;
	test.AddValues(0,648);
	test.AddValues(2,704);
	test.AddValues(3,729);
	test.AddValues(6,9792);



	//test.calcNewton();
	cout << test.interpolantVals(4) << endl ;
	//cout << "value at 175 is: " << test[175] << endl;


	return 0;
}
