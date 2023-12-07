
#include "Locatable.h"

Locatable::Locatable
(void)
{
  this->location = (GPS_DD *) NULL;
}

bool
Locatable::operator==
(const Locatable& another)
{
  std::cout << "Locatable::operator == was called\n";
  return ((*(this->location) == *(another.location)) &&
	  (((MT3_Thing&) (*this)) == ((MT3_Thing&) another)));
}

Json::Value
Locatable::dump2JSON
()
{
  Json::Value result = this->MT3_Thing::dump2JSON();

  if (this->location != NULL)
    {
      result["location"] = (this->location)->dump2JSON();
    }

  return result;
}
