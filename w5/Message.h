#ifndef W5_MESSAGE_H
#define W5_MESSAGE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Message.h"

namespace w5 {
  class Message {
    std::string user;
    std::string reply;
    std::string tweet;
  public:
    Message(std::ifstream& infs, char ch);
    bool empty() const;
    void display(std::ostream&) const;
  };
}

#endif
