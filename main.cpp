#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> 
#include "newton.h"


using namespace std;
int main()
{	

	Newton<int> test;
	test.AddValues(2,15);
	test.AddValues(3,39);
	test.AddValues(6,243);
	test.AddValues(7,375);
	test.AddValues(9,771);

	cout << test << endl;

	test.makeTable();

	//cout << "value at 175 is: " << test[175] << endl;


	return 0;
}
