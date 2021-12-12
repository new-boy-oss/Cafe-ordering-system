#define DATE_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int Year, int Month, int Day);
	int get_year() { return year; }
	int get_month() { return month; }
	int get_day() { return day; }
};
