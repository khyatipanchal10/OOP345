#include <cstring>
#include <iostream>
#include "CString.h"

namespace w1 {
  CString::CString(char* parm) {
    if (parm == NULL) {
      str[0] = '\0';
     
    }
    strncpy(str, parm, MAX);
    str[MAX] = '\0';
  }

  void CString::display(std::ostream& os) {
    os << str;
  }

  std::ostream& operator<<(std::ostream& os, CString cs) {
    static int calls = 0;
    os << calls++ << ": ";
    cs.display(os);
    return os;
  }
}