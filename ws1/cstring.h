#pragma once
#include <iostream>

namespace w1 {

  const int MAX = 3;

  class CString {
    private:
      char str[MAX + 1];
    public:
      CString(char* parm);
      void display(std::ostream& os);
  };

  std::ostream& operator<<(std::ostream& os, CString cs);

}