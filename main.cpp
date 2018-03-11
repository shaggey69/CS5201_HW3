/*
# main file for the third Prgram!
# By: Ari Sherman
# Class: CS5201 HW #3
# Date: 2.26.18
*/
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
	//declartion of vars
	ifstream in;
	int num_of_paris = 0 ;
	vector < tuple<double ,double > > dataVec;
	Newton<double > my_newton;
	double  temp1 = 0 , temp2 = 0;

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
						
			// interpolant values print
			cout <<endl ;
			for (float i = 0; i <= 10 ; i++)
			{
				cout << setprecision(8);
				cout << my_newton.interpolantVals(i/10) << endl;
			}

			cout << endl;
			
			// 1/1+12x^2 function print
			for (float i = 0; i <= 10 ; i++)
				cout << 1/(1+12*pow((i/10),2)) << endl;

			cout << endl;
		
			//abslote error print
			for (float i = 0; i <= 10 ; i++)	
				cout << my_newton.absErr(i/10) << endl;
			
			cout << endl;

			//relative error print
			for (float i = 0; i <= 10 ; i++)			
				cout << my_newton.relErr(i/10) << endl;
				
		}
	}

	in.close();

	return 0;
}
