/* Author: Julian Garay
   Course: CSCI 136
   Task: Lab 10
   Instructor: Ali
This program is designed to open a file, read the data in the file, and use it to populate data structures. */



#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "lab10.h"

using namespace std;

int main()
{
  int localFirst = 0,
      localSecond = 0,
      localThird = 0;
  ifstream pop;
  pop.open("population.csv");

  string localname;
  int locnumCountry = 0;
  long double locpop1950;
  long double locpop1970;
  long double locpop1990;
  long double locpop2010;
  long double locpop2015;

  if (pop.fail())
   {
	cout << "Error opening file\n";
   }

	while (pop >> locpop1950 >> locpop1970 >> locpop1990 >>
		locpop2010 >> locpop2015)
	 {
		if (!pop.eof())
		 {
			getline(pop, localname);
		 }
		myWorld.countries[locnumCountry].pop1950 = locpop1950;
		myWorld.countries[locnumCountry].pop1970 = locpop1970;
		myWorld.countries[locnumCountry].pop1990 = locpop1990;
		myWorld.countries[locnumCountry].pop2010 = locpop2010;
		myWorld.countries[locnumCountry].pop2015 = locpop2015;
        myWorld.countries[locnumCountry].name = localname;
	  locnumCountry++;
	}

	myWorld.numCountries = locnumCountry;

  for (int i=0; i < myWorld.numCountries; i++)
   {
	myWorld.countries[i].growth1950to2015 = abs( ((myWorld.countries[i].pop2015 - myWorld.countries[i].pop1950) /
						      myWorld.countries[i].pop1950) * 100);

    if (myWorld.countries[i].growth1950to2015 > myWorld.countries[localFirst].growth1950to2015)
	{
	  localFirst = i;
	}
     if ((myWorld.countries[localFirst].growth1950to2015 > myWorld.countries[i].growth1950to2015)
	 && (myWorld.countries[localSecond].growth1950to2015 <
	     myWorld.countries[i].growth1950to2015))
	{
	  localSecond = i;
	}
     if ((myWorld.countries[localSecond].growth1950to2015 > myWorld.countries[i].growth1950to2015)  &&
	 (myWorld.countries[localThird].growth1950to2015 <
	 myWorld.countries[i].growth1950to2015))
	{
	  localThird = i;
	}

   }

  cout << fixed << setprecision(0); //formatting

  cout << "The country with the highest growth rate is" << myWorld.countries[localFirst].name << ", which had a rate of "
       << myWorld.countries[localFirst].growth1950to2015 << " from 1950 to 2015." << endl;

  cout << "The country with the second highest growth rate is" << myWorld.countries[localSecond].name << ", which had a rate of " << myWorld.countries[localSecond].growth1950to2015 << " from 1950 to 2015." << endl;

  cout << "The country with the third highest growth rate is" << myWorld.countries[localThird].name <<  ", which had a rate of " << myWorld.countries[localThird].growth1950to2015 << " from 1950 to 2015." << endl;
}
