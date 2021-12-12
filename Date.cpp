#define DATE_H
#include <iostream>
#include <fstream>
#include <string>
#include"Date.h"
using namespace std;
//获取年月日
Date::Date(int Year, int Month, int Day)
{
	year = Year;
	month = Month;
	day = Day;
}