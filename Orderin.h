#pragma once
#include<iostream>
#include "Order.h"
#include <vector> 
using namespace std;
//堂食订单
class Orderin :virtual public Order
{
public:
	vector<Orderin> vOrderInInfo;
	Orderin(){};
	Orderin(string a, string b, double c, int d,string e,string f,string g) :Order(a,b,c,d,e,f,g) {
		totalprice = c;
		calculation();
	}
	virtual void print();//打印堂食订单到一屏幕
    void  printtxt();//打印堂食每日订单并存入到一个当天的外卖文件里面
	void AddOutInfo();//添加订单
	virtual int calculation();
	~Orderin() {};
private:
};