#pragma once
#include<iostream>
#include "Order.h"
#include <vector> 
#include <iomanip>
#include<string>
using namespace std;
//堂食订单
class Orderin :virtual public Order
{
public:
	vector<Orderin> vOrderInInfo;
	Orderin() {};
	Orderin(string b, int c, int d, string e) :Order(b, c, d, e)
	{
		srand((int)(time(NULL)));
		int n = rand() % 9999 + 1000;
		std::string str = std::to_string(n);
		totalprice = c;
		No = str + "i";
		calculation();
	}
	virtual void print();//打印堂食订单到一屏幕
	void  printtxt();//打印堂食每日订单并存入到一个当天的外卖文件里面
	void AddOutInfo();//添加订单
	virtual int calculation();
	~Orderin() {};
private:
};