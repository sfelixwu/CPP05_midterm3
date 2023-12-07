
#ifndef _MT3_THING_H_
#define _MT3_THING_H_

// MT3_Thing.h

#include "ecs36b_Common.h"
using namespace std;

class MT3_Thing
{
 private:
 protected:
 public:
  
  unsigned int sequence_num;

  MT3_Thing(void);
  bool operator==(const MT3_Thing&); 
  virtual Json::Value dump2JSON();
};

#endif /* _MT3_THING_H_ */
