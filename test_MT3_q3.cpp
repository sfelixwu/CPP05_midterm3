
// test_GPS.cpp

#include "Holdable.h"
#include "Labeled_GPS.h"

int
main
(int argc, char *argv[])
{
  Labeled_GPS gps_TLC_UCDavis   { 38.53874868013882,  -121.7542091083306,
				  "Teaching and Learning Complex" };
  Person Felix { "987654321", "Felix" };

  Holdable item_1; // item_1
  item_1.holder = &Felix;
  item_1.location = &gps_TLC_UCDavis;
  item_1.sequence_num = 1;

  MT3_Thing * mt3_ptr = &item_1;
  Locatable * loc_ptr = &item_1;

  void **vtable_ptr = ((void **) (&item_1)); // ptr2_vtable_pr
  // &item_1 ==> address of the object item_1
  // what do we mean by "address of the object item_1"?
  // ==> address of the first byte of the object item_1

  // vtable (data structure storing information about the class. Per class)
  // the class Holdable has a vtable.
  // for each Holdable object (under the class of Holdable), we have one vtable pointer.
  // vtable_ptr (for object) is always the first eight bytes of the object
  
  void **vtable_2_ptr = ((void **) (((unsigned long) (&(item_1.location))) - 8));
  
  std::cout << "MT3 obj  address: " << mt3_ptr                << std::endl;
  std::cout << "MT3 attr address: " << &(item_1.sequence_num) << std::endl;
  std::cout << "LOC obj  address: " << loc_ptr                << std::endl;
  std::cout << "LOC attr address: " << &(item_1.location)     << std::endl;
  std::cout << "HOL obj  address: " << &item_1                << std::endl;
  std::cout << "HOL attr address: " << &(item_1.holder)       << std::endl;
  std::cout << "vtable   address: " << *(vtable_ptr)          << std::endl;
  std::cout << "vtable_2 address: " << *(vtable_2_ptr)     << std::endl;

  return 0;
}
