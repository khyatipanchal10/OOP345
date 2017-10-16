#include "Text.h"
namespace w3{
	Text::Text()
	{
		str = nullptr;
		cnt = 0;
	}

	Text::Text(const string fName) : cnt(0)
	{
		ifstream is(fName);

		if (is.is_open())
		{
			int temp = 0;
			string line;

			do
			{
				getline(is, line, '\n');
				temp++;
			} while (!is.fail());

			is.clear();
			is.seekg(0, ios::beg);

			str = new string[Found];

			for (int i = 0; !is.fail(); i++)
				getline(is, str[i], '\n');

            cnt = Found;
			is.close();
		}
		else
			Text();	
	}

	Text::Text(const Text& other)
	{
		Count = 0;
		strs = '\0';
		*this = other;
	}

	Text& Text::operator=(const Text& other){
		if (this != &other){
			if (strs){
				delete[] strs;
				strs = '\0';
				Count = 0;
			}

			if (other.strs){
				Count = other.Count;
				strs = new string[Count];

				for (size_t i = 0; i < Count; i++)
					strs[i] = other.strs[i];
			}
		}

		return *this;
	}

	Text::Text(Text&& other){
		Count = 0;
		strs = '\0';
		*this = move(other);
	}

	Text&& Text::operator=(Text&& other){
		if (this != &other){
			if (strs){
				delete[] strs;
				strs = '\0';
				Count = 0;
			}

			Count = other.Count;
			strs = other.strs;

			other.Count = 0;
			other.strs = '\0';
		}

		return move(*this);
	}

	Text::~Text(){
		delete[] strs;
		strs = nullptr;
	}

	size_t Text::size() const{
		return fCount;
	}
}
