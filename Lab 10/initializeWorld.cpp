#include <iostream>
#include "lab10.h"

using namespace std;

void initializeWorld(myWorld, std::ifstream pop)
{

  string localname;
  int locnumCountry = 0;
  long double locpop1950;
  long double locpop1970;
  long double locpop1990;
  long double locpop2010;
  long double locpop2015;


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

	  locnumCountry++;
	}

	myWorld.numCountries = locnumCountry;
}
