
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

  Holdable item_1;
  item_1.holder = &Felix;
  item_1.location = &gps_TLC_UCDavis;
  item_1.sequence_num = 1;

  Locatable item_2;
  item_2.location = &gps_TLC_UCDavis;
  item_2.sequence_num = 1;

  if (item_1 == ((Holdable&) item_2))
    {
      std::cout << "item 1 is equal to item 2\n";
    }
  
  if (item_2 == item_1)
    {
      std::cout << "item 2 is equal to item 1\n";
    }

  return 0;
}
