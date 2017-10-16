#ifndef NOTIFICATIONS_H_
#define NOTIFICATIONS_H_
#include "Message.h"

namespace w5
{
	class Notifications
	{
	public:
		char *noti;
		int num;
		Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);            //move constructor
		Notifications& operator=(Notifications&&);
		~Notifications();
		void operator+=(const Message&msg);
		void display(std::ostream& os) const;
	};
}


#endif