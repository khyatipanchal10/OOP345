#include "Stations.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace w2;

Stations::Stations(char* file){
	std::ifstream stnData(file);    //open file
	if (stnData.is_open()){       //check if file successfully opened
		std::string s;
		std::getline(stnData, s, ';');
		count = 4;
		if (count){
			stations = new Station[count];
			for (int i = 0; i < count; i++){
				std::string sName;
				stnData.seekg(1, std::ios::cur);
				std::getline(stnData, sName, ';');
				int studP, adulP;
				stnData >> studP;
				stnData >> adulP;
				stations[i].set(sName, adulP, studP);
			}
		}

	}
}


void Stations::update(){
	int Adultsold, Studentsold;                     
	std::cout << "Passes Sold : \n" << "-------------\n";
	int j= 0;
	while(j < count)
	{
		cout << stations[j].getName() <<  endl  << " Student Passes Sold : ";
		cin >> Studentsold;
		stations[j].update(Student, Studentsold * -1);
		std::cout << " Adult   Passes Sold : ";
		std::cin >> Adultsold;
		stations[j].update(Adult, Adultsold * -1);
		j++;
	}
	std::cout << std::endl;

}

void Stations::restock(){
	int Adultrec, Studentrec;                        //set up temporary variables
	std::cout << "Passes Added :\n";
	std::cout << "--------------\n";
	for (int i = 0; i < count; i++){ //loop until number of stations reached
		std::cout << stations[i].getName() << std::endl; // Print Station Name
		std::cout << " Student Passes Added : ";
		std::cin >> Studentrec;
		stations[i].update(Student, Studentrec); // update student passes received
		std::cout << " Adult   Passes Added : ";
		std::cin >> Adultrec;
		stations[i].update(Adult, Adultrec);
	}
	std::cout << std::endl;

}


void Stations::report(){           //Display number of adult and student passes at each station
	cout << "Passes in Stock : ";
	cout << "Student Adult \n";
	cout << "-------------------------------\n";
	for (int i = 0; i < count; i++){
		std::cout.setf(std::ios::left);
		std::cout.width(15);
		std::cout << stations[i].getName();
		std::cout.unsetf(std::ios::left);
		std::cout.width(10);
		std::cout << stations[i].inStock(Student);
		std::cout.width(6);
		std::cout << stations[i].inStock(Adult) << endl ;

	}
}


Stations::~Stations(){
	if (stations) { delete[] stations; }
}
