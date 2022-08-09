#include <ctime>
#include <iostream>

using namespace std;

string getTodayDate()
{
   time_t currTime;
   tm* currTm;

   char date[11];
   time(&currTime);
   currTm = localtime(&currTime);
   strftime(date, 11, "%Y-%m-%d", currTm);
   string stringDate(date);
   return stringDate;
}