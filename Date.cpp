#define DATE_H
#include <iostream>
#include <fstream>
#include <string>
#include"Date.h"
using namespace std;
Date::Date(int Year, int Month, int Day)
{
	year = Year;
	month = Month;
	day = Day;
}