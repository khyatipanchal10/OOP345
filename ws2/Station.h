#pragma once
#include <string>
#include <iostream>
using namespace std;

enum PassType { Adult, Student };

class Station{
	string name;
	unsigned int Student_Pass;
	unsigned int Adult_Pass;

public:
	Station();
	void set(const std::string&, unsigned, unsigned);
	void update(PassType, int);
	unsigned inStock(PassType);
	const std::string& getName();
};