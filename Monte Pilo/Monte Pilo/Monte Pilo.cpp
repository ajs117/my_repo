// Monte Pilo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

double unigen()
{
	static default_random_engine generator;
	uniform_real_distribution<double> distribution(0, 1);
	return distribution(generator);
}

int main()
{
	int iteration = 1;
	int inCount = 1;

	double calculated = 0;

	for (;;)
	{
		double x = unigen();
		double y = unigen();

		if (pow(x - 0.5, 2) + pow(y - 0.5, 2) <= 0.25)
		{
			inCount++;
		}

		calculated = 4 * ((double)inCount / iteration);

		if (iteration % 1000 == 0)
		{
			system("cls");
			cout << "Iteration: " << setprecision(10) << iteration << endl;
			cout << "Calculated pi: " << setprecision(10) << calculated << endl;
		}

		iteration++;
	}

	return 0;
}

