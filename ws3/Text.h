#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
namespace w3
{
	class Text
	{
	private:
		int cnt;
		string* str;
	public:
		Text();
		Text(const string fName);		
		Text(const Text& other);
		Text& operator=(const Text& other);
		Text(Text&& other);
		Text&& operator=(Text&& other);
		~Text();
		size_t size() const;
	};
}
