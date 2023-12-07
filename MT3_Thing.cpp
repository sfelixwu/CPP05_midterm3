
#include "MT3_Thing.h"

MT3_Thing::MT3_Thing
(void)
{
  this->sequence_num = 0;
}

bool
MT3_Thing::operator==
(const MT3_Thing& another)
{
  std::cout << "MT3_Thing::operator == was called\n";
  return (this->sequence_num == another.sequence_num);
}

Json::Value
MT3_Thing::dump2JSON
()
{
  Json::Value result;

  if (this->sequence_num != 0)
    {
      result["sequence number"] = this->sequence_num;
    }

  return result;
}
