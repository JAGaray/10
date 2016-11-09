struct Country 
{
  string name;
  double pop1950;
  double pop1970;
  double pop1990;
  double pop2010;
  double pop2015;
};

struct World
{
  int numCountries;
  Country countries[MAXCOUNTRIES];
} 

myWorld;
