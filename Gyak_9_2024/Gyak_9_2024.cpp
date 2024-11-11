// Gyak_9_2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	float tmb[3];
	float* mut;
	cout << "A tomb memoriacimek megjelenitese: " << endl;
	for(int i = 0; i < 3; ++i)
		{
			cout << "&tmb[" << i << "] = " << &tmb[i] << endl;
		}
		mut = tmb; // mut = &tmb[0] mutató értéke a tömb elsõ eleme
		cout << "Memoriacimek megjelenitese mutato segitsegevel: " << endl;
		for(int i = 0; i < 3; ++i)
		{
			cout <<"mut + ["<< i << "] =" << mut + i <<  endl;
		}
return 0;
}

