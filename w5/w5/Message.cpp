#include "Message.h"
using namespace std;

char mess[] = "Message";
char user[] = "User  : ";
char tweet[] = "Tweet : ";
char reply[] = "Reply : ";

w5::Message::Message(std::ifstream &in, char c)
{
	message=new char[100];
	char buff[100];
	int flag1 = 0,flag2=0,index=0,index1,count;
	num=0;
	char temp;
	temp=in.get();
	while(temp!=c &&!in.eof())
	{
		if (temp == ' ') flag1 = 1;
		if (temp == '@') flag2 = 1;
		buff[index] = temp;
		index++;
		temp=in.get();
	}
	buff[index] = '\0';
	if (flag1 == 0) return;
	for (int i = 0; mess[i] != '\0'; i++)  //user
	{
		message[i] = mess[i];
		num++;
	}
	message[num] = '\n';
	num++;
	for (count = 0; user[count] != '\0'; count++)  //user
	{
		message[count + num] = user[count];
	}
	num+=count;
	count = 0;
	for (index1 = 0; buff[index1] != ' '; index1++) //user name
	{
		count++;
		message[num + index1] = buff[index1];
	}
	num = num + count;
	message[num] = '\n';
	num++;
	if (flag2 == 1)
	{
		int i = 0;
		for (; reply[i] != '\0'; i++)      //reply
		{
			message[num+i] = reply[i];
		}
		num = num + i;
		index1+=2;
		for (i = 0; buff[index1] != ' '; index1++)  //reply name
		{
			message[num + i] = buff[index1];
			i++;
		}
		num = num + i;
		message[num] = '\n';
		num++;
	}

	for (index=0; tweet[index] != '\0'; index++)
	{
		message[num + index] = tweet[index];
	}
	num += index;
	count = 0;
	index1++;
	for (; buff[index1] != '\0'; index1++)
	{
		message[num + count] = buff[index1];
		count++;
	}
	num += count;
	message[num] = '\n';
	message[++num] = '\0';
}

bool w5::Message::empty() const
{
	return num==0;
}

void w5::Message::display(std::ostream &out) const
{
	out<<message<<endl;
}

w5::Message::~Message()
{
	delete []message;
}