#ifndef LAB_10_H
#define LAB_10_H

const int MAX_COUNTRIES = 500;

// structure and class definitions
struct Country {
	string name; // name of country
	// popululation of country for each specific year
	long double pop1950;
	long double pop1970;
	long double pop1990;
	long double pop2010;
	long double pop2015;

	// store growth rates for each country
	long double growth1950to2015;

};

struct World {
	int numCountries;
	Country countries[MAX_COUNTRIES];
	// indices of 3 largest countries
	int first, second, third;
}; myWorld // myWorld is an instance of World

#endif

