#ifndef MESSAGE_H_
#define MESSAGE_H_
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
namespace w5
{
	class Message
	{
	public:
		char *message;
		int num;
		Message(std::ifstream& in,char c);
		~Message();
		bool empty() const;
		void display(std::ostream&) const;
	};

}
#endif