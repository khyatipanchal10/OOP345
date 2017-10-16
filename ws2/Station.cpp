#include "Station.h"

Station::Station(){            //Default constructor, set all variables to a safe empty state
	name = "";
	Adult_Pass = 0;
	Student_Pass = 0;
}

void Station::set(const std::string& n, unsigned adP, unsigned suP){         //Copy Station name, student and adult passes passed
     name = n;
	Adult_Pass = adP;
	Student_Pass = suP;
}

void Station::update(PassType pTyp, int num){ // Updates number of passes based on passes received and sold
	if (pTyp  == Adult)
		Adult_Pass += (unsigned int)num;
	else
		Student_Pass += (unsigned int)num;
}

unsigned Station::inStock(PassType pTyp){            //returns number of passes bases on pass type parameter
	if (pTyp == Adult)
		return Adult_Pass;
	else
		return Student_Pass;
}
const std::string& Station::getName(){              // return the name of the current objects station.
	return name;
}
