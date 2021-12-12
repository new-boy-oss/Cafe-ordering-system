#pragma once
#include<iostream>
#define DATE_H
#include <iomanip>
#include <sstream>
#include "Orderin.h"
#include "OrderOut.h"
#include "Order manage.h"
using std::setw;
#pragma warning(disable:4996)
using namespace std;
int main()
{    OrderManage c;
    c.DeleteAllOrder();
	for (int i = 0; i < 2; i++)
	{
		int n = 1001 + i;
		std::stringstream ss;
		std::string str;
		ss << n;
		ss >> str;
		Orderin a(str + "i", "奶茶", 12, 1,"是", "是", "是");
		a.AddOutInfo();
		a.print();
	}
	for (int i = 0; i < 2; i++)
	{
		int n = 1001 + i;
		std::stringstream ss;
		std::string str;
		ss << n;
		ss >> str;
		OrderOut b(str + "o", "咖啡", 12, 1, "是", "是", "是");
		b.add();
		b.AddOutInfo();
		b.print();
	}
	cout << "-----------------------------------------------------";
	cout << endl;
	c.displayOrder();
	cout << "-----------------------------------------------------";
	c.UpdateOrder();
	cout << "-----------------------------------------------------5";
	c.SeekOrder();
	cout << "-----------------------------------------------------6";
	c.DeleteoneOrder();
	c.displayOrder();

}