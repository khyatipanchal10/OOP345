#include "Notifications.h"
using namespace std;

w5::Notifications::Notifications()
{
	noti=new char[1024];
	num = 0;
}

w5::Notifications::~Notifications()
{
	if (noti != NULL)
		delete noti;
}

w5::Notifications::Notifications(const w5::Notifications &old)
{
	noti = new char[1024];
	num = old.num;
	for (int i = 0; old.noti[i] != '\0'; i++)
		noti[i] = old.noti[i];
}

w5::Notifications& w5::Notifications::operator=(const Notifications&old)
{
	if (this == &old)  
		return *this;
	if (noti != NULL)
	{
		delete []noti;
		noti = NULL;
	}
	noti = new char[1024];
	num = old.num;
	for (int i = 0; old.noti[i] != '\0'; i++)
		noti[i] = old.noti[i];
	return *this;
}




w5::Notifications::Notifications(Notifications&& old) :noti(old.noti)
{
	old.noti = NULL;
	num = old.num;
}



w5::Notifications& w5::Notifications::operator=(Notifications&& old)
{
	auto noti = this->noti;
	this->noti = old.noti;
	old.noti = noti;
	num = old.num;
	return *this;
}


void w5::Notifications::operator+=(const w5::Message&msg)
{
	int index=0;
	if (num > 0)
	{
		noti[num] = '\n';
		num++;
	}
	for (int i = 0; msg.message[i] != '\0'; i++)
	{
		noti[num + i] = msg.message[i];
	}
	num=num+msg.num;
	noti[num] = '\0';
}

void w5::Notifications::display(std::ostream& os) const
{
	//for (int i = 0; noti[i] != '\0'; i++)
		//os << noti[i] << " ";
	os <<noti<< endl;
}